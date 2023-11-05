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

    std::vector<Producto> min_stock(int n);
    std::vector<Producto> min_stock(int n, int deposito);
    int stock(std::string nombre_articulo);
    int stock(std::string nombre_articulo, int deposito);
    std::vector<Producto>max_stock(int n);
    Producto generarProducto(std::string nombre, std::string codigo, std::vector<int> depositos);
    void cargarMapa(std::string nombre, Producto producto);
    void setUbicacionArchivo(std::string ubicacion_archivo){m_ubicacion_archivo = ubicacion_archivo;}
    std::string getUbicacionArchivo()const{return m_ubicacion_archivo;}
    std::unordered_map<std::string, Producto> getProductos()const{return m_productos;}
    int getTotalArtDif()const{return total_art_dif_;}
    int getTotalArt()const{return total_art_;}
    void setTotalArtDif(int total_art_dif){
        total_art_dif_ = total_art_dif;}
    void setTotalArt(int total_art){total_art_ = total_art;}

    ~Gestor();
private:
    std::unordered_map<std::string, Producto> m_productos;
    int total_art_dif_;
    int total_art_;
    std::vector<Producto> m_min_stock;
    std::vector<Producto> m_max_stock;
    std::vector<Producto> m_min_stock_deposito;
    std::ifstream m_archivo;
    std::string m_ubicacion_archivo;
};










#endif //FPROJECTP3_GESTOR_H