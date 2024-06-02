
#include <PZEM004Tv30.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "Nice";
const char* password = "11111111";

// Alamat I2C LCD, dapat berbeda tergantung pada perangkat Anda
#define LCD_ADDRESS 0x27

// Jumlah kolom dan baris pada LCD
#define LCD_COLUMNS 16
#define LCD_ROWS 2

// Inisialisasi LCD
LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLUMNS, LCD_ROWS);

/* Hardware Serial2 is only available on certain boards.
 * For example the Arduino MEGA 2560
*/
#if defined(ESP32)
PZEM004Tv30 pzem(Serial2, 16, 17);
#else
PZEM004Tv30 pzem(Serial2);
#endif

String watt,ampere,kwh;

void setup() {
    Serial.begin(115200);

    lcd.init();               // Inisialisasi LCD
    lcd.backlight();          // Aktifkan backlight LCD

    // Uncomment in order to reset the internal energy counter
    // pzem.resetEnergy();

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
      Serial.println(".");
      delay(1000);
    }
    Serial.println("WiFi connected");
}

void loop() {
        
    Serial.print("Custom Address:");
    Serial.println(pzem.readAddress(), HEX);

    // Read the data from the sensor
    float voltage = pzem.voltage();
    float current = pzem.current();
    float power = pzem.power();
    float energy = pzem.energy();
    float frequency = pzem.frequency();
    float pf = pzem.pf();

    // Check if the data is valid
    if(isnan(voltage)){
        Serial.println("Error reading voltage");
    } else if (isnan(current)) {
        Serial.println("Error reading current");
    } else if (isnan(power)) {
        Serial.println("Error reading power");
    } else if (isnan(energy)) {
        Serial.println("Error reading energy");
    } else if (isnan(frequency)) {
        Serial.println("Error reading frequency");
    } else if (isnan(pf)) {
        Serial.println("Error reading power factor");
    } else {

        // Print the values to the Serial console
        Serial.print("Voltage: ");      Serial.print(voltage);      Serial.println("V");
        Serial.print("Current: ");      Serial.print(current);      Serial.println("A");
        Serial.print("Power: ");        Serial.print(power);        Serial.println("W");
        Serial.print("Energy: ");       Serial.print(energy,3);     Serial.println("kWh");
        Serial.print("Frequency: ");    Serial.print(frequency, 1); Serial.println("Hz");
        Serial.print("PF: ");           Serial.println(pf);
        Serial.print("RP: ");           Serial.println((energy)*1500);

        lcd.setCursor(0, 0); // Posisi kursor di kolom 0, baris 0
        lcd.print(power);
        watt = power;
        lcd.print(" W ");
        lcd.print(current);
        ampere = current;
        lcd.print(" A");
        lcd.setCursor(0, 1); // Posisi kursor di kolom 0, baris 1
        lcd.print(energy,2);
        kwh = energy,2;
        lcd.print(" kWh");
        lcd.print(" RP ");
        lcd.print(energy*1500);
    }

    Serial.println();
    delay(2000);

    SendData();

    
}

void SendData(){
  HTTPClient http;

    // Alamat API yang dituju
    String serverAddress = "https://script.google.com/macros/s/AKfycbzo0LmvTZOk4arbrEMq9EjCUWzKczD-eI5w40RRKebjSyUe_CBI9oiNMjQG7wIDulNkIA/exec?watt="+watt+"&ampere="+ampere+"&kwh="+kwh;

    http.begin(serverAddress);  // Mulai koneksi ke server

    // Lakukan GET request
    int httpResponseCode = http.GET();

    if (httpResponseCode > 0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
      String response = http.getString(); // Dapatkan respons dari server

    } else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
      delay(2500);
    }

    http.end();
}