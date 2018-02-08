int LEDpin = 12;

void setup() {
  pinMode( LEDpin, OUTPUT );
}

void loop() {
  digitalWrite( LEDpin, HIGH );
  delay(2000);
  digitalWrite( LEDpin, LOW );
  delay(2000);
}
