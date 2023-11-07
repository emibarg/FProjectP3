//
// Created by Emiliano Barg on 18/10/2023.
//

#ifndef FPROJECTP3_CANTARTDIF_H
#define FPROJECTP3_CANTARTDIF_H
#define x_axis 150
#define y_axis 200
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class CantArtDiff {
public:
    CantArtDiff(float width, float height, std::string text);
    void draw(sf::RenderWindow &window);
    std::string text;
    ~CantArtDiff();
private:
    sf::SoundBuffer CantArtDifS;
    sf::Sound CantArtDifSound;
    sf::Font font;
    sf::Text CantArtDifText;

};


#endif //FPROJECTP3_CANTARTDIF_H
