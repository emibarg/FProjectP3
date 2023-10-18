//
// Created by emi on 10/17/23.
//

#ifndef FPROJECTP3_MAINMENU_H
#define FPROJECTP3_MAINMENU_H
#include <SFML/Graphics.hpp>
#include <iostream>
#define max_main_menu 3
class mainMenu {
public:
    mainMenu(float width, float height);
    void draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    int mainMenuPressed(){return mainMenuSelected;};
    ~mainMenu();
private:
    int mainMenuSelected;
    sf::Font font;
    sf::Text mainMenuText[3];

};





#endif //FPROJECTP3_MAINMENU_H
