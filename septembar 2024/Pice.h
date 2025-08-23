#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>
using namespace std;
class Pice
{
protected:
	double zapremina;
	int brojAmbalaza;
public:
	Pice() :zapremina(0),brojAmbalaza(0){};
	Pice(double zapremina) :zapremina(zapremina),brojAmbalaza(1){};
	virtual ~Pice() {};
	Pice(const Pice& obj);
	friend ostream& operator<<(ostream& izlaz, Pice& a1);
	virtual ostream& Prikazi(ostream& izlaz)const=0;
	virtual double vratizapreminu()const {
		return zapremina;
	}
	virtual int vratibrAmbalaze()const=0;
	virtual void SetBrojAmbalaze(int n)=0;
	virtual double vratiUkupnuZap()const {
		return brojAmbalaza * zapremina;
	}
};

