//
// Created by pc on 20/10/2023.
//

#include "../lib/min_stock_depositos.h"

#include <fstream>
#include <sstream>

MinStockDepositos::MinStockDepositos(std::string ubicacion_archivo) {
    std::ifstream archivo(ubicacion_archivo);
    std::string linea;
    while (std::getline(archivo, linea)) {
        std::stringstream ss(linea);
        std::string grupo, codigo;
        std::vector<int> depositos;
        std::string deposito;
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
