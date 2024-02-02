#if defined(USE_TINYUSB)
#include <Adafruit_TinyUSB.h> // for Serial
#endif

int ain1 = 5;
int ain2 = 6;
int bin1 = 9;
int bin2 = 10;
int sle = 11;


void setup() {
  pinMode(ain1, OUTPUT);
  pinMode(ain2, OUTPUT);
  pinMode(bin1, OUTPUT);
  pinMode(bin2, OUTPUT);
  pinMode(sle, OUTPUT);
}

void loop() {
  digitalWrite(sle,HIGH);
  forward();
  delay(500);
  backward();
  delay(500);                     
}

void sleep(){
  analogWrite(ain1, 0);
  analogWrite(ain2, 0);
  analogWrite(bin1, 0);
  analogWrite(bin2, 0);
}

void forward(){
  analogWrite(ain1, 185);
  analogWrite(bin1, 185);
  delay(1000);
  sleep();
}

void backward(){
  analogWrite(ain2, 185);
  analogWrite(bin2, 185);
  delay(1000);
  sleep();
}