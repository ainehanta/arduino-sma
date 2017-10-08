#ifndef _SIMPLE_MOVING_AVERAGE_H
#define _SIMPLE_MOVING_AVERAGE_H

#include <cstdint>
#include <cstddef>

template <typename TYPE, std::size_t SIZE>
class SimpleMovingAverage {
private:
  size_t valuesIndex;
  size_t usedLength;
  TYPE total;
  TYPE values[SIZE];

public:
  SimpleMovingAverage() {
    this->clear();
  }

  ~SimpleMovingAverage() {}

  void clear(void) {
    this->valuesIndex = 0;
    this->usedLength = 0;
    this->total = 0;

    for(uint8_t i=0; i < SIZE; i++) {
      this->values[i] = 0;
    }
  }

  TYPE update(TYPE value) {
    this->total -= this->values[this->valuesIndex];
    this->total += value;
    this->values[this->valuesIndex] = value;

    this->valuesIndex = (this->valuesIndex + 1) % SIZE;
    if(this->usedLength < SIZE) {
      this->usedLength++;
    }

    return this->total / this->usedLength;
  }

  TYPE read(size_t index) {
    return this->values[index];
  }

  TYPE average(void) {
    return this->total / this->usedLength;
  }

  size_t length(void) {
    return SIZE;
  }
};

#endif
