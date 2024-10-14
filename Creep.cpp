#include "Creep.h"
#include <iostream>
using namespace std;
Creep::Creep(Vector2f pos) : NPC(1, 0.1, 1, pos, 50)   {
    shape.setFillColor(Color::Black);
}

void Creep::takeDamage() {
  this->health -= 1;
  if (this->health < 0) {
    this->health = 0;
  }  // Health cannot be negative
  cout << "Creep took damage" << endl;
}