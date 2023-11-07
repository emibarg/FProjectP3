//
// Created by emi on 10/17/23.
//

#ifndef FPROJECTP3_MAINMENU_H
#define FPROJECTP3_MAINMENU_H
#include <SFML/Graphics.hpp>
#include <iostream>
#define x_axis 150
#define y_axis 50
#define max_main_menu 8
class mainMenu {
public:
    mainMenu(float width, float height);
    void draw(sf::RenderWindow &window); 
    void MoveUp();
    void MoveDown();
    int mainMenuPressed()const {return mainMenuSelected;};
    ~mainMenu();
private:
    int mainMenuSelected;
    sf::Font font;
    sf::Text mainMenuText[max_main_menu];

};





#endif //FPROJECTP3_MAINMENU_H
