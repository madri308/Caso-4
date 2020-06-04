//
// Created by emema on 6/2/2020.
//

#ifndef LINEAS_GETNUMBERSINSCREEN_H
#define LINEAS_GETNUMBERSINSCREEN_H


#include <vector>
#include <iostream>
#include <unordered_map>

class getNumbersInScreen {

public:
    std::vector<std::vector<int>> listOfResults = {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}};
    int cantidadLineas[10] = {2,1,2,2,3,3,2,2,2,2};
    getNumbersInScreen(std::vector<std::vector<int>> lines);
    int checkOverflow(int originalN, int limiteN);
    std::vector<std::vector<int>> returnResults();
};


#endif //LINEAS_GETNUMBERSINSCREEN_H
