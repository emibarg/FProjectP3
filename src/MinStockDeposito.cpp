//
// Created by Emiliano Barg on 29/10/2023.
//
#include "../lib/MinStockDeposito.h"
#include "../lib/Producto.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>

MinStockDeposito::MinStockDeposito(float width, float height, std::vector<Producto> items, int dep, int n) {
    MinStockDepS.loadFromFile("../music/MinStockDepS.wav");
    MinStockDepSound.setBuffer(MinStockDepS);
    MinStockDepSound.setVolume(100);
    MinStockDepSound.play();
    font.loadFromFile("../fonts/a-charming-font/Achafexp.ttf");

    sf::RectangleShape background(sf::Vector2f(800.0f, 600.0f));
    sf::Texture mainTexture;
    mainTexture.loadFromFile("../background/demonwpp.jpg");
    background.setTexture(&mainTexture);

    std::vector<std::string> artList;

    if(!font.loadFromFile("../fonts/a-charming-font/Achafexp.ttf")){
        std::cout << "Error loading font" << std::endl;
    }
    //Needs scrolling, list is too large.
    //The way to do it is to create a window with a view, and then move the view.
    //The view is like a camera, and you can move it around.
    //The view is a rectangle, and you can move it around.
    sf::View view(sf::FloatRect(0, 0, 800, 600));
    view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));


    // Now, you can create a new window to display the list of items.
    sf::RenderWindow itemListWindow( sf::VideoMode(800, 600), "Max Stock Items");
    itemListWindow.draw(background);

    sf::Text itemListText;
    itemListText.setFont(font);
    itemListText.setFillColor(sf::Color::White);
    itemListText.setCharacterSize(25);

    // Prepare the text to display the items.
    std::string itemListString = "Lista de items con menos de " + std::to_string(n) + " en el deposito " + std::to_string(dep) + ":\n";
    // Append the items from minStockItems to itemListString.
    for (int i = 0; i < items.size(); i++) {
        itemListString += items[i].getNombre() + "\n";
    }
    itemListText.setString(itemListString);
    sf::FloatRect textRect = itemListText.getLocalBounds();
    while (itemListWindow.isOpen()) {
        sf::Event itemListEvent;
        while (itemListWindow.pollEvent(itemListEvent)) {
            if (itemListEvent.type == sf::Event::Closed) {
                itemListWindow.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                itemListWindow.close();
            }
        }

        // Define the scrolling speed
        float scrollSpeed = 1.5f; // Adjust the value to control scrolling speed

        // Check for keyboard input to scroll the view up
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && view.getCenter().y > view.getSize().y / 2) {
            view.move(0, -scrollSpeed);
        }

        // Check for keyboard input to scroll the view down
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && view.getCenter().y < textRect.height - view.getSize().y / 2) {
            view.move(0, scrollSpeed);
        }

        itemListWindow.clear();
        itemListWindow.setView(view);
        itemListWindow.draw(background);
        itemListWindow.draw(itemListText);
        itemListWindow.display();
    }
};
MinStockDeposito::~MinStockDeposito(){};