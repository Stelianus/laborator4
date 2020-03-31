#include "Apartament.h"
#include <string>


//Descr: creaza un apartament
//In: -
//Out: instanta unui apartament
Apartament::Apartament() {
	this->ap = 0;
	this->tip = NULL;
	this->pret = 0;
}

//Descr: creeaza un apartament
//In: numar ap, tip cheltuieli, pret
//Out: instanta cu info
Apartament::Apartament(int a, char* t, int p) {
	this->ap = a;
	this->tip = new char[strlen(t) + 1];
	strcpy_s(this->tip, strlen(t) + 1, t);
	this->pret = p;
}

//Descr: operator =
//Input: apartament
//Output: this
Apartament & Apartament::operator=(const Apartament &apartament)
{
	if (this != &apartament)
	{
		ap = apartament.ap;
		pret = apartament.pret;
		setTip(apartament.tip);
	}
	return *this;
}

//Descr: creaza u apartament cu datele altui apartament
//In: un apartament a
//Out: o instanta cu informatii din a
Apartament::Apartament(const Apartament &apartament) {
	this->ap = apartament.ap;
	this->tip = new char[strlen(apartament.tip) + 1];
	strcpy_s(this->tip, strlen(apartament.tip) + 1, apartament.tip);
	this->pret = apartament.pret;
}


//Descr: destructor apartament 
//In: un apartament
//Out: - (destructor)
Apartament::~Apartament() {
	if (this->tip != NULL) {
		delete[] this->tip;
		this->tip = NULL;
	}
}

//Descr: acceseaza pretul
//In: un apartament
//Out: pretul
int Apartament::getPret() {
	return this->pret;
}

//Descr: acceseaza numarul
//In: un apartament
//Out: numarul
int Apartament::getAp() {
	return this->ap;
}

//Descr: acceseaza tipul
//In: un apartament
//Out: tipul
char *Apartament::getTip()
{
	return this->tip;
}

//Descr: schimba numarul unui apartament
//In: apartamentul si numarul
//Out: apartamentul cu numarul schimbat
void Apartament::setAp(int a) {
	this->ap = a;
}

//Descr: schimba tipul unei cheltuieli
//In: un apartament si denumirea cheltuielii
//Out: apartamentul cu cheltuielile schimbate
void Apartament::setTip(char* tip) {
	delete[] this->tip;
	this->tip = new char[strlen(tip) + 1];
	strcpy_s(this->tip, strlen(tip) + 1, tip);
}

//Descr: schimba pretul unei cheltuieli
//In: apartamentul si pretul
//Out: apartamentul cu pretul schimbat
void Apartament::setPret(int p) {
	this->pret = p;
}

//Descr: converteste apartamentul la string
//In: un apartament 
//Out: un string cu informatiile despre apartament
char* Apartament::toString() {
	if (this->tip != NULL) {
		int noChars = strlen(this->tip) + 5 + 5 + 3 + 1;
		char* s = new char[noChars];
		char* aux = new char[5];
		char* aux2 = new char[5];
		strcpy_s(s, noChars, this->tip);
		strcat_s(s, noChars, ";");
		_itoa_s(this->ap, aux2, 5, 10);
		_itoa_s(this->pret, aux, 5, 10);
		strcat_s(s, noChars, aux2);
		strcat_s(s, noChars, ";");
		strcat_s(s, noChars, aux);
		if (aux) {
			delete[] aux;
			aux = NULL;
		}
		strcat_s(s, noChars, ";");
		return s;
	}
	else
	{
		char* x = new char[1];
		strcpy_s(x, 1, "");
		return x;
	}
}

//Descr: compara doua apartamente
//In: doua apartamente
//Out: true/false
bool Apartament::compare(Apartament &a) {
	return ((this->ap == a.ap) && (strcmp(this->tip, a.tip) == 0) && (this->pret == a.pret));
}

