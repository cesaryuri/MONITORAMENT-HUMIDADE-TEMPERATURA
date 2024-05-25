# 1 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino"
# 2 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino" 2
# 3 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino" 2

// Define os pinos para o LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Configuração do sensor DHT


DHT dht(13, 11 /**< DHT TYPE 11 */);

float t = 0; //Temperatura
float h = 0; //Umidade

void setup() {
  Serial.begin(9600);
  Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 17 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 17 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino"
                "DHTxx test!"
# 17 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino" 3
                ); &__c[0];}))
# 17 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino"
                )));

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
    Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 35 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino" 3
                  (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 35 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino"
                  "Failed to read from DHT sensor!"
# 35 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino" 3
                  ); &__c[0];}))
# 35 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino"
                  )));
    return;
  }

  Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 39 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino" 3
              (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 39 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino"
              "Humidity: "
# 39 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino" 3
              ); &__c[0];}))
# 39 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino"
              )));
  Serial.print(h, 1);
  Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 41 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino" 3
              (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 41 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino"
              "%  Temperature: "
# 41 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino" 3
              ); &__c[0];}))
# 41 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino"
              )));
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
