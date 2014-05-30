#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

struct strCliente{
    int id;
    char nombre[30],direccion[30],email[20],telefono[10];
};

class Clientes{
    private:
        char *dir="carrito.dat";
    public:
        Clientes();
        void agregarCliente();
        void modificarCliente(int);
        int buscarCliente(char*);
        void verCliente(int);
        void borrarCliente(int);
};

#endif // CLIENTES_H_INCLUDED
