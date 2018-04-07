/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

int RECV_PIN = 7;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  // In case the interrupt driver crashes on setup, give a clue
  // to the user what's going on.
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
}

void loop() {
  if (irrecv.decode(&results)) {
     Serial.println(results.value);

    if (results.value == 4281029425){
      Serial.println("Switch on the TV");
    }

    if (results.value == 911525947){
      Serial.println("Turn on all the light");
    }

    if (results.value == 3226482915){
      Serial.println("Welcome home sir, we are switching, all the lights, the TV, putting on your favorite song by 50 cent.");
    }
    
    irrecv.resume(); // Receive the next value
  }
  delay(100);
}
