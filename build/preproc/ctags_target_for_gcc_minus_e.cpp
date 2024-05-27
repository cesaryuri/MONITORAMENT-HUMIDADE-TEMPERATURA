# 1 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino"
# 2 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino" 2
  const int bluetoothTx = 8; // bluetooth tx to 3 pin
  const int bluetoothRx = 9;
  String sensorData;
  SoftwareSerial bleSerial(bluetoothTx, bluetoothRx);
# 7 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino" 2
# 8 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino" 2

  // Define os pinos para o LCD
  LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

  // Configuração do sensor DHT


  DHT dht(13, 11 /**< DHT TYPE 11 */);

  float t = 0; //Temperatura
  float h = 0; //Umidade

  void setup() {
    Serial.begin(9600);
    //mySerial.begin(9600); 

    //Serial.println(F("DHTxx test!"));
    bleSerial.begin(9600);
    lcd.begin(16, 2);
    dht.begin();
  }

  void loop() {

    delay(2000);
    ReadDHT();
    enviarBle();
    displayData();
  }


  void ReadDHT(){
    h = dht.readHumidity();
    t = dht.readTemperature();

    if (isnan(h) || isnan(t)) {
      Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 44 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino" 3
                    (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 44 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino"
                    "Failed to read from DHT sensor!"
# 44 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino" 3
                    ); &__c[0];}))
# 44 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino"
                    )));
      return;
    }

    Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 48 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 48 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino"
                "Humidity: "
# 48 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino" 3
                ); &__c[0];}))
# 48 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino"
                )));
    Serial.print(h,1);
    Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 50 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 50 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino"
                "%  Temperature: "
# 50 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino" 3
                ); &__c[0];}))
# 50 "/home/cesar/Documentos/GitHub/MONITORAMENT-HUMIDADE-TEMPERATURA/MONITORAMENT-HUMIDADE-TEMPERATURA.ino"
                )));
    Serial.println(t,1);


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


void enviarBle(){
    sensorData = String(t) + "," + String(h); // Concatenate temperature and humidity values
    Serial.print("Data to send: ");
    Serial.println(sensorData);
    bleSerial.println(sensorData);
}
