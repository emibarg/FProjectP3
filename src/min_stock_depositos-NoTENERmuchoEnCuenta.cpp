//
// Created by pc on 20/10/2023.
//

#include "../lib/min_stock_depositos-NoTENERmuchoEnCuenta.h"

#include <fstream>
#include <sstream>

MinStockDepositos::MinStockDepositos(std::string ubicacion_archivo) {
    std::ifstream archivo(ubicacion_archivo); // Abre el archivo
    std::string linea; // Variable para almacenar cada línea del archivo
    while (std::getline(archivo, linea)) { // Lee una línea
        std::stringstream ss(linea); // Lee la línea como una cadena de caracteres
        std::string grupo, codigo; // Variables para almacenar el grupo y el código del producto
        std::vector<int> depositos; // Vector para almacenar los depósitos del producto
        std::string deposito; // Variable para almacenar cada depósito
        std::getline(ss, grupo, ',');
        std::getline(ss, codigo, ',');
        while (std::getline(ss, deposito, ',')) {
            if (deposito.empty()) {
                depositos.push_back(0);
            } else {
                depositos.push_back(std::stoi(deposito));
            }
        }
        Producto producto(grupo, codigo, &depositos);
        productos.push_back(producto);
    }
}

std::vector<Producto> MinStockDepositos::min_stock(int n, int deposito) {
    std::vector<Producto> productos_min_stock;
    for (auto& producto : productos) {
        std::vector<int> depositos = producto.getDepositos();
    if (depositos.size() > deposito && depositos[deposito] <= n)  {
            productos_min_stock.push_back(producto);
        }
    }
    return productos_min_stock;
}

/* 
intento con cola de prioridad para ordenar los productos por cantidad de stock

 std::vector<Producto> MinStockDepositos::min_stock(int n, int deposito) {
    std::priority_queue<Producto, std::vector<Producto>, std::greater<Producto>> productos_min_stock;
    for (auto& producto : productos) {
        std::vector<int> depositos = producto.getDepositos();
        if (depositos.size() > deposito && depositos[deposito] <= n) {
            productos_min_stock.push(producto);
        }
    }
    std::vector<Producto> resultado;
    while (!productos_min_stock.empty()) {
        resultado.push_back(productos_min_stock.top());
        productos_min_stock.pop();
    }
    return resultado;
}
*/
