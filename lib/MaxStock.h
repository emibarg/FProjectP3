//
// Created by Emiliano Barg on 24/10/2023.
//

#ifndef FPROJECTP3_MAXSTOCK_H
#define FPROJECTP3_MAXSTOCK_H
#define x_axis 150
#define y_axis 200
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Producto.h"
class MaxStock {
public:
    MaxStock(float width, float height,std::vector<Producto>items, int n);

    ~MaxStock();


private:
    sf::Text userInputText;
    std::string userInputString;
    sf::SoundBuffer MaxStockS;
    sf::Sound MaxStockSound;
    sf::Font font;



};
#endif //FPROJECTP3_MAXSTOCK_H
