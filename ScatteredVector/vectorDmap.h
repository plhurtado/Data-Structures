/*
 * vectorD.h
 *
 * Copyright  (C) Isidora Reina Molina y Pedro Luis Hurtado González
*/
#ifndef __VECTORDISPERSO_H
#define __VECTORDISPERSO_H

#include <map>
#include <utility> 
#include <cassert> 


using namespace std;
template <typename  T >
class vectorD
{
public:
class stored_iterator; // iterador sobre elementos no nulos
class iterator; // iterador sobre todos los elementos del vector
class const_stored_iterator; //const iterador sobre elementos no nulos
class const_iterator; // const iterador sobre todos los elementos del vector
typedef unsigned int size_type;
      
/** @brief Constructor primitivo indicando valor nulo
  @param t valor nulo del vector
  @post en caso de no indicar el valor nulo, tomará el valor nulo del tipo del vector disperso
  */
vectorD( const  T  & t=  T () );

/** @brief Constructor de copia
  @param b vector disperso a copiar
  */   	
vectorD(  const vectorD< T > & b);  

/** @brief Constructor indicando tamaño y valor nulo
  @param numcomp numero de componentes del vector disperso
  @param t valor nulo del vector disperso
  @post todos los componentes tendran el valor por defecto o nulo
  */ 
vectorD( int numcomp, const  T  & t);

/** @brief Destructor 
  @post libera memoria
  */ 
~vectorD();


/** @brief Tamaño
  @return devuelve el tamaño del vector disperso
  */ 
size_type size() const;

/** @brief Valor nulo
  @return devuelve el valor nulo del vector disperso
  */ 
T  default_value( ) const;

/** @brief Vacio
  @return devuelve un bool indicando si el vector esta vacio
  */ 
bool empty();

/** @brief Asignación
  @param p indica el indice del que se va a cambiar el valor
  @param t valor a asignar
  @post el valor del indice (p) se cambiar por el valor del segundo parametro (t). No modifica el tamaño del vector
  */
void assign(int p, const  T  & t);

/** @brief Añadir elemento
  @param t elemento a insertar
  @post inserta en el vector el valor pasado (t) al final del vector. Aumenta el tamaño en 1
  */
void push_back( const  T  & t);

/** @brief Eliminar elemento
  @post elimina el ultimo elemento del vector. Decrementa el tamaño en 1
  */
void pop_back(  );

/** @brief Vaciar vector disperso
  @post el tamaño del vector pasa a ser cero
  */
void clear(); 

/** @brief Redimensionar
  @param s nuevo tamaño 
  @post el tamaño del vector pasa a ser el indicado como parametro (s). Si s es menor al tamaño del vector se eliminan los restantes, en caso contrario se ponen los nuevos elenmentos con el valor nulo 
  */
void resize(int s);

/** @brief Operador de asignación 
  @param x vector dinamico al que igualamos  
  @return devuelve la referencia al vector
  */
vectorD & operator= (const vectorD & x);

/** @brief Operador de acceso
  @param c indice del que queremos ver el coeficiente. Valor entre 0 y size-1
  @return valor del indice c-esimo 
  */
const  T  & operator[](int c) const;

/** @brief Operador de acceso seguro
  @param c indice del que queremos ver el coeficiente. Valor entre 0 y size-1, en caso contrario se aborta la ejecución
  @return valor en el indice c-esimo 
  */
const  T  & at(int c) const;

/** @brief Operador de comparación igualdad
  @param x vector con el que vamos a comparar
  @return true indicando si los vectores son iguales
  */
bool operator==( const vectorD & x);

/** @brief Operador de comparación diferencia
  @param x vector con el que vamos a comparar
  @return true indicando si los vectores son diferentes
  */
bool operator!=( const vectorD & x);

/** @brief Iterador begin sobre el vector
  @return iterador al primer elemento del vector disperso
  */
iterator begin();

/** @brief Iterador end sobre el vector
  @return iterador al siguiente elemento al último del vector disperso
  */
iterator end();

/** @brief Iterador constante begin sobre el vector
  @return iterador constante al primer elemento del vector disperso
  */
const_iterator cbegin() const;

/** @brief Iterador constante end sobre el vector
  @return iterador constante al siguiente elemento al último del vector disperso
  */
const_iterator cend() const;

/** @brief Iterador begin sobre los elementos no nulos del vector
  @return iterador al primer elemento no nulo del vector
  */
stored_iterator sbegin(); 

/** @brief Iterador end sobre los elementos no nulos del vector
  @return iterador al siguiente elemento al ultimo no nulo del vector
  */
stored_iterator send();

/** @brief Iterador constante begin sobre los elementos no nulos del vector
  @return iterador constante al primer elemento no nulo del vector
  */
const_stored_iterator csbegin() const; 

/** @brief Iterador constante end sobre los elementos no nulos del vector
  @return iterador constate al siguiente elemento al ultimo no nulo del vector
  */
const_stored_iterator csend() const;

private: // parte  privada

