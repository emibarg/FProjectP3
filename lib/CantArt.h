//
// Created by Emiliano Barg on 18/10/2023.
//

#ifndef FPROJECTP3_CANTART_H
#define FPROJECTP3_CANTART_H
#define x_axis 150
#define y_axis 200
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
class CantArt {
public:
    CantArt(float width, float height);
    void draw(sf::RenderWindow &window);
    std::string text;
    ~CantArt();
private:
    sf::SoundBuffer CantArtS;
    sf::Sound CantArtSound;
    sf::Font font;
    sf::Text CantArtText;

};

#endif //FPROJECTP3_CANTART_H
