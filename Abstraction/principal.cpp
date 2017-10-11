/*
* Copyright  (C) Isidora Reina Molina y Pedro Luis Hurtado González
*/

#include "diccionario.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <assert.h>
#include <stdio.h>
#include <cstdio>
#include <time.h>

using namespace std;


void load(diccionario & d, const string & s){

    meteorito meteor;
    string nombre;
    string codigosjuntos;
    string code;
    double masa;
    bool encontrado;
    string anio;
    double latitud;
    double longitud;
    vector <string> identificadores; //Vector utilizado para la eficiencia en la busqueda
    int contador;
    clock_t start,end;

    string linea;
    int posicion;

    ifstream miarchivo;
    miarchivo.open (s.c_str());
    getline(miarchivo, linea);      //Quitamos la primera linea del archivo que son las cabezeras de las columnas

    while (!(miarchivo.eof())){
        getline(miarchivo, linea);

        posicion = linea.find_first_of(";");
        nombre = linea.substr (0,posicion);
        meteor.first = nombre;
        identificadores.push_back(nombre);
        linea= linea.substr (posicion+1);

        posicion = linea.find_first_of(";");
        codigosjuntos = linea.substr (0, posicion);
        linea = linea.substr(posicion+1);

        int posC = 0;
        while (posC != string::npos){
            posC=codigosjuntos.find_first_of(",");
            code= codigosjuntos.substr(0,posC);
            meteor.second.setCode(code);
            codigosjuntos = codigosjuntos.substr(posC+1);
        }

        for(int i=0; i<linea.length(); i++)
            if(linea[i] ==  ',')
                linea[i]= '.';

        posicion = linea.find_first_of(";");
        masa = atof (linea.substr (0, posicion).c_str());
        meteor.second.setMas(masa);
        linea= linea.substr (posicion+1);

        posicion = linea.find_first_of(";");
        if (linea.substr(0,posicion)=="Found")
            encontrado = true;
        else
            encontrado = false;
        meteor.second.setFall(encontrado);
        linea= linea.substr (posicion+1);

        posicion = linea.find_first_of(";");
        anio = linea.substr(0, posicion);
        meteor.second.setYear(anio);
        linea= linea.substr (posicion+1);

        posicion = linea.find_first_of(";");
        latitud = atof (linea.substr (0, posicion).c_str());
        meteor.second.setLat(latitud);
        linea= linea.substr (posicion+1);

        posicion = linea.find_first_of(";");
        longitud = atof (linea.substr (0, posicion).c_str());
        meteor.second.setLong(longitud);

        d.insert(meteor);
        posicion = 0;
    }

    miarchivo.close();
}

int main(){

    diccionario meteoritos;

    load(meteoritos, "meteorites_all.csv");

   return 0;
}
