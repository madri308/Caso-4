#include <iostream>
#include "cmake-build-debug/getNumbersInScreen.h"

int main() {
    std::vector<std::vector<int>> lineaVertical = {{100,0,107,1080}};
    std::vector<std::vector<int>> lineaHorizontal = {{0,200,920,207}};
    std::vector<std::vector<int>> lineaDiagonalCreciente = {{110,0,90,1080}};
                                        //horizontal    vertical          horizontal      diagonalCreciente
    std::vector<std::vector<int>> mix = {{0,200,920,207},{100,0,107,1080},{0,100,920,107},{110,0,90,1080}};


    getNumbersInScreen *l = new getNumbersInScreen(lineaHorizontal);
    std::vector<std::vector<int>> results = l->returnResults();
    for(int esta = 0 ; esta < 10 ; esta++){
       std::cout<<esta<<": "<<results.at(esta).at(0)<<" probabilidad: "<<results.at(esta).at(1)<<std::endl;
    }
    return 0;
}
