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
        void mostrar();//Lista los productos
        void agregar();//Agrega un producto
        void modificar(int);//Modifca un producto
        float getPrecio(int);//Obtener precio
        int getCantidad(int);//Obtener stock
        void setCantidad(int,int);//Asignar stock
        int buscar(const char*);//Buscar por nombre
        int buscar(int);//Buscar por id
        void ver(int);//Muestra producto por id
        void borrar(int);//Borrar por id
};

#endif // PRODUCTOS_H
