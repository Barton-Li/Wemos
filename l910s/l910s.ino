#include <ESP8266WiFi.h>
#define dong1 D6
#define dong2 D7
#define zhuan1 D4
#define zhuan2 D5
char* ssid = "CMCC-bM6N";
char* passed = "123456789.";
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
void initL910s()
{
  pinMode(dong1, OUTPUT);
  pinMode(dong2, OUTPUT);
  pinMode(zhuan1, OUTPUT);
  pinMode(zhuan2, OUTPUT);
}
void hou()
{
  digitalWrite(dong1, LOW);
  digitalWrite(dong2, HIGH);
}
void qian()
{
  digitalWrite(dong1, HIGH);
  digitalWrite(dong2, LOW);
}
void left()
{
  digitalWrite(zhuan1, LOW);
  digitalWrite(zhuan2, HIGH);
}
void right()
{
  digitalWrite(zhuan1, HIGH);
  digitalWrite(zhuan2, LOW);

}
void setup() {
  // put your setup code here, to run once:
  initL910s();
  initWifista();
  Serial.begin(115200);
  server.begin();

}

void loop() {
  
  char cmd;
  WiFiClient client = server.available();
  while (client.connected())
  {
    while (client.available() > 0)
    {
      cmd = client.read();

      switch (cmd)
      {
        case 'a':
          qian();
          break;
        case 'b':
          hou();
          break;
        case 'c':
          left();
          break;
        case 'd':
          right();
          break;
      }
    }
  }
}
