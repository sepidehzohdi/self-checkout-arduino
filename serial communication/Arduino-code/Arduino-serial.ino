
void setup() {
  Serial.begin(9600); 
  
  pinMode(13, OUTPUT);
}

void loop() {


  if (Serial.available() > 0) { 

    Serial.println("Hello");
    char incomingByte = Serial.read();
    
    if(incomingByte == '1')
    {
      digitalWrite(13, HIGH);   
      delay(500);                      
      digitalWrite(13, LOW);    
      delay(500);
    }
    
  }
    
}
