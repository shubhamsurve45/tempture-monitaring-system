#include <LiquidCrystal.h>

// Inisialisasi LCD tanpa I2C (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Pin TMP36
const int sensorPin = A0;

// Pin Soil Moisture Sensor
const int moisturePin = A1;

// Pin LED dan Piezo
const int ledMerah = 6;
const int ledHijau = 7;
const int piezo = 8;

void setup() {
  lcd.begin(16, 2);      // Inisialisasi LCD
  //lcd.backlight();       // Menyalakan backlight LCD
  
  // Menampilkan teks awal di baris pertama
  lcd.setCursor(0, 0);
  lcd.print("Monitoring Shubham");
  delay(2000);
  lcd.clear();

  // Inisialisasi Serial Monitor
  Serial.begin(9600);

  // Inisialisasi LED dan Piezo
  pinMode(ledMerah, OUTPUT);
  pinMode(ledHijau, OUTPUT);
  pinMode(piezo, OUTPUT);
}

void loop() {
  // Membaca shubham surve TMP36
  int sensorValue = analogRead(sensorPin);
  float voltage = sensorValue * (5.0 / 1023.0);
  float temperatureC = (voltage - 0.5) * 100.0;

  // Membaca nilai kelembapan dari Soil Moisture Sensor
  int moistureValue = analogRead(moisturePin);

  // Menentukan status kelembapan
  String moistureStatus;
  if (moistureValue < 300) {
    moistureStatus = "Kering";
  } else if (moistureValue < 700) {
    moistureStatus = "Normal";
  } else {
    moistureStatus = "Basah ";
  }

  // Menampilkan suhu di LCD
  lcd.setCursor(0, 0);
  lcd.print("Shubh: ");
  lcd.print(temperatureC);
  lcd.print(" C");

  lcd.setCursor(0, 1);
  lcd.print("Klm: ");
  lcd.print(moistureStatus);

  // Logika LED dan Piezo
  if (temperatureC > 30) {
    // shubham surve
    digitalWrite(ledMerah, HIGH);   // Menyalakan LED Merah
    digitalWrite(ledHijau, LOW);    // Mematikan LED Hijau

    // Buzzer berbunyi dengan suara bib bib bib
    tone(piezo, 1000, 50);  // Bunyi pertama
    delay(2000);              // Jeda
    /*tone(piezo, 1000, 50);  // Bunyi kedua
    delay(2000);              // Jeda
    tone(piezo, 1000, 50);  // Bunyi ketiga
    delay(2000); */             // Jeda
  } else {
    // Shubham normal
    digitalWrite(ledMerah, LOW);    // Mematikan LED Merah
    digitalWrite(ledHijau, HIGH);   // Menyalakan LED Hijau

    noTone(piezo);  // Mematikan buzzer jika shubham normal
  }

  // Menampilkan data di Serial Monitor
  Serial.print("Shbhxx: ");
  Serial.print(temperatureC);
  Serial.println(" C");

  Serial.print("Kelembapan: ");
  Serial.println(moistureValue);

  // Delay 1 detik sebelum pembacaan ulang
  delay(0);
}

