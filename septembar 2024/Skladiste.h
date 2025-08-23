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
	void Vratinaj(Pice** piceMin, Pice** piceMax);
};

