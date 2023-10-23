//
// Created by pc on 20/10/2023.
//

#ifndef FPROJECTP3_MIN_STOCK_DEPOSITOS_NOTENERMUCHOENCUENTA_H
#define FPROJECTP3_MIN_STOCK_DEPOSITOS_NOTENERMUCHOENCUENTA_H

#include <vector>
#include "Producto.h"

class MinStockDepositos {
public:
    MinStockDepositos(std::string ubicacion_archivo);
    std::vector<Producto> min_stock(int n, int deposito);
private:
    std::vector<Producto> productos;
};


#endif //FPROJECTP3_MIN_STOCK_DEPOSITOS_NOTENERMUCHOENCUENTA_H
