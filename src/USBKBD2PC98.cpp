//---------------------------------------------------------------------
// USB/Keyboard(Japanese) to PC98 Keyboard
// 
// (Arduino Pro Mini 8MHz)
// ・USB_Host_Shield_2.0 (https://github.com/felis/USB_Host_Shield_2.0)
// ・MsTimer2 (http://playground.arduino.cc/Main/MsTimer2)
//
// minidin8P   --  Arduino Pro Mini
//  1 RST      --  1(D1)
//  2 GND      --  GND
//  3 RDY      --  
//  4 RxD      --  2(D0)
//  5 RTY      --  
//  6          --  
//  7          --  
//  8 Vcc(+5V) --  Vcc(+5V)
//
// minidin9P   --  Arduino Pro Mini
//  1 Vcc(+5V) --  
//  2 XA       --  6(D3)
//  3 XB       --  7(D4)
//  4 YA       --  8(D5)
//  5 YB       --  9(D6)
//  6 L        --  10(D7)
//  7 M        --  
//  8 R        --  11(D8)
//  9 GND      --  
//---------------------------------------------------------------------
#include <hidboot.h>
#include <usbhub.h>
#include <MsTimer2.h>
#include "keymap.h"

// DEBUG
#define DEBUG       0     // 0:デバッグ情報出力なし 1:デバッグ情報出力あり
#define LOBYTE(x) ((char*)(&(x)))[0]
#define HIBYTE(x) ((char*)(&(x)))[1]

// GPIO
#define MS_XA       3     // Mouse XA
#define MS_XB       4     // Mouse XB
#define MS_YA       5     // Mouse YA
#define MS_YB       6     // Mouse YB
#define MS_LB       7     // Mouse LB
#define MS_RB       8     // Mouse RB
#define LED        13     // 内蔵LED

// 変数
volatile uint8_t sCode = 0xff;          // スキャンコード
volatile uint8_t prevScode = 0xff;      // 前回スキャンコード
volatile int16_t sCodeCnt = 0;          // キーリピート回数
volatile int16_t delayTime = 500;       // キーリピート開始(初期値500ms)
volatile int16_t repeatTime = 110;      // キーリピート間隔(初期値110ms)

volatile int16_t XYlimit = 256;         // マウスリミット値
volatile int16_t xState = 0;            // マウスステータス(X)
volatile int16_t ySstate = 0;           // マウスステータス(Y)
volatile int16_t bSstate = 0;           // マウスステータス(B)

void sendRepeat();
//
// HIDキーボード レポートパーサークラスの定義
//
class KbdRptParser : public KeyboardReportParser {
  protected:
    void OnControlKeysChanged(uint8_t before, uint8_t after);
    void OnKeyDown(uint8_t mod, uint8_t key);
    void OnKeyUp(uint8_t mod, uint8_t key);
    void OnKeyPressed(uint8_t key) {};
};

//
// HIDマウス レポートパーサークラスの定義
//
class MseRptParser : public MouseReportParser {
  protected:
    void OnMouseMove(MOUSEINFO *mi);
    void OnLeftButtonUp(MOUSEINFO *mi);
    void OnLeftButtonDown(MOUSEINFO *mi);
    void OnRightButtonUp(MOUSEINFO *mi);
    void OnRightButtonDown(MOUSEINFO *mi);
};

//
// PC98 makeコード送信(キー押し)
// 引数 key(IN) HID Usage ID
//
void sendKeyMake(uint8_t key) {
  // HID Usage ID から PC98 スキャンコード に変換
  uint8_t code = 0;
  code = pgm_read_byte(&(keytable98[key]));
  if (code == 0xff) {
    return;
  }
  sCodeCnt++;
  prevScode = code;
#if DEBUG
  Serial.print(F("UP2["));  Serial.print(F("key="));  Serial.print(key, HEX);
  Serial.print(F(" code="));  Serial.print(code, HEX);  Serial.println(F("]"));
#endif
  // PC98キーの発行
  Serial.write(code);
  sCode = code;
  MsTimer2::set(delayTime, sendRepeat);
  MsTimer2::start();
}

//
// PC98 breakコード送信(キー離し)
// 引数 key(IN) HID Usage ID
//
void sendKeyBreak(uint8_t key) {
  // HID Usage ID から PC98 スキャンコード に変換
  uint8_t code = 0;
  code = pgm_read_byte(&(keytable98[key]));
  if (code == 0xff) {
    return;
  }
  sCodeCnt--;
  if (prevScode == code) {
    sCode = 0xff;
  }
#if DEBUG
  Serial.print(F("DN ["));  Serial.print(F("key="));  Serial.print(key, HEX);
  Serial.print(F(" code="));  Serial.print(code, HEX);  Serial.println(F("]"));
#endif
  // PC98キーの発行キーの発行
  Serial.write(code | 0x80);
  if (sCodeCnt == 0) {
    MsTimer2::stop();
  }
}

