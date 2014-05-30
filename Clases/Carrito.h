#ifndef CARRITO_H_INCLUDED
#define CARRITO_H_INCLUDED
#include "Productos.h"
#include "Clientes.h"
#define MAX 10

struct strProducto2{
    int id,cantidad;
    char nombre[30],descripcion[100];
    float precio;
};

struct strCarrito{
    int idCliente;
    strProducto2 productos[MAX];
};

class Carrito{
    private:
        char *dir="carrito.dat";
    public:
        Carrito();
        void quitarProducto(int);
        int buscarProducto(char*);
        void verCarrito();
        void borrarCarrito(int);
};

#endif // CARRITO_H_INCLUDED
