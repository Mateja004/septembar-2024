#include "Skladiste.h"
#include"Sok.h"
#include"Voda.h"
#include"Pice.h"
#include<iostream>
using namespace std;

Skladiste::Skladiste() {
	niz = nullptr;
	trbr = 0;
	maxbr = 0;
}
Skladiste::Skladiste(int maxbr) {
	this->maxbr = maxbr;
	trbr = 0;
	niz = new Pice * [maxbr];
	for (int i = 0;i < maxbr;i++) {
		niz[i] = nullptr;
	}
}
Skladiste::Skladiste(const Skladiste& obj4) {
	for (int i = 0;i < this->trbr;i++) {
		this->niz[i] = nullptr;
	}
	this->niz= nullptr;
	this->maxbr = obj4.maxbr;
	this->trbr = obj4.trbr;
	this->niz = new Pice * [this->maxbr];
	for (int i = 0;i = this->trbr;i++) {
		this->niz[i] = obj4.niz[i];
	}
}
Skladiste::~Skladiste() {
	for (int i = 0;i < trbr;i++) {
		delete niz[i];
	}
	delete[]niz;
}
void Skladiste::Dodaj(Pice* a) {
	for (int i = 0;i < trbr;i++) {
		if (typeid(*a) == typeid(*niz[i])) {
			if (typeid(*a)==typeid(Voda)){
				if(a->vratizapreminu() == niz[i]->vratizapreminu()){
					niz[i]->SetBrojAmbalaze(niz[i]->vratibrAmbalaze() + 1);
					return;
				}
				else{
					niz[trbr++]=a;
					return;
				}
			} 
			else{
				if(a->vratizapreminu()==niz[i]->vratizapreminu()&&a->)
				//za sok
			}
		}
	}	
}












