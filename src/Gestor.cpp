//
// Created by emi on 10/19/23.
//
#include "../lib/Gestor.h"

Gestor::Gestor() {
    total_art_dif_ = 0;
    total_art_ = 0;

}
Gestor::Gestor(std::string ubicacion_archivo){
    total_art_dif_ = 0;
    total_art_ = 0;
    setUbicacionArchivo(ubicacion_archivo);
}

Producto Gestor::generarProducto(std::string nombre, std::string codigo, std::vector<int> depositos) {
    Producto producto(nombre, codigo, &depositos);
    return producto;
}
Gestor::~Gestor() {}

void Gestor::cargarMinStock(Producto producto, int n) {
    m_min_stock.push(producto.getDepositos().size());
}

void Gestor::cargarMapa(std::string nombre, Producto producto) {
    m_productos.insert({nombre, producto});
}
//Utiliza el archivo para almacenar los datos en las diversas estructuras de datos
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

    bool firstLine = true;  // Flag to skip the first line

    while (getline(m_archivo, line)) {
        if (firstLine) {
            firstLine = false;
            continue; // Skip the first line
        }

        std::stringstream ss(line);
        std::string token;
        int i = 0;

        while (getline(ss, token, ';')) {
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
