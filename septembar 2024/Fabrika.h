#pragma once
#include "Sokovi.h"
#include <fstream>
#include <iostream>
using namespace std;

template<typename T>
class Fabrika {
    T* niz;
    int maxBr;
    int trBr;
public:
    Fabrika();
    Fabrika(int maxBr);
    Fabrika(const Fabrika<T>& f1);
    ~Fabrika();
    void Dodaj(T t);
    friend ostream& operator<<(ostream& os, const Fabrika<T> f1) {
        f1.Ispisi(os);
        return os;
    }
    ostream& Ispisi(ostream& os) const;
    void Izbaci(T t);
    float Ukupno() const;
    int UkupniBrojVrednost(T vrednost, float* ukVr) const;
    int NajmanjeAmbalaza(float vr) const;
    void Sacuvaj(const char* nazivFajla) const;
    void Ucitaj(const char* nazivFajla);
};

template<typename T>
Fabrika<T>::Fabrika() {
    maxBr = 0;
    trBr = 0;
    niz = nullptr;
}

template<typename T>
Fabrika<T>::Fabrika(int maxBr) {
    this->maxBr = maxBr;
    this->trBr = 0;
    niz = new T[maxBr];
}

template<typename T>
Fabrika<T>::Fabrika(const Fabrika<T>& f1) {
    this->niz = nullptr;
    this->maxBr = f1.maxBr;
    this->trBr = f1.trBr;
    this->niz = new T[this->maxBr];
    for (int i = 0; i < this->trBr; i++) {
        this->niz[i] = f1.niz[i];
    }
}

template<typename T>
Fabrika<T>::~Fabrika() {
    delete[] niz;
}

template<typename T>
ostream& Fabrika<T>::Ispisi(ostream& os) const {
    os << "U fabrici je:" << endl;
    for (int i = 0; i < trBr; i++) {
        os << niz[i] << endl;
    }
    return os;
}

template<typename T>
float Fabrika<T>::Ukupno() const {
    float ukZap = 0;
    for (int i = 0; i < trBr; i++) {
        ukZap += niz[i];
    }
    return ukZap;
}

template<>
float Fabrika<Sokovi>::Ukupno() const {
    float ukZap = 0;
    for (int i = 0; i < trBr; i++) {
        ukZap += niz[i].getZapremina();
    }
    return ukZap;
}

template<typename T>
int Fabrika<T>::UkupniBrojVrednost(T vrednost, float* ukVr) const {
    int brojAmbalaza = 0;
    for (int i = 0; i < trBr; i++) {
        if (niz[i] == vrednost) {
            brojAmbalaza++;
            *ukVr += vrednost;
        }
    }
    return brojAmbalaza;
}

template<>
int Fabrika<Sokovi>::UkupniBrojVrednost(Sokovi vrednost, float* ukvr) const {
    int brojAmbalaza = 0;
    for (int i = 0; i < trBr; i++) {
        if (niz[i].getZapremina() == vrednost.getZapremina()) {
            brojAmbalaza++;
            *ukvr += vrednost.getZapremina();
        }
    }
    return brojAmbalaza;
}

template<typename T>
void Fabrika<T>::Dodaj(T t) {
    if (trBr >= maxBr) {
        throw runtime_error("Nema mesta u fabrici!");
    }
    niz[trBr++] = t;
    for (int i = 0; i < trBr - 1; i++) {
        for (int j = 0; j < trBr - i - 1; j++) {
            if (niz[j] >= niz[j + 1]) {
                T pom = niz[j];
                niz[j] = niz[j + 1];
                niz[j + 1] = pom;
            }
        }
    }
}

template <>
void Fabrika<Sokovi>::Dodaj(Sokovi t) {
    if (trBr >= maxBr) {
        throw runtime_error("Nema mesta u fabrici!");
    }
    niz[trBr++] = t;
    for (int i = 0; i < trBr - 1; i++) {
        for (int j = 0; j < trBr - i - 1; j++) {
            if (niz[j].getZapremina() >= niz[j + 1].getZapremina()) {
                Sokovi pom = niz[j];
                niz[j] = niz[j + 1];
                niz[j + 1] = pom;
            }
        }
    }
}

template<typename T>
void Fabrika<T>::Izbaci(T t) {
    for (int i = 0; i < trBr; i++) {
        if (niz[i] == t) {
            for (int j = i; j < trBr - 1; j++) {
                niz[j] = niz[j + 1];
            }
            trBr--;
            return;
        }
    }
    throw runtime_error("Nema takvog elementa!");
}

template<>
void Fabrika<Sokovi>::Izbaci(Sokovi t) {
    for (int i = 0; i < trBr; i++) {
        if (t.getZapremina() == niz[i].getZapremina()) {
            for (int j = i; j < trBr - 1; j++) {
                niz[j] = niz[j + 1];
            }
            trBr--;
            return;
        }
    }
    throw runtime_error("Nema takvog pica");
}

template<typename T>
int Fabrika<T>::NajmanjeAmbalaza(float vr) const {
    if (vr <= 0) {
        throw runtime_error("Unesena vrednost nije ispravna!");
    }
    int broj = 0;
    float ukVR = 0;
    for (int i = trBr - 1; i >= 0; i--) {
        ukVR += niz[i];
        if (ukVR <= vr) {
            broj++;
        }
        else {
            break;
        }
    }
    return broj;
}

template<>
int Fabrika<Sokovi>::NajmanjeAmbalaza(float vr) const {
    if (vr <= 0) {
        throw runtime_error("Unesena vrednost nije ispravna!");
    }
    int broj = 0;
    float ukVR = 0;
    for (int i = trBr - 1; i >= 0; i--) {
        ukVR += niz[i].getZapremina();
        if (ukVR <= vr) {
            broj++;
        }
        else {
            break;
        }
    }
    return broj;
}

template<typename T>
void Fabrika<T>::Sacuvaj(const char* nazivFajla) const {
    ofstream fajl(nazivFajla);
    if (!fajl.is_open()) {
        throw runtime_error("Nije moguce otvoriti fajl!");
    }
    for (int i = 0; i < trBr; i++) {
        fajl << niz[i] << endl;
    }
    fajl.close();
}

template<typename T>
void Fabrika<T>::Ucitaj(const char* nazivFajla) {
    ifstream fajl(nazivFajla);
    if (!fajl.is_open()) {
        throw runtime_error("Nije moguce otvoriti fajl!");
    }
    trBr = 0; // Resetujemo broj elemenata
    T pom;
    while (fajl >> pom && trBr < maxBr) {
        niz[trBr] = pom;
        trBr++;
    }
    fajl.close();
    if (fajl >> pom) {
        throw runtime_error("Previše elemenata u fajlu!");
    }
}