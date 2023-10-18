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
    mainMenuText[0].setCharacterSize(60);
    mainMenuText[0].setString("Cantidad total de articulos diferentes.");
    mainMenuText[0].setPosition(200,200);

    mainMenuText[1].setFont(font);
    mainMenuText[1].setFillColor(sf::Color::White);
    mainMenuText[1].setString("Cantidad total de articulos.");
    mainMenuText[1].setCharacterSize(60);
    mainMenuText[1].setPosition(200,300);

    mainMenuText[2].setFont(font);
    mainMenuText[2].setFillColor(sf::Color::White);
    mainMenuText[2].setString("Salir");
    mainMenuText[2].setCharacterSize(60);
    mainMenuText[2].setPosition(200,400);

    mainMenuSelected = 0;

}
mainMenu::~mainMenu() {}
void mainMenu::draw(sf::RenderWindow &window) {
    for(int i = 0; i < max_main_menu; i++){
        window.draw(mainMenuText[i]);
    }
}
void mainMenu::MoveUp() {
    if(mainMenuSelected - 1 >= 0){
        mainMenuText[mainMenuSelected].setFillColor(sf::Color::White);
        mainMenuSelected--;
        if(mainMenuSelected == -1){
            mainMenuSelected = 2;
        } else {
            mainMenuSelected = max_main_menu;  // Wrap around to the last item.
            mainMenuText[0].setFillColor(sf::Color::Red);
        }

        mainMenuText[mainMenuSelected].setFillColor(sf::Color::Red);

    }
}
void mainMenu::MoveDown() {
    if (mainMenuSelected + 1 < max_main_menu) {
        mainMenuText[mainMenuSelected].setFillColor(sf::Color::White);
        mainMenuSelected++;
        mainMenuText[mainMenuSelected].setFillColor(sf::Color::Red);
    }
        // Add an else condition to handle the case when you are already at the last item.
    else {
        mainMenuSelected = 0;  // Wrap around to the first item.
        mainMenuText[0].setFillColor(sf::Color::Red);
    }
}

