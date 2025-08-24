#pragma once
#include "Sokovi.h"
#include<iostream>
using namespace std;
template<typename T>
class Fabrika {
	T* niz;
	int maxBr;
	int trBr;
public:
	Fabrika();
	Fabrika(int maxBr);
	Fabrika(const Fabrika<T> f1);
	~Fabrika();
	void Dodaj(T& t);
	friend ostream& operator<<(ostream& os, const Fabrika<T>);
	ostream& Ispisi(ostream& cout)const;
	void Izbaci(T& t);
	float Ukupno()const;
	int UkupniBrojVrednost(int vrednost, float* ukVr)const;
	int NajmanjeAmbalaza(float vr)const;
	void Sacuvaj(const char* nazivFajla)const;
	void Ucitaj(const char* nazivFajla);
};

