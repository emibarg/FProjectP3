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

void Gestor::leerArchivoV(bool esMin) {


    // Cargar los productos a la lista.

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
        listOrdenada.emplace_back(producto);
        depositos.clear();
    }

    // Ordenar lista con quicksort segun corresponda

    if(esMin)
    {

    }else{

    }


}

void Gestor::quickSort(std::vector<Producto> lista, int inicio, int fin) {

    if(inicio < fin)
    {
        int pivote = (fin - inicio) / 2;

        int Pivot = lista[pivote].getStock();
        int limIzq = inicio, limDer = fin;

        while (limIzq < limDer)
        {
            while (lista[limIzq].getStock() <= Pivot && limIzq < fin)
            {
                limIzq++;
            }
            while (lista[limDer].getStock() > Pivot)
            {
                limDer--;
            }
            if(limIzq < limDer)
            {
                Producto temp = lista[limIzq];
                lista[limIzq] = lista[limDer];
                lista[limDer] = temp;
            }
        }
        lista[inicio] = lista[limDer];
        lista[limDer] = lista[pivote];

        quickSort(lista, inicio, pivote - 1);
        quickSort(lista, pivote + 1, fin);
    }

}

void Gestor::leerArchivoF() {

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

            if (i > 2 && !token.empty()) {
                    sum_stock += std::stoi(token);
            }
            i++;
        }
    }

    for (int i = 0; i < sum_stock; ++i) {
        matrizFran.emplace_back();
    }

    m_archivo.close();
    m_archivo.open(getUbicacionArchivo());

    if (!m_archivo.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        exit(1);
    }

    firstLine = true;
    columnas = 0;

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
                }
            }
            i++;
        }

        Producto producto = generarProducto(nombre, codigo, depositos);
        matrizFran[producto.getStock()].emplace_back(producto);
        depositos.clear();
    }

}

std::vector<Producto> Gestor::min_stockF(int n) {
    std::vector<Producto> output;
    for (int i = 0; i < n + 1; ++i) {
        output.insert(output.end(), matrizFran[i].begin(), matrizFran[i].end());
    }
    return output;
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
