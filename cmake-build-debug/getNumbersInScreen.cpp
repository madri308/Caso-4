//
// Created by emema on 6/2/2020.
//

#include "getNumbersInScreen.h"

getNumbersInScreen::getNumbersInScreen(std::vector<std::vector<int>> lines) {
    //lines = [[xSalida , ySalida , xLlegada , yLlegada]
    std::vector<int> probabilidadFinal = {0,0,0,0,0,0,0,0,0,0};
    for(int line = 0 ; line < lines.size() ; line++){
        int xSalida = lines.at(line).at(0);
        int ySalida = lines.at(line).at(1);
        int xLlegada = lines.at(line).at(2);
        int yLlegada = lines.at(line).at(3);
        //saleHorizontal
        if(xSalida == 0){
            if(yLlegada == 0){
                //es diagonal
            }else{
                if(abs((ySalida - yLlegada)) < 10){
                    //es rectaHorizontal
                    probabilidadFinal.at(0) = probabilidadFinal.at(0) + 25; //Mal, validar que no sean 4 lineas verticales
                    probabilidadFinal.at(1) = 100;
                    probabilidadFinal.at(2) = probabilidadFinal.at(2) + 33;
                    probabilidadFinal.at(3) = probabilidadFinal.at(3) + 25;
                    probabilidadFinal.at(4) = probabilidadFinal.at(4) + 30;
                    probabilidadFinal.at(6) = probabilidadFinal.at(6) + 20;
                    probabilidadFinal.at(7) = probabilidadFinal.at(7) + 50;
                    probabilidadFinal.at(8) = probabilidadFinal.at(8) + 20;
                    probabilidadFinal.at(9) = probabilidadFinal.at(9) + 20
                }else{
                    //es diagonal
                    probabilidadFinal.at(2) = probabilidadFinal.at(2) + 33;
                    probabilidadFinal.at(4) = probabilidadFinal.at(4) + 30;
                    probabilidadFinal.at(5) = probabilidadFinal.at(5) + 33;
                    probabilidadFinal.at(7) = probabilidadFinal.at(7) + 50;
                }
            }
        }else{//saleVertical
            if(xLlegada == 0){
                //es diagonal
            }else{
                if(abs((xSalida - xLlegada)) < 10){
                    //es rectaVertical
                    probabilidadFinal.at(0) = probabilidadFinal.at(0) + 25; //Mal, validar que no sean 4 lineas verticales
                    probabilidadFinal.at(1) = 100;
                    probabilidadFinal.at(2) = probabilidadFinal.at(2) + 33;
                    probabilidadFinal.at(3) = probabilidadFinal.at(3) + 25;
                    probabilidadFinal.at(4) = probabilidadFinal.at(4) + 30;
                    probabilidadFinal.at(6) = probabilidadFinal.at(6) + 20;
                    probabilidadFinal.at(7) = probabilidadFinal.at(7) + 50;
                    probabilidadFinal.at(8) = probabilidadFinal.at(8) + 20;
                    probabilidadFinal.at(9) = probabilidadFinal.at(9) + 20
                }else{
                    //es diagonal
                    probabilidadFinal.at(2) = probabilidadFinal.at(2) + 33;
                    probabilidadFinal.at(4) = probabilidadFinal.at(4) + 30;
                    probabilidadFinal.at(5) = probabilidadFinal.at(5) + 33;
                    probabilidadFinal.at(7) = probabilidadFinal.at(7) + 50;
                }
            }
        }

    }

}

