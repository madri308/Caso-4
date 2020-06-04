//
// Created by emema on 6/2/2020.
//

#include <algorithm>
#include "getNumbersInScreen.h"

getNumbersInScreen::getNumbersInScreen(std::vector<std::vector<int>> lines) {
    //lines = [[xSalida , ySalida , xLlegada , yLlegada]
    std::vector<int> probabilidadFinal, probabilidadDiagonalesDecrecientes, probabilidadLineasHorizontales, probabilidadLineasVerticales, probabilidadDiagonalesCreciente;
    probabilidadFinal =probabilidadDiagonalesDecrecientes=probabilidadLineasHorizontales=probabilidadLineasVerticales=probabilidadDiagonalesCreciente={0,0,0,0,0,0,0,0,0,0};

    for(int line = 0 ; line < lines.size() ; line++){
        int xSalida = lines.at(line).at(0);
        int ySalida = lines.at(line).at(1);
        int xLlegada = lines.at(line).at(2);
        int yLlegada = lines.at(line).at(3);
        //saleHorizontal
        if(xSalida == 0){
            if(yLlegada == 0 || yLlegada == 920){
                //es diagonal de y a x
                if(yLlegada == 0){
                    //creciente
                    probabilidadDiagonalesCreciente.at(7) = checkOverflow((probabilidadDiagonalesCreciente.at(7) + 80),(80));
                    probabilidadDiagonalesCreciente.at(2) = checkOverflow((probabilidadDiagonalesCreciente.at(2) + 80),(80));
                    probabilidadDiagonalesCreciente.at(4) = checkOverflow((probabilidadDiagonalesCreciente.at(4) + 80),(80));
                    probabilidadDiagonalesCreciente.at(5) = checkOverflow((probabilidadDiagonalesCreciente.at(5) + 80),(160));
                }else{
                    //decreciente
                    probabilidadDiagonalesDecrecientes.at(5) = checkOverflow((probabilidadDiagonalesDecrecientes.at(5) + 80),(80));
                }
            }else{
                if(abs((ySalida - yLlegada)) < 10){
                    //es rectaHorizontal
                    probabilidadLineasHorizontales.at(0) = checkOverflow((probabilidadLineasHorizontales.at(0) + 90),(180)); //Mal, validar que no sean 4 lineas verticales
                    probabilidadLineasHorizontales.at(1) = checkOverflow((100),(99));
                    probabilidadLineasHorizontales.at(2) = checkOverflow((probabilidadLineasHorizontales.at(2) + 90),(180));
                    probabilidadLineasHorizontales.at(3) = checkOverflow((probabilidadLineasHorizontales.at(3) + 90),(270));
                    probabilidadLineasHorizontales.at(4) = checkOverflow((probabilidadLineasHorizontales.at(4) + 90),(90));
                    probabilidadLineasHorizontales.at(6) = checkOverflow((probabilidadLineasHorizontales.at(6) + 90),(270));
                    probabilidadLineasHorizontales.at(7) = checkOverflow((probabilidadLineasHorizontales.at(7) + 90),(90));
                    probabilidadLineasHorizontales.at(8) = checkOverflow((probabilidadLineasHorizontales.at(8) + 90),(270));
                    probabilidadLineasHorizontales.at(9) = checkOverflow((probabilidadLineasHorizontales.at(9) + 90),(180));
                }else{
                    //es diagonal
                    if ((ySalida - yLlegada)<0){
                        //decrece
                        probabilidadDiagonalesDecrecientes.at(5) = checkOverflow((probabilidadDiagonalesDecrecientes.at(5) + 90),(90));
                    }else{
                        //crece
                        probabilidadDiagonalesCreciente.at(7) = checkOverflow((probabilidadDiagonalesCreciente.at(7) + 90),(90));
                        probabilidadDiagonalesCreciente.at(2) = checkOverflow((probabilidadDiagonalesCreciente.at(2) + 90),(90));
                        probabilidadDiagonalesCreciente.at(4) = checkOverflow((probabilidadDiagonalesCreciente.at(4) + 90),(90));
                        probabilidadDiagonalesCreciente.at(5) = checkOverflow((probabilidadDiagonalesCreciente.at(5) + 90),(180));

                    }
                }
            }
        }else if (ySalida == 0){//saleVertical
            if(xLlegada == 0 || xLlegada == 1080){
                //es diagonal de x a y
                if(xLlegada == 0){
                    //creciente
                    probabilidadDiagonalesCreciente.at(7) = checkOverflow((probabilidadDiagonalesCreciente.at(7) + 80),(80));
                    probabilidadDiagonalesCreciente.at(2) = checkOverflow((probabilidadDiagonalesCreciente.at(2) + 80),(80));
                    probabilidadDiagonalesCreciente.at(4) = checkOverflow((probabilidadDiagonalesCreciente.at(4) + 80),(80));
                    probabilidadDiagonalesCreciente.at(5) = checkOverflow((probabilidadDiagonalesCreciente.at(5) + 80),(160));
                }else{
                    //decreciente
                    probabilidadDiagonalesDecrecientes.at(5) = checkOverflow((probabilidadDiagonalesDecrecientes.at(5) + 80),(80));
                }
            }else{
                if(abs((xSalida - xLlegada)) < 10){
                    //es rectaVertical
                    probabilidadLineasVerticales.at(0) = checkOverflow((probabilidadLineasVerticales.at(0) + 90),(180)); //Mal, validar que no sean 4 lineas verticales
                    probabilidadLineasVerticales.at(1) = checkOverflow((100),(99));
                    probabilidadLineasVerticales.at(3) = checkOverflow((probabilidadLineasVerticales.at(3) + 90),(90));
                    probabilidadLineasVerticales.at(4) = checkOverflow((probabilidadLineasVerticales.at(4) + 90),(90));
                    probabilidadLineasVerticales.at(6) = checkOverflow((probabilidadLineasVerticales.at(6) + 90),(180));
                    probabilidadLineasVerticales.at(8) = checkOverflow((probabilidadLineasVerticales.at(8) + 90),(180));
                    probabilidadLineasVerticales.at(9) = checkOverflow((probabilidadLineasVerticales.at(9) + 90),(180));
                }else{
                    if((xSalida - xLlegada)>0){
                        //crece
                        probabilidadDiagonalesCreciente.at(7) = checkOverflow((probabilidadDiagonalesCreciente.at(7) + 90),(90));
                        probabilidadDiagonalesCreciente.at(2) = checkOverflow((probabilidadDiagonalesCreciente.at(2) + 90),(90));
                        probabilidadDiagonalesCreciente.at(4) = checkOverflow((probabilidadDiagonalesCreciente.at(4) + 90),(90));
                        probabilidadDiagonalesCreciente.at(5) = checkOverflow((probabilidadDiagonalesCreciente.at(5) + 90),(180));
                    }else{
                        //decrece
                        probabilidadDiagonalesDecrecientes.at(5) = checkOverflow((probabilidadDiagonalesDecrecientes.at(5) + 90),(90));
                    }
                }
            }
        }

    }
    for(int probabilidad = 0 ; probabilidad < 10 ; probabilidad++){
        std::vector<int> probabilidadDeCadaNum = {probabilidadDiagonalesCreciente.at(probabilidad),
                                              probabilidadDiagonalesDecrecientes.at(probabilidad),
                                              probabilidadLineasHorizontales.at(probabilidad),
                                              probabilidadLineasVerticales.at(probabilidad)};
        /*
        int divisor = 4-std::count(probabilidadDeCadaNum.begin(),probabilidadDeCadaNum.end(),0);
        if(divisor == 0){
            divisor = 1;
        }*/
        probabilidadFinal.at(probabilidad) = checkOverflow((probabilidadDiagonalesCreciente.at(probabilidad) +
                                                probabilidadDiagonalesDecrecientes.at(probabilidad) +
                                                probabilidadLineasHorizontales.at(probabilidad) +
                                                probabilidadLineasVerticales.at(probabilidad))/cantidadLineas[probabilidad],(99));
        int randGuiado = rand() % 100;
        if(randGuiado < probabilidadFinal.at(probabilidad)){
            listOfResults.at(probabilidad).at(0) = 1;
            listOfResults.at(probabilidad).at(1) = probabilidadFinal.at(probabilidad);
        }else{
            listOfResults.at(probabilidad).at(0) = 0;
            listOfResults.at(probabilidad).at(1) = probabilidadFinal.at(probabilidad);
        }
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

