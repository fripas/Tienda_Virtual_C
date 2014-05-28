#ifndef PRODUCTOS_H
#define PRODUCTOS_H

class Productos{
    private:
        int id,cant;
        char *tit,*desc;
        float precio;
    public:
        Productos();
        void agregaProducto();
        void modificaProducto();
        int buscaProducto(char*);
        void borrarProducto();
};

#endif // PRODUCTOS_H
