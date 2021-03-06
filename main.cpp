#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include "Productos.h"
#include "Clientes.h"
#include "Carrito.h"

using namespace std;

BOOL setxy(short,short);
BOOL color(int);
void ingreso();
void menu(int,char);
void accion(int,char);

Productos productos;
Carrito carrito;
Clientes clientes;

char usr[30];
int idUsr=0;

int main(){
    ingreso();
    return 0;
}

void ingreso(){
    system("cls");
    char nombre[30];
    cout<<endl;
    cout<<" 浜様様様様様様様様様様様融"<<endl;
    cout<<" �       Ingresar         �"<<endl;
    cout<<" 麺様様様様様様様様様様様郵"<<endl;
    cout<<" �                        �"<<endl;
    cout<<" � Nombre:                �"<<endl;
    cout<<" �                        �"<<endl;
    cout<<" 藩様様様様様様様様様様様夕"<<endl;
    setxy(11,5);
    cin>>nombre;
    idUsr = clientes.buscar(nombre);
    //asignar a idUsr (variable global) el resultado de clientes.buscar(nombre);
    int tipo = clientes.tipo(idUsr);
    //Copia el nombre en la variable global user para usarlo en todo el programa
    strcpy(usr,nombre);
    //Llama a la sobrecarga con la opcion 0 para que se cargue la vista inicial
    menu(tipo,0);
}

void menu(int tipo,char op2){
    system("cls");
    char op;
    switch(tipo){
        case 0: //Usuario inexistente
            color(12);
            setxy(0,0);
            cout<<"                             浜様様様様様様様様様�"<<endl;
            cout<<" 浜様様様様様様様様様様様融 漂      ERROR        �"<<endl;
            cout<<" �       Ingresar         � 彩様様様様様様様様様郵"<<endl;
            cout<<" 麺様様様様様様様様様様様郵 査                   �"<<endl;
            cout<<" �                        � 査 El usuario no se  �"<<endl;
            cout<<" � Nombre:                麺失  encontro en el   �"<<endl;
            cout<<" �                        �  �      sistema      �"<<endl;
            cout<<" 藩様様様様様様様様様様様夕  �                   �"<<endl;
            cout<<"                             藩様様様様様様様様様�"<<endl;
            setxy(11,5);
            cout<<usr;
            color(7);
            setxy(39,8);cout<<"�"<<endl;
            cout<<"                                       �"<<endl;
            cout<<"             浜様様様様様様様様様様様様�"<<endl;
            cout<<"             �"<<endl;
            setxy(0,12);
            cout<<" 浜様様様様様瞥様様様様様融"<<endl;
            cout<<" �      Registrarse       �"<<endl;
            cout<<" 麺様様様様様様様様様様様郵"<<endl;
            cout<<" �                        �"<<endl;
            cout<<" �  �Desea Registrarse?   �"<<endl;
            cout<<" �     1)Si               �"<<endl;
            cout<<" �     2)No               �"<<endl;
            cout<<" �  Opcion:               �"<<endl;
            cout<<" �                        �"<<endl;
            cout<<" 藩様様様様様様様様様様様夕"<<endl;
            setxy(12,19);
            cin>>op;
            if(op=='1'){
                setxy(0,23);
                clientes.agregar(); //Registro
                color(7);
                ingreso();
            }
            else{
                color(7);
                ingreso();
            }
            break;
        case 1: //Administrador
            color(10);
            setxy(0,0);
            cout<<endl;
            cout<<" 浜様様様様様様様様様様様融"<<endl;
            cout<<" �       Bienvenido       �"<<endl;
            cout<<" 麺様様様様様様様様様様様郵"<<endl;
            cout<<" �                        �"<<endl;
            cout<<" � Hola                   �"<<endl;
            cout<<" �                        �"<<endl;
            cout<<" 藩様様様様様様様様様様様夕"<<endl;
            setxy(8,5);
            cout<<usr;
            color(9);
            setxy(26,5);
            cout<<"�";setxy(27,0);
            cout<<"  浜様様様様様様様様様�";setxy(27,1);
            cout<<" 漂       MENU        �";setxy(27,2);
            cout<<" 彩様様様様様様様様様郵";setxy(27,3);
            cout<<" 査                   �";setxy(27,4);
            cout<<" 査  1)Productos      �";setxy(27,5);
            cout<<"夕�  2)Clientes       �";setxy(27,6);
            cout<<"  �  3)Salir          �";setxy(27,7);
            cout<<"  �  Opcion:          �";setxy(27,8);
            cout<<"  �                   �";setxy(27,9);
            cout<<"  藩様様様様様様様様様�";
            if(op2!=0){
                accion(tipo,op2);
            }
            else{
                setxy(40,7);
                cin>>op;
                accion(tipo,op);
            }
            break;
        case 2: //Comprardor
            color(10);
            setxy(0,0);
            cout<<endl;
            cout<<" 浜様様様様様様様様様様様融"<<endl;
            cout<<" �       Bienvenido       �"<<endl;
            cout<<" 麺様様様様様様様様様様様郵"<<endl;
            cout<<" �                        �"<<endl;
            cout<<" � Hola                   �"<<endl;
            cout<<" �                        �"<<endl;
            cout<<" 藩様様様様様様様様様様様夕"<<endl;
            setxy(8,5);
            cout<<usr;
            color(9);
            setxy(26,5);
            cout<<"�";setxy(27,0);
            cout<<"  浜様様様様様様様様様�";setxy(27,1);
            cout<<" 漂       MENU        �";setxy(27,2);
            cout<<" 彩様様様様様様様様様郵";setxy(27,3);
            cout<<" 査                   �";setxy(27,4);
            cout<<" 査  1)Tienda         �";setxy(27,5);
            cout<<"夕�  2)Carrito        �";setxy(27,6);
            cout<<"  �  3)Mis Datos      �";setxy(27,7);
            cout<<"  �  4)Salir          �";setxy(27,8);
            cout<<"  �  Opcion:          �";setxy(27,9);
            cout<<"  �                   �";setxy(27,10);
            cout<<"  藩様様様様様様様様様�";
            if(op2!=0){
                accion(tipo,op2);
            }
            else{
                setxy(40,8);
                cin>>op;
                accion(tipo,op);
            }
            break;
    }
    menu(tipo,op2); //Se autollama para evitar errores
}

