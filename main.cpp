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
    cout<<" ������������������������ͻ"<<endl;
    cout<<" �       Ingresar         �"<<endl;
    cout<<" ������������������������͹"<<endl;
    cout<<" �                        �"<<endl;
    cout<<" � Nombre:                �"<<endl;
    cout<<" �                        �"<<endl;
    cout<<" ������������������������ͼ"<<endl;
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
            cout<<"                             �������������������ͻ"<<endl;
            cout<<" ������������������������ͻ ɺ      ERROR        �"<<endl;
            cout<<" �       Ingresar         � ��������������������͹"<<endl;
            cout<<" ������������������������͹ ��                   �"<<endl;
            cout<<" �                        � �� El usuario no se  �"<<endl;
            cout<<" � Nombre:                �ͼ�  encontro en el   �"<<endl;
            cout<<" �                        �  �      sistema      �"<<endl;
            cout<<" ������������������������ͼ  �                   �"<<endl;
            cout<<"                             �������������������ͼ"<<endl;
            setxy(11,5);
            cout<<usr;
            color(7);
            setxy(39,8);cout<<"�"<<endl;
            cout<<"                                       �"<<endl;
            cout<<"             �������������������������ͼ"<<endl;
            cout<<"             �"<<endl;
            setxy(0,12);
            cout<<" ������������������������ͻ"<<endl;
            cout<<" �      Registrarse       �"<<endl;
            cout<<" ������������������������͹"<<endl;
            cout<<" �                        �"<<endl;
            cout<<" �  �Desea Registrarse?   �"<<endl;
            cout<<" �     1)Si               �"<<endl;
            cout<<" �     2)No               �"<<endl;
            cout<<" �  Opcion:               �"<<endl;
            cout<<" �                        �"<<endl;
            cout<<" ������������������������ͼ"<<endl;
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
            cout<<" ������������������������ͻ"<<endl;
            cout<<" �       Bienvenido       �"<<endl;
            cout<<" ������������������������͹"<<endl;
            cout<<" �                        �"<<endl;
            cout<<" � Hola                   �"<<endl;
            cout<<" �                        �"<<endl;
            cout<<" ������������������������ͼ"<<endl;
            setxy(8,5);
            cout<<usr;
            color(9);
            setxy(26,5);
            cout<<"�";setxy(27,0);
            cout<<"  �������������������ͻ";setxy(27,1);
            cout<<" ɺ       MENU        �";setxy(27,2);
            cout<<" ��������������������͹";setxy(27,3);
            cout<<" ��                   �";setxy(27,4);
            cout<<" ��  1)Productos      �";setxy(27,5);
            cout<<"ͼ�  2)Clientes       �";setxy(27,6);
            cout<<"  �  3)Salir          �";setxy(27,7);
            cout<<"  �  Opcion:          �";setxy(27,8);
            cout<<"  �                   �";setxy(27,9);
            cout<<"  �������������������ͼ";
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
            cout<<" ������������������������ͻ"<<endl;
            cout<<" �       Bienvenido       �"<<endl;
            cout<<" ������������������������͹"<<endl;
            cout<<" �                        �"<<endl;
            cout<<" � Hola                   �"<<endl;
            cout<<" �                        �"<<endl;
            cout<<" ������������������������ͼ"<<endl;
            setxy(8,5);
            cout<<usr;
            color(9);
            setxy(26,5);
            cout<<"�";setxy(27,0);
            cout<<"  �������������������ͻ";setxy(27,1);
            cout<<" ɺ       MENU        �";setxy(27,2);
            cout<<" ��������������������͹";setxy(27,3);
            cout<<" ��                   �";setxy(27,4);
            cout<<" ��  1)Tienda         �";setxy(27,5);
            cout<<"ͼ�  2)Carrito        �";setxy(27,6);
            cout<<"  �  3)Mis Datos      �";setxy(27,7);
            cout<<"  �  4)Salir          �";setxy(27,8);
            cout<<"  �  Opcion:          �";setxy(27,9);
            cout<<"  �                   �";setxy(27,10);
            cout<<"  �������������������ͼ";
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
                    cout<<"�";
                    setxy(50,0);
                    cout<<"  �������������������ͻ";setxy(50,1);
                    cout<<" ɺ     PRODUCTOS     �";setxy(50,2);
                    cout<<" ��������������������͹";setxy(50,3);
                    cout<<" ��                   �";setxy(50,4);
                    cout<<"ͼ�  1)Listar         �";setxy(50,5);
                    cout<<"  �  2)Agregar        �";setxy(50,6);
                    cout<<"  �  3)Editar         �";setxy(50,7);
                    cout<<"  �  4)Borrar         �";setxy(50,8);
                    cout<<"  �  5)Regresar       �";setxy(50,9);
                    cout<<"  �  Opcion:          �";setxy(50,10);
                    cout<<"  �                   �";setxy(50,11);
                    cout<<"  �������������������ͼ";
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
                    cout<<"  �������������������ͻ";setxy(50,1);
                    cout<<" ɺ     CLIENTES      �";setxy(50,2);
                    cout<<" ��������������������͹";setxy(50,3);
                    cout<<" ��                   �";setxy(50,4);
                    cout<<" ��  1)Listar         �";setxy(50,5);
                    cout<<"ͼ�  2)Agregar        �";setxy(50,6);
                    cout<<"  �  3)Editar         �";setxy(50,7);
                    cout<<"  �  4)Borrar         �";setxy(50,8);
                    cout<<"  �  5)Regresar       �";setxy(50,9);
                    cout<<"  �  Opcion:          �";setxy(50,10);
                    cout<<"  �                   �";setxy(50,11);
                    cout<<"  �������������������ͼ";
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
                    cout<<"�";
                    setxy(50,0);
                    cout<<"  ����������������������ͻ";setxy(50,1);
                    cout<<" ɺ       TIENDA         �";setxy(50,2);
                    cout<<" �����������������������͹";setxy(50,3);
                    cout<<" ��                      �";setxy(50,4);
                    cout<<"ͼ�  1)Catalogo          �";setxy(50,5);
                    cout<<"  �  2)Buscar producto   �";setxy(50,6);
                    cout<<"  �  3)Agregar a Carrito �";setxy(50,7);
                    cout<<"  �  4)Regresar          �";setxy(50,8);
                    cout<<"  �  Opcion:             �";setxy(50,9);
                    cout<<"  �                      �";setxy(50,10);
                    cout<<"  ����������������������ͼ";
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
                    cout<<"  ����������������������ͻ";setxy(50,1);
                    cout<<" ɺ       CARRITO        �";setxy(50,2);
                    cout<<" �����������������������͹";setxy(50,3);
                    cout<<" ��                      �";setxy(50,4);
                    cout<<" ��  1)Ver               �";setxy(50,5);
                    cout<<"ͼ�  2)Quitar Producto   �";setxy(50,6);
                    cout<<"  �  3)Vaciar            �";setxy(50,7);
                    cout<<"  �  4)Regresar          �";setxy(50,8);
                    cout<<"  �  Opcion:             �";setxy(50,9);
                    cout<<"  �                      �";setxy(50,10);
                    cout<<"  ����������������������ͼ";
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
                    cout<<"  ����������������������ͻ";setxy(50,1);
                    cout<<" ɺ      MIS DATOS       �";setxy(50,2);
                    cout<<" �����������������������͹";setxy(50,3);
                    cout<<" ��                      �";setxy(50,4);
                    cout<<" ��  1)Ver               �";setxy(50,5);
                    cout<<" ��  2)Editar            �";setxy(50,6);
                    cout<<"ͼ�  3)Eliminar Cuenta   �";setxy(50,7);
                    cout<<"  �  4)Regresar          �";setxy(50,8);
                    cout<<"  �  Opcion:             �";setxy(50,9);
                    cout<<"  �                      �";setxy(50,10);
                    cout<<"  ����������������������ͼ";
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
