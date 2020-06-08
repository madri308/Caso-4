//
// Created by emema on 6/2/2020.
//

#include <algorithm>
#include "getNumbersInScreen.h"

getNumbersInScreen::getNumbersInScreen(std::vector<std::vector<int>> lines) {
    std::srand(time(0));
    //lines = [[xSalida , ySalida , xLlegada , yLlegada]
    std::vector<int> probabilidadFinal, probabilidadDiagonalesDecrecientes, probabilidadLineasHorizontales, probabilidadLineasVerticales, probabilidadDiagonalesCreciente;
    probabilidadFinal =probabilidadDiagonalesDecrecientes=probabilidadLineasHorizontales=probabilidadLineasVerticales=probabilidadDiagonalesCreciente={0,0,0,0,0,0,0,0,0,0};
    for(int line = 0 ; line < lines.size() ; line++) {
        if (tipoDeLinea(lines.at(line)) == 1) {//VERTICAL
            probabilidadLineasVerticales.at(0) = checkOverflow((probabilidadLineasVerticales.at(0) + valorDeLinea),
                                                                    (180));
            probabilidadLineasVerticales.at(1) = checkOverflow((100),
                                                                    (99));
            probabilidadLineasVerticales.at(3) = checkOverflow((probabilidadLineasVerticales.at(3) + valorDeLinea),
                                                                    (90));
            probabilidadLineasVerticales.at(4) = checkOverflow((probabilidadLineasVerticales.at(4) + valorDeLinea),
                                                                     (90));
            probabilidadLineasVerticales.at(6) = checkOverflow((probabilidadLineasVerticales.at(6) + valorDeLinea),
                                                                     (180));
            probabilidadLineasVerticales.at(8) = checkOverflow((probabilidadLineasVerticales.at(8) + valorDeLinea),
                                                                     (180));
            probabilidadLineasVerticales.at(9) = checkOverflow((probabilidadLineasVerticales.at(9) + valorDeLinea),
                                                                     (180));
        } else if (tipoDeLinea(lines.at(line)) == 2) {//CRECIENTE
            probabilidadDiagonalesCreciente.at(7) = checkOverflow(
                    (probabilidadDiagonalesCreciente.at(7) + valorDeLinea), (90));
            probabilidadDiagonalesCreciente.at(2) = checkOverflow(
                    (probabilidadDiagonalesCreciente.at(2) + valorDeLinea), (90));
            probabilidadDiagonalesCreciente.at(4) = checkOverflow(
                    (probabilidadDiagonalesCreciente.at(4) + valorDeLinea), (90));
            probabilidadDiagonalesCreciente.at(5) = checkOverflow(
                    (probabilidadDiagonalesCreciente.at(5) + valorDeLinea), (180));
        } else if (tipoDeLinea(lines.at(line)) == 3) {//DECRECIENTE
            probabilidadDiagonalesDecrecientes.at(5) = checkOverflow(
                    (probabilidadDiagonalesDecrecientes.at(5) + valorDeLinea), (80));
        } else {//HORIZONTAL
            probabilidadLineasHorizontales.at(0) = checkOverflow((probabilidadLineasHorizontales.at(0) + valorDeLinea),
                                                                        (180));
            probabilidadLineasHorizontales.at(2) = checkOverflow((probabilidadLineasHorizontales.at(2) + valorDeLinea),
                                                                        (180));
            probabilidadLineasHorizontales.at(3) = checkOverflow((probabilidadLineasHorizontales.at(3) + valorDeLinea),
                                                                       (270));
            probabilidadLineasHorizontales.at(4) = checkOverflow((probabilidadLineasHorizontales.at(4) + valorDeLinea),
                                                                        (90));
            probabilidadLineasHorizontales.at(6) = checkOverflow((probabilidadLineasHorizontales.at(6) + valorDeLinea),
                                                                        (270));
            probabilidadLineasHorizontales.at(7) = checkOverflow((probabilidadLineasHorizontales.at(7) + valorDeLinea),
                                                                        (90));
            probabilidadLineasHorizontales.at(8) = checkOverflow((probabilidadLineasHorizontales.at(8) + valorDeLinea),
                                                                        (270));
            probabilidadLineasHorizontales.at(9) = checkOverflow((probabilidadLineasHorizontales.at(9) + valorDeLinea),
                                                                        (180));
        }
    }
    for(int numero = 0 ; numero < 10 ; numero++){
        probabilidadFinal.at(numero) = (probabilidadDiagonalesCreciente.at(numero) +
                                                probabilidadDiagonalesDecrecientes.at(numero) +
                                                probabilidadLineasHorizontales.at(numero) +
                                                probabilidadLineasVerticales.at(numero))/cantidadLineas[numero];
        int randGuiado = rand() % 100;
        if(randGuiado < probabilidadFinal.at(numero)){
            listOfResults.at(numero).at(0) = 1;
        }else{
            listOfResults.at(numero).at(0) = 0;
        }
        listOfResults.at(numero).at(1) = probabilidadFinal.at(numero);
    }
}

int getNumbersInScreen::checkOverflow(int originalN, int limiteN) {
    if(originalN > limiteN){
        return limiteN;
    }else{
        return originalN;
    }
}

std::vector<std::vector<int>> getNumbersInScreen::returnResults() {
    return listOfResults;
}

int getNumbersInScreen::tipoDeLinea(std::vector<int> linea) {
    float xSalida = linea.at(0);
    float ySalida = linea.at(1);
    float xLlegada = linea.at(2);
    float yLlegada = linea.at(3);
    valorDeLinea = 90;
    if(!isfinite(((ySalida-yLlegada)/(xSalida-xLlegada))) || abs(((ySalida-yLlegada)/(xSalida-xLlegada))) > 92){
        return 1;//vertical
    }else if (-(0,01) > ((ySalida-yLlegada)/(xSalida-xLlegada))){
        if(yLlegada == 0 || yLlegada == 920){
            valorDeLinea = 80;
        }
        return 2;//diagonalCreciente
    }else if ( 0.01 < ((ySalida-yLlegada)/(xSalida-xLlegada))){
        if(yLlegada == 0 || yLlegada == 920){
            valorDeLinea = 80;
        }
        return 3;//diagonalDecreciente
    }else{
        return 4;//horizontal
    }
}

