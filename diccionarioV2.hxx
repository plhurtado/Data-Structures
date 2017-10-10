/*
 * diccionario.h
 *
 * Copyright  (C) Isidora Reina Molina y Pedro Luis Hurtado González
 *
 * diccionario:: diccionario, end, find, operator[], size, max_element
 * tipos diccionario::entrada, diccionario::size_type
 *
 *
===================================================================================
Funcion de Abstraccion:
  @todo incluir funcion de abstracción
=====================================================================================
Invariante de la Representación:

  @todo incluir invariante dela representación
=====================================================================================
*/
#include <assert.h>
#include <string>
#include <vector>

using namespace std;

/**
 @todo implementa esta función
*/
diccionario::diccionario(){

}

/**
 @todo implementa esta función
*/
diccionario::diccionario (const diccionario & d){
    dic = d.dic;
}


/**
 @todo implementa esta función
*/
pair<diccionario::entrada,bool> diccionario::find( const nombreM & s) const{
    pair <diccionario::entrada, bool> resultado;
    pair <int, bool> encontrado;
    static defM porDefecto;
    meteorito meteor_defecto;


    encontrado = diccionario::findPosition(s);

    if (encontrado.second){
        resultado.first = dic[encontrado.first];
        resultado.second = encontrado.second;
        return resultado;
    }
    else{
        meteor_defecto.first = s;
        meteor_defecto.second = porDefecto;
        resultado.first = meteor_defecto;
        resultado.second = encontrado.second;
        return resultado;
    }
}

/**
 @todo implementa esta función
*/
defM & diccionario::operator[](const nombreM & s) {
    static pair <nombreM, defM> inserto;
    static pair <int,bool> busqueda;
    static defM porDefecto;
    vector<entrada>::iterator it;

    busqueda = diccionario::findPosition(s);
    if (busqueda.second)
        return dic[busqueda.first].second;
    else{
        it = dic.begin()+busqueda.first;
        inserto.first= s;
        inserto.second = porDefecto;
        dic.insert (it, inserto);
        return dic[busqueda.first].second;
        }
}


/**
 @todo implementa esta función
*/
const defM & diccionario::operator[](const nombreM & s) const{
    static pair <int,bool> busqueda;
    static defM porDefecto;

    busqueda = diccionario::findPosition(s);
    if (busqueda.second)
        return dic[busqueda.first].second;
    else
        return porDefecto;
}


/**
 @todo implementa esta función
*/
bool diccionario::insert(const diccionario::entrada & e){
    vector<entrada>::iterator pos_insertar;
    static pair <int,bool> busqueda;

    if (e.first != ""){
        busqueda = diccionario::findPosition(e.first);


        if (!busqueda.second){
            if (dic.size() != 0 && e.first > dic[busqueda.first].first){
                pos_insertar = dic.begin()+busqueda.first+1;
                dic.insert(pos_insertar, e);
            }
            else{
                pos_insertar = dic.begin()+busqueda.first;
                dic.insert(pos_insertar, e);
            }
            return true;
        }
        else
            return false;
    }
}

/**
 @todo implementa esta función
*/
diccionario & diccionario::operator=( const diccionario & org){
    dic.erase (dic.begin(), dic.end());
    for (int i=0; i<org.dic.size(); i++){
        dic[i] = org.dic[i];
    }
    return *this;
}

/** @brief numero de entradas en el diccionario
@post  No se modifica el diccionario.
*/

diccionario::size_type diccionario::size() const {
    diccionario::size_type sz = dic.size();
    return sz;
}

/**
 @todo implementa esta función
*/
bool diccionario::empty() const{
    return (dic.size()==0);
}


/**
 @todo implementa esta función
*/
bool diccionario::cheq_rep( ) const {
    for (int i=0; i<dic.size()-1; i++){
        for (int j=i+1; j<dic.size(); j++){
            if (dic[i].first == dic[j].first)
            return true;
        }
    }
    return false;
}

pair <int, bool> diccionario::findPosition (const nombreM &nombre)const{
    pair <int, bool> resultado;
    int inicio = 0;
    int fin = dic.size()-1;
    int mitad;

    while(inicio<=fin){
        mitad= (fin+inicio)/2;
        if (fin == inicio){
            if (dic[fin].first == nombre){
                resultado.first = fin;
                resultado.second = true;
                return resultado;
            }
            else{
                resultado.first = fin;
                resultado.second = false;
                return resultado;
            }
        }
        else{
            if (nombre == dic[mitad].first){
                resultado.first = mitad;
                resultado.second = true;
                return resultado;
            }
            else{
                if (nombre < dic[mitad].first )
                    fin = mitad-1;
                else
                    inicio = mitad+1;
            }
        }
    }
    resultado.first = 0;
    resultado.second = false;
    return resultado;
}

/**
 @todo implementa esta función
*/
ostream &  operator << ( ostream & sal, const diccionario & D){
    for (int i=0; i<D.dic.size();i++){
        sal << "Identificador: ";
        sal << D.dic[i].first << endl;
        sal << "Definicion Meteorito: " << endl;
        sal << D.dic[i].second << endl;
    }
    return sal;
}



