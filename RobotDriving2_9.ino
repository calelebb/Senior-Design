#if defined(USE_TINYUSB)
#include <Adafruit_TinyUSB.h> // for Serial
#endif



float duration, distance;

const int ain1 = 9;
const int ain2 = 10;
const int bin1 = 11;
const int bin2 = 12;
const int trigPin = 5;
const int echoPin = 6;

void setup() {
  pinMode(ain1, OUTPUT);
  pinMode(ain2, OUTPUT);
  pinMode(bin1, OUTPUT);
  pinMode(bin2, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  scan();
  if (distance <3){
    sleep();
    delay(200);
  }
  while(distance > 25){
    forward();
    delay(200);
    scan();
  }
  if (distance < 25){
    backward();
    delay(25);
    for( int i = 0; i <= 5; i++) {
      right();
      delay(20);
      scan();
      if ( distance > 25 ){
        break;
      }
      if (i == 5){
        left();
        delay(100);
      }
      // add a way to make the program break and turn left if there is still an object to the right after the for loop runs a few times. 
      
    }                
  }
}
void sleep(){
  analogWrite(ain1, 0);
  analogWrite(ain2, 0);
  analogWrite(bin1, 0);
  analogWrite(bin2, 0);
}

void forward(){
  analogWrite(ain1, 220);
  analogWrite(ain2, 0);
  analogWrite(bin1, 220);
  analogWrite(bin2, 0);
}

void backward(){
  analogWrite(ain2, 220);
  analogWrite(ain1, 0);
  analogWrite(bin2, 220);
  analogWrite(bin1, 0);
}

void right(){
  analogWrite(ain2, 220);
  analogWrite(ain1,0);
  analogWrite(bin1, 220);
  analogWrite(bin2,0);
}
void left(){
  analogWrite(ain1, 220);
  analogWrite(ain2,0);
  analogWrite(bin2, 220);
  analogWrite(bin1,0);
}

void scan() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);
}