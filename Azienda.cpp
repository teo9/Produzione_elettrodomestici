//file che contiene tutti i cpp, Azienda,Components,Model,Ordine
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include "Azienda.h"

using namespace std;

/////MANCANO ANCORA DELLE FUNZIONI DA IMPLEMENTARE CHE SONO SCRITTE IN AZIENDA.H/////

Azienda::Azienda() {}				//da fare
Azienda::~Azienda() {}				//da fare
void guadagno() {				//da fare

}

//get_acquired_components() 
void Azienda::get_acquired_component() {
	for (int i = 0; i < ordini_da_fare.size(); i++)
	{
		for (int k=0;k<mod_catalogo.size();k++) 
		{
			if (ordini_da_fare[i].getId()==mod_catalogo[k].getId()) 
			{
			//stampa id, nome, .... std::cout <<
			}
		}
	}
		
}//get_acquired_components
/*
// get_warehouse()											//da sistemare
void Azienda::get_warehouse() {
	for (int i = 0; i < magazzino.size(); i++)
		Components comp = magazzino[i].getComp();
	//stampa id, nome, ... std::cout <<
}//get_warehouse

// get_delivered_orders()									//da sistemare
void Azienda::get_delivered_orders() {
	for (int i = 0; i < ordini_evasi.size(); i++)
		Model m = (ordini_evasi)[i];
	//stampa id, nome, .... std::cout <<	
}//get_delivered_orders*/

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int Azienda::acquista_componenti(Order ord){
	vector<Components> comp_da_acquistare= ord.getModel().getComponents();
	int prezzo= Components.GetPrezzo(comp_da_acquistare.size()); //prezzo totale per l'acquisto
	
	return prezzo;
}//acquista_componenti

int Azienda::num_ordini_possibili(Order ord){
	vector<Components> comp= ord.getModel().getComponents();
	int cost_ordine= Components.GetPrezzo(comp.size());
	int cassa_totale= ord.getCassa();
	int nOrd= 0;
	while(cassa_totale > 0){
		 nOrd++;
		 cassa_totale-= costo_ordine;
	}//while
	return nOrd;
}//num_acquisti_possibili

vector<Components> Azienda::getComponentsModelByOrder(Order ord){
	vector<Components> comp= ord.getModel().getComponents();
	return comp;
}//getComponentsModelByOrder

void Azienda::sposta_ordini(){
	for(int i=0; i<ordini_da_fare.size(); i++)
		if(ordini_da_fare[i].getModel().getBuild())
			ordini_evasi[i]= ordini_da_fare[i];
}//sposta_ordini

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Azienda::sort_ord_in_arrivo() {
	sort(ordini_da_fare.begin(),ordini_da_fare.end());
}
int Azienda::next_mese() {
	mese++;
	return mese;
}
void Azienda::print_mese() {
	cout << mese;
}

int Azienda::getComp_info(int k) const {
	for (int i = 0; i < comp_catalogo.size(); i++) {
		if (k==comp_catalogo[i].GetId()) {
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
			ordini_da_fare.push_back(Ordine(time,id,quantity));
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
			comp_catalogo.push_back(c);
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
				vector<int> tmp= comp_catalogo[getComp_info(id_comp)].GetPrezzi();
				Components c(id_comp, name_comp, comp_catalogo[getComp_info(id_comp)].GetTempo(), quantity, tmp[0], tmp[1], tmp[2]);
				comp.push_back(c);
			}
			mod_catalogo.push_back(Model(id_elettr, s, comp, prezzo));
			elettrodom.close();
		}
	}
}

