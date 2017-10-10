/*
 * meteorito.h
 *
 * Copyright  (C) Isidora Reina Molina y Pedro Luis Hurtado González
*/

#ifndef __METEORITO_H
#define __METEORITO_H
#include <string>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

//! Clase defM, asociada a la definición de un meteorito
/*! defM::defM .....
 * Descripción contiene toda la información asociada a un meteorito
*/


class defM {
 public:
 /** @brief constructor primitivo.
	*/
  defM();

  /** @brief constructor de copia.
	@param[in] x defM a copiar
	*/
  defM(const defM & x);

  /** @brief Introduce un codigo a la definición si este no existe.
    @param[in] s codigo a insertar
    @return booleano True si se ha introducido con exito, False si el codigo ya existe o está vacío
    */
  bool setCode(const string & s);

  /** @brief Introduce la masa del meteorito.
    @param[in] m masa a insertar
    */
  void setMas(const double &  m);

  /** @brief Introduce booleano sobre el hallazgo del meteorito.
    @param[in] f valor a insertar
    */
  void setFall(bool f);

  /** @brief Introduce el año de aparición del meteorito.
    @param[in] y año a insertar
    */
  void setYear(const string & y);

  /** @brief Introduce la latitud de las coordenadas de aparicion.
    @param[in] lat latitud a insertar
    */
  void setLat(double & lat);

  /** @brief Introduce la longitud de las coordenadas de aparicion.
    @param[in] longi longitud a insertar
    */
  void setLong(double & longi);

  /** @brief Devuelve los codigos de un meteorito.
    @return vector <string> codigo
    */
  vector <string> getCodes( );

  /** @brief Devuelve la masa de un meteorito.
    @return double masa
    */
  double getMas( );

  /** @brief Devuelve si el meteorito ha sido encontrado.
    @return bool encontrado
    */
  bool getFall( );

  /** @brief Devuelve el año de aparición de un meteorito.
    @return string anio
    */
  string getYear( );

  /** @brief Devuelve la latitud de un meteorito.
    @return double latitud
    */
  double getLat( );

  /** @brief Devuelve la longitud de un meteorito.
    @return double longitud
    */
  double getLong( );

 private:
    friend  ostream& operator<< ( ostream& , const defM & );

    vector<string> codigo;
    double masa;
    bool encontrado;
    string anio;
    double latitud;
    double longitud;
};


typedef string nombreM;

typedef pair<nombreM,defM> meteorito;

ostream & operator<< ( ostream& os, const meteorito & meteor);

#include "meteorito.hxx"
#endif
