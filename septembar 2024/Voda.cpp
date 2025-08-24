#include "Voda.h"
#include<iostream>
using namespace std;

Voda::Voda(const Voda& obj2) {
	this->zapremina = obj2.zapremina;
	this->brojAmbalaza = obj2.brojAmbalaza;
}
ostream& Voda::Print(ostream& izlaz)const {
	izlaz << "Zapremina:" << zapremina<<"L" << " Broj ambalaza: " << brojAmbalaza << " " << endl;
	return izlaz;
}
void Voda::Prikazi() const{
	cout<<"Zapremina:" << zapremina<<"L" << " Broj ambalaza: " << brojAmbalaza << " " << endl;
}

