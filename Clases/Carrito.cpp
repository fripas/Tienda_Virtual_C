#include "Carrito.h"
#include "Productos.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>

using namespace std;
Productos listaProductos;

Carrito::Carrito(){
    //Verifica si el archivo existe, si no, lo crea.
    archB.open(dir,ios::binary|ios::in);
    if(archB.fail()){
        archB.close();
        archB.open(dir,ios::binary|ios::out);
        if(!archB){
            cerr<<"No se pudo crear el archivo"<<endl;
            return;
        }
        datos.idCliente=0;
        archB.write((char*)&datos,sizeof(strDatos));
    }
    archB.close();
}

void Carrito::agregar(int idC,int idP){
    if(listaProductos.buscar(idP)==-1){
        cerr<<"El producto no existe"<<endl;
        system("Pause");
        return;
    }
    archB.open(dir,ios::binary|ios::in|ios::out|ios::ate);
    if(archB.fail()){
        cerr<<"Error al abrir el archivo"<<endl;
    }
    else{
        //Lee la primer posicion para ver si no es el cascaron
        archB.seekg(idC-1, ios::beg);
        archB.read((char*)&datos,sizeof(strDatos));
        if(!archB.eof()){//Si el carrito ya tiene datos
            cout<<"Agregar al carrito"<<endl;
            datos.idCliente=idC;
            int cant=listaProductos.getCantidad(idP);
            if(datos.tam<MAX && cant>0){
                datos.productos[datos.tam]=idP;
                datos.tam++;
                cant--;
                listaProductos.setCantidad(idP,cant);
                //Colocar el puntero en la posicion del id
                archB.seekp((datos.idCliente-1)*sizeof(strDatos),ios::beg);
                //Graba la estructura
                archB.write((char*)&datos,sizeof(strDatos));
                cout<<"El producto se agrego correctamente."<<endl;
            }
            else{
                if(datos.tam>=MAX)
                    cout<<"El carrito esta lleno (Maximo "<<MAX<<" productos)"<<endl;
                if(cant<=0)
                    cout<<"Producto sin stock"<<endl;
            }
        }
        else{//Si el carrito no existe
            cout<<"Agregar al carrito"<<endl;
            datos.idCliente=idC;
            datos.tam=0;
            datos.productos[datos.tam]=idP;
            datos.tam++;
            //Colocar el puntero en la posicion del id
            archB.seekp((datos.idCliente-1)*sizeof(strDatos),ios::beg);
            //Graba la estructura
            archB.write((char*)&datos,sizeof(strDatos));
            cout<<"El producto se agrego correctamente."<<endl;
        }
    }
    archB.close();
    system("Pause");
}
void Carrito::quitar(int idC,int idP){
    if(buscar(idC)==-1){
        cerr<<"El carrito esta vacio."<<endl;
        system("Pause");
        return;
    }
    archB.open(dir,ios::binary|ios::in|ios::out|ios::ate);
    if(archB.fail()){
        cerr<<"Error al abrir el archivo"<<endl;
    }
    else{
        int ban=-1;
        archB.seekg((idC-1)*sizeof(strDatos),ios::beg);
        archB.read((char*)&datos,sizeof(strDatos));
        if(!archB.eof()){
            for(int i=0;i<datos.tam;i++){
                if(idP==datos.productos[i]){
                    cout<<"Se quito el producto "<<idP<<" del carrito"<<endl;
                    //Recorre los otros productos hacia atras
                    for(int j=i;j<datos.tam-1;j++){
                        datos.productos[j]=datos.productos[j+1];
                    }
                    //Elimina el ultimo producto del carrito
                    datos.productos[datos.tam]=0;
                    ban=idP;
                    datos.tam--;
                    int cant=listaProductos.getCantidad(idP);
                    listaProductos.setCantidad(idP,cant+1);
                    //Colocar el puntero en la posicion del id
                    archB.seekp((idC-1)*sizeof(strDatos),ios::beg);
                    //Graba la estructura
                    archB.write((char*)&datos,sizeof(strDatos));
                    break;
                }
            }
            if(ban==-1){
                cout<<"El producto no se encontro en el carrito"<<endl;
            }
        }
    }
    archB.close();
    system("Pause");
}
void Carrito::mostrar(int idC){
    double total=0;
    if(buscar(idC)==-1){
        cerr<<"El carrito esta vacio."<<endl;
        system("Pause");
        return;
    }
    archB.open(dir,ios::binary|ios::in);
    if(archB.fail()){
        cerr<<"Error al abrir el archivo"<<endl;
    }
    else{
        archB.seekg((idC-1)*sizeof(strDatos),ios::beg);
        archB.read((char*)&datos,sizeof(strDatos));
        if(!archB.eof()){
            cout<<"É";
            for(int i=0;i<77;i++) cout<<"Í";
            cout<<"»"<<endl<<endl;
            cout<<"\tProductos en el carrito "<<datos.tam<<endl;
            for(int i=0;i<datos.tam;i++){
                listaProductos.ver(datos.productos[i]);
                total+=listaProductos.getPrecio(datos.productos[i]);
            }
            cout<<endl<<"\tTotal a pagar: $"<<total<<endl;
            cout<<endl<<"È";
            for(int i=0;i<77;i++) cout<<"Í";
            cout<<"¼"<<endl;
        }
    }
    archB.close();
    system("Pause");
}
void Carrito::vaciar(int idC){
    char op;
    int cant;
    if(buscar(idC)==-1){
        cerr<<"El carrito esta vacio."<<endl;
        system("Pause");
        return;
    }
    archB.open(dir,ios::binary|ios::in|ios::out|ios::ate);
    if(archB.fail()){
        cerr<<"Error al abrir el archivo"<<endl;
    }
    else{
        archB.seekg((idC-1)*sizeof(strDatos),ios::beg);
        archB.read((char*)&datos,sizeof(strDatos));
        if(!archB.eof()){
            cout<<"Esta seguro de borrar el producto?"<<endl;
            cout<<"\t1) Si"<<endl;
            cout<<"\t2) No"<<endl;
            cout<<"Opcion: ";
            cin>>op;
            if(op=='1'){
                datos.idCliente=0;
                for(int i=0;i<datos.tam;i++){
                    cant=listaProductos.getCantidad(datos.productos[i]);
                    listaProductos.setCantidad(datos.productos[i],cant+1);
                    datos.productos[i]=0;
                }

                datos.tam=0;
                //Colocar el puntero en la posicion del id
                archB.seekp((idC-1)*sizeof(strDatos),ios::beg);
                //Graba la estructura
                archB.write((char*)&datos,sizeof(strDatos));
                cout<<"Se vacio el carrito correctamente"<<endl;
            }
        }
    }
    archB.close();
    system("Pause");
}

int Carrito::buscar(int idC){
    archB.open(dir,ios::binary|ios::in);
    if(archB.fail()){
        cerr<<"Error al abrir el archivo"<<endl;
    }
    else{
        archB.seekg((idC-1)*sizeof(strDatos),ios::beg);
        archB.read((char*)&datos,sizeof(strDatos));
        if(!archB.eof()){
            if(datos.idCliente!=idC)
                idC=-1;
        }
        else{
            idC=-1;
        }
    }
    archB.close();
    return idC;
}

