#include "Sokovi.h"
#include <iostream>
using namespace std;

Sokovi::Sokovi() :zapremina(0), procenat(0) {
	ukus = new char[1];
	ukus[0] = '\0';
}
Sokovi::Sokovi(const char* ukus, float zapremina, int procenat)
	:zapremina(zapremina), procenat(procenat) {
	this->ukus = new char[strlen(ukus) + 1];
	strcpy(this->ukus, ukus);
}
Sokovi::Sokovi(const Sokovi& s1) {
	this->zapremina = s1.zapremina;
	this->procenat = s1.procenat;
	this->ukus = new char[strlen(s1.ukus) + 1];
	strcpy(this->ukus, s1.ukus);
}
Sokovi::~Sokovi() {
	delete[] ukus;
}
ostream& Sokovi::Print(ostream& os) {
	os << "Zapremina: " << zapremina << " Procenat: " << procenat << " Ukus: " << ukus << endl;
	return os;
}
ostream& operator<<(ostream& os,  Sokovi& s1){
	s1.Print(os);
	return os;
}