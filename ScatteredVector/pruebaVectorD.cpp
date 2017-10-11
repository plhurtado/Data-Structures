#include <map>
#include "vectorDlistas.h"
#include "vectorDmap.h"
#include "polinomio.h"
#include <iostream>

using namespace std;

int main(){
	cout << "Buenos días" << endl;

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
