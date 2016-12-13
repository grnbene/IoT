#include <IRremote.h>


int LED1 = 13;
int on = 0;
int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, DEC);
    irrecv.resume(); 
  }

  switch (results.value) {
    case 16: {
        on = !on;
        digitalWrite (LED1, on ? HIGH : LOW);
      }
      break;
  }
}
