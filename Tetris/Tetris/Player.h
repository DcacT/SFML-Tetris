#pragma once
#include "Box.h"
#include "time.h"
class Player
{
public:
	int PlayerX;
	int PlayerY;
	Box::state PlayerState;
	int angle;

	void setState(Box::state State);
	void getState();
	void equal(Player a);

	Player();
	void spawnPlayer();
	int getPlayerX();
	int getplayerY();
	Box::state getPlayerState();
	int* getPlayerBlocks();
	//Movement
	void moveTo(int x, int y);
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	void Rotate();
	void RRotate();

};


