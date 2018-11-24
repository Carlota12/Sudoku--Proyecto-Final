//
// Created by Carlota Brauckmeyer on 11/9/18.
//

#include "Sudoku.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Metodos_Generales.h"

using namespace std;


Sudoku::Sudoku(tipoEntero dimension) {
    this->dimension=dimension;

}

void Sudoku::crear_matriz(){
    pMatriz = new tipoEntero *[dimension];
    for(tipoEntero filas=0;filas<dimension;filas++){
        pMatriz[filas]=new tipoEntero[dimension]; //Columnas

    }
}

void Sudoku::completar_sudoku() {
    if(dimension==4) {
        for (tipoEntero fila = 0; fila < dimension; fila++) {
            for (tipoEntero columna = 0; columna < dimension; columna++) {
                pMatriz[fila][columna] = sudoku_base2x2[fila][columna];
            }

        }
    }else{
        for(tipoEntero fila=0;fila<dimension;fila++){
            for(tipoEntero columna=0;columna<dimension;columna++){
                pMatriz[fila][columna]=sudoku_base3x3[fila][columna];
            }
    }
    }

}


void Sudoku::imprimir_sudoku(std::ostream &os) {
        char letra;
        if (dimension == 9) {
            for (auto fila = 0; fila <= dimension; fila++) {
                for (tipoEntero columna = 0; columna <= dimension; columna++) {
                    if (fila == 0 && columna != 0) {
                        if (columna == dimension) os << columna;
                        else os << columna << setw(5);

                    } else if (columna == 0 && fila != 0) {
                        letra = fila + 64;
                        os << letra << setw(8);
                    } else if (fila == 0 && columna == 0)
                        os << setw(6);
                    else {
                        if (dimension == 9) {
                            if (columna == dimension) os << setw(5) << pMatriz[fila - 1][columna - 1] << "|";
                            else if (dimension == 9 && columna % 3 == 1) {
                                os << setw(4) << "|" << pMatriz[fila - 1][columna - 1];
                            } else os << setw(5) << pMatriz[fila - 1][columna - 1] << setw(5);
                        }
                    }
                }
                if (dimension == 9) {
                    if (fila % 3 == 0)
                        os << "\n     -----------------------------------------";
                }
                os << endl;
            }
        } else {
            letra = 65;
            for(tipoEntero fila=0;fila<=4;fila++){
                for(tipoEntero columna=0;columna<=4;columna++){
                    if (fila == 0 && columna != 0) {
                        if (columna == dimension) os << columna;
                        else os << columna << setw(5);

                    } else if (columna == 0 && fila != 0) {
                        letra = fila + 64;
                        os << letra << setw(8);
                    } else if (fila == 0 && columna == 0)
                        os << setw(6);
                    else {
                        if (columna == dimension) os << setw(5) << pMatriz[fila - 1][columna - 1] << "|";
                        else if ((columna == 3 || columna == 1)&& fila!=0) {
                            os << setw(4) << " | " << pMatriz[fila - 1][columna - 1];
                        } else os << setw(5) << pMatriz[fila - 1][columna - 1] << setw(5);
                    }
                }
                if(fila == 0 || fila == 2 || fila==4)
                    os << "\n    -----------------";
                os << endl;
            }
        }
    }


void Sudoku::coordenadas() {
    tipoCaracter columna;
    tipoCaracter fila;
    tipoEntero valor;

    do {
        cout << "Ingrese posicion a sustituir:";
        cin >> columna >> fila;
    }while(ValidarCoordenadas(fila,columna));

    fila -=65;
    columna -=49;

    do {
        cout<<"Ingrese valor:";
        cin >> valor;
    }while(ValidarNumero(valor));


    if(validar_lineas(columna,fila,valor) && validar_cuadrante(columna,fila,valor)){
        pMatriz[fila][columna] = valor;
    }else{
        cout<<"El valor no puede ser ingresado en esta posicion.\n";
    }


}



bool Sudoku::validar_lineas(tipoEntero columna, tipoEntero fila,tipoEntero valor) {

    for (auto movil = 0; movil < dimension; movil++) {
        if (valor == pMatriz[movil][columna] || valor == pMatriz[fila][movil]) {
            cout<<"Error en a validadcion de linea o columna.\n";
            return false;
        }
    }
    cout << "\n";

    return true;
}

