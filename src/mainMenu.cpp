//
// Created by emi on 10/17/23.
//
#include "../lib/mainMenu.h"
mainMenu::mainMenu(float width, float height) {
    if(!font.loadFromFile("../fonts/a-charming-font/Achafexp.ttf")){
        std::cout << "Error loading font" << std::endl;
    }
    int characterSize = 60;
    std::string menuItems[] = {
            "Cantidad total de articulos diferentes",
            "Cantidad total de articulos",
            "Minimo de stock",
            "Salir"
    };

    for (int i = 0; i < max_main_menu; i++) {
        mainMenuText[i].setFont(font);
        mainMenuText[i].setCharacterSize(characterSize);
        mainMenuText[i].setString(menuItems[i]);
        mainMenuText[i].setPosition(x_axis, y_axis + i * 100);
    }
        mainMenuText[0].setFillColor(sf::Color::Red);
        mainMenuText[1].setFillColor(sf::Color::White);
        mainMenuText[2].setFillColor(sf::Color::White);
        mainMenuText[3].setFillColor(sf::Color::White);

        mainMenuSelected = 0;

}
mainMenu::~mainMenu() {}
void mainMenu::draw(sf::RenderWindow &window) {
    for(int i = 0; i < max_main_menu; i++){
        window.draw(mainMenuText[i]);
    }
}
void mainMenu::MoveUp() {
    mainMenuText[mainMenuSelected].setFillColor(sf::Color::White);

    if (mainMenuSelected - 1 >= 0) {
        mainMenuSelected--;
    } else {
        mainMenuSelected = max_main_menu - 1;  // Wrap around to the last item.
    }

    mainMenuText[mainMenuSelected].setFillColor(sf::Color::Red);
}


void mainMenu::MoveDown() {
    mainMenuText[mainMenuSelected].setFillColor(sf::Color::White);

    if (mainMenuSelected + 1 < max_main_menu) {
        mainMenuSelected++;
    } else {
        mainMenuSelected = 0;  // Wrap around to the first item.
    }

    mainMenuText[mainMenuSelected].setFillColor(sf::Color::Red);
}


