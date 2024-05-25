# 1 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino"


//Carrega a biblioteca LiquidCrystal
# 5 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino" 2

//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
# 9 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino" 2


float t = 0;
float h = 0;

DHT dht(1, 11 /**< DHT TYPE 11 */);

void setup() {
  Serial.begin(9600);
  Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 18 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 18 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino"
                "DHTxx test!"
# 18 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino" 3
                ); &__c[0];}))
# 18 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino"
                )));
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
    Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 48 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino" 3
                  (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 48 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino"
                  "Failed to read from DHT sensor!"
# 48 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino" 3
                  ); &__c[0];}))
# 48 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino"
                  )));
    return;
  }
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 54 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino" 3
              (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 54 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino"
              "Humidity: "
# 54 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino" 3
              ); &__c[0];}))
# 54 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino"
              )));
  Serial.print(h);
  Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 56 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino" 3
              (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 56 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino"
              "%  Temperature: "
# 56 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino" 3
              ); &__c[0];}))
# 56 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino"
              )));
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
