#include "Player.h"

void Player::setState(Box::state State)
{
	PlayerState = State;
}

void Player::getState()
{
	int a = rand() % 7;
	switch (a) {
	case 0:
		PlayerState = Box::state::I;
		break;
	case 1:
		PlayerState = Box::state::J;
		break;
	case 2:
		PlayerState = Box::state::L;
		break;
	case 3:
		PlayerState = Box::state::O;
		break;
	case 4:
		PlayerState = Box::state::S;
		break;
	case 5:
		PlayerState = Box::state::T;
		break;
	case 6:
		PlayerState = Box::state::Z;
		break;
	default:
		PlayerState = Box::state::I;
		break;
	}
}

void Player::equal(Player a)
{
	PlayerState = a.getPlayerState();
	angle = a.angle;
}

Player::Player()
{
	spawnPlayer();
}

void Player::spawnPlayer()
{
	PlayerX = 4;
	PlayerY = 1;
	angle = 0;
}

int Player::getPlayerX()
{
	return PlayerX;
}

int Player::getplayerY()
{
	return PlayerY;
}

Box::state Player::getPlayerState()
{
	return PlayerState;
}

int* Player::getPlayerBlocks()
{
	int* arr = new int[4];
	int x = PlayerX;
	int y = PlayerY;
	switch (PlayerState) {
	case Box::state::I:
		switch (angle) {
		case 0:
			arr[0] = (x) * 100 + (y - 1);
			arr[1] = (x) * 100 + (y);
			arr[2] = (x) * 100 + (y + 1);
			arr[3] = (x) * 100 + (y + 2);
			break;
		case 90:
			arr[0] = (x - 1) * 100 + (y);
			arr[1] = (x) * 100 + (y);
			arr[2] = (x + 1) * 100 + (y);
			arr[3] = (x + 2) * 100 + (y);
			break;
		case 180:
			arr[0] = (x) * 100 + (y - 1);
			arr[1] = (x) * 100 + (y);
			arr[2] = (x) * 100 + (y + 1);
			arr[3] = (x) * 100 + (y + 2);
			break;
		case 270:
			arr[0] = (x - 1) * 100 + (y);
			arr[1] = (x) * 100 + (y);
			arr[2] = (x + 1) * 100 + (y);
			arr[3] = (x + 2) * 100 + (y);
			break;

		}
		break;
	case Box::state::J:
		switch (angle) {
		case 0:
			arr[0] = (x - 1) * 100 + (y - 1);
			arr[1] = (x - 1) * 100 + (y);
			arr[2] = (x) * 100 + (y);
			arr[3] = (x + 1) * 100 + (y);
			break;
		case 90:
			arr[0] = (x + 1) * 100 + (y - 1);
			arr[1] = (x) * 100 + (y - 1);
			arr[2] = (x) * 100 + (y);
			arr[3] = (x) * 100 + (y + 1);
			break;
		case 180:
			arr[0] = (x + 1) * 100 + (y + 1);
			arr[1] = (x + 1) * 100 + (y);
			arr[2] = (x) * 100 + (y);
			arr[3] = (x - 1) * 100 + (y);
			return arr;
			break;
		case 270:
			arr[0] = (x - 1) * 100 + (y + 1);
			arr[1] = (x) * 100 + (y - 1);
			arr[2] = (x) * 100 + (y);
			arr[3] = (x) * 100 + (y + 1);
			break;
		}
		break;
	case Box::state::L:
		switch (angle) {
		case 0:
			arr[0] = (x - 1) * 100 + (y);
			arr[1] = (x) * 100 + (y);
			arr[2] = (x + 1) * 100 + (y);
			arr[3] = (x + 1) * 100 + (y - 1);
			break;
		case 90:
			arr[0] = (x) * 100 + (y - 1);
			arr[1] = (x) * 100 + (y);
			arr[2] = (x) * 100 + (y + 1);
			arr[3] = (x + 1) * 100 + (y + 1);
			break;
		case 180:
			arr[0] = (x + 1) * 100 + (y);
			arr[1] = (x) * 100 + (y);
			arr[2] = (x - 1) * 100 + (y);
			arr[3] = (x - 1) * 100 + (y + 1);
			break;
		case 270:
			arr[0] = (x - 1) * 100 + (y - 1);
			arr[1] = (x) * 100 + (y - 1);
			arr[2] = (x) * 100 + (y);
			arr[3] = (x) * 100 + (y + 1);
			break;
		}
		break;
	case Box::state::O:
		switch (angle) {
		case 0:
			arr[0] = (x) * 100 + (y - 1);
			arr[1] = (x + 1) * 100 + (y);
			arr[2] = (x) * 100 + (y);
			arr[3] = (x + 1) * 100 + (y - 1);
			break;
		case 90:
			arr[0] = (x) * 100 + (y - 1);
			arr[1] = (x + 1) * 100 + (y);
			arr[2] = (x) * 100 + (y);
			arr[3] = (x + 1) * 100 + (y - 1);
			break;
		case 180:
			arr[0] = (x) * 100 + (y - 1);
			arr[1] = (x + 1) * 100 + (y);
			arr[2] = (x) * 100 + (y);
			arr[3] = (x + 1) * 100 + (y - 1);
			break;
		case 270:
			arr[0] = (x) * 100 + (y - 1);
			arr[1] = (x + 1) * 100 + (y);
			arr[2] = (x) * 100 + (y);
			arr[3] = (x + 1) * 100 + (y - 1);
			break;
		}
		break;
	case Box::state::S:
		switch (angle) {
		case 0:
			arr[0] = (x + 1) * 100 + (y - 1);
			arr[1] = (x) * 100 + (y - 1);
			arr[2] = (x) * 100 + (y);
			arr[3] = (x - 1) * 100 + (y);
			break;
		case 90:
			arr[0] = (x - 1) * 100 + (y - 1);
			arr[1] = (x - 1) * 100 + (y);
			arr[2] = (x) * 100 + (y);
			arr[3] = (x) * 100 + (y + 1);
			break;
		case 180:
			arr[0] = (x + 1) * 100 + (y - 1);
			arr[1] = (x) * 100 + (y - 1);
			arr[2] = (x) * 100 + (y);
			arr[3] = (x - 1) * 100 + (y);
			break;
		case 270:
			arr[0] = (x - 1) * 100 + (y - 1);
			arr[1] = (x - 1) * 100 + (y);
			arr[2] = (x) * 100 + (y);
			arr[3] = (x) * 100 + (y + 1);
			break;
		}
		break;
	case Box::state::T:
		switch (angle) {
		case 0:
			arr[0] = (x - 1) * 100 + (y);
			arr[1] = (x) * 100 + (y - 1);
			arr[2] = (x) * 100 + (y);
			arr[3] = (x + 1) * 100 + (y);
			break;
		case 90:
			arr[0] = (x) * 100 + (y - 1);
			arr[1] = (x + 1) * 100 + (y);
			arr[2] = (x) * 100 + (y);
			arr[3] = (x) * 100 + (y + 1);
			break;
		case 180:
			arr[0] = (x - 1) * 100 + (y);
			arr[1] = (x) * 100 + (y);
			arr[2] = (x + 1) * 100 + (y);
			arr[3] = (x) * 100 + (y + 1);
			break;
		case 270:
			arr[0] = (x) * 100 + (y - 1);
			arr[1] = (x - 1) * 100 + (y);
			arr[2] = (x) * 100 + (y);
			arr[3] = (x) * 100 + (y + 1);
			break;
		}
		break;
	case Box::state::Z:
		switch (angle) {
		case 0:
			arr[0] = (x - 1) * 100 + (y - 1);
			arr[1] = (x) * 100 + (y - 1);
			arr[2] = (x) * 100 + (y);
			arr[3] = (x + 1) * 100 + (y);
			break;
		case 90:
			arr[0] = (x) * 100 + (y);
			arr[1] = (x + 1) * 100 + (y);
			arr[2] = (x + 1) * 100 + (y - 1);
			arr[3] = (x) * 100 + (y + 1);
			break;
		case 180:
			arr[0] = (x - 1) * 100 + (y - 1);
			arr[1] = (x) * 100 + (y - 1);
			arr[2] = (x) * 100 + (y);
			arr[3] = (x + 1) * 100 + (y);
			break;
		case 270:
			arr[0] = (x) * 100 + (y);
			arr[1] = (x + 1) * 100 + (y);
			arr[2] = (x + 1) * 100 + (y - 1);
			arr[3] = (x) * 100 + (y + 1);
			break;
		}
		break;
	}
	return arr;
}

void Player::moveTo(int x, int y)
{
	PlayerX = x;
	PlayerY = y;
}

void Player::moveUp()
{
	PlayerY -= 1;
}

void Player::moveDown()
{
	PlayerY += 1;
}

void Player::moveLeft()
{
	PlayerX -= 1;
}

void Player::moveRight()
{
	PlayerX += 1;
}

void Player::Rotate()
{
	angle += 90;
	if (angle == 360) {
		angle = 0;
	}
}

void Player::RRotate()
{
	angle -= 90;
	if (angle == -90) {
		angle = 270;
	}
}
