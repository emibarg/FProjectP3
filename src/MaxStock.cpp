//
// Created by Emiliano Barg on 24/10/2023.
//
#include <iostream>
#include "../lib/MaxStock.h"
#include <SFML/Graphics.hpp>
MaxStock::MaxStock(float width, float height,std::vector<Producto>items,int n) {
    MaxStockS.loadFromFile("../music/MinStockS.wav");
    MaxStockSound.setBuffer(MaxStockS);
    MaxStockSound.setVolume(100);
    MaxStockSound.play();
    sf::RectangleShape background(sf::Vector2f(800.0f, 600.0f));
    sf::Texture mainTexture;
    mainTexture.loadFromFile("../background/demonwpp.jpg");
    background.setTexture(&mainTexture);

    std::vector<std::string> artList;

    if(!font.loadFromFile("../fonts/a-charming-font/Achafexp.ttf")){
        std::cout << "Error loading font" << std::endl;
    }


    // Now, you can create a new window to display the list of items.
    sf::RenderWindow itemListWindow( sf::VideoMode(800, 600), "Min Stock Items");
    itemListWindow.draw(background);

    sf::Text itemListText;
    itemListText.setFont(font);
    itemListText.setFillColor(sf::Color::White);
    itemListText.setCharacterSize(25);

    // Prepare the text to display the items.
    std::string itemListString = "Lista de items con mas de " + std::to_string(n) + ":\n";
    // Append the items from minStockItems to itemListString.
    for (int i = 0; i < items.size(); i++) {
        itemListString += items[i].getNombre() + "\n";
    }
    itemListText.setString(itemListString);

    while (itemListWindow.isOpen()) {
        sf::Event itemListEvent;
        while (itemListWindow.pollEvent(itemListEvent)) {
            if (itemListEvent.type == sf::Event::Closed) {
                itemListWindow.close();
            }
        }
        itemListWindow.clear();
        itemListWindow.draw(background);
        itemListWindow.draw(itemListText);
        itemListWindow.display();
    }
}




MaxStock::~MaxStock() {}