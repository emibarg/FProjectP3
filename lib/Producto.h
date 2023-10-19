//
// Created by emi on 10/19/23.
//

#ifndef FPROJECTP3_PRODUCTO_H
#define FPROJECTP3_PRODUCTO_H
#include <iostream>
#include <vector>

class Producto{
public:
    Producto();
    Producto(std::string nombre, std::string codigo, std::vector<int>* depositos){
        m_nombre = nombre;
        m_codigo = codigo;
        m_depositos = *depositos;}
    std::vector<int> getDepositos()const{return m_depositos;};
    void setCodigo(std::string codigo);
    void setNombre(std::string nombre);
    std::string getNombre()const{return m_nombre;};
    std::string getCodigo()const{return m_codigo;};
    void setDepositos(std::vector<int> depositos){m_depositos = depositos;}
    ~Producto(){};
    private:
    std::string m_codigo;
    std::string m_nombre;
    std::vector<int> m_depositos;
};
#endif //FPROJECTP3_PRODUCTO_H
