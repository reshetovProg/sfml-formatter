#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    sf::Font font;
    sf::Text header;
    sf::Text subtitle;

    font.loadFromFile("./fonts/arialbd.ttf");

    subtitle.setFont(font);
    subtitle.setCharacterSize(18);
    subtitle.setString("input your value");
    subtitle.setPosition(sf::Vector2f(0, 30));
    header.setFont(font);
    header.setString("values formatter");
    header.setCharacterSize(24);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(header);
        window.draw(subtitle);

        window.display();
    }

    return EXIT_SUCCESS;
}