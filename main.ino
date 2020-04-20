//led=gnd, button=gnd, buzzer=+ connect digitalPin & gnd, rtc=5v, bluetooth=3.3v
#include <DS3231.h>
#include <Wire.h>
#include<EEPROM.h>
DS3231  rtc(SDA, SCL); //SDA=A4, SCL=A5
const int buzzer = 2;
//Slot 1
const int buttonPin1 = 3;
const int ledPin1 =  7;
//Slot 2
const int buttonPin2 = 4;
const int ledPin2 =  8;
//Slot 3
const int buttonPin3 = 5;
const int ledPin3 =  9;
//Slot 4
const int buttonPin4 = 6;
const int ledPin4 =  10;

int buttonState1 = LOW;
int buttonState2 = LOW;
int buttonState3 = LOW;
int buttonState4 = LOW;
Time  t;
//Set the alarm time here 
int Hour1 = 8, Minute1 = 41; //slot 1
int Hour2 = 8, Minute2 = 53; //slot 2
int Hour3 = 22, Minute3 = 38; //slot 3
int Hour4 = 22, Minute4 = 40; //slot 4
boolean alarm = true;

void setup() {
  rtc.begin();
  Serial.begin(9600);
  //rtc.setTime(20,58, 0);
  pinMode(buzzer, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buttonPin4, INPUT_PULLUP);
}
void loop() {
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);
  Serial.print("Time:  ");
  Serial.println(rtc.getTimeStr());

  t = rtc.getTime();
//  Serial.print("Hour " + (String)Hour + " h");
//  Serial.println(" Minute " + (String)Minute + " m");

  if (Minute1 - t.min == 1) {
    alarm = true;
  }
  if (Minute2 - t.min == 1) {
    alarm = true;
  }
  if (Minute3 - t.min == 1) {
    alarm = true;
  }
  if (Minute4 - t.min == 1) {
    alarm = true;
  }
//  Serial.println("Alarm: " + (String)alarm);
//  Serial.println("Button " + (String)buttonState);

  if (Hour1 == t.hour && Minute1 == t.min) {
    if (alarm) {
      startAlarm1();
    } else {
      stopAlarm1();
    }
  }
   if (Hour2 == t.hour && Minute2 == t.min) {
    if (alarm) {
      startAlarm2();
    } else {
      stopAlarm2();
    }
  }
   if (Hour3 == t.hour && Minute3 == t.min) {
    if (alarm) {
      startAlarm3();
    } else {
      stopAlarm3();
    }
  }
   if (Hour4 == t.hour && Minute4 == t.min) {
    if (alarm) {
      startAlarm4();
    } else {
      stopAlarm4();
    }
  }
  if (buttonState1 == LOW) {
    alarm = false;
  }
   if (buttonState2 == LOW) {
    alarm = false;
  }
   if (buttonState3 == LOW) {
    alarm = false;
  }
   if (buttonState4 == LOW) {
    alarm = false;
  }
  delay(1000);
}

void startAlarm1() {
  Serial.println("Take Medicine from 1 No Slot");
  digitalWrite(ledPin1, HIGH);
  digitalWrite(buzzer, HIGH);
}
void startAlarm2() {
  Serial.println("Take Medicine from 2 no Slot");
  digitalWrite(ledPin2, HIGH);
  digitalWrite(buzzer, HIGH);
}
void startAlarm3() {
  Serial.println("Take Medicine from 3 no Slot");
  digitalWrite(ledPin3, HIGH);
  digitalWrite(buzzer, HIGH);
}
void startAlarm4() {
  Serial.println("Take Medicine from 4 no Slot");
  digitalWrite(ledPin4, HIGH);
  digitalWrite(buzzer, HIGH);
}

void stopAlarm1() {
  Serial.println("Your grandfather take the medicine from Slot 1");
  digitalWrite(buzzer, LOW);
  digitalWrite(ledPin1, LOW);
}
void stopAlarm2() {
  Serial.println("Your grandfather take the medicine from Slot 2");
  digitalWrite(buzzer, LOW);
  digitalWrite(ledPin2, LOW);
}
void stopAlarm3() {
  Serial.println("Your grandfather take the medicine from Slot 3");
  digitalWrite(buzzer, LOW);
  digitalWrite(ledPin3, LOW);
}
void stopAlarm4() {
  Serial.println("Your grandfather take the medicine from Slot 4");
  digitalWrite(buzzer, LOW);
  digitalWrite(ledPin4, LOW);
}
