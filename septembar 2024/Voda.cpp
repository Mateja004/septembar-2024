#include "Voda.h"
#include<iostream>
using namespace std;

Voda::Voda(const Voda& obj2) {
	this->zapremina = obj2.zapremina;
	this->brojAmbalaza = obj2.brojAmbalaza;
}
ostream& Voda::Prikazi(ostream& izlaz)const {
	izlaz << " " << zapremina << " " << brojAmbalaza << " " << endl;
	return izlaz;
}

