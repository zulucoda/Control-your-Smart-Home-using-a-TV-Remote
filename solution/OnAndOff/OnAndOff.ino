#include <IRremote.h>

const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;
unsigned long key_value = 0;

const int led = 5;
const int greenLed = 6;
int isOn = 0;

void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
  pinMode(led, OUTPUT);
  pinMode(greenLed, OUTPUT);
}

void loop(){
  if (irrecv.decode(&results)){

        Serial.println(results.value, HEX);

        switch(results.value){
          case 0x3011D6F:
          Serial.println("On/Off");
          Serial.println("3");

          Serial.println(isOn);
          if (isOn == 0) {
            isOn = 1;
            Serial.println(isOn);
            digitalWrite(led, HIGH);
            digitalWrite(greenLed, HIGH);
            delay(500);
          }else{
            isOn = 0;
            Serial.println(isOn);
            digitalWrite(led, LOW);
            digitalWrite(greenLed, LOW);
            delay(500);
          }
          
          //digitalWrite(led, HIGH);
          //digitalWrite(greenLed, HIGH);
          //delay(5000);
          //digitalWrite(led, LOW);
          //digitalWrite(greenLed, LOW);
          break;
          case 0x3654C83B:
          Serial.println("4");
          digitalWrite(led, HIGH);
          delay(2000);
          digitalWrite(led, LOW);
          break ;  
          case 0x3EF170C9:
          Serial.println("6");
          digitalWrite(greenLed, HIGH);
          delay(1000);
          digitalWrite(greenLed, LOW);
          break ;
          case 0x5139E64D:
          Serial.println("8");
          digitalWrite(greenLed, HIGH);
          delay(500);
          digitalWrite(greenLed, LOW);
          break ;
          
        }
        key_value = results.value;
        irrecv.resume(); 
  }
}
