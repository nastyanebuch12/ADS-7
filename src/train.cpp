// Copyright 2021 NNTU-CS
#include "train.h"
#include <cstdint>

Train::Train() {
  countOp = 0;
  first = nullptr;
}

void Train::addCar(bool light) {
  Car* newCar = new Car {light, nullptr, nullptr};
  if (!first) {
    first = newCar;
    newCar->next = newCar;
    newCar->prev = newCar;
    } else {
      Car* tail = first->prev;
      newCar->next = first;
      newCar->prev = tail;
      first->prev = newCar;
      tail->next = newCar;
      first = newCar;
  }
}

int Train::getLength() {
  if (!first) return 0;
  if (first->next == first) return 1;
  countOp = 0;
  Car* current = first;
  int countOfCars = 1;
  if (!current->light)
    current->light = true;
  current = current->next;
  countOp += 2;
  while (!current->light) {
    current = current->next;
    countOp += 2;
    countOfCars++;
  }
  current->light = false;
  if (!first->light) {
    return countOfCars;
  }
  while (true) {
    current = first;
    countOfCars = 1;
    if (!current->light) {
      current->light = true;
    }
    current = current->next;
    countOp += 2;
    while (!current->light) {
      current = current->next;
      countOp += 2;
      countOfCars++;
    }
    current->light = false;
    if (!first->light)
      return countOfCars;
  }
}

int Train::getOpCount() {
  return countOp;
}
