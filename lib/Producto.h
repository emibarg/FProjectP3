//
// Created by emi on 10/19/23.
//

// Directiva de preprocesador que evita la inclusión múltiple del archivo de encabezado.
#ifndef FPROJECTP3_PRODUCTO_H
#define FPROJECTP3_PRODUCTO_H

// Inclusión de bibliotecas y encabezados necesarios.
#include <iostream>
#include <vector>

class Producto {
public:
    // Constructores de la clase Producto.
    Producto();  // Constructor por defecto.
    Producto(std::string nombre, std::string codigo, std::vector<int>* depositos) {
        // Constructor con parámetros que inicializa los miembros de la clase.
        m_nombre = nombre;
        m_codigo = codigo;
        m_depositos = *depositos;
    }

    // Métodos para acceder a los miembros de la clase.
    std::vector<int> getDepositos() const { return m_depositos; }
    void setCodigo(std::string codigo);
    void setNombre(std::string nombre);
    std::string getNombre() const { return m_nombre; }
    std::string getCodigo() const { return m_codigo; }
    void setDepositos(std::vector<int> depositos) { m_depositos = depositos; }

    // Destructor de la clase (no realiza acciones adicionales en este caso).
    ~Producto() {}

private:
    // Miembros de datos privados de la clase.
    std::string m_codigo;        // Código del producto.
    std::string m_nombre;        // Nombre del producto.
    std::vector<int> m_depositos; // Vector de enteros para representar depósitos asociados al producto.
};

#endif //FPROJECTP3_PRODUCTO_H
