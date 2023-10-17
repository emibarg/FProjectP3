//
// Created by emi on 10/17/23.
//
#include "../lib/mainMenu.h"
#include <SFML/Graphics.hpp>
#include <iostream>
void loop(){
    sf::RenderWindow MENU(sf::VideoMode(800,600),"Menu");
    mainMenu mainMenu(MENU.getSize().x,MENU.getSize().y);

    while (MENU.isOpen()){
        sf::Event event;
        while (MENU.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                MENU.close();
            }
            if (event.type == sf::Event::KeyPressed){
                if (event.key.code == sf::Keyboard::Up){
                    mainMenu.MoveUp();
                }
                if (event.key.code == sf::Keyboard::Down){
                    mainMenu.MoveDown();
                }
                if (event.key.code == sf::Keyboard::Return){
                    switch (mainMenu.mainMenuPressed()){
                        case 0:
                           sf::RenderWindow(sf::VideoMode(800,600),"Cantidad total de artículos diferentes.");
                            break;
                        case 1:
                            sf::RenderWindow(sf::VideoMode(800,600),"Cantidad total de artículos.");
                            break;
                        case 2:
                            MENU.close();
                            break;
                    }
                }
            }
        }
    }


}
