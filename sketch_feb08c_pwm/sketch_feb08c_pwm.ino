int LEDpin = 9;

void setup() {
  pinMode( LEDpin, OUTPUT );
}

void loop() {
  for( int i = 0; i <= 255; i++ )
  {
    analogWrite( LEDpin, i);
    delay(10);
  }
  delay(1000);
  for( int i = 255; i >= 0; i-- )
  {
    analogWrite( LEDpin, i);
    delay(10);
  }
  delay(1000);
  
}
