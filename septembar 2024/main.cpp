#include <iostream>
using namespace std;
#include "Skladiste.h"
#include "Pice.h"
#include "Sok.h"
#include "Voda.h"


void zadatak1()
{
	char ukus1[7] = "jagoda";
	int procenat1 = 50;
	float odnosCene = 0.75;
	// 2 poena 
	Pice* p1 = new Voda(1);
	//p1->Prikazi(); 
	cout << *p1 << endl;
	// 2 poena 
	Pice* p2 = new Sok(0.75, ukus1, procenat1, odnosCene);
	//p2->Prikazi(); 
	cout << *p2 << endl;
	float voda[] = { 1, 0.2, 2, 5, 1, 1, 2, 5 };
	float sok[] = { 1, 0.2, 1.5, 0.5, 1, 0.5, 1, 1.5 };
	Skladiste* s = new Skladiste(10);
	// 2 poena 
	for (int i = 0; i < 4; i++)
	{
		s->Dodaj(new Voda(voda[i]));
		s->Dodaj(new Sok(sok[i], ukus1, procenat1, odnosCene));
	}
	// 2 poena 
	//s->print(); 
	cout << *s << endl;

	// 2 poena 
	for (int i = 4; i < 8; i++)
	{
		s->Dodaj(new Voda(voda[i]));
		s->Dodaj(new Sok(sok[i], ukus1, procenat1, odnosCene));
	}
	//s->print(); 
	cout << *s << endl;

	// 2 poena 
	Sok sok(0.5, ukus1, procenat1, odnosCene);
	s->Izdvoji(sok, 2);
	//s->print(); 
	cout << *s << endl;

	// 1 poena 
	Voda voda1(1);
	s->Izdvoji(voda1, 2);
	//s->print(); 
	cout << *s << endl;

	// 2 poena 
	Voda voda2(2);
	s->Presipaj(voda2, voda1);
	//s->print(); 
	cout << *s << endl;

	// 2 poena 
	int nabavka = 7;
	if (s->DovoljnaKolicina(nabavka))
		cout << "Ima dovoljno vode i sokova za " << nabavka << "l" << endl;
	else
		cout << "Nema dovoljno vode i sokova" << endl;

	// 2 poena 
	Pice* piceMin = nullptr, * piceMax = nullptr;
	s->VratiNaj(piceMin, piceMax);
	piceMin->Prikazi();
	piceMax->Prikazi();

	// 1 poena 
	delete s;
}

int main() {
	zadatak1();
	return 0;
}