    map <int,T> vd; // map que aloja el vector disperso (solo los != valor nulo)
    int n_ele; // numero de elementos totals
    T   v_nulo; //valor nulo del vector
 
    /* FA e IR*/
    /* FA(rep): rep -- > vector
      (vd,n_ele,v_nulo):
         vd=[ (a,v1), (b,v2), ..., (n,vn) ]sb
         n_ele = M
         v_nulo = t
      --------->
      pos: 0 1 2 ... a-1 a ... x .... b....  ... n-1 n  n+1 ..... M-1
      val: t t t ....t  v1 ... t .... v2 ..  ... t   vn  t  ...... t
      */
     
    int checkRep();
    /* devuelve el tipo de fallo segun indica el IR */

    /* IR :
      IR(rep): rep ---> bool
     (vd,n_ele,v_nulo) :
      0 <= vd.size() < n_ele;  //Fallo tipo 1 
      vd[i].second != v_nulo, para todo i = 0, ..., vd.size()-1; // Fallo tipo 2 
      vd[i].first >=0, para todo i = 0, ..., vd.size()-1; // Fallo tipo 3
      vd[i].first < vd[j].first si i<j // Fallo tipo 4
     */
    
  /* ITERADORES SOBRE VECTOR DISPERSO */
public:
  
  
  public:
class stored_iterator{
  public:
    friend class vectorD;
    friend class vectorD< T >::const_stored_iterator;
    

    /** @brief Constructor primitivo
    */
    stored_iterator() {} 

    /** @brief Constructor de copia
    @param d const stored_iterator a copiar
    */
    stored_iterator(const stored_iterator & d) : ite(d.ite) {}

    /** @brief Operador de visualizacion
    @return devuelve el contenido de la direccion a la que apunta el iterador
    */
    const pair<int, T > & operator *(  ) { return (*ite);}

    /** @brief Operador de pre-incremento
    @return stored_iterator que apunta a la posicion donde este el siguiente valor no nulo
    */
    stored_iterator & operator++( ) {++ite; return *this;}  

    /** @brief Operador de post-incremento
    @return stored_iterator que apunta a la posicion donde este el siguiente valor no nulo
    */
    stored_iterator operator++(int ) {stored_iterator tmp(*this); ++ite; return tmp;}  

    /** @brief Operador de comparacion
    @param d const stored_iterator con el que vamos a comparar
    @return devuelve true en caso de que los dos iteradores apunten a la misma direccion
    */
    bool operator == (const stored_iterator & d) {return ite == d.ite;}

    /** @brief Operador de diferencia
    @param d const stored_iterator con el que vamos a comparar
    @return devuelve true en caso de que los dos iteradores apunten a diferentes direcciones
    */
    bool operator != (const stored_iterator & d) {return ite != d.ite; }
    
  private:
    
    typename map<int, T >::iterator ite;
};

class iterator{
  public:
    friend class vectorD;
    
    /** @brief Constructor primitivo
    */
    iterator() ;

    /** @brief Constructor de copia
    @param d const iterator a copiar
    */
    iterator(const iterator & d);

    /** @brief Operador de visualizacion
    @return devuelve el valor constante (T, second) de la direccion a la que apunte el iterador
    */
    const  T  & operator *(  ) ;

    /** @brief Operador de pre-incremento
    @return referencia a iterator que apunta a la posicion donde este el siguiente valor del vector
    */
    iterator & operator++( );

    /** @brief Operador de post-incremento
    @return iterator que apunta a la posicion donde este el siguiente valor del vector
    */
    iterator operator++(int ) ; 

    /** @brief Operador de comparacion
    @param d const iterator con el que vamos a comparar
    @return devuelve true en caso de que los dos iteradores sean iguales
    */
    bool operator == (const iterator & d) ;

    /** @brief Operador de diferencia
    @param d const iterator con el que vamos a comparar
    @return devuelve true en caso de que los dos iteradores apunten a diferentes direcciones
    */
    bool operator != (const iterator & d);

    /** @brief Operador de asignacion
    @param d const iterator a copiar
    @post asigna los valores del iterador pasado como parametro a this
    @return referencia de this
    */
    iterator & operator=(const iterator & d);

