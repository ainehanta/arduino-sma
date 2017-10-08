#include <SimpleMovingAverage.h>

SimpleMovingAverage<double, 10> avg;

void setup() {
  Serial.begin(9600);

  Serial.println(avg.update(10));
  Serial.println(avg.update(11));
  Serial.println(avg.update(10));
  Serial.println(avg.update(10));
  Serial.println(avg.average());
}

void loop() {
}
