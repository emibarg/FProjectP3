//
// Created by emi on 10/17/23.
//

#ifndef FPROJECTP3_MAINMENU_H
#define FPROJECTP3_MAINMENU_H
#include <SFML/Graphics.hpp>
#include <iostream>
class mainMenu {
public:
    mainMenu(float width, float height);
    void draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    int mainMenuPressed();
    ~mainMenu();
private:
    int mainMenuSelected;
    sf::Font font;
    sf::Text mainMenuText[3];

};





#endif //FPROJECTP3_MAINMENU_H
