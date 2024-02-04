
#include<Servo.h>
Servo myservo;
const int trigPin=3;
const int echoPin=5; 
long tmeduration;
int distance;
 int pos;
 int count;
void setup() {
myservo.attach(9);
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);
Serial.begin(9600);
 count=0;
 
 
}
 
void loop() {
digitalWrite(trigPin,LOW);
delayMicroseconds(2);
digitalWrite(trigPin,HIGH);
delayMicroseconds(10);
digitalWrite(trigPin,LOW);
 
tmeduration=pulseIn(echoPin,HIGH);
distance=(0.034*tmeduration)/2;
 
if(distance<=10){
  if (count<5)
{ count++;
for (pos = 0; pos <= 120; pos += 1) { 
    myservo.write(pos);             
   delay(15);                       
  }
  delay(1000);

  for (pos = 120; pos >= 0; pos -= 1) { 
    myservo.write(pos);
    delay(15); } }  
    else {
         tone(2,1000);
delay(500);
noTone(2);                               
    }
 



  }
myservo.write(0);

 if (count<5)
Serial.println(count);
else Serial.println("NO");

 
delay(500);
 
}
