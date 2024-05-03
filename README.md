# USBKBD2PC98

USBKBD2PC98 とは USBキーボードをPC98で使えるようにしたものです。

## 注意
全てのUSB機器に対して稼働確認が取れているわけではありません。
相性等動かないものもありますのでご了承ください。
また、ゲーミングキーボード等電力を多く使用するものも使用できません
※確認はPC9821AP2のみです

## 完成品
![](image/usbkbs2PC981.jpg)
![](image/usbkbs2PC982.jpg)

## ガーバーデータ
![](image/usbkbs2PC983.jpg)
![](image/usbkbs2PC984.jpg)

## 配線図
![](image/USBKBD2PC98.png)

## キーアサイン
日本語109キーボードアサイン例 `赤字部分がPC98のキーアサイン`
![](image/USBKBS2PC98.png)

## Setup
* PlatformIO を使用しています。
 ライブラリとしてUSB_Host_Shield_2.0 を使用しています。
  (https://github.com/felis/USB_Host_Shield_2.0) 
 ライブラリとしてMsTimer2 を使用しています。
  (http://playground.arduino.cc/Main/MsTimer2)

arduino pro mini(3.3v)
https://www.amazon.co.jp/gp/product/B073PYLJDC/ref=ppx_yo_dt_b_asin_title_o00_s00?ie=UTF8&psc=1
ミニusbホストシールド2.0
https://www.amazon.co.jp/gp/product/B074HTPK13/ref=ppx_yo_dt_b_asin_title_o00_s00?ie=UTF8&psc=1
レベル変換
https://www.amazon.co.jp/gp/product/B014F8ZEVM/ref=ppx_yo_dt_b_asin_title_o01_s00?ie=UTF8&psc=1

1.ミニusbホストシールド2.0の5V改造
ミニusbホストシールド2.0はUSB電源が3.3Vになっているので
5Vになるようにします。また、RAWに5V供給すればarduino pro mini(3.3v)は
レギュレーターで3.3Vで駆動します
方法は以下
VBUS パターンカット（赤丸部分）
![](image/cut.png)

2.ミニusbホストシールド2.0とarduino pro mini 3.3vの結合
って言っても重ねて半田します

3.arduino pro mini 3.3vとレベル変換＆minidin7Pの接続
arduino pro mini 3.3vなので
PC98 5Vと接続するためにレベル変換との結合


