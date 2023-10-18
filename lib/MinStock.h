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
class MinStock {
public:
    MinStock(float width, float height);
    void draw(sf::RenderWindow &window);
    std::string text;
    ~MinStock();

private:
    sf::SoundBuffer MinStockS;
    sf::Sound MinStockSound;
    sf::Font font;
    sf::Text MinStockText;
    sf::Text MinStockList[listArtSize];

};

#endif //FPROJECTP3_MINSTOCK_H
