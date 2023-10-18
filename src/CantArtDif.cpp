//
// Created by Emiliano Barg on 18/10/2023.
//
#include <iostream>
#include "../lib/CantArtDif.h"
#include <SFML/Graphics.hpp>
CantArtDiff::CantArtDiff(float width, float height) {
    CantArtDifS.loadFromFile("../music/CantArtDifS.wav");
    CantArtDifSound.setBuffer(CantArtDifS);
    CantArtDifSound.setVolume(100);
    CantArtDifSound.play();

    text = "7";
    if(!font.loadFromFile("../fonts/a-charming-font/Achafexp.ttf")){
        std::cout << "Error loading font" << std::endl;
    }
    CantArtDifText.setFont(font);
    CantArtDifText.setFillColor(sf::Color::White);
    CantArtDifText.setString("Cantidad total de articulos diferentes: " + text);
    CantArtDifText.setCharacterSize(60);
    CantArtDifText.setPosition(x_axis,y_axis);
}
CantArtDiff::~CantArtDiff() {}

void CantArtDiff::draw(sf::RenderWindow &window) {window.draw(CantArtDifText);}