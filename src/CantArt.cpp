//
// Created by Emiliano Barg on 18/10/2023.
//
#include <iostream>
#include "../lib/CantArt.h"
#include <SFML/Graphics.hpp>
CantArt::CantArt(float width, float height, std::string text) {
    CantArtS.loadFromFile("../music/CantArt.wav");
    CantArtSound.setBuffer(CantArtS);
    CantArtSound.setVolume(100);
    CantArtSound.play();

    text = text;
    if(!font.loadFromFile("../fonts/a-charming-font/Achafexp.ttf")){
        std::cout << "Error loading font" << std::endl;
    }
    CantArtText.setFont(font);
    CantArtText.setFillColor(sf::Color::White);
    CantArtText.setString("Cantidad total de articulos:" + text);
    CantArtText.setCharacterSize(60);
    CantArtText.setPosition(x_axis,y_axis);
}
CantArt::~CantArt() {}

void CantArt::draw(sf::RenderWindow &window) {window.draw(CantArtText);}