#include "Game.h"

Game::Game() :
	window(sf::VideoMode(630, 690), "Tetris")
	
	
{
	TextBox.setSize(sf::Vector2f(120, 90));
	TextBox.setFillColor(sf::Color::Black);
	TextBox.setOutlineThickness(1);
	
	TextBox.setPosition(sf::Vector2f(30, 420));
	srand(time(NULL));
	window.setFramerateLimit(60);
	//font
	if (font.loadFromFile("OpenSans-Regular.ttf")) {
		//window.setTitle("Success");
	}
	
	//GreyBlocks
	for (int x = 0; x < 21; x++) {
		for (int y = 0; y < 23; y++) {
			GreyBlocks[x][y] = Box();
			GreyBlocks[x][y].setPosition(sf::Vector2f(x * 30, y * 30));
		}
	}
	//Black Boxes 
	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 20; y++) {
			Blocks[x][y] = Box();
			Blocks[x][y].setState(Box::state::N);
			Blocks[x][y].setPosition(sf::Vector2f((x + 6) * 30, (y + 1) * 30));
		}
	}
	
	for (int i = 0; i < 5;i++) {
		SubPlayer[i].getState();
	}
	SubPlayer[0].moveTo(2, 5);
	SubPlayer[1].moveTo(18, 5);
	SubPlayer[2].moveTo(18, 10);
	SubPlayer[3].moveTo(18, 15);


	//Player
}

void Game::run()
{
	while (window.isOpen()) {
			window.clear(sf::Color::Black);
			if (end != true) {
				counter++;
			}
			//SubPlayers
				//clear SubPlayer Canvas
			for (int x = 0; x < 21; x++) {
				for (int y = 0; y < 23; y++) {
					if (1 <= x && x <= 4 && 3 <= y && y <= 7) {
						GreyBlocks[x][y].setState(Box::state::N);
					}
					else if (17 <= x && x <= 19 && 2 <= y && y <= 19) {
						GreyBlocks[x][y].setState(Box::state::N);
					}
					else if (6 <= x && x <= 15 && 1 <= y && y <= 19) {
						GreyBlocks[x][y].setState(Box::state::L);
					}
					else if (1 <= x && x <= 4 && 14 <= y && y <= 16) {
						GreyBlocks[x][y].setState(Box::state::N);
					}
					else {
						GreyBlocks[x][y].setState(Box::state::G);
					}
				}
			}
			//drawSubPlayers
			for (int i = 0; i < 4; i++) {
				SubPlayerArr = SubPlayer[i].getPlayerBlocks();
				for (int k = 0; k < 4; k++) {
					int n = SubPlayerArr[k] / 100;
					int m = SubPlayerArr[k] % 100;
					GreyBlocks[n][m].setState(SubPlayer[i].getPlayerState());
				}
			}


			//events 
			sf::Event event;
			while (window.pollEvent(event)) {
				switch (event.type) {
				case sf::Event::EventType::Closed:
					window.close();
					break;
				case sf::Event::EventType::KeyPressed:
					switch (event.key.code) {
					case sf::Keyboard::Key::A:
						Darren.moveLeft();
						if (notLegal() == true) {
							Darren.moveRight();
						}
						break;
					case sf::Keyboard::Key::S:
						Darren.moveDown();
						if (notLegal() == true) {
							Darren.moveUp();
						}
						break;
					case sf::Keyboard::Key::D:
						Darren.moveRight();
						if (notLegal() == true) {
							Darren.moveLeft();
						}
						break;
					case sf::Keyboard::Key::R:
						Darren.Rotate();
						if (notLegal() == true) {
							Darren.RRotate();
						}
						break;
					case sf::Keyboard::Key::Q:
						SubPlayer[4].equal(Darren);
						Darren.equal(SubPlayer[0]);
						SubPlayer[0].equal(SubPlayer[4]);
						if (notLegal() == true) {
							SubPlayer[0].equal(Darren);
							Darren.equal(SubPlayer[4]);
						}
						break;
					case sf::Keyboard::Key::C:
						Restart();
						break;
					case sf::Keyboard::Key::Space:
						if (end != true) {
							do {
								Darren.moveDown();
							} while (!notLegal());
							Darren.moveUp();
							killPlayer();
						}
						break;
					case sf::Keyboard::Key::Escape:
						window.close();
						break;
					}
					break;
				}
			}

			if (counter == 60) {
				Darren.moveDown();
				if (notLegal() == true) {
					Darren.moveUp();
					counter2++;
					counter--;
					if (counter2 == 60) {

						killPlayer();
						counter2 = 0;
						counter = 0;
					}
				}
				else {
					counter = 0;
				}
			}
			//get DarrenPosition
			PlayerArr = Darren.getPlayerBlocks();
			//setState Black 
			for (int x = 0; x < 10; x++) {
				for (int y = 0; y < 20; y++) {
					if (StaticBlocks[x][y] == false) {
						Blocks[x][y].setState(Box::state::N);
					}
				}
			}
			//setState Darren
			if (end != true) {
				for (int i = 0; i < 4; i++) {
					int n = PlayerArr[i] / 100;
					int m = PlayerArr[i] % 100;
					Blocks[n][m].setState(Darren.getPlayerState());
				}
			}
			//display 
					//GreyBlocks
			for (int x = 0; x < 21; x++) {
				for (int y = 0; y < 23; y++) {
					window.draw(GreyBlocks[x][y]);
				}
			}
			//Blocks
			for (int x = 0; x < 10; x++) {
				for (int y = 0; y < 20; y++) {
					window.draw(Blocks[x][y]);
				}
			}
			
			window.draw(TextBox);
			displayText();
			window.display();
		}
}



