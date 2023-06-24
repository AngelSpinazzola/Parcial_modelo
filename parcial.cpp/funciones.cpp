#include <iostream>
#include <clocale>
#include "funciones.h"
#include <string>

using namespace std;

void cargarRegistro(int matrizPuntoA[][4], bool vecPuntoB[], float matrizPunto3[][7], float vecPunto4[])
{
    int idVenta, idAutor, idGenero, precio, paginasDelLibro, idSucursal;

    cout << "Ingresar ID de Venta: ";
    cin >> idVenta;

    while(idVenta != 0)
    {
        cout << "Ingresar ID de Autor: ";
        cin >> idAutor;
        cout << "Ingresar ID de Género Literario: ";
        cin >> idGenero;
        cout << "Ingresar precio: ";
        cin >> precio;
        cout << "Ingresar páginas del libro: ";
        cin >> paginasDelLibro;
        cout << "Ingresar ID de Sucursal: ";
        cin >> idSucursal;

        //Registro punto A
        switch(idSucursal)
        {
        case 1000:
            matrizPuntoA[idGenero-1][0]++;
            break;
        case 2000:
            matrizPuntoA[idGenero-1][1]++;
            break;
        case 3000:
            matrizPuntoA[idGenero-1][2]++;
            break;
        case 4000:
            matrizPuntoA[idGenero-1][3]++;
            break;
        }
        //Registro punto B
        if(paginasDelLibro > 1200)
        {
            vecPuntoB[idAutor-500] = true;
        }
        //Registro punto C ( La fila 0 representa el conteo de ventas, la fila 1 el total $ en ventas, y las columnas el género.
        matrizPunto3[0][idGenero-1]++;
        matrizPunto3[1][idGenero-1]+=precio;
        //Registro punto D
        vecPunto4[idAutor-500]+=precio;

        cout << "Ingresar ID de Venta: ";
        cin >> idVenta;
    }
}
void Punto1(int matrizPunto1[][4])
{
    int genero, sucursal, id;
    bool noVendioLibrosTerror, noVendioLibrosCiencia;

    for(sucursal = 0; sucursal < 4; sucursal++)
    {
        for(genero = 0; genero < 7; genero++)
        {
            if(genero == 0)
            {
                if(matrizPunto1[genero][sucursal] == 0)
                {
                    noVendioLibrosTerror = false;
                }
                else{
                    noVendioLibrosTerror = true;
                }
            }
            if(genero == 3){
                if(matrizPunto1[genero][sucursal] == 0)
                {
                    noVendioLibrosCiencia = false;
                }
                else{
                    noVendioLibrosCiencia = true;
                }
            }
        }
        if(noVendioLibrosTerror == false && noVendioLibrosCiencia == false)
        {
            id = (sucursal+1) * 1000;
            cout << "PUNTO 1) El ID #" << id << " no vendio libros del género Terror ni Ciencia Ficción." << endl;
        }
    }
}
void Punto2(bool vecPuntoB[])
{
    int i, contAutores=0;
    for(i=0; i<1000; i++){
        if(vecPuntoB[i] == true)
        {
            contAutores++;
        }
    }
    cout << "PUNTO 2) La cantidad de autores que al menos registraron una venta de un libro de más de 1200 páginas es: " << contAutores << endl;
}
void Punto3(float matrizPunto3[][7])
{
    float promedio;
    bool huboVenta;
    int f, c;

    string nombresDeGeneros[7] = {"Terror", "Biografía", "Novela", "Ciencia ficción", "Historia", "Ciencia", "Salud"};

    for(c=0; c<7; c++)
    {
        huboVenta = false;
        for(f=0; f<2; f++)
        {
            //Corroboro si hubo una venta para no dividir por 0.
            if(matrizPunto3[f][c] > 0)
            {
                promedio = matrizPunto3[1][c] / matrizPunto3[0][c];
                huboVenta = true;
            }
        }
        if(huboVenta == true)
        {
            cout << "PUNTO 3) Para el género " << nombresDeGeneros[c] << " el promedio de precio de venta fue: " << promedio << endl;
        }
    }
}
void Punto4(float vecPunto4[])
{
    float recaudacionMaxima;
    int i, idAutor;

    for(i=0; i<1000; i++)
    {
        if(i == 0)
        {
            recaudacionMaxima = vecPunto4[i];
            idAutor = i + 500;
        }
        else if(vecPunto4[i] > recaudacionMaxima)
        {
            recaudacionMaxima = vecPunto4[i];
            idAutor = i + 500;
        }
    }
    if(recaudacionMaxima > 0)
    {
        cout << "PUNTO 4) El ID del autor que más recaudo en concepto de venta de libros es: #" << idAutor << endl;
    }
}
