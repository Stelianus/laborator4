#include "Apartament.h"
#include <cassert>
#include <iostream>
#include <cstring>
using namespace std;

void teste2() {
	Apartament ap1 = Apartament();
	assert(ap1.getTip() == NULL);
	assert(ap1.getPret() == 0);
	assert(ap1.getAp() == 0);
	assert(strcmp(ap1.toString(), "") == 0);

	char* x = new char[10];
	strcpy_s(x, 4, "gaz");
	Apartament ap2 = Apartament(12, x, 120);
	assert(strcmp(ap2.getTip(), x) == 0);
	assert(ap2.getPret() == 120);
	assert(strcmp(ap2.toString(), "gaz;12;120;") == 0);

	Apartament ap3 = Apartament(ap2);
	assert(strcmp(ap3.getTip(), "gaz") == 0);
	assert(ap3.getPret() == 120);
	assert(strcmp(ap3.toString(), "gaz;12;120;") == 0);

	assert(ap2.compare(ap3) == true);

	ap3.setPret(55);
	assert(ap3.getPret() == 55);
	assert(strcmp(ap3.toString(), "gaz;12;55;") == 0);

	assert(ap2.compare(ap3) == false);

	cout << "teste apartament" << endl;
}