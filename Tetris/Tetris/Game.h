#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Box.h"
#include "Player.h"
#include "time.h"
class Game
{
public:
	Game();
	void run();

private:
	sf::RenderWindow window;
	sf::Font font;
	sf::RectangleShape TextBox;
	int score = 0;			//score
	Box GreyBlocks[21][23];
	Box Blocks[10][20];
	Player Darren;		//player
	Player SubPlayer[5]; //0 left, 1 2 3 right, 4 for backup
	//Player Swap;
	int* PlayerArr;
	int* PlayerArr2;
	int* SubPlayerArr;
	bool StaticBlocks[10][20];
	bool end = false;
	int counter = 0;	//drop down counter 
	int counter2 = 0;	//player -> static counter
	bool notLegal();
	void checkRow();
	void killPlayer();
	void displayText(); //score also here
	void Restart();
};

