int messwert=0; 
int PUMPE=6;// Pumpe wird an Pin 6 festgelegt 
int sensor=A0;//Sensor wird an Pin A0 festgelegt 
float moisture_percentage;// Feuchtigkeitswert wird als Kommazahl ausgegeben 
 
#define PUMPE 12 
#include <LiquidCrystal_I2C.h>// library für die Matrix 
#include <Wire.h> // Wire library hochladen 
LiquidCrystal_I2C lcd(0x27, 20, 4); 
 
void setup() 
{ 
  lcd.init(); //ImSetup wird der Lcd gestartet 
  lcd.backlight();// Hintergrundbeleuchtung anschalten (0 schaltet die Beleuchtung aus) 
 
  pinMode(PUMPE, OUTPUT); 
  digitalWrite(PUMPE, HIGH); // serielle Kommunikation mit der Geschwindigkeit 
 
Serial.begin(9600); 
 
  pinMode(6,OUTPUT); // im setup wird pin 6 als ausgang festgelegt 
 
  lcd.init(); 
  lcd.clear();         
  lcd.backlight(); 
} 
 
void loop() { 
 
  int sensor_analog; 
 
  sensor_analog = analogRead(sensor); 
  Serial.println(sensor_analog); 
  moisture_percentage = map(sensor_analog, -2, 550, 0, 100); 
  delay(1000); 
 
  lcd.clear();         
  lcd.backlight(); 
  set_display(); 
} 
 
void set_display() { 
 
  lcd.clear();         
  lcd.backlight(); 
  
  if (moisture_percentage > 70){ 
      lcd.setCursor(2,0); 
      lcd.print(":) Nice!"); 
      digitalWrite(PUMPE, LOW); 
      delay(500); 
 
      lcd.setCursor(2,1); 
      lcd.print(moisture_percentage); 
  } else if (moisture_percentage < 70 && moisture_percentage > 40){ 
      lcd.setCursor(2,0); 
      lcd.print(":O    oh."); 
      digitalWrite(PUMPE, LOW); 
      lcd.setCursor(2,1); 
      lcd.print(moisture_percentage); 
  } else { 
      lcd.setCursor(2,0); 
      lcd.print(":( I am sad."); 
 
      digitalWrite(PUMPE, HIGH); 
      delay(500); 
 
      lcd.setCursor(2,1); 
      lcd.print(moisture_percentage); 
  } 
} 
