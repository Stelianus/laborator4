//#include "testApartament.h"
#include "Repo.h"
#include <cassert>
#include <iostream>
#include <cstring>
using namespace std;

void teste() {
	Repository r;
	int nr = r.getNumar();
	Apartament* apartamente = new Apartament[nr];
	char* x = new char[10];
	strcpy_s(x, 9, "internet");
	Apartament ap1 = Apartament(11, x, 70);
	r.addApartament(ap1);
	char* c = new char[10];
	strcpy_s(c, 4, "apa");
	Apartament ap2 = Apartament(15, c, 45);
	r.addApartament(ap2);
	apartamente = r.getAllApartamente();
	assert(strcmp((apartamente[0]).toString(), "internet;11;70;") == 0);
	assert(strcmp((apartamente[1]).toString(), "apa;15;45;") == 0);
	assert(r.cautaPosAp(11) == 0);
	assert(r.cautaPosPret(45) == 1);
	char* sir = new char[10];
	strcpy_s(sir, 4, "apa");
	assert(r.cautaPosTip(sir) == 1);
	r.updateAp(11, 13);
	r.updatePret(70, 140);
	char* sir2 = new char[10];
	strcpy_s(sir2, 4, "gaz");
	r.updateTip(x, sir2);
	assert(strcmp(apartamente[0].toString(), "gaz;13;140;") == 0);
	r.eliminare(0);
	assert(r.getNumar() == 1);
	cout << "tests repo..." << endl;
}