# 1 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino"
# 2 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino" 2
# 3 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino" 2

// Define os pinos para o LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Configuração do sensor DHT


DHT dht(13, 11 /**< DHT TYPE 11 */);

float t = 0; // Temperatura
float h = 0; // Umidade

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
    Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 34 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino" 3
                  (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 34 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino"
                  "Failed to read from DHT sensor!"
# 34 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino" 3
                  ); &__c[0];}))
# 34 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino"
                  )));
    return;
  }

  Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 38 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino" 3
              (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 38 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino"
              "Humidity: "
# 38 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino" 3
              ); &__c[0];}))
# 38 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino"
              )));
  Serial.print(h);
  Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 40 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino" 3
              (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 40 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino"
              "%  Temperature: "
# 40 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino" 3
              ); &__c[0];}))
# 40 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino"
              )));
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
