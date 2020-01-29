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
			   cout << ordini_da_fare[i].getId() << " " << ordini_da_fare[i].getTime();
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
int Azienda::acquista_componenti(Ordine ord){
	//vector<Components> comp_da_acquistare= ord.getModel().getComponents();
	int prezzo =0;
	//for(int i =0;i < comp_da_acquistare.size();i++)
	//	prezzo += comp_da_acquistare[i].GetPrezzo(comp_da_acquistare.size()); //prezzo totale per l'acquisto
	
	return prezzo;
}//acquista_componenti

int Azienda::num_ordini_possibili(Ordine ord){
	/*
	vector<Components> comp= ord.getModel().getComponents();
	
	int cost_ordine= Components.GetPrezzo(comp.size());
	int cassa_totale= ord.getCassa();
	int nOrd= 0;
	while(cassa_totale > 0){
		 nOrd++;
		 cassa_totale-= costo_ordine;
	}//while
	return nOrd;
	*/
	return 0;
}//num_acquisti_possibili

vector<Components> Azienda::getComponentsModelByOrder(Ordine ord){
	vector<Components> comp; //= ord.getModel().getComponents();
	return comp;
	
}//getComponentsModelByOrder

void Azienda::sposta_ordini(){
	//for(int i=0; i<ordini_da_fare.size(); i++)
	//	if(ordini_da_fare[i].getModel().getBuild())
	//		ordini_evasi[i]= ordini_da_fare[i];
}//sposta_ordini

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

class less_than_key
{
	public:
		inline bool operator() (const Ordine& ob1, const Ordine& ob2)
		{
			return (ob1.getTime() < ob2.getTime() );
		}
};


void Azienda::sort_ord_in_arrivo() {      
	  sort(ordini_da_fare.begin(),ordini_da_fare.end() , less_than_key() );
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
	ifstream orders("./dats/orders.dat");
	if (orders.is_open()) {
		string c;
		orders >> c;
		c= c.substr(1 , c.length() -2);
		cassa = stoi(c);
		while (orders.good()) {
			string h ;
			orders >> h;
			Ordine o (h);
			ordini_da_fare.push_back(o);
		}
		orders.close();
		cout << "Ordini Caricati" << endl;
	}
}
void Azienda::carica_comp() {
	ifstream componenti("./dats/components_info.dat");
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
	ifstream modelli("./dats/models.dat");
	vector<string> files;
	if (modelli.is_open()) //leggo i nomi dei file
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
		ifstream elettrodom("./dats/models/"+ files.at(i));
		if (elettrodom.is_open())   //prima riga id e nome
		{
			string h;
			elettrodom >> h;
			string* arr = divide(h,2);
		
			string nome = arr[1];
			int id = stoi(arr[0]);
			vector<Components> cc;
			
			
			while (! elettrodom.eof())
			{
				int qta=0;
				elettrodom >> h;
				string *j = divide(h,3);
				int _id = stoi(j[0]);
				qta = stoi(j[2]);

				Components c = GetById(_id);
				c.setQuantity(qta);
				cc.push_back(c);
				delete[] j;
			}
			


			mod_catalogo.push_back(Model(id, nome , cc ));
			elettrodom.close();
			delete[] arr;
			
		}
	}
}

Components Azienda::GetById(int i)
{
	for(int h=0;h< comp_catalogo.size();h++)
	{
		if(comp_catalogo[h].GetId() == i)
			return comp_catalogo[h];
	}
	Components r( "[1][error][1][0][0][0]");
	return r;
}

/** get_acquired_components() */
//void Azienda::get_acquired_component()
//{
 //   for(int i=0; i<comp_acquistati.size(); i++)
 //       Model m = comp_acquistati[i];
 //   vector<Components> comp= m.getComponents();
 //   for(int j=0; j<comp.size(); j++)
        //stampa id, nome, .... std::cout <<
//}//get_acquired_components

/** get_warehouse() */
void Azienda::get_warehouse(){
    for(int i=0; i<magazzino.size(); i++)
        Components comp= magazzino[i];
    //stampa id, nome, ... std::cout <<
}//get_warehouse

/** get_delivered_orders() */
void Azienda::get_delivered_orders(){
   // for(int i=0; i<ordini_evasi.size(); i++)
    //    Model m= ordini_evasi[i];
    //stampa id, nome, .... std::cout <<
}//get_delivered_orders


