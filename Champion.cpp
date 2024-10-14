#include <iostream>
#include "Champion.h"
using namespace std;
Champion::Champion(Vector2f pos, float shieldHP) : NPC(3, 0.5, 3, pos, 200), shieldHP(shieldHP) {
    shape.setFillColor(Color::Yellow);
}

void Champion::takeDamage() {
    if (this->shieldHP > 0){
        this->shieldHP -= 0.5;
    } else{
        this->health -= 1;
    }
    cout << "Champ took damage" << endl;
}