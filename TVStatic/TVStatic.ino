#include <M5Stack.h>
#include <LovyanGFX.hpp>

static LGFX lcd;

uint8_t snowRand;
int pixelGroupCount = 0;


// Fast 0-255 random number generator from http://eternityforest.com/Projects/rng.php:
uint8_t za, zb, zc, zx;
uint8_t __attribute__((always_inline)) inline rng()
{
  zx++;
  za = (za ^ zc ^ zx);
  zb = (zb + za);
  zc = (zc + (zb >> 1)^za);
  return zc;
}



void setup() {
  M5.begin();
  M5.Power.begin();
  M5.Lcd.fillScreen(TFT_BLACK);
  zx = micros() & 255;

  lcd.init();
  pixelGroupCount = (lcd.width() * lcd.height()) / 8;

}


void loop()
{
  unsigned long t0 = micros();

  lcd.startWrite();
  lcd.setAddrWindow(0, 0, lcd.width(), lcd.height());

  for (int i = 0; i < pixelGroupCount; i++) {
    snowRand = rng();

    if ((snowRand & 1) == 0) lcd.writeColor(0, 1); else lcd.writeColor(65535, 1);
    if ((snowRand & 2) == 0) lcd.writeColor(0, 1); else lcd.writeColor(65535, 1);
    if ((snowRand & 4) == 0) lcd.writeColor(0, 1); else lcd.writeColor(65535, 1);
    if ((snowRand & 8) == 0) lcd.writeColor(0, 1); else lcd.writeColor(65535, 1);
    if ((snowRand & 16) == 0) lcd.writeColor(0, 1); else lcd.writeColor(65535, 1);
    if ((snowRand & 32) == 0) lcd.writeColor(0, 1); else lcd.writeColor(65535, 1);
    if ((snowRand & 64) == 0) lcd.writeColor(0, 1); else lcd.writeColor(65535, 1);
    if ((snowRand & 128) == 0) lcd.writeColor(0, 1); else lcd.writeColor(65535, 1);
  }
  lcd.endWrite();

  //delay(50);
  unsigned long t1 = micros();
  Serial.println(1.0 / ((t1 - t0) / 1000000.0));
}
