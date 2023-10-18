//
// Created by emi on 10/17/23.
//
#include "../lib/mainMenu.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "../lib/CantArtDif.h"
#include "../lib/CantArt.h"
#include "../lib/MinStock.h"

int main() {
    sf::RenderWindow MENU(sf::VideoMode(800, 600), "Menu", sf::Style::Default);
    mainMenu mainMenu(MENU.getSize().x, MENU.getSize().y);

    // Initialize background
    sf::RectangleShape background(sf::Vector2f(800.0f, 600.0f));
    sf::Texture mainTexture;
    if (!mainTexture.loadFromFile("../background/demonwpp.jpg")) {
        std::cerr << "Failed to load background texture!" << std::endl;
        return 1;
    }
    background.setTexture(&mainTexture);

    // Initialize music
    sf::Music music;
    if (!music.openFromFile("../music/doom.wav")) {
        std::cerr << "Failed to load music file!" << std::endl;
        return 1;
    }
    music.setVolume(15);
    music.play();
    while (MENU.isOpen()) {
        sf::Event event;
        while (MENU.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                MENU.close();
            }

            if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::Up) {
                    mainMenu.MoveUp();
                } else if (event.key.code == sf::Keyboard::Down) {
                    mainMenu.MoveDown();
                } else if (event.key.code == sf::Keyboard::Return) {
                    int selectedItem = mainMenu.mainMenuPressed();
                    if (selectedItem == 0) {
                        // Handle "Cantidad total de artículos diferentes." menu option
                        // Create a new window or transition to a new state.
                        sf::RenderWindow CantArtDifW(sf::VideoMode(800, 600), "Cantidad total de artículos diferentes.");
                        CantArtDiff CantArtDiff(CantArtDifW.getSize().x, CantArtDifW.getSize().y);
                        // The event loop for the new window
                        while (CantArtDifW.isOpen()) {
                            sf::Event event;
                            while (CantArtDifW.pollEvent(event)) {
                                if (event.key.code == sf::Keyboard::Escape) {
                                    CantArtDifW.close();
                                }
                                // Handle other events specific to this window

                            }

                            CantArtDifW.clear();
                            CantArtDifW.draw(background);
                            CantArtDiff.draw(CantArtDifW);
                            // Draw and update the contents of this window

                            CantArtDifW.display();
                        }

                    } else if (selectedItem == 1) {
                        // Handle "Cantidad total de artículos." menu option
                        // Create a new window or transition to a new state.
                        sf::RenderWindow CantArtW(sf::VideoMode(800, 600), "Cantidad total de artículos diferentes.");
                        CantArt CantArt(CantArtW.getSize().x, CantArtW.getSize().y);
                        // The event loop for the new window
                        while (CantArtW.isOpen()) {
                            sf::Event event;
                            while (CantArtW.pollEvent(event)) {
                                if (event.key.code == sf::Keyboard::Escape) {
                                    CantArtW.close();
                                }
                                // Handle other events specific to this window
                            }

                            CantArtW.clear();
                            // Draw and update the contents of this window

                            CantArtW.draw(background);
                            CantArt.draw(CantArtW);
                            CantArtW.display();
                        }
                    } else if (selectedItem == 2) {
                        sf::RenderWindow MinStockW(sf::VideoMode(800, 600), "Cantidad total de artículos diferentes.");
                        MinStock MinStock(MinStockW.getSize().x, MinStockW.getSize().y);
                        // The event loop for the new window
                        while (MinStockW.isOpen()) {
                            sf::Event event;
                            while (MinStockW.pollEvent(event)) {
                                if (event.key.code == sf::Keyboard::Escape) {
                                    MinStockW.close();
                                }
                                // Handle other events specific to this window
                            }

                            MinStockW.clear();
                            // Draw and update the contents of this window

                            MinStockW.draw(background);
                            MinStock.draw(MinStockW);
                            MinStockW.display();
                        }

                    } else if (selectedItem == 3) {
                        MENU.close();
                    }
                }
            }
        }

        MENU.clear();
        MENU.draw(background);
        mainMenu.draw(MENU);
        MENU.display();


        std::cout<<music.getStatus()<<std::endl;
    }

    // Stop the music when it's no longer needed
    music.stop();

    return 0;
}
