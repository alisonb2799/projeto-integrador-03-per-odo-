#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

Adafruit_BMP280 bmp;

void setup() {
  Serial.begin(9600);
  
  Serial.println("Iniciando BMP280...");
  
  if (!bmp.begin(0x76)) {
    if (!bmp.begin(0x77)) {
      Serial.println("ERRO: BMP280 não encontrado!");
      Serial.println("Verifique as conexões:");
      while (1);
    }
  }
  
  Serial.println("BMP280 iniciado com sucesso!");
  delay(2000); 
}

void loop() {
  float temperatura = bmp.readTemperature();
  
  if (isnan(temperatura)) {
    Serial.println("ERRO|Leitura de temperatura inválida");
  } else {
    Serial.print("TEMPERATURA|");
    Serial.println(temperatura, 2);
  }
  
  delay(10000);
}