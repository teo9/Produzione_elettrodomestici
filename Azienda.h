//Header
#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;


class Azienda {
public:
	Azienda();
	Azienda(int q,vector<Ordine> w,vector<Components> e,vector<Model> r,vector<Ordine> t,vector<Components> y);
	~Azienda();

	void carica_ord();
	void carica_comp();
	void carica_modelli();

	int print();
	int getComp_info(int k) const;



private:
	vector <Ordine> ordini_arrivati;
	vector <Ordine> ordini_in_arrivo;
	vector <Components> comp_info;
	vector<Components>comp_arrivati;
	vector <Model> m;
	int cassa;
};
