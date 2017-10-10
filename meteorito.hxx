/*
*Copyright  (C) Isidora Reina Molina y Pedro Luis Hurtado González
*/
#include <assert.h>
#include <string>
#include <iterator>
#include <vector>
#include <algorithm>
#include <iostream>

defM::defM(){

}

defM::defM(const defM & x){
    codigo = x.codigo;
    masa = x.masa;
    encontrado = x.encontrado;
    anio = x.anio;
    latitud = x.latitud;
    longitud = x.longitud;
}

vector<string> defM::getCodes( ){
    return codigo;
}
double defM::getMas( ){
    return masa;
}

bool defM::getFall( ){
    return encontrado;
}

string defM::getYear( ){
    return anio;
}

double defM::getLat( ){
    return latitud;
}
double defM::getLong( ){
    return longitud;
}

bool defM::setCode(const string & s){
    codigo.clear();
    vector<string>::iterator posicion = find(codigo.begin(),codigo.end(),s);
    if (posicion != codigo.end())
        return false;
    else if(s != ""){
        codigo.push_back(s);
        return true;
    }
    else    return false;
}
void defM::setMas(const double &  m){
    masa = m;
}
void defM::setFall(bool f){
        if (f)
        encontrado = "Found";
    else
        encontrado = "fell";
}
void defM::setYear(const string & y){
    anio = y;
}
void defM::setLat(double & lat){
    latitud = lat;
}
void defM::setLong(double & longi){
    longitud = longi;
}

ostream & operator<< ( ostream& os, const defM & def){
    os << "Codigos: ";
    for(int i=0; i<def.codigo.size(); i++){
        os << def.codigo[i] << " " ;
    }
    os << endl;

    os << "Masa: " << def.masa << endl;
    os << "Encontrado: " << def.encontrado << endl;
    os << "Año: " << def.anio << endl;
    os << "Latitud: " << def.latitud << endl;
    os << "Longitud: " << def.longitud << endl;

    return os;

}

ostream & operator<< ( ostream& os, const meteorito & meteor){
    os << "Identificador: " << meteor.first << endl;
    os << meteor.second << endl;
    return os;
}
