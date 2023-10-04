#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
//constantes
const int pinPSL=12;
const int pinPSH=13;
const int pinVS_01=14;
const int pinVS_02=15;
const int pinBUZZER=16;
const int T_5=24;
const int T_6=10;

LiquidCrystal_I2C lcd(0x27, 20, 4);//crear un objeto lcd (DIRECCIÓN pantalla, Tamaño x, Tamño y)

void setup() {
  pinMode(pinPSH, INPUT_PULLUP);
  pinMode(pinPSL, INPUT_PULLUP);
  pinMode(pinVS_01, OUTPUT);
  pinMode(pinVS_02, OUTPUT);
  pinMode(pinBUZZER, OUTPUT);
  lcd.init();
  lcd.begin(20, 4);//inicializar la pantalla lcd
  lcd.backlight();//Encender la luz de fondo
  lcd.clear();  
}

void loop() {
  if ((digitalRead(pinPSH))==1){
    for (int i = T_5; i > 0; i--)
    {
      lcd.clear();
      lcd.setCursor(1,2);
      lcd.print("STAND BY ");
      lcd.print(i);
      if ((digitalRead(pinPSH))==0)
      {
        break;
      }
      delay(1000); 
    }
    digitalWrite(pinVS_02, HIGH);
    for (int i = T_6; i > 0; i--)
    {
      lcd.clear();
      lcd.setCursor(1,2);
      lcd.print("FLUSHING ");
      lcd.print(i);
      if ((digitalRead(pinPSH))==0)
      {
        break;
      }
      delay(1000); 
    }
    
  } else {
    if (digitalRead(pinPSL)==1)
    {
      digitalWrite(pinVS_02, LOW);
      digitalWrite(pinVS_01, LOW);
      for (int i = 0; i < 7; i++)
      {
        lcd.clear();
        lcd.setCursor(7,0);
        lcd.print("AVISO");
        lcd.setCursor(0,1);
        lcd.print("BAJA PRESION");
        lcd.setCursor(0,2);
        lcd.print("DE ALIMENTACION");
        delay(5000);
        digitalWrite(pinBUZZER,HIGH);
        delay(3000);
        digitalWrite(pinBUZZER,LOW);
        if ((digitalRead(pinPSL))==0)
        {
          break;
        }
        
      }
      lcd.clear();
      lcd.setCursor(7,0);
      lcd.print("ALARMA");
      lcd.setCursor(0,1);
      lcd.print("BAJA PRESION");
      lcd.setCursor(0,2);
      lcd.print("DE ALIMENTACION");
      delay(10000);
    }
    else {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("INICIANDO");
      digitalWrite(pinVS_02, HIGH);
      digitalWrite(pinVS_01, HIGH);
      delay(5000);
      digitalWrite(pinVS_02, LOW);
      digitalWrite(pinVS_01, LOW);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("PRODUCIENDO");
      delay(10000);
    }
  }
}