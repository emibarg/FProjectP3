//
// Created by Emiliano Barg on 29/10/2023.
//

#ifndef FPROJECTP3_MINSTOCKDEPOSITO_H
#define FPROJECTP3_MINSTOCKDEPOSITO_H
#include "Producto.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
class MinStockDeposito {
public:
    MinStockDeposito(float width, float height,std::vector<Producto>items,int dep, int n);
    ~MinStockDeposito();
private:
    sf::Text userInputText;
    std::string userInputString;
    sf::SoundBuffer MinStockDepS;
    sf::Sound MinStockDepSound;
    sf::Font font;


};
#endif //FPROJECTP3_MINSTOCKDEPOSITO_H
