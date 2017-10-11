template <typename T> 		
vectorD<T>:: vectorD( const  T  & t){
  v_nulo = t;
  n_ele = 0;
}
   
template <typename T>    	
vectorD<T>:: vectorD( const vectorD< T > & b){
  n_ele = b.n_ele;
  v_nulo = b.v_nulo;
  vd = b.vd;
}

template <typename T> 
vectorD<T>:: vectorD( int numcomp, const  T  & t){
  n_ele = numcomp;
  v_nulo = t;
}

template <typename T> 
vectorD<T>::~vectorD(){

}

template <typename T> 
typename vectorD<T>::size_type vectorD<T>::size() const{
  return n_ele;
}

template <typename T> 
T  vectorD<T>::default_value( ) const{
  return v_nulo;
}

template <typename T> 
bool vectorD<T>::empty(){
  return (n_ele==0);
}

template <typename T>
void vectorD<T>::assign(int p, const  T  & t){
  if (p>=0 && p<n_ele){
    typename map<int, T>::iterator it;
    it = vd.find(p);
    if (it != vd.end()){
      if (t==v_nulo)
        vd.erase(it);
      else
      (*it).second = t;
    }
    else 
      if (t!=v_nulo)
        vd.insert(pair <int,T> (p, t));
  }
}

template <typename T>
void vectorD<T>::push_back(const  T  & t){
  if (t != v_nulo)
    vd.insert (pair<int,T> (n_ele, t));
  n_ele++;
}

template <typename T>
void vectorD<T>::pop_back( ){
  n_ele--;
  typename map<int,T>::iterator it = vd.end();
  it--;
  if ((*it).first == n_ele)
    vd.erase (it);
}

template<typename T>
void vectorD<T>::clear(){
  n_ele = 0;
  vd.clear();
}

template<typename T>
void vectorD<T>::resize(int t){
  bool sal = false;
  if (t < n_ele){
    for (int i=t; i<n_ele && !sal; i++){
      typename map<int,T>::iterator it = vd.find(i);
      if (it != vd.end()){
        vd.erase(it, vd.end());
        sal = true;
      }
    }
  }
n_ele = t;  
}

/////////////// operadores ///////////////////


template<typename T>
vectorD<T> & vectorD<T>::operator= ( const vectorD & x){
  if (this != &x){
    vd = x.vd;
    n_ele = x.n_ele;
    v_nulo = x.v_nulo;
  }
  return *this;
}

template<typename T>
const  T  & vectorD<T>::operator[](int c) const{
  typename map<int,T>::const_iterator it = vd.find(c);
  if (it!=vd.end())
    return (*it).second;
  else
    return v_nulo;
}

template<typename T>
const  T  & vectorD<T>:: at(int c) const{
  assert(c<n_ele && c>=0);
    typename map<int,T>::const_iterator it = vd.find(c);
    if (it!=vd.end())
      return (*it).second;
    else
      return v_nulo;
}

template<typename T>
bool vectorD<T>::operator==( const vectorD & x){
  return (n_ele == x.n_ele && vd == x.vd && v_nulo == x.v_nulo);
}

