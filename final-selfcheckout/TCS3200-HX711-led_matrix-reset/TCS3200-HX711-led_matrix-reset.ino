#include "HX711.h"
#include "FastLED.h"

//HX711 parameters
#define calibration_factor -290
#define LOADCELL_DOUT_PIN  3
#define LOADCELL_SCK_PIN  2
HX711 scale;

//LED matrix parameters
#define NUM_LEDS 16
#define DATA_PIN 9
CRGB leds[NUM_LEDS];
int i;

// TCS230 or TCS3200 pins wiring to Arduino
#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8
int redFrequency = 0;
int greenFrequency = 0;
int blueFrequency = 0;
int redColor = 0;
int greenColor = 0;
int blueColor = 0;


void setup() {

//HX711 initialization
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_scale(calibration_factor);  
  scale.tare();

//LED matrix initialization
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  

//TCS3200 initialization
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);

//serial begin
  Serial.begin(9600);
}

void(* resetFunc) (void) = 0; 

int detectcolor()
{
  // Setting RED (R) filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  redFrequency = pulseIn(sensorOut, LOW);
  redColor = map(redFrequency, 456, 7567, 255,0);
  delay(10);

  // Setting GREEN (G) filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  greenFrequency = pulseIn(sensorOut, LOW);
  greenColor = map(greenFrequency,672, 11189, 255, 0);
  delay(10);

  // Setting BLUE (B) filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  blueFrequency = pulseIn(sensorOut, LOW);
  blueColor = map(blueFrequency,252, 4385, 255, 0);
  delay(10);

  if(redColor > greenColor && redColor > blueColor){
      return 1;
  }
  else
  {
    return 0;
  }
}

void loop() {
  if (Serial.available() > 0) { 
    
    Serial.print(scale.get_units(),0); 
    Serial.print(detectcolor()); 
    Serial.println();
      
    char incomingByte = Serial.read();
    
    if(incomingByte == '1')
    {
      for(i=0;i<NUM_LEDS;i++)
      {
        leds[i] = CRGB::Red;
        FastLED.show();
      }
      
      delay(1000);
      
      for(i=0;i<NUM_LEDS;i++)
      {
        leds[i] = CRGB::Black;
        FastLED.show();
      }
      delay(200);
      
    }
    
    //call reset   
    if(incomingByte == '2')
    {
      resetFunc();  
      delay(100);
    }
  }


}
