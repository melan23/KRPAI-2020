#include <header.h>

float hitung_jarak(double trig, double echo)
{
  float durasi, jarakD;
  //-- trigger memancarkan sinyal ultrasonik
  digitalWrite(trig, LOW);
  delayMicroseconds(8);
  digitalWrite(trig, HIGH);
  delayMicroseconds(8);
  digitalWrite(trig, LOW);
  delayMicroseconds(8);
  //-- ngitung jarak
  durasi = pulseIn(echo, HIGH); //menerima suara ultrasonik
  jarakD = (durasi/2)/ 29.1; //mengubah durasi menjadi jarak (cm)
  return jarakD;
}