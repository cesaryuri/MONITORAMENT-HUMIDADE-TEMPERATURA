#include <LiquidCrystal.h>
#include "DHT.h"

// Define os pinos para o LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Configuração do sensor DHT
#define DHTPIN 13    
#define DHTTYPE DHT11   
DHT dht(DHTPIN, DHTTYPE);

float t = 0; // Temperatura
float h = 0; // Umidade

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
  
  lcd.begin(16, 2); // Inicializa o display LCD
  dht.begin(); // Inicializa o sensor DHT
}

void loop() {
  delay(2000);
  runDHT();
  displayData();
}

void runDHT(){
  h = dht.readHumidity(); 
  t = dht.readTemperature(); 

  if (isnan(h) || isnan(t)) { 
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.println(t);
}

void displayData() {
  lcd.clear(); 
  lcd.setCursor(0, 0); 
  lcd.print("TEMP: ");
  lcd.print(t);
  lcd.print(" C");

  lcd.setCursor(0, 1);
  lcd.print("HUMI: ");
  lcd.print(h);
  lcd.print(" %");
}