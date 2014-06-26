#include "Productos.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>

using namespace std;

Productos::Productos(){
    //Verifica si el archivo existe, si no, lo crea.
    archB.open(dir,ios::binary|ios::in);
    if(archB.fail()){
        archB.close();
        archB.open(dir,ios::binary|ios::out);
        if(!archB){
            cerr<<"No se pudo crear el archivo"<<endl;
            return;
        }
        datos.id=0;
        archB.write((char*)&datos,sizeof(strDatos));
    }
    archB.close();
    //Abre el archivo para leer el ultimo id
    archB.open(dir,ios::binary|ios::in);
    //Calcula el Id del ultimo producto
    archB.seekg(0, ios::end);
    id = (archB.tellg()/sizeof(strDatos));
    archB.close();
}

void Productos::mostrar(){
    archB.open(dir,ios::binary|ios::in);
    if(archB.fail()){
        cerr<<"Error al abrir el archivo"<<endl;
    }
    else{
        archB.seekg(0, ios::beg);
        archB.read((char*)&datos,sizeof(strDatos));
        while(!archB.eof()){
            if(datos.id>0){//Si el producto tiene un id diferente de 0
                cout<<"É";
                for(int i=0;i<77;i++) cout<<"Í";//Linea superior
                cout<<"»"<<endl<<endl;
                cout<<"\tId: "<<datos.id<<endl;
                cout<<"\tNombre: "<<datos.nombre<<endl;
                cout<<"\tDescripcion: "<<datos.descripcion<<endl;
                cout<<"\tDisponibles: "<<datos.cantidad<<endl;
                cout<<"\tPrecio: $"<<datos.precio<<endl<<endl;
                cout<<"È";
                for(int i=0;i<77;i++) cout<<"Í";//Linea inferior
                cout<<"¼"<<endl;
            }
            archB.read((char*)&datos,sizeof(strDatos));//Lee el siguiente producto
        }
    }
    system("Pause");
    archB.close();
}

