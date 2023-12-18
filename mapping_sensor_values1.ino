#include <Servo.h>

#define led1 3
#define led2 5
#define led3 6
#define led4 9
#define LDR A0
#define pot A1

float brightness;
float LDR_read;
float pot_read;
float rotation;
Servo servo;

void setup()
{
  Serial.begin(9600);  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(LDR, INPUT);
  pinMode(pot, INPUT);
  servo.attach(A2);
  servo.write(0);
}

void loop()
{
  LDR_read = analogRead(LDR);
  pot_read = analogRead(pot);
  rotation = (180.0/1023.0) * pot_read;
  servo.write(rotation);
  if (LDR_read == 923){
    analogWrite(led1, 0);
    analogWrite(led2, 0);
    analogWrite(led3, 0);
    analogWrite(led4, 0);
  }
  else if (LDR_read == 26){
    analogWrite(led1, 255);
    analogWrite(led2, 255);
    analogWrite(led3, 255);
    analogWrite(led4, 255);
  }
  else if(LDR_read > 700){
    analogWrite(led2, 0);
    analogWrite(led3, 0);
    analogWrite(led4, 0);
    brightness = ((-255.0/158.0)*LDR_read + (255.923/158));
    analogWrite(led1, brightness);
  }
  else if (LDR_read > 475){
    analogWrite(led1, 255);
    analogWrite(led3, 0);
    analogWrite(led4, 0);
    brightness = ((-255.0/224.0)*LDR_read + (699.255/224));
    analogWrite(led2, brightness);
  }
  else if (LDR_read > 251){
    analogWrite(led1, 255);
    analogWrite(led2, 255);
    analogWrite(led4, 0);
    brightness = ((-255.0/224.0)*LDR_read + (255.475/224));
    analogWrite(led3, brightness);
  }
  else{
    analogWrite(led1, 255);
    analogWrite(led2, 255);
    analogWrite(led3, 255);
    brightness = ((-254.0/228.0)*LDR_read + 255);
    analogWrite(led4, brightness);
  }
}