//
// Created by emi on 10/17/23.
//

// Incluye los encabezados necesarios para el programa
#include "../lib/mainMenu.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "../lib/CantArtDif.h"
#include "../lib/CantArt.h"
#include "../lib/MinStock.h"
#include "../lib/Producto.h"
#include "../lib/Gestor.h"
#include "../lib/MaxStock.h"

int main() {
    // Crea un objeto Gestor y carga datos desde un archivo CSV
    Gestor gestor("../assets/Inventariado Fisico2.csv");
    gestor.leerArchivo();

    // Crea una ventana de SFML llamada MENU
    sf::RenderWindow MENU(sf::VideoMode(800, 600), "Menu", sf::Style::Default);

    // Crea un objeto mainMenu que representa el menú principal
    mainMenu mainMenu(MENU.getSize().x, MENU.getSize().y);

    // Inicializa el fondo de la ventana
    sf::RectangleShape background(sf::Vector2f(800.0f, 600.0f));
    sf::Texture mainTexture;
    //Fuente
    sf::Font fuente;
    if (!fuente.loadFromFile("../fonts/a-charming-font/Achafexp.ttf")) {
        std::cout << "Error loading font" << std::endl;
    }
    // Carga la textura del fondo desde un archivo
    if (!mainTexture.loadFromFile("../background/demonwpp.jpg")) {
        std::cerr << "Failed to load background texture!" << std::endl;
        return 1;
    }
    background.setTexture(&mainTexture);

    // Inicializa la música de fondo
    sf::Music music;
    if (!music.openFromFile("../music/doom.wav")) {
        std::cerr << "Failed to load music file!" << std::endl;
        return 1;
    }
    music.setVolume(15);
    music.play();

    // Bucle principal del programa
    while (MENU.isOpen()) {
        sf::Event event;
        while (MENU.pollEvent(event)) {
            // Maneja eventos de ventana
            if (event.type == sf::Event::Closed) {
                MENU.close();
            }

            if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::Up) {
                    mainMenu.MoveUp();
                } else if (event.key.code == sf::Keyboard::Down) {
                    mainMenu.MoveDown();
                } else if (event.key.code == sf::Keyboard::Return) {
                    // Obtiene el elemento seleccionado del menú principal
                    int selectedItem = mainMenu.mainMenuPressed();

                    if (selectedItem == 0) {
                        // Handle "Cantidad total de artículos diferentes." menu option
                        // Crea una nueva ventana para mostrar la cantidad de artículos diferentes
                        sf::RenderWindow CantArtDifW(sf::VideoMode(800, 600), "Cantidad total de artículos diferentes.");
                        CantArtDiff CantArtDiff(CantArtDifW.getSize().x, CantArtDifW.getSize().y, std::to_string(gestor.getTotalArtDif()));
                        // Bucle de eventos para la nueva ventana
                        while (CantArtDifW.isOpen()) {
                            sf::Event event;
                            while (CantArtDifW.pollEvent(event)) {
                                if (event.key.code == sf::Keyboard::Escape) {
                                    CantArtDifW.close();
                                }
                                // Maneja otros eventos específicos de esta ventana
                            }

                            CantArtDifW.clear();
                            CantArtDifW.draw(background);
                            CantArtDiff.draw(CantArtDifW);
                            CantArtDifW.display();
                        }
                    } else if (selectedItem == 1) {
                        // Handle "Cantidad total de artículos." menu option
                        // Crea una nueva ventana para mostrar la cantidad total de artículos
                        sf::RenderWindow CantArtW(sf::VideoMode(800, 600), "Cantidad total de artículos.");
                        CantArt CantArt(CantArtW.getSize().x, CantArtW.getSize().y, std::to_string(gestor.getTotalArt()));
                        // Bucle de eventos para la nueva ventana
                        while (CantArtW.isOpen()) {
                            sf::Event event;
                            while (CantArtW.pollEvent(event)) {
                                if (event.key.code == sf::Keyboard::Escape) {
                                    CantArtW.close();
                                }
                                // Maneja otros eventos específicos de esta ventana
                            }

                            CantArtW.clear();
                            CantArtW.draw(background);
                            CantArt.draw(CantArtW);
                            CantArtW.display();
                        }
                    } else if (selectedItem == 2) {
                        // Handle "Cantidad mínima de stock" menu option
                        // Create an SFML text input field for 'n'.
                        sf::Text inputText;
                        sf::String inputString;
                        inputText.setFont(fuente);
                        inputText.setCharacterSize(70);
                        inputText.setPosition(355, 100);
                        //Text for button
                        sf::Text submitText;
                        submitText.setFont(fuente);
                        submitText.setFillColor(sf::Color::White);
                        submitText.setString("Submit");
                        submitText.setCharacterSize(40);
                        submitText.setPosition(352, 195);
                        // Create a submit button.
                        sf::RectangleShape submitButton(sf::Vector2f(100, 40));
                        submitButton.setPosition(350, 200);
                        submitButton.setFillColor(sf::Color::Black);
                        submitButton.setOutlineColor(sf::Color::White);
                        submitButton.setOutlineThickness(2);


                        sf::RenderWindow window(sf::VideoMode(800, 600), "MinStock");
                        window.clear();

                        while (window.isOpen()) {
                            window.draw(background);
                            window.draw(inputText);
                            window.draw(submitButton);
                            window.draw(submitText);
                            window.display();
                            sf::Event event;
                            while (window.pollEvent(event)) {
                                if (event.type == sf::Event::Closed) {
                                    window.close();
                                }

                                if (event.type == sf::Event::TextEntered) {
                                    if (event.text.unicode < 128) {
                                        inputString += static_cast<char>(event.text.unicode);
                                        inputText.setString(inputString);
                                    }
                                }

                                if (event.type == sf::Event::MouseButtonPressed) {
                                    if (submitButton.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                                        // The submit button was clicked. Convert inputString to an integer and call minstock(n).
                                        int n = std::stoi(inputString.toAnsiString());
                                        // Call your minstock(n) function and store the results in minStockItems.
                                        std::vector<Producto> items = gestor.min_stock(n);
                                        std::cout<<items.size()<<std::endl;




                                        // Create a new window for "Cantidad mínima de stock"
                                        sf::RenderWindow MinStockW(sf::VideoMode(800, 600), "Cantidad mínima de stock");
                                        MinStock MinStock(MinStockW.getSize().x, MinStockW.getSize().y, items, n);
                                        items.clear();

                                    }
                                }
                            }
                        }

                    }
                    else if (selectedItem ==3){
                        // Handle "Cantidad mínima de stock" menu option
                        // Create an SFML text input field for 'n'.
                        sf::Text inputText;
                        sf::String inputString;
                        inputText.setFont(fuente);
                        inputText.setCharacterSize(70);
                        inputText.setPosition(355, 100);
                        //Text for button
                        sf::Text submitText;
                        submitText.setFont(fuente);
                        submitText.setFillColor(sf::Color::White);
                        submitText.setString("Submit");
                        submitText.setCharacterSize(40);
                        submitText.setPosition(352, 195);
                        // Create a submit button.
                        sf::RectangleShape submitButton(sf::Vector2f(100, 40));
                        submitButton.setPosition(350, 200);
                        submitButton.setFillColor(sf::Color::Black);
                        submitButton.setOutlineColor(sf::Color::White);
                        submitButton.setOutlineThickness(2);

                        sf::RenderWindow window(sf::VideoMode(800, 600), "MaxStock");
                        window.clear();
                        while (window.isOpen()) {
                            window.draw(background);
                            window.draw(inputText);
                            window.draw(submitButton);
                            window.draw(submitText);
                            window.display();
                            sf::Event event;
                            while (window.pollEvent(event)) {
                                if (event.type == sf::Event::Closed) {
                                    window.close();
                                }

                                if (event.type == sf::Event::TextEntered) {
                                    if (event.text.unicode < 128) {
                                        inputString += static_cast<char>(event.text.unicode);
                                        inputText.setString(inputString);
                                    }
                                }

                                if (event.type == sf::Event::MouseButtonPressed) {
                                    if (submitButton.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                                        // The submit button was clicked. Convert inputString to an integer and call minstock(n).
                                        int n = std::stoi(inputString.toAnsiString());
                                        // Call your minstock(n) function and store the results in minStockItems.
                                        std::vector<Producto> items = gestor.max_stock(n);
                                        std::cout<<items.size()<<std::endl;




                                        // Create a new window for "Cantidad mínima de stock"
                                        sf::RenderWindow MaxStockW(sf::VideoMode(800, 600), "Cantidad mínima de stock");
                                        MaxStock MaxStock(MaxStockW.getSize().x, MaxStockW.getSize().y, items, n);
                                        items.clear();

                                    }
                                }
                            }
                        }
                    }
                    else if (selectedItem == 4) {
                        MENU.close(); // Cierra la ventana principal para salir del programa
                    }
                }
            }
        }

        MENU.clear();
        MENU.draw(background);
        mainMenu.draw(MENU);
        MENU.display();
    }

    // Detiene la música cuando ya no es necesaria
    music.stop();

    return 0;
}
