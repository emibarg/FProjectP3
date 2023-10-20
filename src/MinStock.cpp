//
// Created by Emiliano Barg on 18/10/2023.
//
#include <iostream>
#include "../lib/MinStock.h"
#include <SFML/Graphics.hpp>
MinStock::MinStock(float width, float height)  {
    MinStockS.loadFromFile("../music/MinStockS.wav");
    MinStockSound.setBuffer(MinStockS);
    MinStockSound.setVolume(100);
    MinStockSound.play();
    int characterSize = 60;
    std::vector<std::string> artList;
    artList.push_back("queso");
    artList.push_back("jamon");
    artList.push_back("pan");
    text = "7";
    if(!font.loadFromFile("../fonts/a-charming-font/Achafexp.ttf")){
        std::cout << "Error loading font" << std::endl;
    }
    MinStockText.setFont(font);
    MinStockText.setFillColor(sf::Color::White);
    MinStockText.setString("Listado de articulos en minimo de stock: ");
    MinStockText.setCharacterSize(characterSize);
    MinStockText.setPosition(x_axis,50);
    // Create an input text box for user input
    userInputText.setFont(font);
    userInputText.setFillColor(sf::Color::White);
    userInputText.setCharacterSize(characterSize);
    userInputText.setPosition(x_axis, 100); // Adjust the position as needed
    userInputString = "";

    for (int i = 0; i < artList.size(); ++i) {
        MinStockList[i].setFont(font);
        MinStockList[i].setCharacterSize(characterSize);
        MinStockList[i].setString(artList[i]);
        MinStockList[i].setPosition(x_axis, y_axis + i * 100);
        MinStockList[i].setFillColor(sf::Color::White);
    }
}
MinStock::~MinStock() {}
void MinStock::update(sf::RenderWindow &window) {
    // Handle user input
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::TextEntered) {
            if (event.text.unicode == 8 && userInputString.length() > 0) {
                // Backspace: remove the last character
                userInputString.pop_back();
            } else if (event.text.unicode >= 32 && event.text.unicode <= 126) {
                // Printable ASCII characters: add them to the input string
                userInputString += static_cast<char>(event.text.unicode);
            }
            userInputText.setString("Minimum Stock: " + userInputString);
        }
    }
}
void MinStock::draw(sf::RenderWindow &window) {window.draw(MinStockText);
    window.draw(userInputText);
for(int i = 0; i < listArtSize; i++){
    window.draw(MinStockList[i]);
}
    }
