int LEDpin = 9
;
int pinA = 5;  // Connected to CLK on KY-040
int pinB = 4;  // Connected to DT on KY-040
int encoderPosCount = 0; 
int pinALast;  
int aVal;
boolean bCW;

void setup() { 
  pinMode (LEDpin,OUTPUT);  
  pinMode (pinA,INPUT);
  pinMode (pinB,INPUT);
  /* Read Pin A
  Whatever state it's in will reflect the last position   
  */
  pinALast = digitalRead(pinA);   
  Serial.begin (9600);
} 

void loop() { 
  aVal = digitalRead(pinA);
  if (aVal != pinALast){ // Means the knob is rotating
    // if the knob is rotating, we need to determine direction
    // We do that by reading pin B.
    if (digitalRead(pinB) != aVal) {  // Means pin A Changed first - We're Rotating Clockwise
      bCW = true;
      if ( encoderPosCount < 255 ) {
        encoderPosCount += 5; 
       }
    } else {// Otherwise B changed first and we're moving CCW
      bCW = false;
      if (encoderPosCount > 0 ) {
        encoderPosCount -= 5;
      }
    }
    Serial.print ("Rotated: ");
    if (bCW){
      Serial.println ("clockwise");
    }else{
      Serial.println("counterclockwise");
    }
    Serial.print("Encoder Position: ");
    Serial.println(encoderPosCount);
    
  } 
  pinALast = aVal;
  analogWrite(LEDpin, encoderPosCount);
} 
