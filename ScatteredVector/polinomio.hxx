template <typename T>
polinomio<T>::polinomio(){
}

template <typename T>
polinomio<T>::polinomio(const polinomio<T> & p){
	vect = p.vect;
}

template <typename T>
polinomio<T>::polinomio(const vectorD<T> & v){
	vect = v;
}

template <typename T> 
polinomio<T>::~polinomio(){

}

template <typename T>
const int polinomio<T>::getGrado(){
	typename polinomio<T>::iterator it, fin;
	int aux;
	it.ite = vect.sbegin();
	fin.ite = vect.send();
	for (it; it!=fin; ++it){
		aux = (*it).first;
	}
	return aux;
}

template <typename T>
const T & polinomio<T>::getCoeficiente(const int & i){
	return vect.at(i);
}

template <typename T>
void polinomio<T>::setGrado(const int & i, const T coef){
	T valor= vect.at(i);
	int grado = getGrado();
	T valorNulo = vect.default_value();
	//Existe en la lista
	if (valor != vect.default_value()){		
		//vect.assign(i,coef);
		for (int j = i+1 ; j<=grado; j++ ){
			vect.assign(j,valorNulo);
		}		
	}else{
		if (i < grado){
			for (int j = i+1 ; j<=grado; j++ ){
				vect.assign(j,valorNulo);
			}
		}
		vect.assign(i,coef);
	}
}


template <typename T>
typename polinomio<T>::iterator polinomio<T>::begin(){
	typename polinomio<T>::iterator it;
	it.ite = vect.sbegin();
	return it;
}

template <typename T>
typename polinomio<T>::iterator polinomio<T>::end(){
	typename polinomio<T>::iterator it;
	it.ite = vect.send();
	return it;
}

template <typename T>
typename polinomio<T>::const_iterator polinomio<T>::cbegin () const{
	typename polinomio<T>::const_iterator it;
	it.ite = vect.cbegin();
	return it;
}

template <typename T>
typename polinomio<T>::const_iterator polinomio<T>::cend () const{
	typename polinomio<T>::const_iterator it;
	it.ite = vect.cend();
	return it;
}

template <typename T>
polinomio<T> & polinomio<T>::operator=(const polinomio & p){
	if (this != &p)
		vect=p.vect;
	return *this;
}

template <typename T>
polinomio<T> polinomio<T>::operator+(polinomio & p){

	polinomio<T> sal;
	typename polinomio<T>::iterator ini, fin;
	T coef;
	T nuestrocoef;
	int grado;
	int grado1;

	if (getGrado() > p.getGrado()){
		sal = *this;
		ini = p.begin();
		fin = p.end();
		for (ini; ini!=fin; ini++){
			grado = (*ini).first;
			coef = (*ini).second;
			nuestrocoef = sal.vect.at(grado);
			if (nuestrocoef != sal.vect.default_value())
				sal.vect.assign(grado, nuestrocoef+coef);
			else
				sal.vect.assign(grado, coef);
		}
	}
	else{
		sal = p;
		ini = begin();
		fin = end();
		for (ini; ini!=fin; ini++){
			grado = (*ini).first;
			coef = (*ini).second;
			nuestrocoef = sal.vect.at(grado);
			if (nuestrocoef != sal.vect.default_value())
				sal.vect.assign(grado, nuestrocoef+coef);
			else
				sal.vect.assign(grado, coef);
		}
	}
	return sal;
}

template <typename T>
polinomio<T> polinomio<T>::operator-(polinomio & p){

	polinomio<T> sal;
	typename polinomio<T>::iterator ini, fin;
	T coef;
	T nuestrocoef;
	int grado;
	int grado1;

	if (getGrado() > p.getGrado()){
		sal = *this;
		ini = p.begin();
		fin = p.end();
		for (ini; ini!=fin; ini++){
			grado = (*ini).first;
			coef = (*ini).second;
			nuestrocoef = sal.vect.at(grado);
			if (nuestrocoef != sal.vect.default_value())
				sal.vect.assign(grado, nuestrocoef-coef);
			else
				sal.vect.assign(grado, coef);
		}
	}
	else{
		sal = p;
		ini = begin();
		fin = end();
		for (ini; ini!=fin; ini++){
			grado = (*ini).first;
			coef = (*ini).second;
			nuestrocoef = sal.vect.at(grado);
			if (nuestrocoef != sal.vect.default_value())
				sal.vect.assign(grado, nuestrocoef-coef);
			else
				sal.vect.assign(grado, coef);
		}
	}
	return sal;
}




