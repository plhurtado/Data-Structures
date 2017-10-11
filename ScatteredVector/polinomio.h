/*
 * polinomio.h
 *
 * Copyright  (C) Isidora Reina Molina y Pedro Luis Hurtado González
*/
#ifndef __POLINOMIO_H
#define __POLINOMIO_H

#include <map>
#include <utility> 
#include <cassert> 
#include <iostream>

using namespace std;

//! Clase polinomio
/*! polinomio:: polinomio, getGrado, getCoeficiente, setGrado, setCoeficiente, 
* operator= , operator+, operator-, begin, end.
* Descripción
* Un polinomio es una clase que utiliza un contenedor de tipo vectorD (completar)
*/

template <typename T>
class polinomio{
public:
class iterator;
class const_iterator;

	/** @brief constructor primitivo. 
	@post define la entrada nula como el polinomio que hace refencia al valor por defecto del vector
	*/
	polinomio();

	/** @brief constructor de copia
	@param[in] p polinomio a copiar
	*/
	polinomio(const polinomio<T> & p);

	/** @brief constructor a partir de un vector
	@param[in] v vector a partir del que crear el polinomio
	*/
	polinomio(const vectorD<T> & v);

	/** @brief destructor
	@post libera memoria 
	*/
	~polinomio();

	/** @brief obtener grado
	@post devuelve el grado del polinomio
	@return el grado del polinomio 
	*/
	const int getGrado();

	/** @brief obtener coeficiente
	@param i grado
	@post devuelve el coeficiente del polinomio en el grado i sin modificarlo
	@return el coeficiente del polinomio 
	*/
	const T & getCoeficiente(const int & i);

	/** @brief modificar el grado de un polinomio
	@param i grado a modificar
	@param coef coeficiente del grado
	*/
	void setGrado(const int & i, const T coef);

	/** @brief modificar el coeficiente de un polinomio
	@param i grado del coeficiente a modificar 
	*/
	void setCoeficiente(const int & i);

	/** @brief operador de asignación
	@param[in] p polinomio a copiar.
 	@return la refencia al polinomio
	*/
	polinomio<T> & operator= (const polinomio<T> & p);

	/** @brief operador de suma
	@param[in] p polinomio a sumar 
 	@return el polinomio sumado al pasado por parámetro
	*/
	polinomio<T> operator+ (polinomio<T> & p);

	/** @brief operador de resta
	@param[in] p polinomio a restar 
 	@return el polinomio restado al pasado por parámetro
	*/
	polinomio<T> operator- (polinomio<T> & p);

	/** @brief iterador al principio del polinomio
 	@return un iterator al principio del polinomio
	*/
	iterator begin();

	/** @brief iterador al final del polinomio
 	@return un iterator al final del polinomio
	*/
	iterator end();

	/** @brief iterador constante al principio del polinomio
 	@return un iterator constante al principio del polinomio
	*/
	const_iterator cbegin() const;

	/** @brief iterador constante al final del polinomio
 	@return un iterator constante al final del polinomio
	*/
	const_iterator cend() const;

private:
	vectorD <T> vect; //Vector disperso

public:
	class iterator{
	public:
		friend class polinomio;
		
		/** @brief constructor primitivo 
		*/
		iterator() {} 

		/** @brief constructor de copia
		@param[in] d iterador a copiar
		*/
	    iterator(const iterator & d): ite(d.ite) {}

	    /** @brief operador *
		@return el par al que apunta el iterador del conjunto de valores no nulos
		*/
	    const pair<int, T > & operator *(  ) { return (*ite);}

	    /** @brief operador preincremento
		@return la referencia al siguiente iterador
		*/
	    iterator & operator++( ) {++ite; return *this;}  

	    /** @brief operador postincremento
	    @post el iterador se incrementa
		@return el iterador sin incrementar
		*/
	    iterator operator++(int ) {iterator tmp(*this); ++ite; return tmp;}  

	    /** @brief operador comparacion
	    @param[in] iterador a comparar
		@return true si this y el iterador d son iguales
		*/
	    bool operator == (const iterator & d) {return ite == d.ite;}

	    /** @brief operador comparacion
	    @param[in] iterador a comparar
		@return true si this y el iterador d son distintos
		*/
	    bool operator != (const iterator & d) {return ite != d.ite; }
	  
	  private:
	    typename vectorD<T>::stored_iterator ite; 
	};
	
	class const_iterator{
  	public:
	    friend class polinomio;
	    
	    /** @brief constructor primitivo 
		*/
	    const_iterator() ;

	    /** @brief constructor de copia
		@param[in] d iterador a copiar
		*/
	    const_iterator(const const_iterator & d): ite(d.ite) {}

	    /** @brief constructor que transforma un iterador en un iterador constante
		@param[in] d iterador a copiar
		*/
	    const_iterator(const iterator & d): ite(d.ite) {};

	    /** @brief operador *
		@return un valor T constante al que apunta el iterador
		*/
	    const  T  &  operator *(  ) { return (*ite);}

	    /** @brief operador preincremento
		@return la referencia al siguiente iterador
		*/
	    const_iterator & operator++( ) {++ite; return *this;} 

	    /** @brief operador postincremento
	    @post el iterador se incrementa
		@return el iterador sin incrementar
		*/
	    const_iterator operator++(int ) {iterator tmp(*this); ++ite; return tmp;} 

	    /** @brief operador comparacion
	    @param[in] iterador a comparar
		@return true si this y el iterador d son iguales
		*/
	    bool operator == (const const_iterator & d) {return ite == d.ite;}

	    /** @brief operador comparacion
	    @param[in] iterador a comparar
		@return true si this y el iterador d son distintos
		*/
	    bool operator != (const const_iterator & d) {return ite != d.ite; }
    
  	private:
	    typename vectorD<T>::const_stored_iterator ite; 
	};
};

#include "polinomio.hxx"

#endif
