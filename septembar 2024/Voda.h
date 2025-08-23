#pragma once
#include "Pice.h"
#include<iostream>
using namespace std;
class Voda :
    public Pice
{
public:
    Voda():Pice(){}
    Voda(double zapremina) :Pice(zapremina) {}
    ~Voda() {}
    Voda(const Voda& obj2);
    ostream& Prikazi(ostream& izlaz)const;
    double vratizapreminu()const {
        return zapremina;
    }
    int vratibrAmbalaze()const {
        return brojAmbalaza;
    }
    double vratiUkupnuZap()const {
        return brojAmbalaza * zapremina;
    }
    void SetBrojAmbalaze(int n){
        brojAmbalaza=n;
    }
};

