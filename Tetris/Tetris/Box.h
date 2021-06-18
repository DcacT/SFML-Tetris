#pragma once
#include <SFML/Graphics.hpp>
class Box:public sf::RectangleShape
{
public:
	enum state {
		I,
		J,
		L,
		O,
		S,
		T,
		Z,
		N,
		G
	};
	state BoxState;
	Box();
	void setState(Box::state b);
	void fill();
	


};

