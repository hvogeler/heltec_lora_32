#include <Arduino.h>
#include <Wire.h>
#include <U8g2lib.h>

#define OLED_RESET 21
#define OLED_DATA 17
#define OLED_CLOCK 18
#define BAND 868E6

#define FONT_14 u8g2_font_profont22_tf
#define FONT_11 u8g2_font_t0_17_tf 
#define FONT_21 u8g2_font_logisoso22_tf
#define FONT_28 u8g2_font_logisoso28_tf
#define FONT_38 u8g2_font_logisoso38_tf
#define FONT_50 u8g2_font_logisoso50_tf

// 12px: u8g2_font_12x6LED_tf

// put function declarations here:
int myFunction(int, int);
volatile auto count = 1000;
char print_buf[100];

// bU8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, 15, 4, 16);
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, OLED_RESET, OLED_CLOCK, OLED_DATA);
void setup()
{
  // put your setup code here, to run once:
  int result = myFunction(2, 3);
  Serial.begin(115200);
  // Heltec.begin (true /* DisplayEnable Enable */, true /*Heltec.LoRa Disable */, true /* Serial Enable */, true /* PABOOST Enable */, BAND /* long BAND */);

  u8g2.begin();
  delay(100);
}

void loop()
{
  // put your main code here, to run repeatedly:
  sprintf(print_buf, "%d", count--);
  Serial.println(print_buf);
  u8g2.clearBuffer();
  u8g2.setFont(FONT_50);
  u8g2.drawStr(2, 57, print_buf);
  // u8g2.drawStr(2, 60, print_buf);
  // u8g2.drawStr(2, 42, print_buf);
  // u8g2.drawStr(2, 56, print_buf);
  // u8g2.drawBox(10, 10, 50, 30);
  // u8g2.drawLine(10, 10, 30, 30);
  u8g2.sendBuffer();
  delay(1000);
}

// put function definitions here:
int myFunction(int x, int y)
{
  return x + y;
}