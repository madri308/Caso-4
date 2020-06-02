//
// Created by emema on 6/2/2020.
//

#include "getNumbersInScreen.h"

getNumbersInScreen::getNumbersInScreen(std::vector<std::vector<int>> lines) {
    //lines = [[xSalida , ySalida , xLlegada , yLlegada]
    int xLehemer = 30;
    int probabilidadCero,probabilidadUno,probabilidadDos,probabilidadTres,probabilidadCuatro,probabilidadCinco,probabilidadSeis,probabilidadSiete,probabilidadOcho,probabilidadNueve;
    probabilidadCero=probabilidadUno=probabilidadDos=probabilidadTres=probabilidadCuatro=probabilidadCinco=probabilidadSeis=probabilidadSiete=probabilidadOcho=probabilidadNueve = 0;
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
                    probabilidadCero = probabilidadCero + 25; //Mal, validar que no sean 4 lineas verticales
                    probabilidadUno = 100;
                    probabilidadDos = probabilidadDos + 33;
                    probabilidadTres = probabilidadTres + 25; //Mal, validar que no sean 4 lineas verticales
                    probabilidadCuatro = probabilidadCuatro + 30;
                    probabilidadSeis = probabilidadSeis + 20;
                    probabilidadSiete = probabilidadSiete + 50;
                    probabilidadOcho = probabilidadOcho + 20;
                    probabilidadNueve = probabilidadNueve + 20;
                }else{
                    //es diagonal
                    probabilidadDos = probabilidadDos + 33;
                    probabilidadCuatro = probabilidadCuatro + 30;
                    probabilidadCinco = probabilidadCinco + 33;
                    probabilidadSiete = probabilidadSiete + 50;
                }
            }
        }else{//saleVertical
            if(xLlegada == 0){
                //es diagonal
            }else{
                if(abs((xSalida - xLlegada)) < 10){
                    //es rectaVertical
                    probabilidadCero = probabilidadCero + 25; //Mal, validar que no sean 4 lineas verticales
                    probabilidadUno = 100;
                    probabilidadDos = probabilidadDos + 33;
                    probabilidadTres = probabilidadTres + 25; //Mal, validar que no sean 4 lineas verticales
                    probabilidadCuatro = probabilidadCuatro + 30;
                    probabilidadSeis = probabilidadSeis + 20;
                    probabilidadSiete = probabilidadSiete + 50;
                    probabilidadOcho = probabilidadOcho + 20;
                }else{
                    //es diagonal
                    probabilidadDos = probabilidadDos + 33;
                    probabilidadCuatro = probabilidadCuatro + 30;
                    probabilidadCinco = probabilidadCinco + 33;
                    probabilidadSiete = probabilidadSiete + 50;
                    probabilidadNueve = probabilidadNueve + 20;
                }
            }
        }

    }

}

int getNumbersInScreen::getRandomLehemer(int x) {
    return (75*x)%101 ;
}
