//
// Created by emi on 10/19/23.
//
#include "../lib/Gestor.h"

// Constructor por defecto de la clase Gestor
Gestor::Gestor() {
    total_art_dif_ = 0;
    total_art_ = 0;
}

// Constructor con un parámetro que establece la ubicación del archivo
Gestor::Gestor(std::string ubicacion_archivo) {
    total_art_dif_ = 0;
    total_art_ = 0;
    setUbicacionArchivo(ubicacion_archivo);
}

// Método para generar un objeto Producto a partir de los parámetros y devolverlo
Producto Gestor::generarProducto(std::string nombre, std::string codigo, std::vector<int> depositos) {
    Producto producto(nombre, codigo, &depositos);
    return producto;
}

// Destructor de la clase Gestor
Gestor::~Gestor() {}

// Método para cargar la cantidad mínima de stock para un producto en la cola m_min_stock
void Gestor::cargarMinStock(Producto producto, int n) {
    m_min_stock.push(producto.getDepositos().size());
}

// Método para cargar un producto en el mapa m_productos
void Gestor::cargarMapa(std::string nombre, Producto producto) {
    m_productos.insert({nombre, producto});
}

// Método para leer datos desde un archivo y almacenarlos en las estructuras de datos
void Gestor::leerArchivo() {
    m_archivo.open(getUbicacionArchivo());

    if (!m_archivo.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        exit(1);
    }

    std::string line;
    std::string nombre;
    std::string codigo;
    std::vector<int> depositos;
    int sum_stock = 0;
    int columnas = 0;
    bool firstLine = true;  // Bandera para omitir la primera línea del archivo

    while (getline(m_archivo, line)) {
        if (firstLine) {
            firstLine = false;

            // Contar la cantidad de columnas
            std::stringstream SS(line);
            std::string relleno;
            while (getline(SS, relleno, ';')) {
                columnas++;
            }

            continue; // Omitir la primera línea
        }

        std::stringstream ss(line);
        std::string token;
        int i = 0;

        while (i<columnas) {
            getline(ss, token, ';');

            if (i == 1) {
                codigo = token;
            } else if (i == 2) {
                nombre = token;
            } else if (i > 2) {
                if (token.empty()) {
                    depositos.push_back(0);
                } else {
                    depositos.push_back(std::stoi(token));
                    sum_stock += std::stoi(token);
                }
            }
            i++;
        }

        Producto producto = generarProducto(nombre, codigo, depositos);
        cargarMapa(nombre, producto);
        depositos.clear();
    }

    setTotalArt(sum_stock);
    setTotalArtDif(m_productos.size());
}

int Gestor::stock(std::string nombre_articulo) {

    Producto n = m_productos[nombre_articulo]; // Busca en el Hash ese articulo

    std::vector<int> depositos_n = n.getDepositos(); // Accedemos a la lista de depositos

    // Sumamos todos los depositos
    int sum_stock = 0;
    for (int i = 0; i < depositos_n.size(); ++i) {
        sum_stock += depositos_n[i];
    }

    // Return sumatoria
    return sum_stock;
}

int Gestor::stock(std::string nombre_articulo, int deposito) {
    // Devuelve el stock de un producto en un depósito

    return m_productos[nombre_articulo].getDepositos()[deposito];
}