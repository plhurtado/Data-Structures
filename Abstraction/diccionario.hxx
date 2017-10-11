/*
 * diccionario.h
 *
 * Copyright  (C) Juan F. Huete
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


/**
 @todo implementa esta función
*/
diccionario::diccionario(){

}

/**
 @todo implementa esta función
*/
diccionario::diccionario (const diccionario & d){
    dic=d.dic;
}


/**
 @todo implementa esta función
*/
pair<diccionario::entrada,bool> & diccionario::find( const nombreM & s) const{
    diccionario::entrada meteor;
    bool encontrado = false;
    pair <meteor , encontrado> resultado;
    for (int i=0;i<dic.size() &&!encontrado;i++){
        if (dic[i].first == s){
            encontrado = true;
            meteor = dic[i]
            return resultado;
    }
    return resultado;
}

/**
 @todo implementa esta función
*/
defM & diccionario::operator[](const nombreM & s) {

}


/**
 @todo implementa esta función
*/
const defM & diccionario::operator[](const nombreM & s) const{

}


/**
 @todo implementa esta función
*/
bool diccionario::insert(const diccionario::entrada & e) const{
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
    for (int i=0; i<D.dic.size(),i++){
        sal << "Identificador: "
        sal << D[i].dic.first << endl;
        sal << D[i].dic.second << endl;
    }
    return sal;
}


