#include "gs1Set.h"

using namespace std;


gs1Set ::gs1Set (){
  pair<string,int> aux("gs1",0);
  arbol = tree<pair<string,int> >(aux);
  tama = 0;
}

gs1Set ::gs1Set (const gs1Set  & x){
  arbol = x.arbol;
  tama = x.tama;
}

/** @brief insercion del string, cada caracter en una posicion independiente
@todo implementar este metodo correctamente
OJO ESTE METODO SOLO SIRVE PARA DAR UNA IDEA DEL PROCESO DE INSERCION,
HAY QUE IMPLEMENTARLO CORRECTAMENTE
*/
bool gs1Set::insert(const string& s){ 
tree<pair<string,int> >::node n, aux, ant; //guardamos en ant el nodo anterior al actual (hermano)
string::const_iterator it;
pair<string,int> par;
bool enc;
bool id;
string idc;

  n = arbol.root();
  for (it = s.begin(); it!=s.end(); ++it) { // Para cada caracter del string
    if (*it == '('){
      idc.clear();
      while (*it!=')'){
        idc = idc + *it;
        ++it;
      }
      idc = idc + *it;
    } else idc=string(1,*it);

   aux = n.left(); // aux es el primer hijo
   enc = false;
   par.first = idc;
   par.second = 0;
    if (aux.null() || (*aux).first > idc){
      n=arbol.insert_left(n,par);
    }
    else{
      while ( !enc ){ // buscamos el caracter dentro de la lista de hijos

          if ( !aux.null() && idc == ((*aux).first )) { 
            enc = true;
            n = aux; // si lo encuentra, desciende al siguiente nivel
          }
          else if(aux.null() || (*aux).first>idc){
            n = arbol.insert_right_sibling(ant, par);
            enc = true;
          }
          else {
            ant = aux;
            aux = aux.next_sibling();
          }
      }    
    }
  }
  while (!n.null()){
    if ((*n).first.size() == 1)
      (*n).second = (*n).second+1;
    else
      (*n).second = -1;
    n = n.parent();
  }
}


void gs1Set::print( ) const {
  tree<pair<string,int> >::const_preorderiterator it;
  tree<pair<string,int> >::const_leveliterator itn;
   cout << "preorden " << endl;
   
  for (it= arbol.beginPreorder(); it!= arbol.endPreorder();++it)
    cout << (*it).first <<".." << (*it).second << endl;

   cout << "Nivel " << endl;
  for (itn= arbol.beginlevel(); itn!= arbol.endlevel();++itn)
    cout << (*itn).first << ".." << /*(*it).second << */endl;
  
}


/**
@todo implementar este metodo correctamente
OJO ESTE METODO OS SIRVE PARA PODER CONSTRUIR UN ARBOL
NO TIENE EN CUENTA EL INVARIANTE DE LA REPRESENTACION
AL NO CONSIDERAR EL CAMPO INT DEL NODO!!!!!
DEBEIS MODIFICARLO PARA QUE LO HAGA DE FORMA CORRECTA
*/      
  
/*void gs1Set::reading_gs1Set ( ) {

  tree<pair<string,int> >::node n, h;
  queue< tree<pair<string,int> >::node > Q;
   
  pair<string,int> aux;

  n = arbol.root();
  Q.push(n);
  while (!Q.empty() ){
    n = Q.front(); 
    Q.pop();
    cout << "Hijo Izq de " << (*n).first << "/ si no tiene hijos "<< endl;
    cin >> aux.first;
    if (aux.first != "/") { 
      h= arbol.insert_left(n,aux);
      Q.push(h);
      cout << "Hermano Dhc de " << (*h).first<< "/ si no tiene hermano "<< endl;
      cin >> aux.first;
      while (aux.first != "/") {
      	h= arbol.insert_right_sibling(h,aux);
      	Q.push(h);
      	cout << "Hermano Dhc de " << (*h).first<< "/ si no tiene hermano"<< endl;
        cin >> aux.first;
      } 
    }
    
  }
}*/

gs1Set  & gs1Set::operator= (const gs1Set  &org){
  if (this != &org){
    arbol = org.arbol;
    tama = org.tama;

  }
  return *this;
}

/*const_iterator gs1Set::begin() const{
  
}*/


////////////////////////////////////////////////////////////////////////////////////////
//                                  Const_iterator
////////////////////////////////////////////////////////////////////////////////////////
gs1Set::const_iterator::const_iterator(){

}

gs1Set::const_iterator::const_iterator( const const_iterator & it){
  act = it.act;
  ptr = it.ptr;
}

string gs1Set::const_iterator::operator*(){
  return (*act).first;
}

gs1Set::const_iterator & gs1Set::const_iterator::operator++(){

  /*bool subiendo = false;

  if (act.left().null())
    subiendo = true;
  else
    act = act.left();
    
  if (subiendo){
    while (act.next_sibling().null()){
      if (!act.parent().null())
        act = act.parent();

      else
        //AQUI TENEMOS QUE DEVOLVER END (NO IMPLEMENTADO AUN)
        return *this;

    }
    act = act.next_sibling();
  }
  while (!act.left().null() || (*act.left()).second != -1) //Bajamos buscando la hoja
    act = act.left();
  return *this;*/
  //tree<pair<string,int> >::node aux;
  tree<pair<string,int> >::node aux;
  avanza(act);

  //cout << (*aux).second;
  /*while (!(avanza(act)).null() || (*(avanza(act))).second != -1){

    
}*/
}
  //TENEMOS QUE PONERLO COMo PRIVADO AQUI Y EN .H
 tree<pair<string,int> >::node  & avanza (tree<pair<string,int> >::node elnodo1){

  static tree<pair<string,int> >::node elnodo(elnodo1);
  if (elnodo.null())
    return elnodo;

  if (!elnodo.left().null()) {
     elnodo = elnodo.left();
  }
  else if (!elnodo.next_sibling().null()) {
      elnodo = elnodo.next_sibling();
  }
  else {
    while ((!elnodo.parent().null()) &&
         (elnodo.parent().next_sibling() == elnodo ||
          elnodo.parent().next_sibling().null()))
      elnodo = elnodo.parent();
    if (elnodo.parent().null())
      elnodo = tree<pair<string, int> >::node();
    else
      elnodo = elnodo.parent().next_sibling();
  }
  return elnodo;
}