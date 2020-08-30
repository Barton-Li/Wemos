#include <ESP8266WiFi.h>
#define BEEP D5
char* ssid = "TP-LINK_C062";
char* passed = "123456789";
int port = 8888;
WiFiServer server(port);
void initWifista()
{
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, passed);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println(WiFi.localIP());
}
void initDeep()
{
  pinMode(BEEP, OUTPUT);
  digitalWrite(BEEP, HIGH);
}
void setup() {
  // put your setup code here, to run once:
  //启动wifi

  Serial.begin(115200);
  initWifista();
  server.begin();
  initDeep();
}

void loop() {

  char cad;
  WiFiClient client = server.available();
  while (client.connected())
  {
    while (client.available() > 0)
    {
      cad = client.read();
      if (cad == '1')
      {
        digitalWrite(BEEP, LOW);
      }
      else
      {

        digitalWrite(BEEP, HIGH);
      }
    }

  }

}