//
// アップデートマウスボタン
//
void updateMouseBtn() {
#ifdef DEBUG_MOUSE
  Serial.print("bSstate = ");
  Serial.println(bSstate,HEX);
#endif
  // ボタンの判定
  switch (bSstate) {
    case 0x00:
      pinMode(MS_LB, INPUT);
      pinMode(MS_RB, INPUT);
      break;
    case 0x01:
      pinMode(MS_LB, OUTPUT);
      pinMode(MS_RB, INPUT);
      break;
    case 0x02:
      pinMode(MS_LB, INPUT);
      pinMode(MS_RB, OUTPUT);
      break;
    case 0x03:
      pinMode(MS_LB, OUTPUT);
      pinMode(MS_RB, OUTPUT);
      break;
  }
}

//
// アップデートマウスX
//
void updateMouseX(bool di) {
#ifdef DEBUG_MOUSE
  Serial.print("xState = ");
  Serial.println(xState,HEX);
#endif
  if (di) {
    //+方向(右方向) 0->1->3->2
    if (xState == 0) {
      xState = 1;
      pinMode(MS_XA, OUTPUT);
      pinMode(MS_XB, INPUT);
    } else if (xState == 1) {
      xState = 3;
      pinMode(MS_XA, OUTPUT);
      pinMode(MS_XB, OUTPUT);
    } else if (xState == 3) {
      xState = 2;
      pinMode(MS_XA, INPUT);
      pinMode(MS_XB, OUTPUT);
    } else if (xState == 2) {
      xState = 0;
      pinMode(MS_XA, INPUT);
      pinMode(MS_XB, INPUT);
    } else {
      xState = 0;
    }
  } else {
    //-方向(左方向) 2->3->1->0
    if (xState == 2) {
      xState = 3;
      pinMode(MS_XA, OUTPUT);
      pinMode(MS_XB, OUTPUT);
    } else if (xState == 3) {
      xState = 1;
      pinMode(MS_XA, OUTPUT);
      pinMode(MS_XB, INPUT);
    } else if (xState == 1) {
      xState = 0;
      pinMode(MS_XA, INPUT);
      pinMode(MS_XB, INPUT);
    } else if (xState == 0) {
      xState = 2;
      pinMode(MS_XA, INPUT);
      pinMode(MS_XB, OUTPUT);
    } else {
      xState = 0;
    }
  }
  delayMicroseconds(150);
}

//
// アップデートマウスY
//
void updateMouseY(bool di) {
#ifdef DEBUG_MOUSE  
  Serial.print("ySstate = ");
  Serial.println(ySstate,HEX);
#endif
  if (di) {
    //+方向(下方向) 0->1->3->2
    if (ySstate == 0) {
      ySstate = 1;
      pinMode(MS_YA, OUTPUT);
      pinMode(MS_YB, INPUT);
    } else if (ySstate == 1) {
      ySstate = 3;
      pinMode(MS_YA, OUTPUT);
      pinMode(MS_YB, OUTPUT);
    } else if (ySstate == 3) {
      ySstate = 2;
      pinMode(MS_YA, INPUT);
      pinMode(MS_YB, OUTPUT);
    } else if (ySstate == 2) {
      ySstate = 0;
      pinMode(MS_YA, INPUT);
      pinMode(MS_YB, INPUT);
    } else {
      ySstate = 0;
    }
  } else {
    //-方向(上方向) 2->3->1->0
    if (ySstate == 2) {
      ySstate = 3;
      pinMode(MS_YA, OUTPUT);
      pinMode(MS_YB, OUTPUT);
    } else if (ySstate == 3) {
      ySstate = 1;
      pinMode(MS_YA, OUTPUT);
      pinMode(MS_YB, INPUT);
    } else if (ySstate == 1) {
      ySstate = 0;
      pinMode(MS_YA, INPUT);
      pinMode(MS_YB, INPUT);
    } else if (ySstate == 0) {
      ySstate = 2;
      pinMode(MS_YA, INPUT);
      pinMode(MS_YB, OUTPUT);
    } else {
      ySstate = 0;
    }
  }
  delayMicroseconds(150);
}

