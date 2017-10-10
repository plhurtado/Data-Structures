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
    diccionario::entrada meteor;
    bool encontrado = false;
    pair <diccionario::entrada, bool> resultado;
    for (int i=0;i<dic.size() &&!encontrado;i++){
        if (dic[i].first == s){
            encontrado = true;
            meteor = dic[i];
        }
    }
    resultado.first = meteor;
    resultado.second = encontrado;
    return resultado;
}

/**
 @todo implementa esta función
*/
defM & diccionario::operator[](const nombreM & s) {
    static pair <diccionario::entrada,bool> busqueda;
    static pair <nombreM, defM> inserto;
    busqueda = diccionario::find (s);
    defM porDefecto;

  if (busqueda.second)
        return busqueda.first.second;
    else
        inserto.first = s;
        inserto.second = porDefecto;
        diccionario::insert(inserto);
        return inserto.second;
}


/**
 @todo implementa esta función
*/
const defM & diccionario::operator[](const nombreM & s) const{
    static pair <diccionario::entrada,bool> busqueda;
    static defM porDefecto;

    busqueda = diccionario::find(s);
    if (busqueda.second)
        return busqueda.first.second;
    else
        return porDefecto;
}


/**
 @todo implementa esta función
*/
bool diccionario::insert(const diccionario::entrada & e){
    for (int i=0;i<dic.size();i++){
        if (dic[i].first == e.first)
            return false;
    }
    dic.push_back(e);
    return true;
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


