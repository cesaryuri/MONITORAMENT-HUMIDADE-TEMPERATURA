#include <Arduino.h>
#line 1 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino"
#include <LiquidCrystal.h>
#include "DHT.h"

// Define os pinos para o LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Configuração do sensor DHT
#define DHTPIN 13    
#define DHTTYPE DHT11   
DHT dht(DHTPIN, DHTTYPE);

float t = 0; //Temperatura
float h = 0; //Umidade

#line 15 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino"
void setup();
#line 23 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino"
void loop();
#line 30 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino"
void ReadDHT();
#line 46 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino"
void displayData();
#line 15 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino"
void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
  
  lcd.begin(16, 2);
  dht.begin(); 
}

void loop() {
  delay(2000);
  ReadDHT();
  displayData();
}


void ReadDHT(){
  h = dht.readHumidity(); 
  t = dht.readTemperature(); 

  if (isnan(h) || isnan(t)) { 
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  
  Serial.print(F("Humidity: "));
  Serial.print(h, 1);
  Serial.print(F("%  Temperature: "));
  Serial.println(t, 1);
}


void displayData() {
  lcd.clear(); 
  lcd.setCursor(0, 0); 
  lcd.print("TEMP: ");
  lcd.print(t,1);
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("HUMI: ");
  lcd.print(h,1);
  lcd.print("%");
}