//
// コントロールキー変更ハンドラ
// SHIFT、CTRL、ALT、GUI(Win)キーの処理を行う
// 引数 before : 変化前のコード USB Keyboard Reportの1バイト目
//      after  : 変化後のコード USB Keyboard Reportの1バイト目
//
void KbdRptParser::OnControlKeysChanged(uint8_t before, uint8_t after) {
  MODIFIERKEYS beforeMod;
  *((uint8_t*)&beforeMod) = before;

  MODIFIERKEYS afterMod;
  *((uint8_t*)&afterMod) = after;

  // 左Ctrlキー
  if (beforeMod.bmLeftCtrl != afterMod.bmLeftCtrl) {
    if (afterMod.bmLeftCtrl) {
      // 左Ctrltキーを押した
      sendKeyMake(0xe0);
    } else {
      // 左Ctrltキーを離した
      sendKeyBreak(0xe0);
    }
  }
  // 左Shiftキー
  if (beforeMod.bmLeftShift != afterMod.bmLeftShift) {
    if (afterMod.bmLeftShift) {
      // 左Shiftキーを押した
      sendKeyMake(0xe1);
    } else {
      // 左Shiftキーを離した
      sendKeyBreak(0xe1);
    }
  }
  // 左Altキー
  if (beforeMod.bmLeftAlt != afterMod.bmLeftAlt) {
    if (afterMod.bmLeftAlt) {
      // 左Altキーを押した
      sendKeyMake(0xe2);
    } else {
      // 左Altキーを離した
      sendKeyBreak(0xe2);
    }
  }
  // 左GUIキー(Winキー)
  if (beforeMod.bmLeftGUI != afterMod.bmLeftGUI) {
    if (afterMod.bmLeftGUI) {
      // 左GUIキーを押した
      sendKeyMake(0xe3);
    } else {
      // 左GUIキーを離した
      sendKeyBreak(0xe3);
    }
  }
  // 右Ctrlキー
  if (beforeMod.bmRightCtrl != afterMod.bmRightCtrl) {
    if (afterMod.bmRightCtrl) {
      // 右Ctrltキーを押した
      sendKeyMake(0xe4);
    } else {
      // 右Ctrltキーを離した
      sendKeyBreak(0xe4);
    }
  }
  // 右Shiftキー
  if (beforeMod.bmRightShift != afterMod.bmRightShift) {
    if (afterMod.bmRightShift) {
      // 右Shiftキーを押した
      sendKeyMake(0xe5);
    } else {
      // 右Shiftキーを離した
      sendKeyBreak(0xe5);
    }
  }
  // 右Altキー
  if (beforeMod.bmRightAlt != afterMod.bmRightAlt) {
    if (afterMod.bmRightAlt) {
      // 右Altキーを押した
      sendKeyMake(0xe6);
    } else {
      // 右Altキーを離した
      sendKeyBreak(0xe6);
    }
  }
  // 右GUIキー
  if (beforeMod.bmRightGUI != afterMod.bmRightGUI) {
    if (afterMod.bmRightGUI) {
      // 右GUIキーを押した
      sendKeyMake(0xe7);
    } else {
      // 右GUIキーを離した
      sendKeyBreak(0xe7);
    }
  }
}

//
// キー押しハンドラ
// 引数
//  mod : コントロールキー状態
//  key : HID Usage ID
//
void KbdRptParser::OnKeyDown(uint8_t mod, uint8_t key) {
#if DEBUG
  Serial.print(F("DN ["));  Serial.print(F("mod="));  Serial.print(mod, HEX);
  Serial.print(F(" key="));  Serial.print(key, HEX);  Serial.println(F("]"));
#endif
  // HID Usage ID から PC98 スキャンコード に変換
  sendKeyMake(key);
}

//
// キー離し ハンドラ
// 引数
//  mod : コントロールキー状態
//  key : HID Usage ID
//
void KbdRptParser::OnKeyUp(uint8_t mod, uint8_t key) {
#if DEBUG
  Serial.print(F("UP ["));  Serial.print(F("mod="));  Serial.print(mod, HEX);
  Serial.print(F(" key="));  Serial.print(key, HEX);  Serial.println(F("]"));
#endif
  // HID Usage ID から PC98 スキャンコード に変換
  sendKeyBreak(key);
}

