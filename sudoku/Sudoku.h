//
// Created by Carlota Brauckmeyer on 11/9/18.
//

#ifndef SUDOKY_SUDOKU_H
#define SUDOKY_SUDOKU_H

#include "Metodos_Generales.h"

class Sudoku {
private:
    tipoEntero ** pMatriz = nullptr;
    tipoEntero dimension;
    tipoEntero sudoku_base2x2[4][4]={ 0,3,0,1,
                                      0,0,0,2,
                                      0,2,0,0,
                                      0,0,0,0};
    tipoEntero sudoku_base3x3[9][9]={0,7,0,0,2,0,0,5,0,
                                     0,0,3,0,0,0,0,0,0,
                                     0,0,0,0,3,0,9,0,0,
                                     0,0,0,0,0,0,0,0,0,
                                     4,0,0,0,0,0,0,9,0,
                                     0,0,0,1,7,0,0,0,3,
                                     0,0,5,0,0,0,0,0,7,
                                     3,0,0,0,8,6,0,0,0,
                                     0,0,1,0,0,0,0,0,0};
public:
    Sudoku(){};
    Sudoku(tipoEntero dimension);
    void crear_matriz();
    void completar_sudoku();
    void imprimir_sudoku(std::ostream &os);
    void coordenadas();
    bool validar_cuadrante(tipoEntero CooColumna,tipoEntero CooFila, tipoEntero valor);
    bool validar_lineas(tipoEntero columna, tipoEntero fila, tipoEntero valor);
    bool validar_completo();
    bool ValidarNumero(tipoEntero num);
    bool ValidarCoordenadas(tipoEntero fila, tipoEntero columna);


};



#endif //SUDOKY_SUDOKU_H
