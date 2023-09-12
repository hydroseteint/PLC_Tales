#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);//crear un objeto lcd (DIRECCIÓN pantalla, Tamaño x, Tamño y)

void setup() {
  lcd.init();
  lcd.begin(20, 4);//inicializar la pantalla lcd
  lcd.backlight();//Encender la luz de fondo

  lcd.setCursor (0, 0);//poner el cursor en las coordenadas (x,y)
  lcd.print(" Pantalla lcd 20x4  ");//muestra en la pantalla max 20 caracteres
  lcd.setCursor (0, 1);//poner el cursor en las coordenadas (x,y)
  lcd.print("       esp32-s      ");//muestra en la pantalla max 20 caracteres
  
}

void loop() {
  lcd.setCursor (0, 3);//poner el cursor en las coordenadas (x,y)
  lcd.print("Tiempo activo:");//muestra en la pantalla max 20 caracteres
  //La funcion millis() regresa los ms que lleva encendido
  //Lo dividimos entre 1000 para que nos muestre en segundos.
  lcd.print(millis()/1000);
  lcd.print("s");
  delay(1000);//Esperamos 1 segundo antes de repetir el loop
}