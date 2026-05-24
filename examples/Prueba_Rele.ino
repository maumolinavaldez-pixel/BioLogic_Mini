#include <BioLogic.h>

BioLogic biologic;

void setup() {
  biologic.begin(); 
}
void loop() {
  biologic.relayTimed(r1, 2000);
  biologic.relayToggle(r2);
  delay(1000);
}
