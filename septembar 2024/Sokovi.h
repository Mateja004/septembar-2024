#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <string>
using namespace std;

class Sokovi {
    string ukus;
    float zapremina;
    int procenat;
public:
    Sokovi();
    Sokovi(const string& ukus, float zapremina, int procenat);
    Sokovi(const Sokovi& s1);
    friend ostream& operator<<(ostream& os, const Sokovi& s1);
    friend istream& operator>>(istream& ul, Sokovi& s1);
    ostream& Print(ostream& os) const;
    const string& getUkus() const { return ukus; }
    float getZapremina() const { return zapremina; }
    int getProcenat() const { return procenat; }
};