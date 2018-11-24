#include <iostream>
#include <fstream>
#include <string>
#include "Metodos_Generales.h"
#include "Sudoku.h"

using namespace std;


int main() {
    imprimir_menu();
    tipoEntero dimension = leer_dimensiones();
    Sudoku sudoku(dimension);
    sudoku.crear_matriz();
    sudoku.completar_sudoku();
    sudoku.imprimir_sudoku(cout);

    bool sudoku_completo = false;

    while(sudoku_completo == false) {
        sudoku.coordenadas();
        sudoku.imprimir_sudoku(cout);
        sudoku_completo = sudoku.validar_completo();
    }

    fstream archivo;
    archivo.open("Sudoku.txt",ios::out);
    sudoku.imprimir_sudoku(archivo);



}