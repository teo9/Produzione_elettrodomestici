//Azienda
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include "header.h" // include tutti gli header Model.h  Components.h, Orders.h

using namespace std;

Azienda::Azienda() {
	//vector <Ordine> v = vector <Ordine>();
	//vector <componenti> q = vector <componenti>();
	//vector <modelli> w = vector <modelli>();


}

int Azienda::getComp_info(int k) const {
	for (int i = 0; i < comp_info.size(); i++) {
		if (k==comp_info[i].GetId()) {
			return i;
		}
	}
	return -1;
}
void Azienda::carica_ord() {
	ifstream orders("orders.dat");
	if (orders.is_open()) {
		int c;
		orders >> c;
		cassa = c;
		while (orders.good()) {
			int time;
			orders >> time;
			int id;
			orders >> id;
			int quantity;
			orders >> quantity;
			ordini_arrivati.push_back(Ordine(time,id,quantity));
		}
		orders.close();
	}
}
void Azienda::carica_comp() {
	ifstream componenti("components_info.dat");
	if (componenti.is_open()) {
		while (componenti.good()) {
			int id;
			componenti >> id;
			componenti.clear();
			string s;
			componenti >> s;
			int time;
			componenti >> time;
			int prezzi[3];
			for (int i = 0; i < 3; i++) {
				componenti >> prezzi[i];
			}
			Components c(id, s, time, prezzi[0], prezzi[1], prezzi[2]);
			comp_info.push_back(c);
		}
		componenti.close();
	}
}
void Azienda::carica_modelli() 
{
	ifstream modelli("models.dat");
	vector<string> files;
	if (modelli.is_open()) 
	{
		string riga;
		while (getline(modelli,riga)) 
		{
			files.push_back(riga);
		}
		modelli.close();
	}
	for (int i = 0; i < files.size(); i++) 
	{
		ifstream elettrodom(files[i]);
		if (elettrodom.is_open()) 
		{
			int id_elettr;
			elettrodom >> id_elettr;
			string s;
			elettrodom >> s;
			int prezzo;
			elettrodom >> prezzo;
			vector<Components> comp;
			while (elettrodom.good()) 
			{
				int id_comp;
				elettrodom >> id_comp;
				string name_comp;
				elettrodom >> name_comp;
				int quantity;
				elettrodom >> quantity;
				vector<int> tmp= comp_info[getComp_info(id_comp)].GetPrezzi();
				Components c(id_comp, name_comp, comp_info[getComp_info(id_comp)].GetTempo(), quantity, tmp[0], tmp[1], tmp[2]);
				comp.push_back(c);
			}
			m.push_back(Model(id_elettr, s, comp, prezzo));
			elettrodom.close();
		}
	}
}
