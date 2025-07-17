#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Button.h"
#include "windows.h"

class Formatter
{
	sf::RenderWindow window;
	sf::Font font;
	sf::Text header;
	sf::Text subtitle;
	std::vector<Button> buttons;
	std::vector<Button> values;
	std::vector<sf::Text> fieldsName;
	std::string names[5] = { "mm", "sm", "dm", "m", "km" };
	sf::Event event;
	int activeField = 0;

public:
	Formatter();
	void run();
private:
	void processEvent();
	void update();
	void render();

	void buttonsInit();
	void valuesInit(); 
	void titlesInit();

	void keyboardsEvent(sf::Event::MouseButtonEvent mousePosition);
	void valuesEvent(sf::Event::MouseButtonEvent mousePosition);

	void resetButtons(std::vector<Button>& btns);
};

