void led3On() {
  valD3 = 0;
  EEPROM.put(4, valD3);
  digitalWrite(ledD3, valD3);
  server.sendHeader("Location", String("/"), true);
  server.send ( 302, "text/plain", "");
}

void led3Off() {
  valD3 = 1;
  EEPROM.put(4, valD3);
  digitalWrite(ledD3, valD3);
  server.sendHeader("Location", String("/"), true);
  server.send ( 302, "text/plain", "");
}
