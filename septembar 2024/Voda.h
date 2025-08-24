#pragma once
#include "Pice.h"
#include<iostream>
using namespace std;
class Voda :
    public Pice
{
public:
    Voda():Pice(){}
    Voda(float zapremina) :Pice(zapremina) {}
    ~Voda() {}
    Voda(const Voda& obj2);
    ostream& Print(ostream& izlaz)const;
    float vratizapreminu()const {
        return zapremina;
    }
    int vratibrAmbalaze()const {
        return brojAmbalaza;
    }
    float vratiUkupnuZap()const {
        return brojAmbalaza * zapremina;
    }
    void SetBrojAmbalaze(int n){
        brojAmbalaza=n;
    }
    void Prikazi()const;
};

