//
// Created by emi on 10/17/23.
//
#include "../lib/mainMenu.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

int main() {
    sf::RenderWindow MENU(sf::VideoMode(800, 600), "Menu", sf::Style::Default);
    mainMenu mainMenu(MENU.getSize().x, MENU.getSize().y);
    //Background
    sf::RectangleShape background(sf::Vector2f(800.0f, 600.0f));
    sf::Texture mainTexture;
    mainTexture.loadFromFile("../background/demonwpp.jpg");
    background.setTexture(&mainTexture);
    //Music
    sf::Music music;
    if (!music.openFromFile("../music/doom.wav")) {
        // Handle the case where the file failed to load
        // Print an error message, log, or exit the program gracefully.
        std::cerr << "Failed to load music file!" << std::endl;
        return 1; // Exit the program with an error code
    }

// Rest of your code



    while (MENU.isOpen()) {
        sf::Event event;
        while (MENU.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                MENU.close();
            }
            if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::Up) {
                    mainMenu.MoveUp();
                    break;
                }
                if (event.key.code == sf::Keyboard::Down) {
                    mainMenu.MoveDown();
                    break;
                }
                if (event.key.code == sf::Keyboard::Return) {
                    sf::RenderWindow CantArtDif(sf::VideoMode(800, 600), "Cantidad total de artículos diferentes.");
                    sf::RenderWindow CantArt(sf::VideoMode(800, 600), "Cantidad total de artículos.");
                    int x = mainMenu.mainMenuPressed();
                    if(x == 0){
                        while (CantArtDif.isOpen()) {
                            sf::Event event;
                            while (CantArtDif.pollEvent(event)) {
                                if (event.type == sf::Event::KeyPressed) {
                                    if (event.key.code == sf::Keyboard::Escape) {
                                        CantArtDif.close();
                                    }
                                }
                            }
                            CantArt.close();
                            CantArtDif.clear();
                            CantArtDif.display();
                        }
                    }
                    if(x == 1){
                        while (CantArt.isOpen()) {
                            sf::Event aevent;
                            while (CantArtDif.pollEvent(aevent)) {
                                if (aevent.type == sf::Event::KeyPressed) {
                                    if (aevent.key.code == sf::Keyboard::Escape) {
                                        CantArtDif.close();
                                    }
                                }
                            }
                            CantArtDif.close();
                            CantArt.clear();
                            CantArt.display();
                        }
                    }
                    if(x == 2){
                        MENU.close();
                    }
                }
            }
            MENU.clear();
            MENU.draw(background);
            music.play();
            mainMenu.draw(MENU);
            MENU.display();
        }
    }


    return 0;
}