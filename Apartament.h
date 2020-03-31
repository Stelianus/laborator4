#ifndef APARTAMENT_H
#define APARTAMENT_H

#include <iostream>
using namespace std;

const int MAX_AP = 100;

class Apartament {
private:
	int ap;
	char* tip;
	int pret;
public:
	Apartament();
	Apartament(int ap, char* tip, int pret);
	Apartament(const Apartament & apartament);
	~Apartament();
	Apartament &operator=(const Apartament & apartament);
	/*
	//Descr: acceseaza tipul chetuielii
	//In: un apartament
	//Out: tipul
	char* const getTip() const {
	//return tipul;
	return this->tip;
	}*/
	char* getTip();
	int getAp();
	int getPret();
	void setAp(int ap);
	void setTip(char* t);
	void setPret(int pret);
	char* toString();
	bool compare(Apartament & apartament);
};

#endif

