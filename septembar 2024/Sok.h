#pragma once
#include "Pice.h"
class Sok :
    public Pice
{
public:
    char* ukus;
    float procenatSoka;
    float cena;
private:
    Sok();
    Sok(double zapremina,const char* ukus, float procenatSoka, float cena);
    ~Sok();
    Sok(const Sok& obj3);
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
     const char* vratiUkus()const {
        return ukus;
    }
};

