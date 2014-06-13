#include "Clientes.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>

using namespace std;

Clientes::Clientes(){
    archB.open(dir,ios::binary|ios::in);
    if(archB.fail()){
        archB.close();
        archB.open(dir,ios::binary|ios::out);
        if(!archB){
            cerr<<"No se pudo crear el archivo"<<endl;
            return;
        }
        datos.id=1;
        datos.tipo=1;
        strcpy(datos.nombre,"admin");
        strcpy(datos.direccion,"UAA");
        strcpy(datos.email,"admin@uaa.mx");
        strcpy(datos.telefono,"4491234567");
        archB.write((char*)&datos,sizeof(strDatos));
    }
    archB.close();
    archB.open(dir,ios::binary|ios::in);
    archB.seekg(0, ios::end);
    id = (archB.tellg()/sizeof(strDatos));
    archB.close();
}

void Clientes::mostrar(){
    archB.open(dir,ios::binary|ios::in);
    if(archB.fail()){
        cerr<<"Error al abrir el archivo"<<endl;
    }
    else{
        archB.seekg(0, ios::beg);
        archB.read((char*)&datos,sizeof(strDatos));
        while(!archB.eof()){
            if(datos.id>0){
                cout<<"É";
                for(int i=0;i<77;i++) cout<<"Í";
                cout<<"»"<<endl<<endl;
                cout<<"\tId: "<<datos.id<<endl;
                cout<<"\tNombre: "<<datos.nombre<<endl;
                cout<<"\tDireccion: "<<datos.direccion<<endl;
                cout<<"\tEmail: "<<datos.email<<endl;
                cout<<"\tTelefono: "<<datos.telefono<<endl;
                cout<<"È";
                for(int i=0;i<77;i++) cout<<"Í";
                cout<<"¼"<<endl;
            }
            archB.read((char*)&datos,sizeof(strDatos));
        }
    }
    system("Pause");
    archB.close();
}

void Clientes::agregar(){
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
        cout<<"Alta de Clientes"<<endl;
        datos.tipo=2;//Tipo de usuario normal
        datos.id=id;
        cout<<"Nombre del cliente: ";
        cin.sync();
        cin.getline(datos.nombre,30);
        cout<<"Direccion del cliente: ";
        cin.sync();
        cin.getline(datos.direccion,50);
        cout<<"Email: ";
        cin.sync();
        cin.getline(datos.email,20);
        cout<<"Telefono: ";
        cin>>datos.telefono;
        //Colocar el puntero en la posicion del id
        archB.seekp((datos.id-1)*sizeof(strDatos),ios::beg);
        //Graba la estructura
        archB.write((char*)&datos,sizeof(strDatos));
        cout<<"El cliente se guardo correctamente."<<endl;
    }
    archB.close();
    system("Pause");
}

void Clientes::modificar(int idC){
    if(buscar(idC)==-1){
        cerr<<"El cliente no existe."<<endl;
        system("Pause");
        return;
    }
    archB.open(dir,ios::binary|ios::in|ios::out|ios::ate);
    if(archB.fail()){
        cerr<<"Error al abrir el archivo"<<endl;
    }
    else{
        cout<<"Modificando el cliente con el nombre de "<<datos.nombre<<endl;
        datos.id = idC;
        cout<<"Introduzca el nombre: ";
        cin.sync();
        cin.getline(datos.nombre,30);
        cout<<"Introduzca la direccion: ";
        cin.sync();
        cin.getline(datos.direccion,50);
        cout<<"Introduzca el email: ";
        cin.sync();
        cin.getline(datos.email,20);
        cout<<"Introduzca el telefono: ";
        cin>>datos.telefono;
        //Colocar el puntero en la posicion del id
        archB.seekp((datos.id-1)*sizeof(strDatos),ios::beg);
        //Graba la estructura
        archB.write((char*)&datos,sizeof(strDatos));
        cout<<"El cliente se modifico correctamente."<<endl;
    }
    archB.close();
    system("Pause");
}

int Clientes::buscar(const char* nombreC){
    int idC=-1;
    archB.open(dir,ios::binary|ios::in);
    if(archB.fail()){
        cerr<<"Error al abrir el archivo"<<endl;
    }
    else{
        archB.read((char*)&datos,sizeof(strDatos));
        while(!archB.eof()){
            if(strcmp(datos.nombre,nombreC)==0){
                idC=datos.id;
                archB.close();
                return idC;
                //ver(idC);
                //system("Pause");
                break;
            }
            archB.read((char*)&datos,sizeof(strDatos));
        }
    }
    if(idC==-1){
        archB.close();
    }
    return idC;
}

int Clientes::buscar(int idC){
    archB.open(dir,ios::binary|ios::in);
    if(archB.fail()){
        cerr<<"Error al abrir el archivo"<<endl;
    }
    else{
        archB.seekg((idC-1)*sizeof(strDatos),ios::beg);
        archB.read((char*)&datos,sizeof(strDatos));
        if(!archB.eof()){
            if(datos.id!=idC)
                idC=-1;
        }
        else{
            idC=-1;
        }
    }
    archB.close();
    return idC;
}

void Clientes::ver(int idC){
    if(buscar(idC)==-1){
        cerr<<"El cliente no existe."<<endl;
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
            cout<<"\tId: "<<datos.id<<endl;
            cout<<"\tNombre: "<<datos.nombre<<endl;
            cout<<"\tDireccion: "<<datos.direccion<<endl;
            cout<<"\tEmail: "<<datos.email<<endl;
            cout<<"\tTelefono: "<<datos.telefono<<endl<<endl;
            cout<<"È";
            for(int i=0;i<77;i++) cout<<"Í";
            cout<<"¼"<<endl;
            system("Pause");
        }
    }
    archB.close();
}

void Clientes::borrar(int idC){
    char op;
    if(buscar(idC)==-1){
        cerr<<"El cliente no existe."<<endl;
        system("Pause");
        return;
    }
    archB.open(dir,ios::binary|ios::in|ios::out|ios::ate);
    if(archB.fail()){
        cerr<<"Error al abrir el archivo"<<endl;
    }
    else{
        cout<<"Esta seguro de borrar la cuenta?"<<endl;
        cout<<"\t1) Si"<<endl;
        cout<<"\t2) No"<<endl;
        cout<<"Opcion: ";
        cin.sync();
        cin>>op;
        if(op=='1'){
            datos.id=0;
            //Colocar el puntero en la posicion del id
            archB.seekp((idC-1)*sizeof(strDatos),ios::beg);
            //Graba la estructura
            archB.write((char*)&datos,sizeof(strDatos));
            cout<<"El cliente se elimino correctamente."<<endl;
        }
    }
    archB.close();
    system("Pause");
}

int Clientes::tipo(int idC){
    int tipo=0;
    if(buscar(idC)==-1){
        return 0;
    }
    archB.open(dir,ios::binary|ios::in);
    if(archB.fail()){
        cerr<<"Error al abrir el archivo"<<endl;
    }
    else{
        archB.seekg((idC-1)*sizeof(strDatos),ios::beg);
        archB.read((char*)&datos,sizeof(strDatos));
        if(!archB.eof()){
            tipo=datos.tipo;
        }
    }
    archB.close();
    return tipo;
}

