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
    std::unordered_map<int,int> result;
    getNumbersInScreen(std::vector<std::vector<int>> lines);
    std::unordered_map<int,int> returnResults();
};


#endif //LINEAS_GETNUMBERSINSCREEN_H
