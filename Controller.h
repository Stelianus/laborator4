#pragma once
#ifndef Controller_H
#define Controller_H
#include "Repo.h"
#include "Apartament.h"
#include <iostream>
using namespace std;

class Controller {
private:
	Repository repo;
public:
	Controller();
	Controller(Repository &repo);
	Controller(const Controller &c);
	~Controller();
	Controller &operator=(const Controller &c);
	Repository getRepo();
	Apartament* getAllC();
	Apartament& getApartamentC(int p);
	int getNumarC();
	void setNumarC(int nr);
	void obtPropr(char* tip, int ok, int &suma, int ap);
	void addC(int ap, int p, char* tip);
	void stergere(int ap, int p, char* tip);
	void afisare(int ok, int val, int suma, int comp);
	void inlocuire_gaz(char* tip, int val1, int val2);
	void filtrare(char* tip, int val, int ok);
	void setLista(Apartament* ap);
	void inlocuire(int ap, int p, char* tip, int ap2, int p2, char* tip2);
	void eliminare(int ap, int st, char* tip, int fi, int ok);
	void update(Apartament &ap, char* tip, int apart, int p);
	//Descr: acceseaza tipul chetuielii
	//In: un apartament
	//Out: tipul
	char* toString();
	//bool compare(Apartament &apartament);
};

#endif
