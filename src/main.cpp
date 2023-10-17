//
// Created by emi on 10/17/23.
//
#include "../lib/mainMenu.h"
#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    sf::RenderWindow MENU(sf::VideoMode(800, 600), "Menu", sf::Style::Default);
    mainMenu mainMenu(MENU.getSize().x, MENU.getSize().y);

    sf::RenderWindow subWindow1(sf::VideoMode(800, 600), "Cantidad total de artículos diferentes.");
    sf::RenderWindow subWindow2(sf::VideoMode(800, 600), "Cantidad total de artículos.");

    while (MENU.isOpen()) {
        sf::Event event;
        while (MENU.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                MENU.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up) {
                    mainMenu.MoveUp();
                }
                if (event.key.code == sf::Keyboard::Down) {
                    mainMenu.MoveDown();
                }
                if (event.key.code == sf::Keyboard::Return) {
                    switch (mainMenu.mainMenuPressed()) {
                        case 0:
                            subWindow1.display();
                            break;
                        case 1:
                            subWindow2.display();
                            break;
                        case 2:
                            MENU.close();
                            break;
                    }
                }
            }
        }
    }

    return 0;
}
