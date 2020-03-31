#include"Repo.h"
#include<cstring>
#include<string>
#include<cstdlib>

//Descr: creeaza un repo
//In:-
//Out: o instanta Repository

Repository::Repository()
{
	this->numar = 0;
	this->apartamente = new Apartament[MAX_CHELTUIELI];
	this->capacity = MAX_CHELTUIELI;
}

/*
Descr: creeaza un repo
In: un numar de apartamente, un vector cu apartamente
Out: o instanta(cu informatii) a unui Repo
*/
Repository::Repository(Apartament *ap, int numar, int c)
{
	this->numar = numar;
	this->apartamente = new Apartament[c];
	for (int i = 0; i < this->numar; i++)
		this->apartamente[i] = ap[i];
}

/*
Descr:distruge un Repo
In:un repo
Out:-(destructor)
*/
Repository::~Repository()
{
	if (this->apartamente)
	{
		delete[] this->apartamente;
		this->apartamente = NULL;
	}
}

/*
Descr: creeaza un repo utilizand informatii de la alt repo
In: un repo(r)
Out: o instanta de Repo cu informatii de la r
*/
Repository::Repository(const Repository &r)
{
	this->numar = r.numar;
	this->capacity = r.capacity;
	if (this->apartamente)
		delete[]this->apartamente;
	this->apartamente = new Apartament[this->capacity];
	for (int i = 0; i < this->numar; i++)
		this->apartamente[i] = r.apartamente[i];
}
/*
Descr: creeeaza un nou repo(egal cu cel dat r)
In: un repo(r)
Out: un nou repo(egal cu r)
*/
Repository&Repository::operator=(const Repository &r) {
	if (this != &r)
	{
		this->numar = r.numar;
		this->capacity = r.capacity;
		if (this->apartamente)
			delete[]this->apartamente;
		this->apartamente = new Apartament[this->capacity];
		for (int i = 0; i < this->numar; i++)
			this->apartamente[i] = r.apartamente[i];
	}
	return *this;
}

/*
Descr: acceseaza numarul de apartamente din repo
In: un repo
Out: numarul de apartamente
*/
int Repository::getNumar()
{
	return this->numar;
}

//Descr: schimba numarul de apartamente
//In: un repo si un numar de apartamente
//Out: repo cu numarul de apartamente schimbat
void Repository::setNumar(int numar)
{
	this->numar = numar;
}

/*
Descr: adauga un apartament in repo
Input: un apartament
Output: lista modificata
*/
void Repository::addApartament(Apartament ap)
{
	this->apartamente[this->numar] = ap;
	this->numar++;
}


/*
Descr: acceseaza un apartament(de la o pozitie)
In: un repo si o pozitie
Out: apartamentul de la pozitia respectiva
*/
Apartament& Repository::getApartament(int pos) {
	return this->apartamente[pos];
}


/*
Descr: converteste un repo la un string
In: un repo
Out: stringul corespunzator
*/

char* Repository::toString() {
	int lungimea = this->numar * (MAX_CHELTUIELI + 1) + 6;
	char* s = new char[lungimea];
	char* aux = new char[5];
	_itoa_s(this->numar, aux, 5, 10);
	strcpy_s(s, 1, "");
	for (int i = 0; i < this->numar; i++) {
		strcat_s(s, 50, this->apartamente[i].toString());
	}
	return s;
}

/*
Descr: returneaza lista de partamente
Input: -
Output: lista de apartamente
*/
Apartament* Repository::getAllApartamente()
{
	return this->apartamente;
}

/*
Descr: afiseaza o lista
Input: -
Output: afisare
*/
void Repository::afisareLista()
{
	Apartament*ap = new Apartament[this->numar];
	ap = this->getAllApartamente();
	for (int i = 0; i < this->numar; i++)
		cout << ap[i].toString();
}

/*
Descr: cauta un apartament dupa pret
Input: pretul dupa care se face cautarea
Output: pozitia apartamentului
*/
int Repository::cautaPosPret(int pret) {
	int pozc = -1;
	Apartament* apartamente = new Apartament[this->numar];
	apartamente = this->getAllApartamente();
	for (int i = 0; i < this->numar; i++) {
		if (apartamente[i].getPret() == pret) {
			pozc = i;
		}
	}
	return pozc;
}

/*
Descr: cauta un apartament dupa numarul de partament
Input: numarul dupa care se face cautarea
Output: pozitia apartamentului
*/

int Repository::cautaPosAp(int ap) {
	int pozc = -1;
	Apartament* apartamente = new Apartament[this->numar];
	apartamente = this->getAllApartamente();
	for (int i = 0; i < this->numar; i++) {
		if (apartamente[i].getAp() == ap) {
			pozc = i;
		}
	}
	return pozc;
}

/*
Descr: cauta un apartament dupa tip
Input: tipul dupa care se face cautarea
Output: pozitia apartamentului
*/
int Repository::cautaPosTip(char* tip) {
	int pozc = -1;
	Apartament* apartamente = new Apartament[this->numar];
	apartamente = this->getAllApartamente();
	for (int i = 0; i < this->numar; i++) {
		if (strcmp(apartamente[i].getTip(), tip) == 0) {
			pozc = i;
		}
	}
	return pozc;
}

/*
Descr: modifica pretul unui apartament
Input: pretul actual si cel cu care se inlocuieste
Output: -
*/
void Repository::updatePret(int pret1, int pret2) {
	int rez = -1;
	Apartament* apartamente = new Apartament[this->numar];
	apartamente = this->getAllApartamente();
	rez = this->cautaPosPret(pret1);
	apartamente[rez].setPret(pret2);
}

/*
Descr: modifica tipul unui apartament
Input: tipul actual si cel cu care se inlocuieste
Output: -
*/
void Repository::updateTip(char* tip1, char* tip2) {
	int rez = -1;
	Apartament* apartamente = new Apartament[this->numar];
	apartamente = this->getAllApartamente();
	rez = this->cautaPosTip(tip1);
	apartamente[rez].setTip(tip2);
}

/*
Descr: modifica numarul unui apartament
Input: numarul actual si cel cu care se inlocuieste
Output: -
*/
void Repository::updateAp(int ap1, int ap2) {
	int rez = -1;
	Apartament* apartamente = new Apartament[this->numar];
	apartamente = this->getAllApartamente();
	rez = this->cautaPosAp(ap1);
	apartamente[rez].setAp(ap2);
}

void Repository::setLista(Apartament* ap)
{
	this->apartamente = ap;
}

/*
Descr:
*/
void Repository::update(Apartament &ap, Apartament &ap2)
{
	int ok = 1;
	Apartament* apartamente = new Apartament[this->numar];
	apartamente = this->getAllApartamente();
	for (int i = 0; i < this->numar; i++)
	{
		if (strcmp(apartamente[i].toString(), ap.toString()) != 0)
		{
			ok = 0;
			this->apartamente[i] = ap2;
		}
	}
	if (ok == 1)
	{
		cout << "nu exista apartamentul" << endl;
	}
}

/*
Descr: elimina un apartament dupa pozitia din lista
Input: pozitia de pe care se elimina
Output: lista modificata
*/
void Repository::eliminare(int poz)
{
	Apartament* apartamente = new Apartament[this->numar];
	apartamente = this->getAllApartamente();
	for (int i = poz; i < this->numar - 1; i++) {
		apartamente[i] = apartamente[i + 1];
	}
	this->numar--;
}