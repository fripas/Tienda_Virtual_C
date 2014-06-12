#ifndef CARRITO_H_INCLUDED
#define CARRITO_H_INCLUDED
#include <fstream>

const int MAX = 20;
using namespace std;

class Carrito{
    private:
        const char *dir="carrito.dat";
        struct strDatos{
            int idCliente,tam,productos[MAX];
        }datos;
        fstream archB;
    public:
        Carrito();
        void agregar(int,int);
        void todo();
        void quitar(int,int);
        int buscar(int);
        void mostrar(int);
        void vaciar(int);
};



#endif // CARRITO_H_INCLUDED
