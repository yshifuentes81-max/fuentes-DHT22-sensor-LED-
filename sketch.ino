#include <DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT22
DHT dht(DHTPIN,DHTTYPE);
void setup(){Serial.begin(9600);dht.begin();pinMode(8,OUTPUT);}
void loop(){float t=dht.readTemperature();if(isnan(t)){digitalWrite(8,LOW);delay(2000);return;}Serial.println(t);digitalWrite(8,t>=38?HIGH:LOW);delay(2000);}