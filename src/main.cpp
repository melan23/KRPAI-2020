#include <header.h>

/*
  setiap ganti fungsi jalan, lakukan init_bot()
*/

int i; // increment
float jarak_depan, jarak_kanan, jarak_kiri;

void setup()
{
  ax12a.begin(BaudRate, DirectionPin, &Serial);
  Serial.begin(1000000);
}

void loop()
{
  maju();
}