//
// マウス移動 ハンドラ
// 引数
//  mi : マウス情報
//
void MseRptParser::OnMouseMove(MOUSEINFO *mi) {
#if DEBUG
  Serial.print("dx="); Serial.print(mi->dX, DEC);
  Serial.print(" dy="); Serial.print(mi->dY, DEC);
  Serial.print(" bmLeftButton="); Serial.print(mi->bmLeftButton, DEC);
  Serial.print(" bmRightButton="); Serial.print(mi->bmRightButton, DEC);
  Serial.print(" bmMiddleButton="); Serial.println(mi->bmMiddleButton, DEC);
#endif
  // マウスデータ(X,Y)
  int8_t dxData = abs(mi->dX);
  int8_t dyData = abs(mi->dY);
  if (dxData > XYlimit) {
    dxData = XYlimit;
  }
  if (dyData > XYlimit) {
   dyData = XYlimit;
  }
  for (int8_t i = 0 ; i < dxData ; i++) {
    updateMouseX(mi->dX >= 0);
  }
  for (int8_t i = 0 ; i < dyData ; i++) {
    updateMouseY(mi->dY >= 0);
  }
}

//
// マウス左ボタン離し ハンドラ
// 引数
//  mi : マウス情報
//
void MseRptParser::OnLeftButtonUp(MOUSEINFO *mi) {
#if DEBUG
  Serial.println("L Butt Up");
#endif
  bSstate = bSstate & 0xFE;
  updateMouseBtn();
}

//
// マウス左ボタン押し ハンドラ
// 引数
//  mi : マウス情報
//
void MseRptParser::OnLeftButtonDown(MOUSEINFO *mi) {
#if DEBUG
  Serial.println("L Butt Dn");
#endif
  bSstate = bSstate | 0x01;
  updateMouseBtn();
}

//
// マウス右ボタン離し ハンドラ
// 引数
//  mi : マウス情報
//
void MseRptParser::OnRightButtonUp(MOUSEINFO *mi) {
#if DEBUG
  Serial.println("R Butt Up");
#endif
  bSstate = bSstate & 0xFD;
  updateMouseBtn();
}

//
// マウス右ボタン押し ハンドラ
// 引数
//  mi : マウス情報
//
void MseRptParser::OnRightButtonDown(MOUSEINFO *mi) {
#if DEBUG
  Serial.println("R Butt Dn");
#endif
  bSstate = bSstate | 0x02;
  updateMouseBtn();
}

USB     Usb;
USBHub  Hub1(&Usb);

//HIDBoot<USB_HID_PROTOCOL_KEYBOARD>    HidKeyboard(&Usb);
//HIDBoot<USB_HID_PROTOCOL_MOUSE>    HidMouse(&Usb);
//HIDBoot<USB_HID_PROTOCOL_KEYBOARD | USB_HID_PROTOCOL_MOUSE>    HidComposite(&Usb);
HIDBoot<3>    HidComposite(&Usb);
HIDBoot<1>    HidKeyboard(&Usb);
HIDBoot<2>    HidMouse(&Usb);

KbdRptParser keyboardPrs;
MseRptParser msePrs;

// リピート処理(タイマー割り込み処理から呼ばれる)
void sendRepeat() {
  if (sCode != 0xff) {
    Serial.write(sCode);
  }
  MsTimer2::set(repeatTime, sendRepeat);
  MsTimer2::start();
}

//
// セットアップ
//
void setup() {
  // シリアル初期化
#if DEBUG
  Serial.begin(9600);
#else
  //19.2kbps 8ビット 奇数パリティ ストップビット1ビット
  Serial.begin(19200, SERIAL_8O1);
#endif
  while (!Serial);
#if DEBUG
  Serial.println("Self Test OK.");
#endif
  if (Usb.Init() == -1) {
#if DEBUG
    Serial.println(F("OSC did not start."));
#endif
    // Halt
    while (1);
  }
  // Inputモードでプルアップ抵抗を有効
  pinMode(MS_XA, INPUT);
  pinMode(MS_XB, INPUT);
  pinMode(MS_YA, INPUT);
  pinMode(MS_YB, INPUT);
  pinMode(MS_LB, INPUT);
  pinMode(MS_RB, INPUT);
  // LED設定
  pinMode(LED, OUTPUT );
  digitalWrite(MS_XA, LOW);
  digitalWrite(MS_XB, LOW);
  digitalWrite(MS_YA, LOW);
  digitalWrite(MS_YB, LOW);
  digitalWrite(MS_LB, LOW);
  digitalWrite(MS_RB, LOW);
  digitalWrite(LED, LOW);

  // Hid初期化
  HidComposite.SetReportParser(0, &keyboardPrs);
  HidComposite.SetReportParser(1, &msePrs);
  HidKeyboard.SetReportParser(0, &keyboardPrs);
  HidMouse.SetReportParser(0, &msePrs);

#if DEBUG
  Serial.println(F("Start."));
#endif
}

//
// ループ
//
void loop() {
  Usb.Task();
}
