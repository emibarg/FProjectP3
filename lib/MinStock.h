//
// Created by Emiliano Barg on 18/10/2023.
//

#ifndef FPROJECTP3_MINSTOCK_H
#define FPROJECTP3_MINSTOCK_H
#define x_axis 150
#define y_axis 200
#define listArtSize 3
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Producto.h"
class MinStock {
public:
    MinStock(float width, float height,std::vector<Producto>items, int n);

    ~MinStock();


private:
    sf::Text userInputText;
    std::string userInputString;
    sf::SoundBuffer MinStockS;
    sf::Sound MinStockSound;
    sf::Font font;



};

#endif //FPROJECTP3_MINSTOCK_H
