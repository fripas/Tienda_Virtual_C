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

char usr[30];
int idUsr=1;

int main(){
    ingreso();
    return 0;
}

void ingreso(){
    system("cls");
    char nombre[30];
    cout<<endl;
    cout<<" ษออออออออออออออออออออออออป"<<endl;
    cout<<" บ       Ingresar         บ"<<endl;
    cout<<" ฬออออออออออออออออออออออออน"<<endl;
    cout<<" บ                        บ"<<endl;
    cout<<" บ Nombre:                บ"<<endl;
    cout<<" บ                        บ"<<endl;
    cout<<" ศออออออออออออออออออออออออผ"<<endl;
    setxy(11,5);
    cin>>nombre;
    //asignar a idUsr (variable global) el resultado de clientes.buscar(nombre);
    int tipo = 2;//asignar a tipo el resultado de clientes.tipo(idUsr);
    strcpy(usr,nombre);
    menu(tipo,0);
}

void menu(int tipo,char op2){
    system("cls");
    char op;
    switch(tipo){
        case 0:
            color(12);
            setxy(0,0);
            cout<<"                             ษอออออออออออออออออออป"<<endl;
            cout<<" ษออออออออออออออออออออออออป ษบ      ERROR        บ"<<endl;
            cout<<" บ       Ingresar         บ บฬอออออออออออออออออออน"<<endl;
            cout<<" ฬออออออออออออออออออออออออน บบ                   บ"<<endl;
            cout<<" บ                        บ บบ El usuario no se  บ"<<endl;
            cout<<" บ Nombre:                ฬอผบ  encontro en el   บ"<<endl;
            cout<<" บ                        บ  บ      sistema      บ"<<endl;
            cout<<" ศออออออออออออออออออออออออผ  บ                   บ"<<endl;
            cout<<"                             ศอออออออออออออออออออผ"<<endl;
            setxy(11,5);
            cout<<usr;
            color(7);
            setxy(39,8);cout<<"ห"<<endl;
            cout<<"                                       บ"<<endl;
            cout<<"             ษอออออออออออออออออออออออออผ"<<endl;
            cout<<"             บ"<<endl;
            setxy(0,12);
            cout<<" ษอออออออออออสออออออออออออป"<<endl;
            cout<<" บ      Registrarse       บ"<<endl;
            cout<<" ฬออออออออออออออออออออออออน"<<endl;
            cout<<" บ                        บ"<<endl;
            cout<<" บ  จDesea Registrarse?   บ"<<endl;
            cout<<" บ     1)Si               บ"<<endl;
            cout<<" บ     2)No               บ"<<endl;
            cout<<" บ  Opcion:               บ"<<endl;
            cout<<" บ                        บ"<<endl;
            cout<<" ศออออออออออออออออออออออออผ"<<endl;
            setxy(12,19);
            cin>>op;
            if(op=='1'){
                //clientes.agregar();
            }
            else{
                color(7);
                ingreso();
            }
            break;
        case 1:
            color(10);
            setxy(0,0);
            cout<<endl;
            cout<<" ษออออออออออออออออออออออออป"<<endl;
            cout<<" บ       Bienvenido       บ"<<endl;
            cout<<" ฬออออออออออออออออออออออออน"<<endl;
            cout<<" บ                        บ"<<endl;
            cout<<" บ Hola                   ฬ"<<endl;
            cout<<" บ                        บ"<<endl;
            cout<<" ศออออออออออออออออออออออออผ"<<endl;
            setxy(8,5);
            cout<<usr;
            color(9);
            setxy(26,5);
            cout<<"ฬ";setxy(27,0);
            cout<<"  ษอออออออออออออออออออป";setxy(27,1);
            cout<<" ษบ       MENU        บ";setxy(27,2);
            cout<<" บฬอออออออออออออออออออน";setxy(27,3);
            cout<<" บบ                   บ";setxy(27,4);
            cout<<" บบ  1)Productos      บ";setxy(27,5);
            cout<<"อผบ  2)Clientes       บ";setxy(27,6);
            cout<<"  บ  3)Salir          บ";setxy(27,7);
            cout<<"  บ  Opcion:          บ";setxy(27,8);
            cout<<"  บ                   บ";setxy(27,9);
            cout<<"  ศอออออออออออออออออออผ";
            if(op2!=0){
                accion(tipo,op2);
            }
            else{
                setxy(40,7);
                cin>>op;
                accion(tipo,op);
            }
            break;
        case 2:
            color(10);
            setxy(0,0);
            cout<<endl;
            cout<<" ษออออออออออออออออออออออออป"<<endl;
            cout<<" บ       Bienvenido       บ"<<endl;
            cout<<" ฬออออออออออออออออออออออออน"<<endl;
            cout<<" บ                        บ"<<endl;
            cout<<" บ Hola                   ฬ"<<endl;
            cout<<" บ                        บ"<<endl;
            cout<<" ศออออออออออออออออออออออออผ"<<endl;
            setxy(8,5);
            cout<<usr;
            color(9);
            setxy(26,5);
            cout<<"ฬ";setxy(27,0);
            cout<<"  ษอออออออออออออออออออป";setxy(27,1);
            cout<<" ษบ       MENU        บ";setxy(27,2);
            cout<<" บฬอออออออออออออออออออน";setxy(27,3);
            cout<<" บบ                   บ";setxy(27,4);
            cout<<" บบ  1)Tienda         บ";setxy(27,5);
            cout<<"อผบ  2)Carrito        บ";setxy(27,6);
            cout<<"  บ  3)Mis Datos      บ";setxy(27,7);
            cout<<"  บ  4)Salir          บ";setxy(27,8);
            cout<<"  บ  Opcion:          บ";setxy(27,9);
            cout<<"  บ                   บ";setxy(27,10);
            cout<<"  ศอออออออออออออออออออผ";
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
}

void accion(int tipo,char op){
    char op2;
    int idP;
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
                    cout<<"ฬ";
                    setxy(50,0);
                    cout<<"  ษอออออออออออออออออออป";setxy(50,1);
                    cout<<" ษบ     PRODUCTOS     บ";setxy(50,2);
                    cout<<" บฬอออออออออออออออออออน";setxy(50,3);
                    cout<<" บบ                   บ";setxy(50,4);
                    cout<<"อผบ  1)Listar         บ";setxy(50,5);
                    cout<<"  บ  2)Agregar        บ";setxy(50,6);
                    cout<<"  บ  3)Editar         บ";setxy(50,7);
                    cout<<"  บ  4)Borrar         บ";setxy(50,8);
                    cout<<"  บ  5)Regresar       บ";setxy(50,9);
                    cout<<"  บ  Opcion:          บ";setxy(50,10);
                    cout<<"  บ                   บ";setxy(50,11);
                    cout<<"  ศอออออออออออออออออออผ";
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
                    cout<<"ฬ";
                    setxy(50,0);
                    cout<<"  ษอออออออออออออออออออป";setxy(50,1);
                    cout<<" ษบ     CLIENTES      บ";setxy(50,2);
                    cout<<" บฬอออออออออออออออออออน";setxy(50,3);
                    cout<<" บบ                   บ";setxy(50,4);
                    cout<<" บบ  1)Listar         บ";setxy(50,5);
                    cout<<"อผบ  2)Agregar        บ";setxy(50,6);
                    cout<<"  บ  3)Editar         บ";setxy(50,7);
                    cout<<"  บ  4)Borrar         บ";setxy(50,8);
                    cout<<"  บ  5)Regresar       บ";setxy(50,9);
                    cout<<"  บ  Opcion:          บ";setxy(50,10);
                    cout<<"  บ                   บ";setxy(50,11);
                    cout<<"  ศอออออออออออออออออออผ";
                    setxy(63,9);
                    cin>>op2;
                    setxy(0,13);
                    switch(op2){
                        case '1':
                            //clientes.mostrar();
                            menu(tipo,op);
                            break;
                        case '2':
                            //clientes.agregar();
                            menu(tipo,op);
                            break;
                        case '3':
                            //clientes.modificar(idC);
                            menu(tipo,op);
                            break;
                        case '4':
                            //clientes.borrar(idC);
                            menu(tipo,op);
                            break;
                        case '5':
                            menu(tipo,0);
                            break;
                    }
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
                    cout<<"ฬ";
                    setxy(50,0);
                    cout<<"  ษออออออออออออออออออออออป";setxy(50,1);
                    cout<<" ษบ       TIENDA         บ";setxy(50,2);
                    cout<<" บฬออออออออออออออออออออออน";setxy(50,3);
                    cout<<" บบ                      บ";setxy(50,4);
                    cout<<"อผบ  1)Catalogo          บ";setxy(50,5);
                    cout<<"  บ  2)Buscar producto   บ";setxy(50,6);
                    cout<<"  บ  3)Agregar a Carrito บ";setxy(50,7);
                    cout<<"  บ  4)Regresar          บ";setxy(50,8);
                    cout<<"  บ  Opcion:             บ";setxy(50,9);
                    cout<<"  บ                      บ";setxy(50,10);
                    cout<<"  ศออออออออออออออออออออออผ";
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
                    cout<<"ฬ";
                    setxy(50,0);
                    cout<<"  ษออออออออออออออออออออออป";setxy(50,1);
                    cout<<" ษบ       CARRITO        บ";setxy(50,2);
                    cout<<" บฬออออออออออออออออออออออน";setxy(50,3);
                    cout<<" บบ                      บ";setxy(50,4);
                    cout<<" บบ  1)Ver               บ";setxy(50,5);
                    cout<<"อผบ  2)Quitar Producto   บ";setxy(50,6);
                    cout<<"  บ  3)Vaciar            บ";setxy(50,7);
                    cout<<"  บ  4)Regresar          บ";setxy(50,8);
                    cout<<"  บ  Opcion:             บ";setxy(50,9);
                    cout<<"  บ                      บ";setxy(50,10);
                    cout<<"  ศออออออออออออออออออออออผ";
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
                    cout<<"ฬ";
                    setxy(50,0);
                    cout<<"  ษออออออออออออออออออออออป";setxy(50,1);
                    cout<<" ษบ      MIS DATOS       บ";setxy(50,2);
                    cout<<" บฬออออออออออออออออออออออน";setxy(50,3);
                    cout<<" บบ                      บ";setxy(50,4);
                    cout<<" บบ  1)Ver               บ";setxy(50,5);
                    cout<<" บบ  2)Editar            บ";setxy(50,6);
                    cout<<"อผบ  3)Eliminar Cuenta   บ";setxy(50,7);
                    cout<<"  บ  4)Regresar          บ";setxy(50,8);
                    cout<<"  บ  Opcion:             บ";setxy(50,9);
                    cout<<"  บ                      บ";setxy(50,10);
                    cout<<"  ศออออออออออออออออออออออผ";
                    setxy(63,8);
                    cin>>op2;
                    setxy(0,12);
                    switch(op2){
                        case '1':
                            //clientes.mostrar(idUsr);
                            menu(tipo,op);
                            break;
                        case '2':
                            //clientes.modificar(idUsr);
                            menu(tipo,op);
                            break;
                        case '3':
                            //clientes.borrar(idUsr);
                            menu(tipo,op);
                            break;
                        case '4':
                            menu(tipo,0);
                            break;
                    }
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
