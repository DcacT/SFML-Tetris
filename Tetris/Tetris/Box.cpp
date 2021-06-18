#include "Box.h"

Box::Box()
{
	setState( Box::state::G);
	setSize(sf::Vector2f(30, 30));
	setOutlineColor(sf::Color::White);
	setOutlineThickness(1);
}

void Box::setState(Box::state b)
{
	BoxState = b;
	fill();
}

void Box::fill()
{
	switch (BoxState) {
	case N:
		setFillColor(sf::Color::Black);
		break;
	case I:
		setFillColor(sf::Color::Cyan);
		break;
	case J:
		setFillColor(sf::Color::Blue);
		break;
	case L:
		setFillColor(sf::Color{ 255, 69, 0 }); //orange
		break;
	case O:
		setFillColor(sf::Color::Yellow);
		break;
	case S:
		setFillColor(sf::Color::Green);
		break;
	case T:
		setFillColor(sf::Color::Magenta);
		break;
	case Z:
		setFillColor(sf::Color::Red);
		break;
	case G:
		setFillColor(sf::Color{ 105,105,105 });
		break;
	Default:
		setFillColor(sf::Color::White);
		break;
	}

}
