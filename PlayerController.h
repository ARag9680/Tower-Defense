#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include <string>

class PlayerController {
    private:
        std::string name; 


    public: 

        PlayerController(); 
        PlayerController(std::string name); 
        
        void initializeInput(); 

        void initializePlayer(); 

        void leftMousePressed(); 
        void rightMousePressed(); 




};

#endif