//
// Created by emi on 10/17/23.
//

// Incluye los encabezados necesarios para el programa
#include "../lib/mainMenu.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include "../lib/CantArtDif.h"
#include "../lib/CantArt.h"
#include "../lib/MinStock.h"
#include "../lib/Producto.h"
#include "../lib/Gestor.h"

int main(int argc, char** argv) {

    std::string archivo = argv[argc - 1];

    // Crea un objeto Gestor y carga datos desde un archivo CSV
    Gestor gestor("../assets/Inventariado Fisico2.csv");
    gestor.leerArchivo();


    for (int i = 0; i < argc; ++i) {
        std::cout<<"Argumento "<<i<<": "<<argv[i]<<std::endl;
    }

    /*
     * Crea el gestor con el comando.
     *
     * Gestor gestor(archivo);
     *
     */

    if(argc > 2) // Si hay mas argumentos que solo la main y el archivo
    {
        std::string comando = argv[1];

        if(comando == "-min_stock"){ // Armar vector ordenado de menor a mayor

        }else if(comando == "-max_Stock"){ // Armar vector ordenado de mayor a menor

        }else{ // Armar el hashmap
            gestor.leerArchivo();

            if(comando == "-total_art_dif")
            {
                // Total art dif.
                std::cout<<"Cantidad de articulos diferentes: "<<gestor.getTotalArtDif()<<std::endl;
                return 0;
            }

            if(comando == "-total_art")
            {
                // Total art:
                std::cout<<"Cantidad de articulos: "<<gestor.getTotalArt()<<std::endl;
                return 0;
            }

            if(comando == "-stock")
            {
                if(argc == 4){


                    std::string nombre = argv[2];

                    nombre = gestor.reemplazarN(nombre);

                    std::cout<<"Stock de "<<nombre<<": "<<gestor.stock(nombre)<<std::endl;
                    return 0;

                }else if(argc == 5) {
                    std::string nombre = argv[2];
                    int deposito = std::stoi(argv[3]);

                    std::cout << "Stock de " << nombre << " en el deposito " << deposito << ": "
                              << gestor.stock(nombre, deposito) << std::endl;
                    return 0;
                }
            }
            std::cout<<"COMANDO INVALIDO"<<std::endl;
            return 0;
        }
    }else{ // Interfaz grafica



    }





    // Crea una ventana de SFML llamada MENU
    sf::RenderWindow MENU(sf::VideoMode(800, 600), "Menu", sf::Style::Default);

    // Crea un objeto mainMenu que representa el menú principal
    mainMenu mainMenu(MENU.getSize().x, MENU.getSize().y);

    // Inicializa el fondo de la ventana
    sf::RectangleShape background(sf::Vector2f(800.0f, 600.0f));
    sf::Texture mainTexture;

    // Carga la textura del fondo desde un archivo
    if (!mainTexture.loadFromFile("../background/demonwpp.jpg")) {
        std::cerr << "Failed to load background texture!" << std::endl;
        return 1;
    }
    background.setTexture(&mainTexture);

    // Inicializa la música de fondo
    sf::Music music;
    if (!music.openFromFile("../music/doom.wav")) {
        std::cerr << "Failed to load music file!" << std::endl;
        return 1;
    }
    music.setVolume(15);
    music.play();

    // Bucle principal del programa
    while (MENU.isOpen()) {
        sf::Event event;
        while (MENU.pollEvent(event)) {
            // Maneja eventos de ventana
            if (event.type == sf::Event::Closed) {
                MENU.close();
            }

            if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::Up) {
                    mainMenu.MoveUp();
                } else if (event.key.code == sf::Keyboard::Down) {
                    mainMenu.MoveDown();
                } else if (event.key.code == sf::Keyboard::Return) {
                    // Obtiene el elemento seleccionado del menú principal
                    int selectedItem = mainMenu.mainMenuPressed();

                    if (selectedItem == 0) {
                        // Handle "Cantidad total de artículos diferentes." menu option
                        // Crea una nueva ventana para mostrar la cantidad de artículos diferentes
                        sf::RenderWindow CantArtDifW(sf::VideoMode(800, 600), "Cantidad total de artículos diferentes.");
                        CantArtDiff CantArtDiff(CantArtDifW.getSize().x, CantArtDifW.getSize().y, std::to_string(gestor.getTotalArtDif()));
                        // Bucle de eventos para la nueva ventana
                        while (CantArtDifW.isOpen()) {
                            sf::Event event;
                            while (CantArtDifW.pollEvent(event)) {
                                if (event.key.code == sf::Keyboard::Escape) {
                                    CantArtDifW.close();
                                }
                                // Maneja otros eventos específicos de esta ventana
                            }

                            CantArtDifW.clear();
                            CantArtDifW.draw(background);
                            CantArtDiff.draw(CantArtDifW);
                            CantArtDifW.display();
                        }
                    } else if (selectedItem == 1) {
                        // Handle "Cantidad total de artículos." menu option
                        // Crea una nueva ventana para mostrar la cantidad total de artículos
                        sf::RenderWindow CantArtW(sf::VideoMode(800, 600), "Cantidad total de artículos.");
                        CantArt CantArt(CantArtW.getSize().x, CantArtW.getSize().y, std::to_string(gestor.getTotalArt()));
                        // Bucle de eventos para la nueva ventana
                        while (CantArtW.isOpen()) {
                            sf::Event event;
                            while (CantArtW.pollEvent(event)) {
                                if (event.key.code == sf::Keyboard::Escape) {
                                    CantArtW.close();
                                }
                                // Maneja otros eventos específicos de esta ventana
                            }

                            CantArtW.clear();
                            CantArtW.draw(background);
                            CantArt.draw(CantArtW);
                            CantArtW.display();
                        }
                    } else if (selectedItem == 2) {
                        // Handle "Cantidad mínima de stock" menu option
                        sf::RenderWindow MinStockW(sf::VideoMode(800, 600), "Cantidad mínima de stock");
                        MinStock MinStock(MinStockW.getSize().x, MinStockW.getSize().y);

                        // Bucle de eventos para la nueva ventana
                        while (MinStockW.isOpen()) {
                            sf::Event event;
                            while (MinStockW.pollEvent(event)) {
                                if (event.key.code == sf::Keyboard::Escape) {
                                    MinStockW.close();
                                }
                                // Maneja otros eventos específicos de esta ventana
                            }

                            MinStock.update(MinStockW); // Llama al método update para manejar la entrada del usuario
                            MinStockW.clear();
                            MinStockW.draw(background);
                            MinStock.draw(MinStockW); // Llama al método draw para mostrar información de MinStock
                            MinStockW.display();
                        }
                    } else if (selectedItem == 3) {
                        MENU.close(); // Cierra la ventana principal para salir del programa
                    }
                }
            }
        }

        MENU.clear();
        MENU.draw(background);
        mainMenu.draw(MENU);
        MENU.display();
    }

    // Detiene la música cuando ya no es necesaria
    music.stop();

    return 0;
}
