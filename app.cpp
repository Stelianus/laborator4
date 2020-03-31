#include "Apartament.h"
#include "Repo.h"
#include "Controller.h"
#include "testApartament.h"
#include "testRepo.h"
#include "TestController.h"
#include "ui.h"
#include <stdlib.h> 
#include <iostream>
#include <cstring>
#include <conio.h>


using namespace std;

int main() {

	cout << " start main ..." << endl;

	//teste();
	//teste2();
	//testController();
	Repository r;
	Controller c;
	c = Controller(r);
	char* tip = new char[4];
	strcpy_s(tip, 4, "gaz");
	Apartament ap = Apartament(12, tip, 150);
	char* x = new char[10];
	strcpy_s(x, 9, "internet");
	Apartament ap1 = Apartament(11, x, 70);
	c.addC(12, 150, tip);
	c.addC(11, 70, x);
	UI ui;
	ui = UI(c);
	ui.run();
	return 0;
}


