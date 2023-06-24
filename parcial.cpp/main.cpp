#include <iostream>
#include <locale.h>
using namespace std;
#include "funciones.h"

int main()
{
    setlocale(LC_ALL, "Spanish");
    //Declaro matriz para guardar punto A, las filas representan los géneros y las columnas los id de sucursal
    int matrizPunto1[7][4]={};
    //
    bool vecPuntoB[1000]={};
    //
    float matrizPunto3[2][7]={};
    //
    float vecPunto4[1000]={};

    cargarRegistro(matrizPunto1, vecPuntoB, matrizPunto3, vecPunto4);
    Punto1(matrizPunto1);
    Punto2(vecPuntoB);
    Punto3(matrizPunto3);
    Punto4(vecPunto4);

    return 0;
}