  private:
    int i_vect; // indice sobre el vector abstracto
    typename map<int, T >::iterator ite_rep; //iterador a la representacion
    vectorD *el_vect; // ptro al vector para obtener el valor nulo del vector
    /* FA e IR*/
    /* FA(rep): rep -- > iterador sobre vector abstracto
      (i_vect, ite_rep, el_vec):
      i_vect = k
      ite_rep = p 
      el_vect = v
       --------->
      iterador a la posicion k-esima del vector abstracto con valor nulo (*v).v_nulo
       */
   
      /* IR :
       IR(rep): rep ---> bool
     (i_vect, ite_rep): 
       --------->
       0 <= i_vect <=n_ele
       i_vect <= (*ite_rep).first
       */
       
};

class const_stored_iterator{
  public:
    friend class vectorD;
    
    /** @brief Constructor primitivo
    */
    const_stored_iterator();

    /** @brief Constructor de copia
    @param d const stored_iterator a copiar
    */
    const_stored_iterator(const const_stored_iterator & d) ;

    /** @brief Constructor de copia. Paso de normal a constante
    @param d const stored_iterator a copiar
    */
    const_stored_iterator(const stored_iterator & d) ; 

    /** @brief Operador de visualizacion
    @return un par de tipo int, T
    */
    const pair<int, T > & operator *(  ) ;

    /** @brief Operador pre-incremento
    @return const_stored_iterator que apunta a la posicion donde este el siguiente valor no nulo
    */
    const_stored_iterator & operator++( ) ; 

    /** @brief Operador post-incremento
    @return const_stored_iterator que apunta a la posicion donde este el siguiente valor no nulo
    */
    const_stored_iterator operator++(int ) ;

    /** @brief Operador de comparacion
    @param d const const_stored_iterator con el que vamos a comparar
    @return devuelve true en caso de que los dos iteradores apunten a la misma direccion
    */
    bool operator == (const const_stored_iterator & d) ;

    /** @brief Operador de diferencia
    @param d const const_stored_iterator con el que vamos a comparar
    @return devuelve true en caso de que los iteradores apunten a diferentes direcciones
    */
    bool operator != (const const_stored_iterator & d) ;

    /** @brief Operador de asignacion
    @param d const const_stored_iterator a copiar
    @post asigna los valores del iterador pasado como parametro a this
    @return referencia de this
    */
    const_stored_iterator & operator= (const const_stored_iterator & d) ;
 
  private:
    typename map<int, T >::const_iterator ite;
};

class const_iterator{
  public:
    friend class vectorD;
    
    /** @brief Constructor primitivo
    */
    const_iterator() ;

    /** @brief Constructor de copia
    @param d const const_iterator a copiar
    */
    const_iterator(const const_iterator & d) ;

    /** @brief Constructor de copia pasando iterador variable
    @param d const iterator a copiar
    */
    const_iterator(const iterator & d) ;

    /** @brief Operador de visualizacion
    @return devuelve el valor constante (T, second) de la direccion a la que apunte el iterador
    */
    const  T  &  operator *(  ) ;

    /** @brief Operador de pre-incremento
    @return referencia a const_iterator que apunta a la posicion donde este el siguiente valor del vector
    */
    const_iterator & operator++( ) ;

    /** @brief Operador de post-incremento
    @return iterator que apunta a la posicion donde este el siguiente valor del vector
    */
    const_iterator operator++(int ) ;

    /** @brief Operador de comparacion
    @param d const const_iterator con el que vamos a comparar
    @return devuelve true en caso de que los dos iteradores sean iguales
    */
    bool operator == (const const_iterator & d) ;

    /** @brief Operador de diferencia
    @param d const const_iterator con el que vamos a comparar
    @return devuelve true en caso de que los dos iteradores apunten a diferentes direcciones
    */
    bool operator != (const const_iterator & d) ;
    
  private:
    int i_vect; // indice sobre el vector abstracto
    typename map<int, T >::const_iterator ite_rep; //iterador a la representacion
    const vectorD *el_vect; // ptro al vector para obtener el valor nulo del vector
    /* FA e IR*/
    /* FA(rep): rep -- > iterador sobre vector abstracto
      (i_vect, ite_rep, el_vec):
      i_vect = k
      ite_rep = p 
      el_vect = v
       --------->
      iterador a la posicion k-esima del vector abstracto con valor nulo (*v).v_nulo
       */
   
      /* IR :
       IR(rep): rep ---> bool
     (i_vect, ite_rep): 
       --------->
       0 <= i_vect <=n_ele
       i_vect <= (*ite_rep).first
       */
       
};


};

#include "vectorDmap.hxx"

#endif
 
