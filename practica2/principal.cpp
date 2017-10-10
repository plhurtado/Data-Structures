#include "diccionario.h"
#include "meteorito.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <assert.h>
#include <stdio.h>
#include <cstdio>

using namespace std;


void load(diccionario & d, const string & s){
    int inicio = 0;
    int posicion;
    string linea;
    meteorito meteor;
    string nombre;
    string codigosjuntos;
    vector<string> codigos;
    double masa;
    bool encontrado;
    string anio;
    double latitud;
    double longitud;

    cout << "Entra load";
    ifstream miarchivo;
    miarchivo.open ("meteorites_all.csv");

    while (!(miarchivo.eof())){

        getline(miarchivo, linea);

        posicion = linea.find_first_of(";", inicio);
        nombre = linea.substr (inicio, posicion-1);
        inicio = posicion+1;
        cout << nombre << " ";

        posicion = linea.find_first_of(";", inicio);
        codigosjuntos = linea.substr (inicio , posicion-1);
        int iniC = 0;
        int posC = 0;
        int j=0;
        //cout << codigosjuntos<< endl;
        /*
        while (posC != string::npos){
            posC=codigosjuntos.find_first_of(",", iniC);
            codigos.push_back(codigosjuntos.substr(iniC, posC-1));
            iniC = posC+1;
            j++;
            cout << "correcto";
        }
        /*
        inicio = posicion+1;

        posicion = linea.find_first_of(";", inicio);
        masa = atof (linea.substr (inicio, posicion-1).c_str());
        inicio = posicion+1;

        posicion = linea.find_first_of(";", inicio);
        if (linea.substr(inicio, posicion-1)=="Found")
            encontrado = true;
        else
            encontrado = false;
        inicio = posicion+1;

        posicion = linea.find_first_of(";", inicio);
        anio = linea.substr(inicio, posicion-1);
        inicio = posicion+1;

        posicion = linea.find_first_of(";", inicio);
        latitud = atof (linea.substr (inicio, posicion-1).c_str());
        inicio = posicion+1;

        posicion = linea.find_first_of(";", inicio);
        longitud = atof (linea.substr (inicio, posicion-1).c_str());

        meteor.first = nombre;
        for (int i=0; i<codigos.size(); i++)
            meteor.second.setCode(codigos[i]);
        meteor.second.setMas(masa);
        meteor.second.setFall(encontrado);
        meteor.second.setYear(anio);
        meteor.second.setLat(latitud);
        meteor.second.setLong(longitud);

        d.insert(meteor);
*/
        inicio = 0;
        posicion = 0;
    }

    miarchivo.close();
}

int main()
{
    cout << "punto0";


    pair<diccionario::entrada,bool> p;


    cout << "punto1";
    diccionario meteoritos;
    cout << "generado";

    load(meteoritos, "meteorites_all.csv");

   return 0;
}