template<typename T>
bool vectorD<T>::operator !=( const vectorD & x){
  return (n_ele != x.n_ele && vd != x.vd && v_nulo != x.v_nulo);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                ITERADORES SOBRE VECTOR DISPERSO                                       //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<typename T>
typename vectorD<T>::iterator vectorD<T>::begin ( ){
  typename vectorD<T>::iterator sal;
  sal.i_vect = 0;
  sal.ite_rep = vd.begin();
  sal.el_vect = this;
  return sal;
}

template<typename T>
typename vectorD<T>::iterator vectorD<T>::end (){
  typename vectorD<T>::iterator sal;
  sal.i_vect = n_ele;
  sal.ite_rep = vd.end();
  sal.el_vect = this;
  return sal;
}

template<typename T>
typename vectorD<T>::const_iterator vectorD<T>::cbegin ( ) const{
  typename vectorD<T>::const_iterator sal;
  sal.i_vect = 0;
  sal.ite_rep = vd.cbegin();
  sal.el_vect = this;
  return sal;
}

template<typename T>
typename vectorD<T>::const_iterator vectorD<T>::cend () const{
  typename vectorD<T>::const_iterator sal;
  sal.i_vect = n_ele;
  sal.ite_rep = vd.cend();
  sal.el_vect = this;
  return sal;
}

template<typename T>
typename vectorD<T>::stored_iterator vectorD<T>::sbegin(){
  typename vectorD<T>::stored_iterator sal;
  sal.ite = vd.begin();
  return sal;
}

template<typename T>
typename vectorD<T>::stored_iterator vectorD<T>::send(){
  typename vectorD<T>::stored_iterator sal;
  sal.ite = vd.end();
  return sal;
}

template<typename T>
typename vectorD<T>::const_stored_iterator vectorD<T>::csbegin() const{
  typename vectorD<T>::const_stored_iterator sal;
  sal.ite = vd.cbegin();
  return sal;
}

template<typename T>
typename vectorD<T>::const_stored_iterator vectorD<T>::csend() const{
  typename vectorD<T>::const_stored_iterator sal;
  sal.ite = vd.cend();
  return sal;
}

template<typename T>
int vectorD<T>::checkRep(){
  if (!(0 <= vd.size() < n_ele))
    return 1;
  else{
    bool sal = false;
    typename vectorD<T>::stored_iterator ini, fin;
    T aux;
    bool entrar = false;
    ini = sbegin();
    fin = send();
    aux = (*ini).first;
    for (ini; ini!=fin && !sal; ini++){
      if ((*ini).second == v_nulo)
        return 2;
      if (!((*ini).first >= 0))
        return 3;
      if (entrar){
        if ((*ini).first <= aux)
          return 4;     
      }
    aux=(*ini).first;  
    entrar=true;    
    }
    return 0;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                               Implementacion iterator                                                 //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<typename T>
vectorD<T>::iterator::iterator(){
}

template<typename T>
vectorD<T>::iterator::iterator(const iterator & d){
  i_vect = d.i_vect;
  ite_rep = d.ite_rep;
  el_vect = d.el_vect;
}

template<typename T>
const T & vectorD<T>::iterator::operator*( ){
  if (i_vect==(*ite_rep).first)
    return (*ite_rep).second;
  else
    return el_vect->v_nulo;
}

template<typename T>
typename vectorD<T>::iterator & vectorD<T>::iterator::operator++( ){
  i_vect++;
  if (i_vect > (*ite_rep).first)
    ite_rep++;
  return *this;
}

template<typename T>
typename vectorD<T>::iterator vectorD<T>::iterator::operator++(int ){
  typename vectorD<T>::iterator clon (*this);
  i_vect++;
  if (i_vect > (*ite_rep).first)
    ite_rep++;
  return clon;
}

template<typename T>
bool vectorD<T>::iterator::operator==(const iterator & d){
  return (ite_rep == d.ite_rep && i_vect == d.i_vect);
}

template<typename T>
bool vectorD<T>::iterator::operator!=(const iterator & d){
  return (ite_rep != d.ite_rep || i_vect != d.i_vect);
}

template<typename T>
typename vectorD<T>::iterator & vectorD<T>::iterator::operator=(const iterator & d){
  i_vect = d.i_vect;
  ite_rep = d.ite_rep;
  el_vect = d.el_vect;

  return *this;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                               Implementacion const_iterator                                           //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<typename T>
vectorD<T>::const_iterator::const_iterator(){
}

template<typename T>
vectorD<T>::const_iterator::const_iterator(const const_iterator & d){
  i_vect = d.i_vect;
  ite_rep = d.ite_rep;
  el_vect = d.el_vect;
}

template<typename T>
vectorD<T>::const_iterator::const_iterator(const iterator & d){
  i_vect = d.i_vect;
  ite_rep = d.ite_rep;
  el_vect = d.el_vect;
}

template<typename T>
const T & vectorD<T>::const_iterator::operator*( ){
  if (i_vect==(*ite_rep).first)
    return (*ite_rep).second;
  else
    return el_vect->v_nulo;
}

template<typename T>
typename vectorD<T>::const_iterator & vectorD<T>::const_iterator::operator++( ){
  i_vect++;
  if (i_vect > (*ite_rep).first)
    ite_rep++;
  return *this;
}

template<typename T>
typename vectorD<T>::const_iterator vectorD<T>::const_iterator::operator++(int ){
  typename vectorD<T>::const_iterator clon (*this);
  i_vect++;
  if (i_vect > (*ite_rep).first)
    ite_rep++;
  return clon;
}

template<typename T>
bool vectorD<T>::const_iterator::operator==(const const_iterator & d){
  return (ite_rep == d.ite_rep && i_vect == d.i_vect);
}

template<typename T>
bool vectorD<T>::const_iterator::operator!=(const const_iterator & d){
  return (ite_rep != d.ite_rep || i_vect != d.i_vect);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                               Implementacion const_stored_iterator                                    //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<typename T>
vectorD<T>::const_stored_iterator::const_stored_iterator(){

}

template<typename T>
vectorD<T>::const_stored_iterator::const_stored_iterator(const const_stored_iterator & d){
  ite = d.ite;
}

template<typename T>
vectorD<T>::const_stored_iterator::const_stored_iterator(const stored_iterator & d){
  ite = d.ite;
}

template<typename T>
const pair<int, T> & vectorD<T>::const_stored_iterator::operator *( ){
  return (*ite);
}


template<typename T>
typename vectorD<T>::const_stored_iterator & vectorD<T>::const_stored_iterator::operator++( ){
  ++ite;
  return *this;
}

template<typename T>
typename vectorD<T>::const_stored_iterator vectorD<T>::const_stored_iterator::operator++(int ){
  const_stored_iterator tmp(*this);
  ++ite;
  return tmp;
}

template<typename T>
bool vectorD<T>::const_stored_iterator::operator == (const const_stored_iterator & d){
  return ite == d.ite;
}

template<typename T>
bool vectorD<T>::const_stored_iterator::operator != (const const_stored_iterator & d){
  return ite != d.ite;
}

template<typename T>
typename vectorD<T>::const_stored_iterator & vectorD<T>::const_stored_iterator::operator= (const const_stored_iterator & d){
  if (this!=&d){
    ite = d.ite;
  }
  return *this;
}