#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Bilet {
private:
	const int id_bilet;
	char rand;
	int loc;
	float pret;

public:
	Bilet() : id_bilet(0){
		rand = NULL;
		loc = 0;
		pret = 0.0;
	}

};

class PiesaTeatru {
private:
	char* nume_piesa;
	char data;
	char ora;
	int nr_actori;
	string* actori;

public:
	PiesaTeatru() {
		nume_piesa = nullptr;
		data = NULL;
		ora = NULL;
		actori = nullptr;
	}

	PiesaTeatru(const char* nume_piesa, char data, char ora, int nr_actori, const string* actori) {
		this->nume_piesa = new char[strlen(nume_piesa) + 1];
		strcpy(this->nume_piesa, nume_piesa);
		this->data = data;
		this->ora = ora;
		this->nr_actori = nr_actori;
		for (int i = 0;i < this->nr_actori;i++) {
			this->actori[i] = actori[i];
		}
	}

	char* getNumePiesa() {
		return this->nume_piesa;
	}

	char getData() {
		return this->data;
	}

	char getOra() {
		return this->ora;
	}

	int getNrActori() {
		return this->nr_actori;
	}

	string* getActori() {
		return this->actori;
	}

};

class Sala {
private:
	static string denumire;
	int capacitate;

};