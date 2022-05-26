void led1On() {
  valD1 = 0;
  EEPROM.put(0, valD1);
  digitalWrite(ledD1, valD1);
  server.sendHeader("Location", String("/"), true);
  server.send ( 302, "text/plain", "");
}

void led1Off() {
  valD1 = 1;
  EEPROM.put(0, valD1);
  digitalWrite(ledD1, valD1);
  server.sendHeader("Location", String("/"), true);
  server.send ( 302, "text/plain", "");
}
