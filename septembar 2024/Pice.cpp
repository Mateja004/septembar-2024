#include "Pice.h"
#include<iostream>
using namespace std;

Pice::Pice(const Pice& obj) {
	this->brojAmbalaza = obj.brojAmbalaza;
	this->zapremina = obj.zapremina;
}
ostream& operator<<(ostream& izlaz, Pice& a1) {
	a1.Print(izlaz);
	return izlaz;
}
