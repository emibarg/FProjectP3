//
// Created by emi on 10/19/23.
//
#include "../lib/Gestor.h"// Constructor por defecto de la clase Gestor
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
    bool firstLine = true;  // Bandera para omitir la primera línea del archivo

    while (getline(m_archivo, line)) {
        if (firstLine) {
            firstLine = false;
            continue; // Omitir la primera línea
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

//metodo para mostrar los productos que tienen stock menor a n en el deposito ingresado
void Gestor::min_stock(int n, int deposito) {

    for (auto& producto : m_productos) { // recorremos el mapa de productos

        std::vector<int> depositos = producto.second.getDepositos(); // obtenemos los depositos del producto

        if (depositos.size() > deposito && depositos[deposito] <=n) { // si el producto tiene mas depositos que el ingresado y el stock del deposito ingresado es menor a n
            m_min_stock_deposito.push_back(producto.second); // lo metemos en la cola de prioridad
        }
    }
}

void Gestor::max_stock(int n) {
    int suma_stock = 0; // inicializamos la suma
    for (auto &producto: m_productos) { // recorremos el mapa de productos
        std::vector<int> depositos = producto.second.getDepositos(); // obtenemos los depositos del producto
        suma_stock = 0; // inicializamos la suma

        for(int i : depositos){ // recorremos los depositos
            suma_stock += i; // sumamos el stock de cada deposito
        } // si la suma es mayor a n

        if(suma_stock > n){ // si la suma es mayor a n lo metemos en la cola de prioridad
            m_max_stock.push_back(producto.second); // lo metemos en la cola de prioridad
        }
    }
}