#include "Player.h"
#include <iostream>

int main() {

    //For player testing purposes 
    std::string playerName; 
    std::cout << "Enter player name" << std::endl; 
    std::cin >> playerName; 

    Player player1(10, playerName, 60); 

    std::cout << player1.getName() << std::endl; 
    std::cout << player1.getCurrency() << std::endl; 
    std::cout << player1.getHealth() << std::endl; 

    int newAmount = 0; 
    std::cout << "Enter currency to add: " << std::endl; 
    std::cin >> newAmount; 

    player1.addMoney(newAmount); 
    player1.takeDamage(5); 

    std::cout << player1.getHealth(); 


}