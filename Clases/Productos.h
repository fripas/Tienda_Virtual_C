#ifndef PRODUCTOS_H_INCLUDED
#define PRODUCTOS_H_INCLUDED
#include <fstream>

using namespace std;

class Productos{
    private:
        const char *dir="productos.dat";
        struct strDatos{
            int id,cantidad;
            char nombre[30],descripcion[100];
            float precio;
        }datos;
        fstream archB;
        int id;
    public:
        Productos();
        void pausa();
        void mostrar();
        void agregar();
        void modificar(int);
        float getPrecio(int);
        int getCantidad(int);
        void setCantidad(int,int);
        int buscar(const char*);
        int buscar(int);
        void ver(int);
        void borrar(int);
};

#endif // PRODUCTOS_H
