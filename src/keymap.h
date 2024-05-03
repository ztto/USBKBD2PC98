// HID Usage ID => PC98 スキャンコード 変換テーブル
const uint8_t keytable98[] PROGMEM = {
    0xff,    // 00h  []
    0xff,    // 01h  []
    0xff,    // 02h  []
    0xff,    // 03h  []
    0x1d,    // 04h  A
    0x2d,    // 05h  B
    0x2b,    // 06h  C
    0x1f,    // 07h  D
    0x12,    // 08h  E
    0x20,    // 09h  F
    0x21,    // 0Ah  G
    0x22,    // 0Bh  H
    0x17,    // 0Ch  I
    0x23,    // 0Dh  J
    0x24,    // 0Eh  K
    0x25,    // 0Fh  L
    0x2f,    // 10h  M
    0x2e,    // 11h  N
    0x18,    // 12h  O
    0x19,    // 13h  P
    0x10,    // 14h  Q
    0x13,    // 15h  R
    0x1e,    // 16h  S
    0x14,    // 17h  T
    0x16,    // 18h  U
    0x2c,    // 19h  V
    0x11,    // 1Ah  W
    0x2a,    // 1Bh  X
    0x15,    // 1Ch  Y
    0x29,    // 1Dh  Z
    0x01,    // 1Eh  ! 1
    0x02,    // 1Fh  " 2
    0x03,    // 20h  # 3
    0x04,    // 21h  $ 4
    0x05,    // 22h  % 5
    0x06,    // 23h  & 6
    0x07,    // 24h  ' 7
    0x08,    // 25h  ( 8
    0x09,    // 26h  ) 9
    0x0a,    // 27h  0
    0x1c,    // 28h  Enter
    0x00,    // 29h  Esc
    0x0e,    // 2Ah  Backspace
    0x0f,    // 2Bh  Tab
    0x34,    // 2Ch  空白
    0x0b,    // 2Dh  = -
    0x0c,    // 2Eh  ~ ^
    0x1a,    // 2Fh  ` @
    0x1b,    // 30h  { [
    0x28,    // 31h  []
    0x28,    // 32h  } ]
    0x26,    // 33h  + ;
    0x27,    // 34h  * :
    0xff,    // 35h  半角/全角
    0x30,    // 36h  < ,
    0x31,    // 37h  > .
    0x32,    // 38h  ? /
    0x71,    // 39h  Caps Lock
    0x62,    // 3Ah  F1
    0x63,    // 3Bh  F2
    0x64,    // 3Ch  F3
    0x65,    // 3Dh  F4
    0x66,    // 3Eh  F5
    0x67,    // 3Fh  F6
    0x68,    // 40h  F7
    0x69,    // 41h  F8
    0x6a,    // 42h  F9
    0x6b,    // 43h  F10
    0xff,    // 44h  F11
    0xff,    // 45h  F12
    0x61,    // 46h  Print Screen
    0xff,    // 47h  Scroll Lock
    0x60,    // 48h  Pause
    0x38,    // 49h  INSERT
    0x3f,    // 4Ah  HOME
    0x36,    // 4Bh  PAGE UP
    0x39,    // 4Ch  DEL
    0xff,    // 4Dh  End
    0x37,    // 4Eh  PAGE
    0x3c,    // 4Fh  RIGHT
    0x3b,    // 50h  LEFT
    0x3d,    // 51h  DOWN
    0x3a,    // 52h  UP
    0xff,    // 53h  NumLock
    0x41,    // 54h  Num /
    0xff,    // 55h  Num *
    0x40,    // 56h  Num -
    0x49,    // 57h  Num +
    0x1c,    // 58h  Num Enter
    0x4a,    // 59h  Num 1
    0x4b,    // 5Ah  Num 2
    0x4c,    // 5Bh  Num 3
    0x46,    // 5Ch  Num 4
    0x47,    // 5Dh  Num 5
    0x48,    // 5Eh  Num 6
    0x42,    // 5Fh  Num 7
    0x43,    // 60h  Num 8
    0x44,    // 61h  Num 9
    0x4e,    // 62h  Num 0
    0xff,    // 63h  Num .
    0xff,    // 64h  []
    0xff,    // 65h  App
    0xff,    // 66h  []
    0xff,    // 67h  []
    0xff,    // 68h  []
    0xff,    // 69h  []
    0xff,    // 6Ah  []
    0xff,    // 6Bh  []
    0xff,    // 6Ch  []
    0xff,    // 6Dh  []
    0xff,    // 6Eh  []
    0xff,    // 6Fh  []
    0xff,    // 70h  []
    0xff,    // 71h  []
    0xff,    // 72h  []
    0xff,    // 73h  []
    0xff,    // 74h  []
    0xff,    // 75h  []
    0xff,    // 76h  []
    0xff,    // 77h  []
    0xff,    // 78h  []
    0xff,    // 79h  []
    0xff,    // 7Ah  []
    0xff,    // 7Bh  []
    0xff,    // 7Ch  []
    0xff,    // 7Dh  []
    0xff,    // 7Eh  []
    0xff,    // 7Fh  []
    0xff,    // 80h  []
    0xff,    // 81h  []
    0xff,    // 82h  []
    0xff,    // 83h  []
    0xff,    // 84h  []
    0xff,    // 85h  []
    0xff,    // 86h  []
    0x33,    // 87h  _ 
    0x72,    // 88h  カタカナ ひらがな
    0x0d,    // 89h  | 
    0x35,    // 8Ah  変換
    0x51,    // 8Bh  無変換
    0xff,    // 8Ch  []
    0xff,    // 8Dh  []
    0xff,    // 8Eh  []
    0xff,    // 8Fh  []
    0xff,    // 90h  []
    0xff,    // 91h  []
    0xff,    // 92h  []
    0xff,    // 93h  []
    0xff,    // 94h  []
    0xff,    // 95h  []
    0xff,    // 96h  []
    0xff,    // 97h  []
    0xff,    // 98h  []
    0xff,    // 99h  []
    0xff,    // 9Ah  []
    0xff,    // 9Bh  []
    0xff,    // 9Ch  []
    0xff,    // 9Dh  []
    0xff,    // 9Eh  []
    0xff,    // 9Fh  []
    0xff,    // A0h  []
    0xff,    // A1h  []
    0xff,    // A2h  []
    0xff,    // A3h  []
    0xff,    // A4h  []
    0xff,    // A5h  []
    0xff,    // A6h  []
    0xff,    // A7h  []
    0xff,    // A8h  []
    0xff,    // A9h  []
    0xff,    // AAh  []
    0xff,    // ABh  []
    0xff,    // ACh  []
    0xff,    // ADh  []
    0xff,    // AEh  []
    0xff,    // AFh  []
    0xff,    // B0h  []
    0xff,    // B1h  []
    0xff,    // B2h  []
    0xff,    // B3h  []
    0xff,    // B4h  []
    0xff,    // B5h  []
    0xff,    // B6h  []
    0xff,    // B7h  []
    0xff,    // B8h  []
    0xff,    // B9h  []
    0xff,    // BAh  []
    0xff,    // BBh  []
    0xff,    // BCh  []
    0xff,    // BDh  []
    0xff,    // BEh  []
    0xff,    // BFh  []
    0xff,    // C0h  []
    0xff,    // C1h  []
    0xff,    // C2h  []
    0xff,    // C3h  []
    0xff,    // C4h  []
    0xff,    // C5h  []
    0xff,    // C6h  []
    0xff,    // C7h  []
    0xff,    // C8h  []
    0xff,    // C9h  []
    0xff,    // CAh  []
    0xff,    // CBh  []
    0xff,    // CCh  []
    0xff,    // CDh  []
    0xff,    // CEh  []
    0xff,    // CFh  []
    0xff,    // D0h  []
    0xff,    // D1h  []
    0xff,    // D2h  []
    0xff,    // D3h  []
    0xff,    // D4h  []
    0xff,    // D5h  []
    0xff,    // D6h  []
    0xff,    // D7h  []
    0xff,    // D8h  []
    0xff,    // D9h  []
    0xff,    // DAh  []
    0xff,    // DBh  []
    0xff,    // DCh  []
    0xff,    // DDh  []
    0xff,    // DEh  []
    0xff,    // DFh  []
    0x74,    // E0h  Left-Ctrl
    0x70,    // E1h  Left-Shift
    0x73,    // E2h  Left-Alt
    0x77,    // E3h  GUI
    0x74,    // E4h  Right-Ctrl
    0x70,    // E5h  Right-Shift
    0x73,    // E6h  Right-Alt
    0x78,    // E7h  Right-GUI
};

