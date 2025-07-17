#include "Formatter.h"


Formatter::Formatter():
	window(sf::VideoMode(800, 600), "SFML window")
{
	font.loadFromFile("./fonts/arialbd.ttf");
    buttonsInit();
    valuesInit();
    titlesInit();
}

void Formatter::run()
{
    while (window.isOpen())
    {
        processEvent();
        update();
        render();
    }
}

void Formatter::processEvent()
{
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();

        if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Left) {
                auto mousePosition = event.mouseButton;
                keyboardsEvent(mousePosition);
                valuesEvent(mousePosition);      
            }
        }
        else {
            resetButtons(buttons);
        }
    }
}

void Formatter::update()
{
    auto activeNumber = std::stod(values[activeField].getText().toAnsiString());
    for (int i = activeField - 1, index = 10; i >= 0; i--, index *= 10) {
        values[i].setText(std::to_string(activeNumber * index));
    }
    for (int i = activeField + 1, index = 10; i < values.size(); i++, index *= 10) {
        values[i].setText(std::to_string(activeNumber / index));
    }

    resetButtons(values);
    values[activeField].on();
}

void Formatter::render()
{
    window.clear();
    window.draw(header);
    window.draw(subtitle);

    for (auto name : fieldsName) {
        window.draw(name);
    }

    for (auto value : values) {
        value.draw(window);
    }

    for (auto btn : buttons) {
        btn.draw(window);
    }

    window.display();
}

void Formatter::buttonsInit()
{
    for (int i = 0; i < 12; i++) {
        Button button(SIZE_BTN, font);
        if (i == 10) button.setText(".");
        else if (i == 11) button.setText("C");
        else button.setText(std::to_string(i));
        button.setPosition(sf::Vector2f(i * 60, 100));
        buttons.push_back(button);
    }
}

void Formatter::valuesInit()
{
    for (int i = 0; i < 5; i++) {
        sf::Text textName;
        Button button(SIZE_FIELD, "0", font);
        button.setPosition(sf::Vector2f(65, (150) + (i * 50)));
        values.push_back(button);

        textName.setFont(font);
        textName.setCharacterSize(18);
        textName.setString(names[i]);
        textName.setFillColor(sf::Color::White);
        textName.setPosition(sf::Vector2f(0, (150) + (i * 50)));
        fieldsName.push_back(textName);
    }
}

void Formatter::titlesInit()
{
    subtitle.setFont(font);
    subtitle.setCharacterSize(18);
    subtitle.setString("input your value");
    subtitle.setPosition(sf::Vector2f(0, 30));
    header.setFont(font);
    header.setString("values formatter");
    header.setCharacterSize(24);
}

void Formatter::keyboardsEvent(sf::Event::MouseButtonEvent mousePosition)
{
    for (int i = 0; i < buttons.size(); i++) {
        if (mousePosition.x >= buttons[i].getPosition().x &&
            mousePosition.x <= buttons[i].getPosition().x + SIZE_BTN.x &&
            mousePosition.y >= buttons[i].getPosition().y &&
            mousePosition.y <= buttons[i].getPosition().y + SIZE_BTN.y) {
            buttons[i].on();

            auto currentString = values[activeField].getText();
            if (i == 10) {
                values[activeField].setText(currentString + ".");
            }
            else if (i == 11) {
                values[activeField].setText("0");
            }
            else {
                auto num = buttons[i].getText().toAnsiString();

                auto currentNum = std::stod(values[activeField].getText().toAnsiString());
                if (currentNum == 0) currentString = "";
                values[activeField].setText(currentString + num);
            }
        }
    }
}

void Formatter::valuesEvent(sf::Event::MouseButtonEvent mousePosition) {
    for (int i = 0; i < values.size(); i++) {
        if (mousePosition.x >= values[i].getPosition().x &&
            mousePosition.x <= values[i].getPosition().x + SIZE_FIELD.x &&
            mousePosition.y >= values[i].getPosition().y &&
            mousePosition.y <= values[i].getPosition().y + SIZE_FIELD.y) {
            activeField = i;
        }
    }
}

void Formatter::resetButtons(std::vector<Button>& btns)
{
    for (int i = 0; i < btns.size(); i++) {
        btns[i].off();
    }
}


