#include <SimpleMovingAverage.h>

SimpleMovingAverage avg;

void setup() {
  Serial.begin(9600);
  avg.begin();

  for(uint8_t i = 0; i < 10; i++) {
    Serial.println(avg.update(i));
  }
}

void loop() {
}