bool Sudoku::validar_cuadrante(tipoEntero CooColumna, tipoEntero CooFila, tipoEntero valor) {
    tipoEntero valorfijof=0;
    tipoEntero valorfijoc=0;
    if(dimension==4) {
        if (0 <= CooColumna && CooColumna <= 1 && 0 <= CooFila && CooFila <= 1) {
            valorfijof = 0;
            valorfijoc = 0;
        } else if (2 <= CooColumna && CooColumna <= 3 && 0 <= CooFila && CooFila <= 1) {
            valorfijoc = 2;
            valorfijof = 0;
        } else if (0 <= CooColumna && CooColumna <= 1 && 2 <= CooFila && CooFila <= 3) {
            valorfijoc = 0;
            valorfijof = 2;

        } else if (2 <= CooColumna && CooColumna <= 3 && 2 <= CooFila && CooFila <= 3) {
            valorfijoc = 2;
            valorfijof = 2;
        }
        for (tipoEntero fila = valorfijof; fila <= valorfijof + 1; fila++) {
            for (tipoEntero columna = valorfijoc; columna <= valorfijoc + 1; columna++) {
                if (pMatriz[fila][columna] == valor) {
                    cout<<"Error de validacion en el cuadrante\n";
                    return false;
                }

            }
        }
    }else{
        if (0 <= CooColumna && CooColumna <= 2 && 0 <= CooFila && CooFila <= 2) {
            valorfijoc = 0;
            valorfijof = 0;
        } else if (3 <= CooColumna && CooColumna <= 5 && 0 <= CooFila && CooFila <= 2) {
            valorfijoc = 3;
            valorfijof = 0;
        } else if (6 <= CooColumna && CooColumna <= 8 && 0 <= CooFila && CooFila <= 2) {
            valorfijoc = 6;
            valorfijof = 0;
        } else if (0 <= CooColumna && CooColumna <= 2 && 3 <= CooFila && CooFila <= 5) {
            valorfijoc = 0;
            valorfijof = 3;
        } else if (3 <= CooColumna && CooColumna <= 5 && 3 <= CooFila && CooFila <= 5) {
            valorfijoc = 3;
            valorfijof = 3;
        } else if (6 <= CooColumna && CooColumna <= 8 && 3 <= CooFila && CooFila <= 5) {
            valorfijoc = 6;
            valorfijof = 3;
        } else if (0 <= CooColumna && CooColumna <= 2 && 6 <= CooFila && CooFila <= 8) {
            valorfijoc = 0;
            valorfijof = 6;
        } else if (3 <= CooColumna && CooColumna <= 5 && 6 <= CooFila && CooFila <= 8) {
            valorfijoc = 3;
            valorfijof = 6;
        } else if (6 <= CooColumna && CooColumna <= 8 && 6 <= CooFila && CooFila <= 8) {
            valorfijoc = 6;
            valorfijof = 6;
        }
        for (tipoEntero fila = valorfijof; fila <= valorfijof + 2; fila++) {
            for (tipoEntero columna = valorfijoc; columna <= valorfijoc + 2; columna++) {
                if (pMatriz[fila][columna] == valor) {
                    cout<<"Error de validacion en el cuadrante\n";
                    return false;
                }
            }
        }
    }

    return true;
}

bool Sudoku::validar_completo(){
    for(auto fila=0;fila<dimension;fila++){
        for(auto columna=0;columna<dimension;columna++){
            if(pMatriz[fila][columna]==0)
                return false;
        }
    }

    return true;

}

bool Sudoku::ValidarNumero(tipoEntero num){
    if(dimension == 9) {
        if (num >= 0 && num <= 9)
            return false;
    }
    if(dimension == 4){
        if(num>=0 && num<=4)
            return false;
    }
    cout << "Valor Inválido\n";
    return true;
}

bool Sudoku::ValidarCoordenadas(tipoEntero fila, tipoEntero columna){
    fila -=65;
    columna-=49;

    if(dimension == 9){
        if(0<=fila && fila<=8 && 0<=columna && columna<=8)
            return false;
    }
    if(dimension == 4){
        if(0<=fila && fila<=3 && 0<=columna && columna<=3)
            return false;
    }
    cout << "Coordenadas Inválidas\n";
    return true;
}