void Game::checkRow()
{
	int row = 0;
	int rowCount = 0;
	for (int m =19; m >= 0; m--) {
		for (int n = 0; n < 10;n++) {
			if (StaticBlocks[n][m] == true) {
				row++;
			}
		}
		if (row == 10) {
		//delete
			rowCount++;
			for (int k = m; k > 0; k--) {
				for (int j = 0; j < 10; j++) {
					Blocks[j][k].setState(Blocks[j][k-1].BoxState);
					StaticBlocks[j][k] = StaticBlocks[j][k - 1];
				}
			}
			m++;
			row = 0;
		}
		row = 0;
	}
	if (rowCount != 0) {
		score += (rowCount * 10 + ((rowCount - 1) * 5));
	}
}

void Game::displayText()
{
	sf::Text ScoreText("SCORE: ", font, 18);
	ScoreText.setPosition(sf::Vector2f(30, 422));
	window.draw(ScoreText);
	
	sf::Text Score(std::to_string(score) , font, 22);
	Score.setPosition(sf::Vector2f(30, 448));
	window.draw(Score);
	if (end == true) {
		sf::Text GameOver("GAME OVER, R to replay", font, 10);
		GameOver.setPosition(sf::Vector2f(30, 495));
		window.draw(GameOver);
	}
}

void Game::Restart()
{
	window.clear(sf::Color::White);
	end = false;
	score = 0;
	for (int n = 0; n < 10; n++) {
		for (int m = 0; m < 20; m++) {
			StaticBlocks[n][m] = false;
		}
	}
	Darren.spawnPlayer();
	Darren.getState();
	for (int i = 0; i < 4; i++) {
		SubPlayer[i].getState();
	}
}

void Game::killPlayer()
{
	PlayerArr = Darren.getPlayerBlocks();
	for (int i = 0; i < 4; i++) {
		int n = PlayerArr[i] / 100;
		int m = PlayerArr[i] % 100;
		StaticBlocks[n][m] = true;
		Blocks[n][m].setState(Darren.getPlayerState());
	}
	checkRow();
	Darren.spawnPlayer();
	if (notLegal()) {
		end = true;
	}
	Darren.setState(SubPlayer[1].getPlayerState());
	SubPlayer[1].setState(SubPlayer[2].getPlayerState());
	SubPlayer[2].setState(SubPlayer[3].getPlayerState());
	SubPlayer[3].getState();
}

bool Game::notLegal()
{
	if (end == true) {
		return true;
	}
	PlayerArr = Darren.getPlayerBlocks();
	for (int i = 0; i < 4; i++) {
		int n = PlayerArr[i] / 100;
		int m = PlayerArr[i] % 100;
		if (n < 0 || n>9 || m < 0 || m>19) {
			return true;
		}
		else if (StaticBlocks[n][m] == true) {
			return true;
		}
	}
	return false;
}
