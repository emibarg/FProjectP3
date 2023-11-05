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
std::vector<Producto> Gestor::min_stock(int n, int deposito) {
    m_min_stock_deposito.clear(); // limpiamos el vector
    for (auto& producto : m_productos) { // recorremos el mapa de productos

        std::vector<int> depositos = producto.second.getDepositos(); // obtenemos los depositos del producto

        if (depositos.size() > deposito && depositos[deposito] <=n) { // si el producto tiene mas depositos que el ingresado y el stock del deposito ingresado es menor a n
            m_min_stock_deposito.push_back(producto.second); // vector
        }
    }
    return m_min_stock_deposito;
}

std::vector<Producto> Gestor::max_stock(int n) {
    m_max_stock.clear(); // limpiamos la cola de prioridad
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
    return m_max_stock; // devolvemos la cola de prioridad
}
std::vector<Producto> Gestor::min_stock(int n) {
    m_min_stock.clear();
    for (const auto& producto : m_productos) {

        const std::vector<int>& depositos = producto.second.getDepositos();
        int suma_stock = 0;

        for (int i : depositos) {
            suma_stock += i;
        }

        if (suma_stock <= n) {
            m_min_stock.push_back(producto.second);
        }
    }
    return m_min_stock;
}

std::string Gestor::reemplazarN(std::string base) {
    std::string output;

    for (int i = 0; i < base.length(); ++i) {

        std::string temp;

        if( isValidUTF8( base.substr(i, 1) )  ){
            temp = base.substr(i, 1);
        }else{
            temp = base.substr(i, 2);
            i++;
        }

        if( temp == "Á"){
            output += '\301';
        }else if(temp == "É"){
            output += '\311';
        }else if(temp == "Í"){
            output += '\315';
        }else if(temp == "Ó"){
            output += '\323';
        }else if(temp == "Ú"){
            output += '\332';
        }else if(temp == "Ñ") {
            output += '\321';
        }else if(temp == "Ü") {
            output += '\334';
        }else if(temp == "Ø") {
            output += '\330';
        }else{
            output += temp;
        }

    }

    return output;
}


