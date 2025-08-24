#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>
using namespace std;
class Pice
{
protected:
	float zapremina;
	int brojAmbalaza;
public:
	Pice() :zapremina(0), brojAmbalaza(0) {};
	Pice(float zapremina) :zapremina(zapremina), brojAmbalaza(1) {};
	virtual ~Pice() {};
	Pice(const Pice& obj);
	friend ostream& operator<<(ostream& izlaz, Pice& a1);
	virtual ostream& Print(ostream& izlaz)const = 0;
	virtual void Prikazi()const = 0;
	virtual float vratizapreminu()const {
		return zapremina;
	}
	virtual int vratibrAmbalaze()const = 0;
	virtual void SetBrojAmbalaze(int n) = 0;
	virtual float vratiUkupnuZap()const {
		return brojAmbalaza * zapremina;
	}
};

