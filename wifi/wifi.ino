#include <ESP8266WiFi.h>
/*#include "motor.h"
#include "wifiUtils.h"
#include  "dis.h"*/
char* ssid = "TP-LINK_C062";
char* passed = "123456789";


void initWifista()
{
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, passed);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }

}
void setup() {
  // put your setup code here, to run once:
  //启动wifi
  Serial.begin(115200);
  initWifista();
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(WiFi.localIP());
  delay(500);
}
