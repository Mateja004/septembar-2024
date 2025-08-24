#include "Sok.h"
#include<iostream>
using namespace std;


Sok::Sok() {
	ukus = new char[1];
	ukus[0] = '\0';
	cena = 0;
	procenatSoka = 0;
	zapremina = 0;
	brojAmbalaza = 0;
}
Sok::Sok(float zapremina,const char* ukus, int procenatSoka, float cena) {
	this->zapremina = zapremina;
	this->brojAmbalaza = 1;
	this->ukus = new char[strlen(ukus) + 1];
	strcpy(this->ukus, ukus);
	this->cena = cena;
	this->procenatSoka = procenatSoka;
}
Sok::~Sok() {
	delete[]ukus;
}
Sok::Sok(const Sok& obj3) {
	this->zapremina = obj3.zapremina;
	this->brojAmbalaza = obj3.brojAmbalaza;
	this->ukus = new char[strlen(obj3.ukus) + 1];
	strcpy(this->ukus, obj3.ukus);
	this->cena = obj3.cena;
	this->procenatSoka = obj3.procenatSoka;
}
ostream& Sok::Print(ostream& izlaz)const {
	izlaz << "Zapremina: " << zapremina <<"L" << " Broj ambalaza" << brojAmbalaza << " Ukus:" << ukus << " Cena:" << cena << " Procenat soka:" << procenatSoka << endl;
	return izlaz;
}
void Sok::Prikazi()const {
	cout <<"Zapremina: " << zapremina << " Broj ambalaza: " << brojAmbalaza << " Ukus:" << ukus << " Cena:" << cena << " Procenat soka: " << procenatSoka << endl;
}
