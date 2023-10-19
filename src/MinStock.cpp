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
    std::string artList[listArtSize] = {"Queso", "Pan", "Chauchas"};
    text = "7";
    if(!font.loadFromFile("../fonts/a-charming-font/Achafexp.ttf")){
        std::cout << "Error loading font" << std::endl;
    }
    MinStockText.setFont(font);
    MinStockText.setFillColor(sf::Color::White);
    MinStockText.setString("Listado de articulos en minimo de stock: ");
    MinStockText.setCharacterSize(characterSize);
    MinStockText.setPosition(100,50);
    for (int i = 0; i < listArtSize; i++) {
        MinStockList[i].setFont(font);
        MinStockList[i].setCharacterSize(characterSize);
        MinStockList[i].setString(artList[i]);
        MinStockList[i].setPosition(x_axis, y_axis + i * 100);
        MinStockList[i].setFillColor(sf::Color::White);
    }
}
MinStock::~MinStock() {}

void MinStock::draw(sf::RenderWindow &window) {window.draw(MinStockText);}
