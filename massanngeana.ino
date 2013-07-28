#include <DHT22.h>
// Only used for sprintf
#include <stdio.h>

// Data wire is plugged into port 7 on the Arduino
// Connect a 4.7K resistor between VCC and the data pin (strong pullup)
#define DHT22_PIN 3

// Setup a DHT22 instance
DHT22 myDHT22(DHT22_PIN);

void setup(void)
{
  analogReference(DEFAULT);
  // start serial port
  Serial.begin(9600);  
}

void loop(void)
{ 
  DHT22_ERROR_t errorCode;
  
  // The sensor can only be read from every 1-2s, and requires a minimum
  // 2s warm-up after power-on.
  delay(5000);
  
  errorCode = myDHT22.readData();
  switch(errorCode)
  {
    case DHT_ERROR_NONE:
      Serial.print(analogRead(A0));
      Serial.print(",");
      Serial.print(analogRead(A1));
      Serial.print(",");
      Serial.print(myDHT22.getTemperatureC());
      Serial.print(",");
      Serial.println(myDHT22.getHumidity());
      break;
    case DHT_ERROR_CHECKSUM:
      Serial.print(analogRead(A0));
      Serial.print(",");
      Serial.print(analogRead(A1));
      Serial.print(",");
      Serial.print("check sum error ");
      Serial.print(myDHT22.getTemperatureC());
      Serial.print(",");
      Serial.print(myDHT22.getHumidity());
      Serial.println(",");
      break;
    case DHT_BUS_HUNG:
      Serial.println("BUS Hung ");
      break;
    case DHT_ERROR_NOT_PRESENT:
      Serial.println("Not Present ");
      break;
    case DHT_ERROR_ACK_TOO_LONG:
      Serial.println("ACK time out ");
      break;
    case DHT_ERROR_SYNC_TIMEOUT:
      Serial.println("Sync Timeout ");
      break;
    case DHT_ERROR_DATA_TIMEOUT:
      Serial.println("Data Timeout ");
      break;
    case DHT_ERROR_TOOQUICK:
      Serial.println("Polled to quick ");
      break;
  }
}
