#include "Repo.h"
#include "Controller.h"
#include <cstring>
#include <iostream>

Controller::Controller()
{
	this->repo = Repository();
}

Controller::Controller(Repository &r)
{
	this->repo = r;
}

Controller::Controller(const Controller &c)
{
	this->repo = c.repo;
}

Controller::~Controller()
{
}

Controller&Controller::operator=(const Controller &c)
{
	if (this != &c) this->repo = c.repo;
	return *this;
}

Repository Controller::getRepo()
{
	return this->repo;
}

/*
Descr: calculeaza suma totala in functie de tip
calculeaza cea mai valoroasa cheltuiala a apartamentului ap
sorteaza in functie de tip
Input: tip, ok (in functie ce cerinta), suma
Output: in functie de cerinta (suma, )
*/
void Controller::obtPropr(char* tip, int ok, int &suma, int ap)
{
	Apartament* apartamente = new Apartament[this->repo.getNumar()];
	apartamente = this->repo.getAllApartamente();
	if (ok == 1)
	{
		int sumT = 0;
		for (int i = 0; i < this->repo.getNumar(); i++)
		{
			if (strcmp(apartamente[i].getTip(), tip) == 0)
			{
				sumT = sumT + apartamente[i].getPret();
			}
		}
		suma = sumT;
	}
	else if (ok == 2)
	{
		int max = 0;
		for (int i = 0; i < this->repo.getNumar(); i++)
		{
			if (apartamente[i].getAp() == ap && apartamente[i].getPret() > max)
			{
				max = apartamente[i].getPret();
			}
		}
		cout << "cea mai valoroasa cheltuiala a apartamentului " << ap << " este: " << max;
	}
	else if (ok == 3)
	{
		Apartament* rez = new Apartament[this->repo.getNumar()];
		int n = 0;
		for (int i = 0; i < this->repo.getNumar(); i++)
		{
			if (strcmp(repo.getApartament(i).getTip(), tip) == 0)
			{
				cout << repo.getApartament(i).toString() << endl;
				rez[n] = repo.getApartament(i);
				n++;
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (rez[i].getPret() < rez[j].getPret())
				{
					Apartament aux;
					aux = rez[i];
					rez[i] = rez[j];
					rez[j] = aux;
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			cout << rez[i].toString() << " ";
		}
	}
}

char* Controller::toString()
{
	char* ap = new char[this->repo.getNumar()];
	ap = this->repo.toString();
	return ap;
}

Apartament* Controller::getAllC()
{
	return this->repo.getAllApartamente();
}

Apartament& Controller::getApartamentC(int pos) {
	return this->repo.getApartament(pos);
}

void Controller::addC(int ap, int p, char* tip)
{
	Apartament apart = Apartament(ap, tip, p);
	this->repo.addApartament(apart);
}

void Controller::stergere(int ap, int p, char* tip)
{
	Apartament apart = Apartament(ap, tip, p);
	int poz = repo.cautaPosAp(ap);
	repo.eliminare(poz);
}
/*
Descr: afiseaza lista, cheltuielile mai mari de 100,
toate cheltuielile unui apartament,
cheltuielile egale cu o suma data
Input:
Output:
*/
void Controller::afisare(int ok, int val, int suma, int comp)
{
	Apartament* apartamente = new Apartament[this->repo.getNumar()];
	apartamente = this->repo.getAllApartamente();
	if (ok == 1)
	{
		for (int i = 0; i < this->repo.getNumar(); i++)
		{
			cout << apartamente[i].toString() << " ";
		}
		cout << endl;
	}
	else if (ok == 2)
	{
		for (int i = 0; i <= this->repo.getNumar(); i++)
		{
			if (apartamente[i].getPret() == suma)
			{
				cout << apartamente[i].toString() << " ";
			}
		}
	}
	else if (ok == 3)
	{
		for (int i = 0; i < this->repo.getNumar(); i++)
		{
			if (apartamente[i].getAp() == val)
			{
				cout << apartamente[i].toString() << " ";
			}
		}
	}
	else if (ok == 4)
	{
		for (int i = 0; i < this->repo.getNumar(); i++)
		{
			if (apartamente[i].getPret() > comp)
			{
				cout << apartamente[i].toString() << " ";
			}
		}
	}
}

/*
Descr: elimina cheltuielile unui apartament
elimina cheltuielile apartamentelor de la start la final
elimina chetuielile dupa tip
Input: apartament, start, final, tip, ok(optiunea)
Output: rezultatul in functie de cerinta
*/
void Controller::eliminare(int ap, int st, char* tip, int fi, int ok)
{
	Apartament* apartamente = new Apartament[this->repo.getNumar()];
	apartamente = this->repo.getAllApartamente();
	if (ok == 1)
	{
		int i = 0;
		while (i < this->repo.getNumar())
		{
			if (this->repo.getApartament(i).getAp() == ap)
			{
				repo.eliminare(i);
			}
			else
			{
				i++;
			}
		}
	}
	else if (ok == 2)
	{
		int i = 0;
		while (i < this->repo.getNumar())
		{
			if (this->repo.getApartament(i).getAp() >= st && this->repo.getApartament(i).getAp() <= fi)
			{
				repo.eliminare(i);
			}
			else
			{
				i++;
			}
		}
	}
	else if (ok == 3)
	{
		int i = 0;
		while (i < this->repo.getNumar())
		{
			if (strcmp(this->repo.getApartament(i).getTip(), tip) == 0)
			{
				repo.eliminare(i);
			}
			else
			{
				i++;
			}
		}
	}
}

/*
Descr: inlocuirea pretului unei cheltuieli in functie de tip si numar apartament
Input: tipul dupa care se face inlocuirea si numarul apartamentului
Output: -
*/
void Controller::inlocuire_gaz(char* tip, int v, int n)
{
	Apartament* apartamente = new Apartament[this->repo.getNumar()];
	apartamente = this->repo.getAllApartamente();
	for (int i = 0; i < this->repo.getNumar(); i++)
	{
		if (strcmp(apartamente[i].getTip(), tip) == 0 && apartamente[i].getAp() == v)
		{
			apartamente[i].setPret(n);
		}
	}
}

/*
Descr: filtreaza lista
eliminand cheltuielile dupa un anumit tip
eliminand cheltuielile mai mari decat o valoare
Input: tipul, valoarea, ok(id cerinta)
Output: -
*/
void Controller::filtrare(char* tip, int val, int ok)
{
	if (ok == 1)
	{
		int i = 0;
		while (i < this->repo.getNumar())
		{
			if (strcmp(this->repo.getApartament(i).getTip(), tip) != 0)
			{
				repo.eliminare(i);
			}
			else
			{
				i++;
			}
		}
	}
	else if (ok == 2)
	{
		int i = 0;
		while (i < this->repo.getNumar())
		{
			if (this->repo.getApartament(i).getPret() >= val)
			{
				repo.eliminare(i);
			}
			else
			{
				i++;
			}
		}
	}
}

void Controller::setLista(Apartament* ap)
{
	this->repo.setLista(ap);
}

int Controller::getNumarC()
{
	return this->repo.getNumar();
}

void Controller::setNumarC(int nr)
{
	this->repo.setNumar(nr);
}

void Controller::update(Apartament &apart, char* tip, int apart2, int p)
{
	Apartament ap2 = Apartament(apart2, tip, p);
	repo.update(apart, ap2);
}