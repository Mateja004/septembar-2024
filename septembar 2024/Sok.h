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
    Sok(float zapremina,const char* ukus, int procenatSoka, float cena);
    ~Sok();
    Sok(const Sok& obj3);
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
     const char* vratiUkus()const {
        return ukus;
    }
     void Prikazi()const;
};

