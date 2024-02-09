#if defined(USE_TINYUSB)
#include <Adafruit_TinyUSB.h> // for Serial
#endif

const int trigPin = 9;
const int echoPin = 10;

float duration, distance;

const int ain1 = 5;
const int ain2 = 6;
const int bin1 = 9;
const int bin2 = 10;
const int sle = 11;


void setup() {
  pinMode(ain1, OUTPUT);
  pinMode(ain2, OUTPUT);
  pinMode(bin1, OUTPUT);
  pinMode(bin2, OUTPUT);
  pinMode(sle, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  scan();
  while(distance > 20){
    forward();
    delay(500)
    scan();
  }
  if (distance < 20){
    for( int i = 0, i <= 5, i++) ){
      right();
      delay(100);
      scan()
      if ( distance > 20 ){
        break
      }
      // add a way to make the program break and turn left if there is still an object to the right after the for loop runs a few times. 
      
  }        
  
  }         
}

void sleep(){
  digitalWrite(sle,HIGH);
  analogWrite(ain1, 0);
  analogWrite(ain2, 0);
  analogWrite(bin1, 0);
  analogWrite(bin2, 0);
}

void forward(){
  digitalWrite(sle,HIGH);
  analogWrite(ain1, 185);
  analogWrite(bin1, 185);
  delay(1000);
  sleep();
}

void backward(){
  digitalWrite(sle,HIGH);
  analogWrite(ain2, 185);
  analogWrite(bin2, 185);
  delay(1000);
  sleep();
}

void right(){
  digitalWrite(sle,HIGH);
  analogWrite(ain1, 185);
  analogWrite(bin2, 185);
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