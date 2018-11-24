//
// Created by Carlota Brauckmeyer on 11/9/18.
//

#include<iostream>
#include<fstream>
#include<string>
#include "Metodos_Generales.h"

using namespace std;

void imprimir_menu(){
    cout<<"Que desea jugar hoy el dificil o el facil?\n";
    cout<<"Ingrese 9 para un sudoku 3x3!\n";
    cout<<"Ingrese 4 para un sudoku 2x2!\n";
    cout<<"Ingrese 0 para no hacer nada!!!\n";
    cout<<"Opcion:\n";
}

int leer_dimensiones(){
    tipoEntero dimension;
    do {
        cin >> dimension;
    }while(!(dimension==4||dimension==9));

    return dimension;
}