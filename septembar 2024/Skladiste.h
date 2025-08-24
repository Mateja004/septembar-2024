#pragma once
#include"Pice.h"
#include<iostream>
using namespace std;
class Skladiste
{
private:
	Pice** niz;
	int maxbr;
	int trbr;
public:
	Skladiste();
	Skladiste(int maxbr);
	~Skladiste();
	Skladiste(const Skladiste& obj4);
	void Dodaj(Pice* a);
	friend ostream& operator<<(ostream& izlaz, const Skladiste& a2);
	void Izdvoji(Pice& a2, int broj);
	void Presipaj(Pice& a3, Pice& a2);
	bool DovoljnaKolicina(int nabavka);
	void VratiNaj(Pice*& piceMin, Pice*& piceMax); //mora da se prosledi referenca pointera (*&)
};												// zato sto je u mainu prosledjen samo pointer
												// a mora da se u funkciji vrati naj menja vrednost

