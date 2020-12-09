/* PHOTO_SENSOR (1) */
#define PIN_LED 13
#define PIN_PHOTO_SENSOR A0
/* GAS (2) */
#define MQ2pin (0)
float sensorValue;
/* Humidity && Temperature (3) */
#include "DHT.h"
#define DHTPIN 2
DHT dht(DHTPIN, DHT22);


void setup() 
{
  Serial.begin(9600);
  /* (1) */
  pinMode(PIN_LED, OUTPUT);
  /* (3) */
  dht.begin();

}

void loop() 
{
  if(Serial.available() > 0)
  {
    char Qt = Serial.read();
    Serial.println();
    if(Qt == 'b')
    {
      Serial.println("=======Beggin========");
          
        delay(500);
      /* (1) */
      int val = analogRead(PIN_PHOTO_SENSOR);
      Serial.print("Свет: ");
      Serial.println(val);

      if(val > 120)
      {
        Serial.println("                                 [_YOU___ARE___MAKE___A___PROBLEM_] ");
        return;
      }
      else{}

      /* (2) */
        delay(500);
      sensorValue = analogRead(MQ2pin);
      Serial.print("Газ: ");
      Serial.print("Sensor Value: ");
      Serial.print(sensorValue);
  
      if(sensorValue > 320)
      {
        Serial.print(" | Smoke detected!");
      }
      Serial.println();

      /* (3) */
        delay(500);
      // Задержка 2 секунды между измерениями
      //delay(2000);
 
      float h = dht.readHumidity();       //Считываем влажность
      float t = dht.readTemperature();    // Считываем температуру

      Serial.print("Влажность и температура: ");
      // Проверка удачно прошло ли считывание.
      if (isnan(h) || isnan(t)) {
        Serial.println("Не удается считать показания");
        Serial.println("===End===");
        return;
      }
      else
      {
        Serial.print ("Humidity: ");
        Serial.print (h);
        Serial.print ("%\t");
        Serial.print ("Temperature: ");
        Serial.print (t);
        Serial.println (" *C");
      }
      Serial.println("===End===");
      Serial.println();
    }
  }
}