void accion(int tipo,char op){
    char op2;
    int idP,idC;
    switch(tipo){
        case 1:
            setxy(40,7);
            cout<<op;
            switch(op){
                case '1':
                    color(11);
                    setxy(32,4);
                    cout<<"1)Productos";
                    setxy(49,4);
                    cout<<"�";
                    setxy(50,0);
                    cout<<"  浜様様様様様様様様様�";setxy(50,1);
                    cout<<" 漂     PRODUCTOS     �";setxy(50,2);
                    cout<<" 彩様様様様様様様様様郵";setxy(50,3);
                    cout<<" 査                   �";setxy(50,4);
                    cout<<"夕�  1)Listar         �";setxy(50,5);
                    cout<<"  �  2)Agregar        �";setxy(50,6);
                    cout<<"  �  3)Editar         �";setxy(50,7);
                    cout<<"  �  4)Borrar         �";setxy(50,8);
                    cout<<"  �  5)Regresar       �";setxy(50,9);
                    cout<<"  �  Opcion:          �";setxy(50,10);
                    cout<<"  �                   �";setxy(50,11);
                    cout<<"  藩様様様様様様様様様�";
                    setxy(63,9);
                    cin>>op2;
                    setxy(0,13);
                    switch(op2){
                        case '1':
                            productos.mostrar();
                            menu(tipo,op);
                            break;
                        case '2':
                            productos.agregar();
                            menu(tipo,op);
                            break;
                        case '3':
                            cout<<"Introduzca el id del producto: ";
                            cin>>idP;
                            productos.modificar(idP);
                            menu(tipo,op);
                            break;
                        case '4':
                            cout<<"Introduzca el id del producto: ";
                            cin>>idP;
                            productos.borrar(idP);
                            menu(tipo,op);
                            break;
                        case '5':
                            menu(tipo,0);
                            break;
                    }
                    break;
                case '2':
                    color(15);
                    setxy(32,5);
                    cout<<"2)Clientes";
                    setxy(49,5);
                    cout<<"�";
                    setxy(50,0);
                    cout<<"  浜様様様様様様様様様�";setxy(50,1);
                    cout<<" 漂     CLIENTES      �";setxy(50,2);
                    cout<<" 彩様様様様様様様様様郵";setxy(50,3);
                    cout<<" 査                   �";setxy(50,4);
                    cout<<" 査  1)Listar         �";setxy(50,5);
                    cout<<"夕�  2)Agregar        �";setxy(50,6);
                    cout<<"  �  3)Editar         �";setxy(50,7);
                    cout<<"  �  4)Borrar         �";setxy(50,8);
                    cout<<"  �  5)Regresar       �";setxy(50,9);
                    cout<<"  �  Opcion:          �";setxy(50,10);
                    cout<<"  �                   �";setxy(50,11);
                    cout<<"  藩様様様様様様様様様�";
                    setxy(63,9);
                    cin>>op2;
                    setxy(0,13);
                    switch(op2){
                        case '1':
                            clientes.mostrar();
                            menu(tipo,op);
                            break;
                        case '2':
                            clientes.agregar();
                            menu(tipo,op);
                            break;
                        case '3':
                            cout<<"Introduce el id del cliente: ";
                            cin>>idC;
                            clientes.modificar(idC);
                            menu(tipo,op);
                            break;
                        case '4':
                            cout<<"Introduce el id del cliente: ";
                            cin>>idC;
                            clientes.borrar(idC);
                            menu(tipo,op);
                            break;
                        case '5':
                            menu(tipo,0);
                            break;
                    }
                    break;
                case '3':
                    color(7);
                    ingreso();
                    break;

            }
            break;
        case 2:
            setxy(40,8);
            cout<<op;
            switch(op){
                case '1':
                    char tit[30];
                    color(11);
                    setxy(32,4);
                    cout<<"1)Tienda";
                    setxy(49,4);
                    cout<<"�";
                    setxy(50,0);
                    cout<<"  浜様様様様様様様様様様融";setxy(50,1);
                    cout<<" 漂       TIENDA         �";setxy(50,2);
                    cout<<" 彩様様様様様様様様様様様�";setxy(50,3);
                    cout<<" 査                      �";setxy(50,4);
                    cout<<"夕�  1)Catalogo          �";setxy(50,5);
                    cout<<"  �  2)Buscar producto   �";setxy(50,6);
                    cout<<"  �  3)Agregar a Carrito �";setxy(50,7);
                    cout<<"  �  4)Regresar          �";setxy(50,8);
                    cout<<"  �  Opcion:             �";setxy(50,9);
                    cout<<"  �                      �";setxy(50,10);
                    cout<<"  藩様様様様様様様様様様夕";
                    setxy(63,8);
                    cin>>op2;
                    setxy(0,12);
                    switch(op2){
                        case '1':
                            productos.mostrar();
                            menu(tipo,op);
                            break;
                        case '2':
                            cout<<"Introduzca el titulo del producto: ";
                            cin.sync();
                            cin.getline(tit,30);
                            productos.buscar(tit);
                            menu(tipo,op);
                            break;
                        case '3':
                            cout<<"Introduzca el id del producto: ";
                            cin>>idP;
                            carrito.agregar(idUsr,idP);
                            menu(tipo,op);
                            break;
                        case '4':
                            menu(tipo,0);
                            break;
                    }
                    break;
                case '2':
                    color(15);
                    setxy(32,5);
                    cout<<"2)Carrito";
                    setxy(49,5);
                    cout<<"�";
                    setxy(50,0);
                    cout<<"  浜様様様様様様様様様様融";setxy(50,1);
                    cout<<" 漂       CARRITO        �";setxy(50,2);
                    cout<<" 彩様様様様様様様様様様様�";setxy(50,3);
                    cout<<" 査                      �";setxy(50,4);
                    cout<<" 査  1)Ver               �";setxy(50,5);
                    cout<<"夕�  2)Quitar Producto   �";setxy(50,6);
                    cout<<"  �  3)Vaciar            �";setxy(50,7);
                    cout<<"  �  4)Regresar          �";setxy(50,8);
                    cout<<"  �  Opcion:             �";setxy(50,9);
                    cout<<"  �                      �";setxy(50,10);
                    cout<<"  藩様様様様様様様様様様夕";
                    setxy(63,8);
                    cin>>op2;
                    setxy(0,12);
                    switch(op2){
                        case '1':
                            carrito.mostrar(idUsr);
                            menu(tipo,op);
                            break;
                        case '2':
                            cout<<"Introduzca el id del producto: ";
                            cin>>idP;
                            carrito.quitar(idUsr,idP);
                            menu(tipo,op);
                            break;
                        case '3':
                            carrito.vaciar(idUsr);
                            menu(tipo,op);
                            break;
                        case '4':
                            menu(tipo,0);
                            break;
                    }
                    break;
                case '3':
                    color(12);
                    setxy(32,6);
                    cout<<"3)Mis Datos";
                    setxy(49,6);
                    cout<<"�";
                    setxy(50,0);
                    cout<<"  浜様様様様様様様様様様融";setxy(50,1);
                    cout<<" 漂      MIS DATOS       �";setxy(50,2);
                    cout<<" 彩様様様様様様様様様様様�";setxy(50,3);
                    cout<<" 査                      �";setxy(50,4);
                    cout<<" 査  1)Ver               �";setxy(50,5);
                    cout<<" 査  2)Editar            �";setxy(50,6);
                    cout<<"夕�  3)Eliminar Cuenta   �";setxy(50,7);
                    cout<<"  �  4)Regresar          �";setxy(50,8);
                    cout<<"  �  Opcion:             �";setxy(50,9);
                    cout<<"  �                      �";setxy(50,10);
                    cout<<"  藩様様様様様様様様様様夕";
                    setxy(63,8);
                    cin>>op2;
                    setxy(0,12);
                    switch(op2){
                        case '1':
                            clientes.ver(idUsr);
                            menu(tipo,op);
                            break;
                        case '2':
                            clientes.modificar(idUsr);
                            menu(tipo,op);
                            break;
                        case '3':
                            clientes.borrar(idUsr);
                            color(7);
                            ingreso();
                            break;
                        case '4':
                            menu(tipo,0);
                            break;
                    }
                    break;
                case '4':
                    color(7);
                    ingreso();
                    break;

            }
            break;
    }
}

BOOL setxy(short x, short y){//Posiciona el cursor en las coordenadas dada
	COORD c = {x,y};
	return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
BOOL color(int color){//Da color a la consola
	return SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
