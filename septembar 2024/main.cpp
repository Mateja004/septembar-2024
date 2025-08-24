#include <iostream>
using namespace std;
#include "Skladiste.h"
#include "Pice.h"
#include "Sok.h"
#include "Voda.h"
#include "Sokovi.h"
#include "Fabrika.h"

void zadatak1()
{
    char ukus1[7] = "jagoda";
    int procenat1 = 50;
    float odnosCene = 0.75;
    // 2 poena 
    Pice* p1 = new Voda(1);
    cout << *p1 << endl;

    Pice* p2 = new Sok(0.75, ukus1, procenat1, odnosCene);
    cout << *p2 << endl;

    float voda[] = { 1.0f, 0.2f, 2.0f, 5.0f, 1.0f, 1.0f, 2.0f, 5.0f };
    float sok[] = { 1.0f, 0.2f, 1.5f, 0.5f, 1.0f, 0.5f, 1.0f, 1.5f };
    Skladiste* s = new Skladiste(10);

    for (int i = 0; i < 4; i++)
    {
        s->Dodaj(new Voda(voda[i]));
        s->Dodaj(new Sok(sok[i], ukus1, procenat1, odnosCene));
    }
    cout << *s << endl;

    for (int i = 4; i < 8; i++)
    {
        s->Dodaj(new Voda(voda[i]));
        s->Dodaj(new Sok(sok[i], ukus1, procenat1, odnosCene));
    }
    cout << *s << endl;

    Sok sokic(0.5f, ukus1, procenat1, odnosCene);
    s->Izdvoji(sokic, 2);
    cout << *s << endl;

    Voda voda1(1);
    s->Izdvoji(voda1, 2);
    cout << *s << endl;

    Voda voda2(2);
    s->Presipaj(voda2, voda1);
    cout << *s << endl;

    int nabavka = 7;
    if (s->DovoljnaKolicina(nabavka))
        cout << "Ima dovoljno vode i sokova za " << nabavka << "l" << endl;
    else
        cout << "Nema dovoljno vode i sokova" << endl;

    Pice* piceMin = nullptr, * piceMax = nullptr;
    s->VratiNaj(piceMin, piceMax);
    piceMin->Prikazi();
    piceMax->Prikazi();

    delete s;
}

void zadatak2()
{
    try {
        int maxPodataka = 8, brojPodataka = 7;

        float voda[] = { 1.0f, 0.2f, 0.5f, 1.0f, 0.5f, 0.2f, 0.2f };
        Fabrika<float> fv(maxPodataka);

        for (int i = 0; i < brojPodataka; i++) {
            try {
                fv.Dodaj(voda[i]);
            }
            catch (const runtime_error& e) {
                cout << "Greska pri dodeli! " << e.what() << endl;
            }
        }

        cout << fv << endl;

        try {
            fv.Izbaci(voda[1]);
        }
        catch (const runtime_error& g) {
            cout << g.what() << endl;
        }
        cout << fv << endl;

        try {
            float ukupno = fv.Ukupno();
            cout << ukupno << endl;
        }
        catch (const runtime_error& p) {
            cout << p.what() << endl;
        }

        try {
            int vrednost = 1; float ukupnaVrednost = 0;
            int broj = fv.UkupniBrojVrednost(vrednost, &ukupnaVrednost);
            cout << broj << " " << ukupnaVrednost << endl;
        }
        catch (const runtime_error& k) {
            cout << k.what() << endl;
        }

        try {
            int najmanjeAmbalaza = fv.NajmanjeAmbalaza(2.8f);
            cout << najmanjeAmbalaza << endl;
        }
        catch (const runtime_error& j) {
            cout << j.what() << endl;
        }

        try {
            fv.Sacuvaj("NovaFabrikaVode.txt");
        }
        catch (const runtime_error& h) {
            cout << h.what() << endl;
        }

        try {
            Fabrika<float> novaUcitana(maxPodataka);
            novaUcitana.Ucitaj("NovaFabrikaVode.txt");
            cout << novaUcitana << endl;
        }
        catch (const runtime_error& g) {
            cout << g.what() << endl;
        }

        // deo sa Sokovima
        try {
            char ukus[][7] = { "jagoda", "jabuka", "jagoda", "jagoda", "jagoda", "jabuka",
                               "jagoda" };
            float zap[] = { 1.0f, 0.2f, 0.5f, 1.0f, 0.5f, 0.2f, 0.2f };
            int procenat[] = { 50, 70, 50, 50, 50, 70, 50 };

            Fabrika<Sokovi> fs(maxPodataka);
            for (int i = 0; i < brojPodataka; i++) {
                fs.Dodaj(Sokovi(ukus[i], zap[i], procenat[i]));
            }
            cout << fs << endl;

            fs.Izbaci(Sokovi(ukus[1], zap[1], procenat[1]));
            cout << fs << endl;

            float ukupno2 = fs.Ukupno();
            cout << ukupno2 << endl;

            Sokovi vr(ukus[0], zap[0], procenat[0]);
            float ukupnaVrednost = 0;
            int broj = fs.UkupniBrojVrednost(vr, &ukupnaVrednost);
            cout << broj << " " << ukupnaVrednost << endl;

            int najmanjeAmbalaza = fs.NajmanjeAmbalaza(2.5);
            cout << najmanjeAmbalaza << endl;

            fs.Sacuvaj("NovaFabrikaSokova.txt");

            Fabrika<Sokovi> novaUcS(maxPodataka);
            novaUcS.Ucitaj("NovaFabrikaSokova.txt");
            cout << novaUcS << endl;
        }
        catch (const runtime_error& r) {
            cout << r.what() << endl;
        }
    }
    catch (const runtime_error& l) {
        cout << "greska! " << l.what() << endl;
    }
}

int main() {
    zadatak1();
    zadatak2();
    return 0;
}
