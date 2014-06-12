#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
#include <fstream>

using namespace std;

class Clientes{
    private:
        const char *dir="clientes.dat";
        struct strDatos{
            int id,tipo;
            char nombre[30],direccion[50],email[20],telefono[10];
        }datos;
        fstream archB;
        int id;
    public:
        Clientes();//Comprueba si el archivo existe, si no lo crea (y agrega un usuario por defecto de tipo administrador)
        void mostrar();//Muestra todos los clientes
        void agregar();//Agrega un nuevo cliente
        void modificar(int);//Modifica un cliente existente
        int buscar(const char*);//Regresa el id del usuario
        int buscar(int);//Busca un cliente por id (se usa para comprobar si existe)
        void ver(int);//Muestra los datos de un cliente especifico
        void borrar(int);//Borra un cliente
        int tipo(int);//Regresa el tipo de usuario (0: No existe; 1: Administrador; 2: Usuario Normal)
};

#endif // CLIENTES_H_INCLUDED
