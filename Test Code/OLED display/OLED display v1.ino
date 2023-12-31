#include <U8g2lib.h>
#include <Wire.h>

U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE, /* clock=*/ A5,/* data=*/ A4);

void setup() {
  u8g2.begin();
}

void loop() {
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB10_tr); // font choose
  u8g2.setCursor(0, 20); // cursor position
  u8g2.print("Hello, OLED!");

  u8g2.sendBuffer();
  delay(1000); // display for 1s
}
