void led2On() {
  valD2 = 0;
  EEPROM.put(2, valD2);
  digitalWrite(ledD2, valD2);
  server.sendHeader("Location", String("/"), true);
  server.send ( 302, "text/plain", "");
}

void led2Off() {
  valD2 = 1;
  EEPROM.put(2, valD2);
  digitalWrite(ledD2, valD2);
  server.sendHeader("Location", String("/"), true);
  server.send ( 302, "text/plain", "");
}
