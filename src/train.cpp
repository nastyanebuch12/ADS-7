// Copyright 2021 NNTU-CS
#include "train.h"
#include <cstdint>

Train::Train() {
  countOp = 0;
  first = nullptr;
}

void Train::addCar(bool light) {
  Car* Car_new = new Car{light, nullptr, nullptr};
  if (first == nullptr) {
    Car_new->next = Car_new;
    Car_new->prev = Car_new;
    first = Car_new;
  }
  else {
    Car* tail = first->prev;
    Car_new->next = first;
    Car_new->prev = tail;
    tail->next = Car_new;
    first->prev = Car_new;
  }
}

int Train::getLength() {
  countOp = 0;
  while (true) {
    Car* current = first;
    uint16_t lengthEstimate = 1;
    if (!current->light)
      current->light = true;
    current = current->next;
    countOp += 2;
    while (!current->light) {
      current = current->next;
      countOp += 2;
      ++lengthEstimate;
    }
    current->light = false;
    if (!first->light)
      return lengthEstimate;
  }
}

int Train::getOpCount() {
  return countOp;
}
