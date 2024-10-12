#include "Elite.h"

Elite::Elite(Vector2f pos) : NPC(2, 0.6, 2, pos, 100)   {
    shape.setFillColor(Color::Magenta);
}

void Elite::takeDamage() {
  double r = ((double)rand() / (RAND_MAX));  // random number from 0 to 1
  if (r > 0.3) {
    this->health -= 1;
  }  // Takes damage 70% of the time
  if (this->health < 0) {
    this->health = 0;
  }  // Health cannot be negative
}