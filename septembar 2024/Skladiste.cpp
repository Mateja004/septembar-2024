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
	if (a == nullptr) {
		cout << "Nepravilno prosledjeno pice" << endl;
		return;
	}
	for (int i = 0; i < trbr; i++) {
		if (a->vratizapreminu() == niz[i]->vratizapreminu()) {
			if (dynamic_cast<Voda*>(niz[i])!=nullptr && dynamic_cast<Voda*>(a)!=nullptr) {
				niz[i]->SetBrojAmbalaze(niz[i]->vratibrAmbalaze() + 1);
				return;
			}
			Sok *nizniz = dynamic_cast<Sok*>(niz[i]);
			Sok*aa = dynamic_cast<Sok*>(a);
			if (aa != nullptr && nizniz != nullptr && strcmp(nizniz->vratiUkus(), aa->vratiUkus()) == 0) {
				niz[i]->SetBrojAmbalaze(niz[i]->vratibrAmbalaze() + 1);
				return;
			}
		}
	}
	if (trbr < maxbr) {
		niz[trbr++] = a;
	}
	else {
		cout << "Nema mesta u skladistu!" << endl;
	}
}
ostream& operator<<(ostream& izlaz, const Skladiste& a2) {
	izlaz << "U skladistu je:" << endl;
	for (int i = 0; i < a2.trbr; i++) {
		a2.niz[i]->Print(izlaz);
	}
	return izlaz;
}
void Skladiste::Izdvoji(Pice& a2, int broj) {
	if (broj < 0) {
		cout << "Ne sme da bude negativan broj!" << endl;
		return;
	}
	for (int i = 0; i < trbr; i++) {
		if (niz[i]->vratizapreminu() == a2.vratizapreminu()) {
			if (dynamic_cast<Voda*>(niz[i]) != nullptr && typeid(a2) == typeid(Voda)) {
				if (niz[i]->vratibrAmbalaze() >= broj) {
					niz[i]->SetBrojAmbalaze(niz[i]->vratibrAmbalaze() - broj);
					if (niz[i]->vratibrAmbalaze() == 0) {
						delete niz[i];
						for (int j = i; j < trbr; j++) {
							niz[j] = niz[j + 1];
						}
						trbr--;
					}
					return;
				}
			}
			Sok* nizniz = dynamic_cast<Sok*>(niz[i]);
			Sok* a2a2 = new Sok(dynamic_cast<Sok&>(a2));
			if (nizniz != nullptr && a2a2 != nullptr&& strcmp(a2a2->vratiUkus(),nizniz->vratiUkus())==0) {
				if (niz[i]->vratibrAmbalaze() >= broj) {
					niz[i]->SetBrojAmbalaze(niz[i]->vratibrAmbalaze() - broj);
					if (niz[i]->vratibrAmbalaze() == 0) {
						delete niz[i];
						for (int j = i; j < trbr; j++) {
							niz[j] = niz[j + 1];
						}
						trbr--;
					}
					return;
				}
			}
		}
	}
	if (trbr < maxbr) {
		niz[trbr++] = &a2;
	}
}
void Skladiste::Presipaj(Pice& a3, Pice& a2) {
	if (typeid(a3) != typeid(a2)) {
		cout << "ne moze se presipati!" <<endl;
		return;
	}
	int brojManjih = 0;
	brojManjih = static_cast<int>(  a3.vratizapreminu() / a2.vratizapreminu());
	if (!brojManjih * a2.vratizapreminu() == a3.vratizapreminu()) {
		cout << "nemoguce je presipati!" << endl;
		return;
	}
	Izdvoji(a3, 1);
	for (int i = 0; i < brojManjih; i++) {
		Pice* novo = new Voda(a2.vratizapreminu());
		Dodaj(novo);
	}
	
}
bool Skladiste::DovoljnaKolicina(int nabavka) {
	double ukZapremina = 0;
	for (int i = 0; i < trbr; i++) {
		ukZapremina += niz[i]->vratiUkupnuZap();
	}
	return ukZapremina >= nabavka;
}

void Skladiste::VratiNaj(Pice*& piceMin, Pice*& piceMax) {
	if (trbr == 0) {
		return;
	}
	piceMin = niz[0];
	piceMax = niz[0];
	double piceMaxx = niz[0]->vratiUkupnuZap();
	double piceMinn = niz[0]->vratiUkupnuZap();
	for (int i = 1; i < trbr; i++) {
		double sadasnjaZap = niz[i]->vratiUkupnuZap();
		if (sadasnjaZap >piceMaxx) {
			piceMaxx = sadasnjaZap;
			piceMax = niz[i];
		}
		if (sadasnjaZap < piceMinn) {
			piceMinn = sadasnjaZap;
			piceMin = niz[i];
		}
	}
}








