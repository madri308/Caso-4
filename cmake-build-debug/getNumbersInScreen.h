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
    std::vector<int> returnResults();
    getNumbersInScreen(std::vector<std::vector<int>> lines);
    int checkOverflow(int originalN, int limiteN);
};


#endif //LINEAS_GETNUMBERSINSCREEN_H
