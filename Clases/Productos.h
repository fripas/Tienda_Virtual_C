#ifndef PRODUCTOS_H_INCLUDED
#define PRODUCTOS_H_INCLUDED

#include "Carrito.h"

struct strProducto{
    int id,cantidad;
    char nombre[30],descripcion[100];
    float precio;
};

class Productos{
    private:
        char *dir="productos.dat";
    public:
        Productos();
        void agregarProducto();
        void modificarProducto(int);
        void agregarAlCarrito(int);
        int buscarProducto(char*);
        void verProducto(int);
        void borrarProducto(int);
};

#endif // PRODUCTOS_H
