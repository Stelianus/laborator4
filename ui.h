#pragma once
#ifndef UI_H
#define UI_H
#include "Controller.h"
class UI {
private:
	Controller ctrl;
	void printMenu();
	void adauga();
	void afiseaza();
public:
	UI();
	~UI();
	UI(Controller &c);
	void run();
};


#endif