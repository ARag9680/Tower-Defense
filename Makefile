SFMLLIBRARIES = -I/opt/homebrew/Cellar/sfml/2.6.1/include -L/opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system
COMPILER = g++
COMPILERFLAGS = -std=c++11 -Wall -Wextra

TARGET = testProgram-TowerDefense
SOURCEFILES = main.cpp map.cpp npc.cpp button.cpp champion.cpp creep.cpp elite.cpp Main_Menu.cpp player.cpp towers.cpp 

.PHONY: all

all:
	$(COMPILER) $(COMPILERFLAGS) -o $(TARGET) $(SFMLLIBRARIES) $(SOURCEFILES) 
	./$(TARGET)

.PHONY: clean

clean:
	rm -f $(TARGET)