#include <map>
#include "vectorDlistas.h"
#include "vectorDmap.h"
#include "polinomio.h"
#include <iostream>

using namespace std;

int main(){
	cout << "Buenos días" << endl;

	//vectorD<int> mivectord(10, 0);
	/*vectorD<int> x(5, 0);
	vectorD<int> y(x);
	vectorD<int>::stored_iterator it;
	

	//cout << (x == y);
	cout << "Tamaño lista x: " << x.n_lista()<<endl;
	cout << "Tamaño vector x:" << x.size()<<endl;
	x.assign(0,5);
	cout << "Tamaño vector y: " << y.size()<<endl;
	cout << "Tamaño lista y: " << y.n_lista()<<endl;
	x.push_back (2);

	cout << "Tamaño vector" << x.size()<<endl;
	x.push_back(0);*/
	/*cout << "Tamaño lista" << x.n_lista()<<endl;
	cout << "Tamaño vector" << x.size()<<endl;
	x.pop_back( );
	cout << "Tamaño vector" << x.size()<<endl;*/
	//x.resize(6);
	/*x.push_back(23);
	x.push_back(0);
	x.push_back(90);
	x.push_back(0);
	x.push_back(0);
	x.push_back(0);
	x.push_back(0);
	x.push_back(0);
	x.push_back(0);

	cout << "Tamaño lista x: " << x.n_lista()<<endl;
	cout << "Tamaño vector x:" << x.size()<<endl;
	
	cout << "Tamaño lista y: " << y.n_lista()<<endl;
	cout << "Tamaño vector y:" << y.size()<<endl;

	cout <<"El valor de la posicion " << 0 << " es: " << x.at(0) <<endl;
		for (it=x.sbegin(); it!=x.send();it++){
			cout << (*it).second << endl;
		}
	polinomio<int> p(x);
	int coeficiente = p.getCoeficiente(7);
	polinomio<int>::iterator ito,itf;
	p.setGrado(8,20);
	ito = p.begin();
	itf = p.end();
	for (ito;ito!=itf;ito++)
		cout<< (*ito).second << "x^" << (*ito).first << endl;

	polinomio<int> l;
	l = p;

	polinomio<int>::iterator itol,itfl;
	itol = p.begin();
	itfl = p.end();
	for (itol;itol!=itfl;itol++)
		cout<< (*itol).second << "x^" << (*itol).first << endl;
	polinomio<int> resultado;

	x.push_back(100);*/

	//p.setGrado(3,77);
	//cout << p.getCoeficiente(3) << endl;

	//it = x.begin();
	/*for (it; it != x.send(); it++){
		cout << *it << endl;
	}*/
	//cout << (x != y);
	//cout << *x.begin();
	vectorD<int> vp(0);
	for (int i = 0; i<10; i++){
		vp.push_back(i);
	}

	vectorD<int> vs(0);
	for (int i = 0; i<5; i++){
		vs.push_back(i);
	}

	polinomio<int> pp(vp);
	polinomio<int> ps(vs);
	polinomio<int> resultado;
	resultado = pp - ps;

	polinomio<int>::iterator ini, fin;
	ini = resultado.begin();
	fin = resultado.end();
	for (ini;ini!=fin;ini++)
	cout<< (*ini).second << "x^" << (*ini).first << endl;
	

}
