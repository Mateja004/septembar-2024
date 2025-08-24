#include "Sokovi.h"
#include <iostream>
using namespace std;

Sokovi::Sokovi() : zapremina(0), procenat(0), ukus("") {}

Sokovi::Sokovi(const string& ukus, float zapremina, int procenat)
    : ukus(ukus), zapremina(zapremina), procenat(procenat) {
}

Sokovi::Sokovi(const Sokovi& s1) : ukus(s1.ukus), zapremina(s1.zapremina), procenat(s1.procenat) {}

ostream& Sokovi::Print(ostream& os) const {
    os << "Zapremina: " << zapremina << " Procenat: " << procenat << " Ukus: " << ukus;
    return os;
}

ostream& operator<<(ostream& os, const Sokovi& s1) {
    s1.Print(os);
    return os;
}

istream& operator>>(istream& ul, Sokovi& s1) {
    string temp;
    // Preskačemo "Zapremina:"
    ul >> temp >> s1.zapremina;
    // Preskačemo "Procenat:"
    ul >> temp >> s1.procenat;
    // Preskačemo "Ukus:" i čitamo ukus
    ul >> temp;
    getline(ul, s1.ukus);
    // Uklanjamo početni razmak ako postoji
    if (!s1.ukus.empty() && s1.ukus[0] == ' ') {
        s1.ukus.erase(0, 1);
    }
    return ul;
}