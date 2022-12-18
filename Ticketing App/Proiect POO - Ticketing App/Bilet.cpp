#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;
//Gestionarea biletelor unui teatru


class Bilet {
private:
	const int idBilet;
	char* numePiesa;
	string data_ora;
	string zona;
	int nrPersoane;
	char* locuri;
	float pret;
protected:
	static int contor;
public:
	Bilet() : idBilet(contor++) {
		this->numePiesa = new char[strlen("Necunoscut") + 1];
		strcpy(this->numePiesa, "Necunoscut");
		this->data_ora = "Necunoscut";
		this->zona = "Necunoscut";
		this->nrPersoane = 0;
		this->locuri = nullptr;
		this->pret = 0;
	}

	Bilet(const char* numePiesa, string data_ora, string zona, int nrPersoane, const char* locuri, float pret) :idBilet(contor++) {
		this->numePiesa = new char[strlen(numePiesa) + 1];
		strcpy(this->numePiesa, numePiesa);
		this->data_ora = data_ora;
		this->zona = zona;
		this->nrPersoane = nrPersoane;
		this->locuri = new char[this->nrPersoane];
		for (int i = 0;i < this->nrPersoane;i++) {
			this->locuri[i] = locuri[i];
		}
		this->pret = pret;
	}

	char* getNumePiesa() {
		return this->numePiesa;
	}

	void setNumePiesa(const char* numePiesa) {
		if (this->numePiesa != nullptr)
		{
			delete[]this->numePiesa;
			this->numePiesa = new char[strlen(numePiesa) + 1];
			strcpy(this->numePiesa, numePiesa);
		}
	}

	string getDataOra() {
		return this->data_ora;
	}

	void setDataOra(string data_ora) {
		if (data_ora != "")
		{
			this->data_ora = data_ora;
		}
		else {
			this->data_ora = "Necunoscut";
		}
	}

	string getZona() {
		return this->zona;
	}

	void setZona(string zona) {
		if (zona != "")
		{
			this->zona = zona;
		}
		else {
			this->zona = "Necunoscut";
		}
	}

	int getNrPersoane() {
		return this->nrPersoane;
	}

	char* getLocuri() {
		return this->locuri;
	}

	void setNrFacilitati(int nrPersoane, char* locuri) {
		if (nrPersoane >= 0 && locuri != NULL) {
			if (this->locuri != NULL) {
				delete[]this->locuri;
			}
			this->nrPersoane = nrPersoane;
			this->locuri = new char[this->nrPersoane];
			for (int i = 0;i < this->nrPersoane;i++) {
				this->locuri[i] = locuri[i];
			}
		}
	}

	float getPret() {
		return this->pret;
	}

	void setPret(float pret) {
		if (pret > 0)
		{
			this->pret = pret;
		}
		else {
			this->pret = 0;
		}
	}

	Bilet(const Bilet& b) :idBilet(b.idBilet) {
		this->numePiesa = new char[strlen(b.numePiesa) + 1];
		strcpy(this->numePiesa, numePiesa);
		this->data_ora = b.data_ora;
		this->zona = b.zona;
		this->nrPersoane = b.nrPersoane;
		this->locuri = new char[this->nrPersoane];
		for (int i = 0;i < this->nrPersoane;i++) {
			this->locuri[i] = b.locuri[i];
		}
		this->pret = b.pret;
	}

	~Bilet() {
		if (this->numePiesa != NULL)
		{
			delete[]this->numePiesa;
		}
		if (this->locuri != NULL) 
		{
			delete[]this->locuri;
		}
	}

	Bilet& operator=(const Bilet& b) {
		if (this != &b) {
			if (this->numePiesa != NULL)
			{
				delete[]this->numePiesa;
			}
			if (this->locuri != NULL) 
			{
				delete[]this->locuri;
			}
			this->numePiesa = new char[strlen(b.numePiesa) + 1];
			strcpy(this->numePiesa, numePiesa);
			this->data_ora = b.data_ora;
			this->zona = b.zona;
			this->nrPersoane = b.nrPersoane;
			this->locuri = new char[this->nrPersoane];
			for (int i = 0;i < this->nrPersoane;i++) {
				this->locuri[i] = b.locuri[i];
			}
			this->pret = b.pret;
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Bilet b) {
		out << "Id bilet: " << b.idBilet << endl;
		out << "Piesa: " << b.numePiesa << endl;
		out << "Data si ora: " << b.data_ora << endl;
		out << "Zona: " << b.zona << endl;
		out << "Nr persoane: " << b.nrPersoane << endl;
		out << "Locuri: ";
		for (int i = 0;i < b.nrPersoane;i++) {
			out << b.locuri[i] << " | ";
		}
		out << endl;
		out << "Pret: " << b.pret << " lei" << endl;
		return out;
	}

	friend istream& operator>>(istream& in, Bilet& b) {
		if (b.numePiesa != NULL)
		{
			delete[]b.numePiesa;
		}
		if (b.locuri != NULL) 
		{
			delete[]b.locuri;
		}
		cout << "Nume piesa: ";
		char aux[100];
		in >> aux;
		in.getline(aux, 99);
		b.numePiesa = new char[strlen(aux) + 1];
		strcpy(b.numePiesa, aux);
		cout << "Data si ora: ";
		in >> b.data_ora;
		cout << "Zona: ";
		in >> b.zona;
		cout << "Numar persoane: ";
		in >> b.nrPersoane;
		cout << "Locuri: ";
		b.locuri = new char[b.nrPersoane];
		for (int i = 0;i < b.nrPersoane;i++) {
			in >> ws;
			in >> aux;
			in.getline(aux, 99);
			b.locuri = new char[strlen(aux) + 1];
			strcpy(b.locuri, aux);
		}
		cout << "Pret: ";
		in >> b.pret;
		return in;
	}

	Bilet operator+(Bilet b)
	{
		Bilet copie = *this;
		copie.pret = copie.pret + b.pret;

		return copie;
	}

	bool operator==(Bilet b) {
		return (this->idBilet == b.idBilet && strcmp(this->numePiesa, b.numePiesa) == 0 && this->data_ora == b.data_ora && this->zona == b.zona &&
			this->nrPersoane == b.nrPersoane && strcmp(this->locuri, b.locuri) && this->pret == b.pret);
	}

	
};

