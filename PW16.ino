#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <EEPROM.h>

const char *ssid = "Sitnikova";
const char *password = "Yekaterina";
ESP8266WebServer server(80);

#define ledD1 D5
#define ledD2 D6
#define ledD3 D7
#define ledD4 D8

int valD1 = 0;
int valD2 = 1;
int valD3 = 0;
int valD4 = 1;

void handleRoot() {
  String s = (valD1) ? "<span>LED_1 Off   " : "<span>LED_1 On   ";
  s += (valD1) ? "<a href=\"/ledD1/on\"><button style=\"background-color:#E14D4D; border-radius:28px; border:1px solid #black; font-size:17px;\">Off</button></a></span></br>" : "<a href=\"/ledD1/off\"><button style=\"background-color:#44c767; border-radius:28px; border:1px solid #black;font-size:17px;\">On</button></a></span></br>";

  s += (valD2) ? "<span>LED_2 Off   " : "<span>LED_2 On  ";
  s += (valD2) ? "<a href=\"/ledD2/on\"><button style=\"background-color:#E14D4D; border-radius:28px; border:1px solid #black; font-size:17px;\">Off</button></a></span></br>" : "<a href=\"/ledD2/off\"><button style=\"background-color:#44c767; border-radius:28px; border:1px solid #black;font-size:17px;\">On</button></a></span></br>";

  s += (valD3) ? "<span>LED_3 Off   " : "<span>LED_3 On   ";
  s += (valD3) ? "<a href=\"/ledD3/on\"><button style=\"background-color:#E14D4D; border-radius:28px; border:1px solid #black; font-size:17px;\">Off</button></a></span></br>" : "<a href=\"/ledD3/off\"><button style=\"background-color:#44c767; border-radius:28px; border:1px solid #black;font-size:17px;\">On</button></a></span></br>";

  s += (valD4) ? "<span>LED_4 Off   " : "<span>LED_4 On   ";
  s += (valD4) ? "<a href=\"/ledD4/on\"><button style=\"background-color:#E14D4D; border-radius:28px; border:1px solid #black; font-size:17px;\">Off</button></a></span>" : "<a href=\"/ledD4/off\"><button style=\"background-color:#44c767; border-radius:28px; border:1px solid #black;font-size:17px;\">On</button></a></span>";

  server.send(200, "text/html", s);
}

void setup() {
  valD1 = EEPROM.read(0);
  valD2 = EEPROM.read(2);
  valD3 = EEPROM.read(4);
  valD4 = EEPROM.read(6);

  WiFi.softAP(ssid, password);
  server.on("/", handleRoot);

  server.on("/ledD1/on", led1On);
  server.on("/ledD1/off", led1Off);

  server.on("/ledD2/on", led2On);
  server.on("/ledD2/off", led2Off);

  server.on("/ledD3/on", led3On);
  server.on("/ledD3/off", led3Off);

  server.on("/ledD4/on", led4On);
  server.on("/ledD4/off", led4Off);
  server.begin();

  pinMode(ledD1, OUTPUT);
  pinMode(ledD2, OUTPUT);
  pinMode(ledD3, OUTPUT);
  pinMode(ledD4, OUTPUT);

  digitalWrite(ledD1, valD1);
  digitalWrite(ledD2, valD2);
  digitalWrite(ledD3, valD3);
  digitalWrite(ledD4, valD4);
}

void loop() {
  server.handleClient();
}
