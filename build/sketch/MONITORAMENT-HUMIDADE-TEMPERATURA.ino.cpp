#include <Arduino.h>
#line 1 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino"


//Carrega a biblioteca LiquidCrystal
#include <LiquidCrystal.h>
 
//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#include "DHT.h"
#define DHTPIN 1    
#define DHTTYPE DHT11   
float t = 0;
float h = 0;

DHT dht(DHTPIN, DHTTYPE);

#line 16 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino"
void setup();
#line 25 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino"
void loop();
#line 38 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino"
void rundth();
#line 61 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino"
void tela();
#line 16 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino"
void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
  //Define o número de colunas e linhas do LCD
  lcd.begin(16, 2);
  dht.begin();
}


void loop() {
    // Wait a few seconds between measurements.
    delay(2000);
    
    tela();
    //rundth();

}




//rodar DTH e printar
void rundth(){
    
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  t = dht.readTemperature();
  
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
}


void tela()
{
  //Limpa a tela
  lcd.clear();
  //Posiciona o cursor na coluna 3, linha 0;
  lcd.setCursor(3, 0);
  //Envia o texto entre aspas para o LCD
  lcd.print("COMPILANDO......");
  lcd.setCursor(3, 1);
  lcd.print("RODOUUUU");
  delay(5000);
    
  //Rolagem para a esquerda
  for (int posicao = 0; posicao < 3; posicao++)
  {
    lcd.scrollDisplayLeft();
    delay(300);
  }
    
  //Rolagem para a direita
  for (int posicao = 0; posicao < 6; posicao++)
  {
    lcd.scrollDisplayRight();
    delay(300);
  }
}

