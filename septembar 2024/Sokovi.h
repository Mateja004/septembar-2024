#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
using namespace std;
class Sokovi
{
	char* ukus;
	float zapremina;
	int procenat;
public:
	Sokovi();
	Sokovi(const char* ukus, float zapremina, int procenat);
	Sokovi(const Sokovi& s1);
	~Sokovi();
	friend ostream& operator<<(ostream& os,  Sokovi& s1);
	ostream& Print(ostream& os);
	const char* getUkus()const { return ukus; }
	float getZapremina()const { return zapremina; }
	int getProcenat()const { return procenat; }
};