// HID Usage ID => PC88 スキャンコード 変換テーブル
const uint8_t keytable88[] PROGMEM = {
    0xff,    // 00h  []
    0xff,    // 01h  []
    0xff,    // 02h  []
    0xff,    // 03h  []
    0x1d,    // 04h  A
    0x2d,    // 05h  B
    0x2b,    // 06h  C
    0x1f,    // 07h  D
    0x12,    // 08h  E
    0x20,    // 09h  F
    0x21,    // 0Ah  G
    0x22,    // 0Bh  H
    0x17,    // 0Ch  I
    0x23,    // 0Dh  J
    0x24,    // 0Eh  K
    0x25,    // 0Fh  L
    0x2f,    // 10h  M
    0x2e,    // 11h  N
    0x18,    // 12h  O
    0x19,    // 13h  P
    0x10,    // 14h  Q
    0x13,    // 15h  R
    0x1e,    // 16h  S
    0x14,    // 17h  T
    0x16,    // 18h  U
    0x2c,    // 19h  V
    0x11,    // 1Ah  W
    0x2a,    // 1Bh  X
    0x15,    // 1Ch  Y
    0x29,    // 1Dh  Z
    0x01,    // 1Eh  ! 1
    0x02,    // 1Fh  " 2
    0x03,    // 20h  # 3
    0x04,    // 21h  $ 4
    0x05,    // 22h  % 5
    0x06,    // 23h  & 6
    0x07,    // 24h  ' 7
    0x08,    // 25h  ( 8
    0x09,    // 26h  ) 9
    0x0a,    // 27h  0
    0x1c,    // 28h  Enter
    0x00,    // 29h  Esc
    0x0e,    // 2Ah  Backspace
    0x0f,    // 2Bh  Tab
    0x34,    // 2Ch  空白
    0x0b,    // 2Dh  = -
    0x0c,    // 2Eh  ~ ^
    0x1a,    // 2Fh  ` @
    0x1b,    // 30h  { [
    0x28,    // 31h  []
    0x28,    // 32h  } ]
    0x26,    // 33h  + ;
    0x27,    // 34h  * :
    0xff,    // 35h  半角/全角
    0x30,    // 36h  < ,
    0x31,    // 37h  > .
    0x32,    // 38h  ? /
    0x71,    // 39h  Caps Lock
    0x62,    // 3Ah  F1
    0x63,    // 3Bh  F2
    0x64,    // 3Ch  F3
    0x65,    // 3Dh  F4
    0x66,    // 3Eh  F5
    0x67,    // 3Fh  F6
    0x68,    // 40h  F7
    0x69,    // 41h  F8
    0x6a,    // 42h  F9
    0x6b,    // 43h  F10
    0xff,    // 44h  F11
    0xff,    // 45h  F12
    0x61,    // 46h  Print Screen
    0xff,    // 47h  Scroll Lock
    0x60,    // 48h  Pause
    0x38,    // 49h  INSERT
    0x3f,    // 4Ah  HOME
    0x36,    // 4Bh  PAGE UP
    0x39,    // 4Ch  DEL
    0xff,    // 4Dh  End
    0x37,    // 4Eh  PAGE
    0x3c,    // 4Fh  RIGHT
    0x3b,    // 50h  LEFT
    0x3d,    // 51h  DOWN
    0x3a,    // 52h  UP
    0xff,    // 53h  NumLock
    0x41,    // 54h  Num /
    0xff,    // 55h  Num *
    0x40,    // 56h  Num -
    0x49,    // 57h  Num +
    0x1c,    // 58h  Num Enter
    0x4b,    // 59h  Num 1
    0x4c,    // 5Ah  Num 2
    0x4a,    // 5Bh  Num 3
    0x46,    // 5Ch  Num 4
    0x47,    // 5Dh  Num 5
    0x48,    // 5Eh  Num 6
    0x42,    // 5Fh  Num 7
    0x43,    // 60h  Num 8
    0x44,    // 61h  Num 9
    0x4e,    // 62h  Num 0
    0xff,    // 63h  Num .
    0xff,    // 64h  []
    0xff,    // 65h  App
    0xff,    // 66h  []
    0xff,    // 67h  []
    0xff,    // 68h  []
    0xff,    // 69h  []
    0xff,    // 6Ah  []
    0xff,    // 6Bh  []
    0xff,    // 6Ch  []
    0xff,    // 6Dh  []
    0xff,    // 6Eh  []
    0xff,    // 6Fh  []
    0xff,    // 70h  []
    0xff,    // 71h  []
    0xff,    // 72h  []
    0xff,    // 73h  []
    0xff,    // 74h  []
    0xff,    // 75h  []
    0xff,    // 76h  []
    0xff,    // 77h  []
    0xff,    // 78h  []
    0xff,    // 79h  []
    0xff,    // 7Ah  []
    0xff,    // 7Bh  []
    0xff,    // 7Ch  []
    0xff,    // 7Dh  []
    0xff,    // 7Eh  []
    0xff,    // 7Fh  []
    0xff,    // 80h  []
    0xff,    // 81h  []
    0xff,    // 82h  []
    0xff,    // 83h  []
    0xff,    // 84h  []
    0xff,    // 85h  []
    0xff,    // 86h  []
    0x33,    // 87h  _ 
    0x72,    // 88h  カタカナ ひらがな
    0x0d,    // 89h  | 
    0x35,    // 8Ah  変換
    0x51,    // 8Bh  無変換
    0xff,    // 8Ch  []
    0xff,    // 8Dh  []
    0xff,    // 8Eh  []
    0xff,    // 8Fh  []
    0xff,    // 90h  []
    0xff,    // 91h  []
    0xff,    // 92h  []
    0xff,    // 93h  []
    0xff,    // 94h  []
    0xff,    // 95h  []
    0xff,    // 96h  []
    0xff,    // 97h  []
    0xff,    // 98h  []
    0xff,    // 99h  []
    0xff,    // 9Ah  []
    0xff,    // 9Bh  []
    0xff,    // 9Ch  []
    0xff,    // 9Dh  []
    0xff,    // 9Eh  []
    0xff,    // 9Fh  []
    0xff,    // A0h  []
    0xff,    // A1h  []
    0xff,    // A2h  []
    0xff,    // A3h  []
    0xff,    // A4h  []
    0xff,    // A5h  []
    0xff,    // A6h  []
    0xff,    // A7h  []
    0xff,    // A8h  []
    0xff,    // A9h  []
    0xff,    // AAh  []
    0xff,    // ABh  []
    0xff,    // ACh  []
    0xff,    // ADh  []
    0xff,    // AEh  []
    0xff,    // AFh  []
    0xff,    // B0h  []
    0xff,    // B1h  []
    0xff,    // B2h  []
    0xff,    // B3h  []
    0xff,    // B4h  []
    0xff,    // B5h  []
    0xff,    // B6h  []
    0xff,    // B7h  []
    0xff,    // B8h  []
    0xff,    // B9h  []
    0xff,    // BAh  []
    0xff,    // BBh  []
    0xff,    // BCh  []
    0xff,    // BDh  []
    0xff,    // BEh  []
    0xff,    // BFh  []
    0xff,    // C0h  []
    0xff,    // C1h  []
    0xff,    // C2h  []
    0xff,    // C3h  []
    0xff,    // C4h  []
    0xff,    // C5h  []
    0xff,    // C6h  []
    0xff,    // C7h  []
    0xff,    // C8h  []
    0xff,    // C9h  []
    0xff,    // CAh  []
    0xff,    // CBh  []
    0xff,    // CCh  []
    0xff,    // CDh  []
    0xff,    // CEh  []
    0xff,    // CFh  []
    0xff,    // D0h  []
    0xff,    // D1h  []
    0xff,    // D2h  []
    0xff,    // D3h  []
    0xff,    // D4h  []
    0xff,    // D5h  []
    0xff,    // D6h  []
    0xff,    // D7h  []
    0xff,    // D8h  []
    0xff,    // D9h  []
    0xff,    // DAh  []
    0xff,    // DBh  []
    0xff,    // DCh  []
    0xff,    // DDh  []
    0xff,    // DEh  []
    0xff,    // DFh  []
    0x74,    // E0h  Left-Ctrl
    0x70,    // E1h  Left-Shift
    0x73,    // E2h  Left-Alt
    0x77,    // E3h  GUI
    0x74,    // E4h  Right-Ctrl
    0x70,    // E5h  Right-Shift
    0x73,    // E6h  Right-Alt
    0x78,    // E7h  Right-GUI
};
