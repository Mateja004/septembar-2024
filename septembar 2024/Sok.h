#pragma once
#include "Pice.h"
class Sok :
    public Pice
{
private:
    char* ukus;
    int procenatSoka;
    float cena;
public:
    Sok();
    Sok(double zapremina,const char* ukus, int procenatSoka, float cena);
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

