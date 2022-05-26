void led4On() {
  valD4 = 0;
  EEPROM.put(6, valD4);
  digitalWrite(ledD4, valD4);
  server.sendHeader("Location", String("/"), true);
  server.send ( 302, "text/plain", "");
}

void led4Off() {
  valD4 = 1;
  EEPROM.put(6, valD4);
  digitalWrite(ledD4, valD4);
  server.sendHeader("Location", String("/"), true);
  server.send ( 302, "text/plain", "");
}