void Productos::agregar(){
    archB.open(dir,ios::binary|ios::in|ios::out|ios::ate);
    if(archB.fail()){
        cerr<<"Error al abrir el archivo"<<endl;
    }
    else{
        //Lee la primer posicion para ver si no es el cascaron
        archB.seekg(0, ios::beg);
        archB.read((char*)&datos,sizeof(strDatos));
        if(datos.id!=0)
            id++;
        cout<<"Alta de productos"<<endl;
        datos.id=id;
        cout<<"Introduzca el nombre: ";
        cin.sync();
        cin.getline(datos.nombre,30);
        cout<<"Introduzca la descripcion: ";
        cin.sync();
        cin.getline(datos.descripcion,100);
        cout<<"Introduzca el precio: $";
        cin>>datos.precio;
        cout<<"Introduzca la cantidad en stock: ";
        cin>>datos.cantidad;
        //Colocar el puntero en la posicion del id
        archB.seekp((datos.id-1)*sizeof(strDatos),ios::beg);
        //Graba la estructura
        archB.write((char*)&datos,sizeof(strDatos));
        cout<<"El producto se guardo correctamente."<<endl;
    }
    archB.close();
    system("Pause");
}
void Productos::modificar(int idP){
    if(buscar(idP)==-1){
        cerr<<"El producto no existe."<<endl;
        system("Pause");
        return;
    }
    archB.open(dir,ios::binary|ios::in|ios::out|ios::ate);
    if(archB.fail()){
        cerr<<"Error al abrir el archivo"<<endl;
    }
    else{
        cout<<"Modificando el producto "<<idP<<endl;
        datos.id = idP;
        cout<<"Introduzca el nombre: ";
        cin.sync();
        cin.getline(datos.nombre,30);
        cout<<"Introduzca la descripcion: ";
        cin.sync();
        cin.getline(datos.descripcion,100);
        cout<<"Introduzca el precio: $";
        cin>>datos.precio;
        cout<<"Introduzca la cantidad en stock: ";
        cin>>datos.cantidad;
        //Colocar el puntero en la posicion del id
        archB.seekp((datos.id-1)*sizeof(strDatos),ios::beg);
        //Graba la estructura
        archB.write((char*)&datos,sizeof(strDatos));
        cout<<"El producto se modifico correctamente."<<endl;
    }
    archB.close();
    system("Pause");
}
float Productos::getPrecio(int idP){
    float tmp;
    if(buscar(idP)==-1){
        cerr<<"El producto no existe."<<endl;
        system("Pause");
        return 0;
    }
    archB.open(dir,ios::binary|ios::in);
    if(archB.fail()){
        cerr<<"Error al abrir el archivo Precio"<<endl;
    }
    else{
        archB.seekg((idP-1)*sizeof(strDatos),ios::beg);//Hacia la posicion del id
        archB.read((char*)&datos,sizeof(strDatos));//Lee el producto
        if(!archB.eof()){
            tmp=datos.precio;//Guarda el precio en la variable tmp
        }
    }
    archB.close();
    return tmp;
}
int Productos::getCantidad(int idP){
    int tmp;
    if(buscar(idP)==-1){
        cerr<<"El producto no existe."<<endl;
        system("Pause");
        return 0;
    }
    archB.open(dir,ios::binary|ios::in);
    if(archB.fail()){
        cerr<<"Error al abrir el archivo Precio"<<endl;
    }
    else{
        archB.seekg((idP-1)*sizeof(strDatos),ios::beg);
        archB.read((char*)&datos,sizeof(strDatos));//Lee el producto
        if(!archB.eof()){
            tmp=datos.cantidad;//Guarda la cantidad en tmp
        }
    }
    archB.close();
    return tmp;
}
void Productos::setCantidad(int idP,int cant){
    if(buscar(idP)==-1){
        cerr<<"El producto no existe."<<endl;
        system("Pause");
        return;
    }
    archB.open(dir,ios::binary|ios::in|ios::out|ios::ate);
    if(archB.fail()){
        cerr<<"Error al abrir el archivo"<<endl;
    }
    else{
        //Asigna la cantidad recibida por parametro
        datos.cantidad=cant;
        //Colocar el puntero en la posicion del id
        archB.seekp((datos.id-1)*sizeof(strDatos),ios::beg);
        //Graba la estructura
        archB.write((char*)&datos,sizeof(strDatos));
    }
    archB.close();
}
//Busca por id
int Productos::buscar(int idP){
    archB.open(dir,ios::binary|ios::in);
    if(archB.fail()){
        cerr<<"Error al abrir el archivo"<<endl;
    }
    else{
        archB.seekg((idP-1)*sizeof(strDatos),ios::beg);
        archB.read((char*)&datos,sizeof(strDatos));
        if(!archB.eof()){
            if(datos.id!=idP)
                idP=-1;
        }
        else{
            idP=-1;
        }
    }
    archB.close();
    return idP;
}
//Busca por nombre
int Productos::buscar(const char *nombre){
    int idP=-1;
    archB.open(dir,ios::binary|ios::in);
    if(archB.fail()){
        cerr<<"Error al abrir el archivo"<<endl;
    }
    else{
        archB.read((char*)&datos,sizeof(strDatos));
        while(!archB.eof()){
            if(strcmp(datos.nombre,nombre)==0){
                idP=datos.id;
                archB.close();
                ver(idP);
                system("Pause");
                break;
            }
            archB.read((char*)&datos,sizeof(strDatos));
        }
    }
    if(idP==-1){
        cout<<"No se encontraron resultados de la busqueda"<<endl;
        system("Pause");
        archB.close();
    }
    return idP;
}
//Muestra producto
void Productos::ver(int idP){
    if(buscar(idP)==-1){
        cerr<<"El producto no existe."<<endl;
        system("Pause");
        return;
    }
    archB.open(dir,ios::binary|ios::in);
    if(archB.fail()){
        cerr<<"Error al abrir el archivo"<<endl;
    }
    else{
        archB.seekg((idP-1)*sizeof(strDatos),ios::beg);//Mueve hacia el id
        archB.read((char*)&datos,sizeof(strDatos));//Lee el producto
        if(!archB.eof()){
            cout<<"É";
            for(int i=0;i<77;i++) cout<<"Í";
            cout<<"»"<<endl<<endl;
            cout<<"\tId: "<<datos.id<<endl;
            cout<<"\tNombre: "<<datos.nombre<<endl;
            cout<<"\tDescripcion: "<<datos.descripcion<<endl;
            cout<<"\tDisponibles: "<<datos.cantidad<<endl;
            cout<<"\tPrecio: $"<<datos.precio<<endl<<endl;
            cout<<"È";
            for(int i=0;i<77;i++) cout<<"Í";
            cout<<"¼"<<endl;
        }
    }
    archB.close();
}
void Productos::borrar(int idP){
    char op;
    if(buscar(idP)==-1){
        cerr<<"El producto no existe."<<endl;
        system("Pause");
        return;
    }
    archB.open(dir,ios::binary|ios::in|ios::out|ios::ate);
    if(archB.fail()){
        cerr<<"Error al abrir el archivo"<<endl;
    }
    else{
        cout<<"Esta seguro de borrar el producto?"<<endl;
        cout<<"\t1) Si"<<endl;
        cout<<"\t2) No"<<endl;
        cout<<"Opcion: ";
        cin>>op;
        if(op=='1'){
            //Asigna el id en 0 (Borrado logico)
            datos.id=0;
            //Colocar el puntero en la posicion del id
            archB.seekp((idP-1)*sizeof(strDatos),ios::beg);
            //Graba la estructura
            archB.write((char*)&datos,sizeof(strDatos));
            cout<<"El producto se borro correctamente."<<endl;
        }
    }
    archB.close();
    system("Pause");
}
