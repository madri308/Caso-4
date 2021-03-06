//
// Created by emema on 6/2/2020.
//

#ifndef LINEAS_GETNUMBERSINSCREEN_H
#define LINEAS_GETNUMBERSINSCREEN_H


#include <vector>
#include <iostream>
#include <unordered_map>
#include <cstdlib>
#include <ctime>
#include <math.h>

class getNumbersInScreen {

public:
    int valorDeLinea = 0;
    std::vector<std::vector<int>> listOfResults = {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}};
    int cantidadLineas[10] = {4,1,3,4,3,3,5,2,5,4};
    getNumbersInScreen(std::vector<std::vector<int>> lines);
    int checkOverflow(int originalN, int limiteN);
    std::vector<std::vector<int>> returnResults();
    int tipoDeLinea(std::vector<int> linea);
};


#endif //LINEAS_GETNUMBERSINSCREEN_H
