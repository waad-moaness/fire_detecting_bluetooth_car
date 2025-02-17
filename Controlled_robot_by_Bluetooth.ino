
#include<Servo.h>
#define speedL 3
#define IN1 9
#define IN2 8
#define IN3 7
#define IN4 6
#define speedR 5
#define buzzer 4
Servo servo;
int angle, flame_detector=0;
int flame =2;
char Reading;


void setup()
{
Serial.begin (9600);
for(int i=3 ; i<=9 ; i++)
{
pinMode(i, OUTPUT);
}
servo.attach(11);
pinMode(flame,INPUT);
}


void forword()
{
digitalWrite(IN1, HIGH);
digitalWrite(IN2, LOW);
digitalWrite(IN3, HIGH);
digitalWrite(IN4, LOW);
analogWrite(speedL,110);
analogWrite(speedR,150);
}
void backword()
{
digitalWrite(IN1, LOW);
digitalWrite(IN2, HIGH);
digitalWrite(IN3, LOW);
digitalWrite(IN4, HIGH);
analogWrite(speedL,110);
analogWrite(speedR,150);
}void left()
{
digitalWrite(IN1, LOW);
digitalWrite(IN2, LOW);
digitalWrite(IN3, HIGH);
digitalWrite(IN4, LOW);
analogWrite(speedL,0);
analogWrite(speedR,150);
}
void right()
{
digitalWrite(IN1, HIGH);
digitalWrite(IN2, LOW);
digitalWrite(IN3, LOW);
digitalWrite(IN4, LOW);
analogWrite(speedL,150);
analogWrite(speedR,0);
}void stopp() {
digitalWrite(IN1, LOW);
digitalWrite(IN2, LOW);
digitalWrite(IN3, LOW);
digitalWrite(IN4, LOW);
analogWrite(speedL,0);
analogWrite(speedR,0); }
void loop() {
if(Serial.available()>0){
Reading=Serial.read();
switch(Reading){
case 'F': forword(); break;
case 'B': backword(); break;
case 'R': right(); break;
case 'L' : left(); break;
case 'S' :stopp(); break;
case 'Q':
{
  for(angle=90;angle<=180 ;angle+=1)
  {
    if(digitalRead(flame)==1)
    flame_detector++;
    servo.write(angle);
    delay(15);
    
  }
  for(angle=180;angle>=0;angle--)
  {
    if(digitalRead(flame)==1 )
    flame_detector++;
    servo.write(angle);
    delay(15);
    
    
  }
  servo.write(90);
  if(flame_detector >0)
  {
    for(int i=0;i<=10 ;i++)
    {
      digitalWrite(buzzer,1);
      delay(100);
      digitalWrite(buzzer,0);
      delay(100);  
    }
    flame_detector=0;
  }
  }
}
}
}
