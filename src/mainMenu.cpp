//
// Created by emi on 10/17/23.
//

#include "../lib/mainMenu.h"

mainMenu::mainMenu(float width, float height) {
    // Constructor de la clase mainMenu

    if (!font.loadFromFile("../fonts/a-charming-font/Achafexp.ttf")) {
        std::cout << "Error loading font" << std::endl;
    }

    int characterSize = 60;
    std::string menuItems[] = {
            "Cantidad total de articulos diferentes",
            "Cantidad total de articulos",
            "Minimo de stock",
            "Salir"
    };

    // Configura las opciones del menú y sus posiciones
    for (int i = 0; i < max_main_menu; i++) {
        mainMenuText[i].setFont(font);
        mainMenuText[i].setCharacterSize(characterSize);
        mainMenuText[i].setString(menuItems[i]);
        mainMenuText[i].setPosition(x_axis, y_axis + i * 100);
    }

    // Establece el color del texto para resaltar la primera opción
    mainMenuText[0].setFillColor(sf::Color::Red);
    mainMenuText[1].setFillColor(sf::Color::White);
    mainMenuText[2].setFillColor(sf::Color::White);
    mainMenuText[3].setFillColor(sf::Color::White);

    mainMenuSelected = 0;  // Inicializa la opción seleccionada como la primera.
}

mainMenu::~mainMenu() {
    // Destructor de la clase mainMenu
}

void mainMenu::draw(sf::RenderWindow &window) {
    // Método para dibujar el menú en la ventana

    for (int i = 0; i < max_main_menu; i++) {
        window.draw(mainMenuText[i]);
    }
}

void mainMenu::MoveUp() {
    // Método para mover la selección hacia arriba en el menú

    mainMenuText[mainMenuSelected].setFillColor(sf::Color::White);

    if (mainMenuSelected - 1 >= 0) {
        mainMenuSelected--;
    } else {
        mainMenuSelected = max_main_menu - 1;  // Vuelve a la última opción si ya está en la primera.
    }

    mainMenuText[mainMenuSelected].setFillColor(sf::Color::Red);
}

void mainMenu::MoveDown() {
    // Método para mover la selección hacia abajo en el menú

    mainMenuText[mainMenuSelected].setFillColor(sf::Color::White);

    if (mainMenuSelected + 1 < max_main_menu) {
        mainMenuSelected++;
    } else {
        mainMenuSelected = 0;  // Vuelve a la primera opción si ya está en la última.
    }

    mainMenuText[mainMenuSelected].setFillColor(sf::Color::Red);
}
