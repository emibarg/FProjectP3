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
    void leerArchivoV(bool esMin);
    void leerArchivoV(int deposito);

    void leerArchivoF();
    std::vector<Producto> min_stockF(int n);



    std::string reemplazarN(std::string base);



    bool isValidUTF8(const std::string &input) {
        for (size_t i = 0; i < input.length(); ) {
            unsigned char current = input[i];
            size_t bytesToRead = 0;

            // Determine how many bytes the current character should be encoded with
            if (current <= 0x7F) {
                bytesToRead = 1;
            } else if ((current & 0xE0) == 0xC0) {
                bytesToRead = 2;
            } else if ((current & 0xF0) == 0xE0) {
                bytesToRead = 3;
            } else if ((current & 0xF8) == 0xF0) {
                bytesToRead = 4;
            } else {
                return false; // Invalid UTF-8 sequence
            }

            // Check if there are enough bytes left in the string
            if (i + bytesToRead > input.length()) {
                return false; // Incomplete UTF-8 sequence
            }

            // Verify that the following bytes are valid continuations
            for (size_t j = 1; j < bytesToRead; ++j) {
                if ((input[i + j] & 0xC0) != 0x80) {
                    return false; // Invalid UTF-8 sequence
                }
            }

            i += bytesToRead;
        }

        return true;
    }




    void total_art_dif();
    void total_art();
    void min_stock(int n);
    void min_stock(int n, int deposito);
    int stock(std::string nombre_articulo);
    int stock(std::string nombre_articulo, int deposito);
    void max_stock(int n);
    Producto generarProducto(std::string nombre, std::string codigo, std::vector<int> depositos);
    void cargarMapa(std::string nombre, Producto producto);
    void cargarMinStock(Producto producto, int n);
    void cargarMaxStock(Producto producto, int n);
    void cargarMinStockDeposito(Producto producto, int n, int deposito);
    void setUbicacionArchivo(std::string ubicacion_archivo){m_ubicacion_archivo = ubicacion_archivo;}
    std::string getUbicacionArchivo()const{return m_ubicacion_archivo;}
    std::unordered_map<std::string, Producto> getProductos()const{return m_productos;}
    int getTotalArtDif()const{return total_art_dif_;}
    int getTotalArt()const{return total_art_;}
    std::priority_queue<int> getMinStock()const{return m_min_stock;}
    std::priority_queue<int> getMaxStock()const{return m_max_stock;}
    std::priority_queue<int> getMinStockDeposito()const{return m_min_stock_deposito;}
    void setTotalArtDif(int total_art_dif){
        total_art_dif_ = total_art_dif;}
    void setTotalArt(int total_art){total_art_ = total_art;}

    void quickSort(std::vector<Producto> lista, int inicio, int fin);


    ~Gestor();
    private:
    std::unordered_map<std::string, Producto> m_productos;
    int total_art_dif_;
    int total_art_;

    std::vector<Producto> listOrdenada;

    std::vector<std::vector<Producto>> matrizFran;

    std::priority_queue<int> m_min_stock;
    std::priority_queue<int> m_max_stock;
    std::priority_queue<int> m_min_stock_deposito;
    std::ifstream m_archivo;
    std::string m_ubicacion_archivo;
};










#endif //FPROJECTP3_GESTOR_H
