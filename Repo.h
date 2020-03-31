#ifndef REPO_H
#define REPO_H
#include "Apartament.h"
#include <iostream>
using namespace std;

const int MAX_CHELTUIELI = 10;

class Repository {
private:
	//vector <Apartament> apartamente;
	Apartament * apartamente;
	int numar;
	int capacity;
public:
	Repository();
	Repository(Apartament* apartamente, int numar, int cap);
	Repository(const Repository &r);
	~Repository();
	Repository &operator=(const Repository & r);
	//Descr: acceseaza tipul chetuielii
	//In: un apartament
	//Out: tipul
	void setNumar(int numar);
	void addApartament(Apartament apartament);
	void afisareLista();
	void setLista(Apartament* ap);
	int cautaPosPret(int p);
	int cautaPosAp(int ap);
	int cautaPosTip(char *tip);
	void update(Apartament &ap, Apartament &ap2);
	void updatePret(int p, int newp);
	void updateTip(char *t, char* newt);
	void updateAp(int ap, int newap);
	void eliminare(int poz);
	Apartament& getApartament(int poz);
	Apartament* getAllApartamente();
	int getNumar();
	char* toString();
	//bool compare(Apartament &apartament);
};

#endif


