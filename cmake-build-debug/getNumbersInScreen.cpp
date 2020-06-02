//
// Created by emema on 6/2/2020.
//

#include "getNumbersInScreen.h"

getNumbersInScreen::getNumbersInScreen(std::vector<std::vector<int>> lines) {
    //lines = [[xSalida , ySalida , xLlegada , yLlegada]
    for(int line = 0 ; line < lines.size() ; line++){
        int xSalida = lines.at(line).at(0);
        int ySalida = lines.at(line).at(1);
        int xLlegada = lines.at(line).at(2);
        int yLlegada = lines.at(line).at(3);
        //saleHorizontal
        if(xSalida == 0){
            if(yLlegada = 0){
                //es diagonal
            }else{
                if(abs((ySalida - yLlegada)) < 10){
                    //es recta
                }else{
                    //es diagonal
                }
            }
        }else{//saleVertical
            if(xLlegada = 0){
                //es diagonal
            }else{
                if(abs((xSalida - xLlegada)) < 10){
                    //es recta
                }else{
                    //es diagonal
                }
            }
        }

    }

}
