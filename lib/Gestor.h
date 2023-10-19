//
// Created by emi on 10/19/23.
//

#ifndef FPROJECTP3_GESTOR_H
#define FPROJECTP3_GESTOR_H
#include <iostream>
#include<unordered_map>
#include <vector>
#include <fstream>
#include <sstream>
#include <queue>
#include "Producto.h"

/* Lee un archivo .csv y almacena sus contenidos en diversas estructuras de datos
 -total_art_dif Cantidad total de artículos diferentes.
  -total_art Cantidad total de artículos.
  -min_stock [n] Listado de artículos con cantidad n o menos de stock.
  -min_stock [n],[deposito] Listado de artículos con cantidad n o menos de stock según un depósito.
  -stock [nombre_articulo] El stock total del artículo ingresado como argumento.
  -stock [nombre_articulo],[depósito] El stock del artículo en un depósito.
  -max_Stock [n] Listado de aquellos artículos cuyo stock es igual o supera el número n.

Objetivo: Ejercitar y afianzar el uso de estructuras y algoritmos de datos mediante una aplicación concisa y de uso
general
*/
class Gestor {
public:
    Gestor();
    Gestor(std::string ubicacion_archivo);
    void leerArchivo();
    void total_art_dif();
    void total_art();
    void min_stock(int n);
    void min_stock(int n, int deposito);
    void stock(std::string nombre_articulo);
    void stock(std::string nombre_articulo, int deposito);
    void max_stock(int n);
    Producto generarProducto(std::string nombre, std::string codigo, std::vector<int> depositos);
    void cargarMapa(std::string nombre, Producto producto);
    void cargarMinStock(Producto producto, int n);
    void cargarMaxStock(Producto producto, int n);
    void cargarMinStockDeposito(Producto producto, int n, int deposito);
    void setUbicacionArchivo(std::string ubicacion_archivo){m_ubicacion_archivo = ubicacion_archivo;}
    std::string getUbicacionArchivo()const{return m_ubicacion_archivo;}

    ~Gestor();
    private:
    std::unordered_map<std::string, Producto> m_productos;
    int total_art_dif_;
    int total_art_;
    std::priority_queue<int> m_min_stock;
    std::priority_queue<int> m_max_stock;
    std::priority_queue<int> m_min_stock_deposito;
    std::ifstream m_archivo;
    std::string m_ubicacion_archivo;
};










#endif //FPROJECTP3_GESTOR_H