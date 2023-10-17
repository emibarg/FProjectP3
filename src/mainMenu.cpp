//
// Created by emi on 10/17/23.
//
#include "../lib/mainMenu.h"
mainMenu::mainMenu(float width, float height) {
    if(!font.loadFromFile("../fonts/a-charming-font/Achafexp.ttf")){
        std::cout << "Error loading font" << std::endl;
    }
    mainMenuText[0].setFont(font);
    mainMenuText[0].setFillColor(sf::Color::Red);
    mainMenuText[0].setString("Cantidad total de artículos diferentes.");
    mainMenuText[0].setPosition(400,200);

    mainMenuText[1].setFont(font);
    mainMenuText[1].setFillColor(sf::Color::White);
    mainMenuText[1].setString("Cantidad total de artículos.");
    mainMenuText[1].setPosition(400,300);

    mainMenuText[2].setFont(font);
    mainMenuText[2].setFillColor(sf::Color::White);
    mainMenuText[2].setString("Salir");
    mainMenuText[2].setPosition(400,400);

    mainMenuSelected = -1;

}
mainMenu::~mainMenu() {}
void mainMenu::draw(sf::RenderWindow &window) {
    for(int i = 0; i < 3; i++){
        window.draw(mainMenuText[i]);
    }
}
void mainMenu::MoveUp() {
    if(mainMenuSelected - 1 >= -1){
        mainMenuText[mainMenuSelected].setFillColor(sf::Color::White);
        mainMenuSelected--;
        if(mainMenuSelected == -1){
            mainMenuSelected = 2;
        }
        mainMenuText[mainMenuSelected].setFillColor(sf::Color::Red);
    }
}
void mainMenu::MoveDown() {
    if(mainMenuSelected + 1 <= 3){
        mainMenuText[mainMenuSelected].setFillColor(sf::Color::White);
        mainMenuSelected++;
        if(mainMenuSelected == 3){
            mainMenuSelected = 0;
        }
        mainMenuText[mainMenuSelected].setFillColor(sf::Color::Red);
    }
}
int mainMenu::mainMenuPressed() {
    return mainMenuSelected;
}

