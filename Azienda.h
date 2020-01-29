//Header che contiene tutti i vari header
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include "Order.h"
#include "Components.h"
#include "Model.h"

using namespace std;


class Azienda {
public:
	Azienda();
	//Azienda(int q,vector<Ordine> w,vector<Components> e,vector<Model> r,vector<Ordine> t,vector<Components> y);
	~Azienda();

	void carica_ord();						//funzioni che caricano i vettori con le info prese dai file
	void carica_comp();
	void carica_modelli();

	void get_warehouse();					//da fare
	void get_acquired_component();			//da finire
	void get_delivered_orders();			//da fare

	void stato_corrente();					//funzione che stampa lo stato corrente
	void sort_ord_in_arrivo();//fatta		//funzione che ordina gli ordini in arrivo secondo il time_stamp 
	void sposta();							//funzione che sposta il componente arrivato in magazzino
	void guadagno();						//funzione che calcola il guadagno e lo aggiunge alla cassa
	void tolgo_magazzino();					//funzione che toglie un componente dal magazzino
	int next_mese();//fatta					//ritorna il mese successivo
	void print_mese();//fatta				//stampa a video il mese corrente
	bool cerca_comp();						//funzione che controlla se ci sono i componenti in magazzino per produrre un elettrodomestico
	bool ordina_comp();						//funzione che ordina il componente necessario
	int getComp_info(int k) const;//fatta	//funzione che mi restituisce il numero di riga del vettore di componenti dato l'id
    int acquista_componenti(Ordine ord);
	void sposta_ordini();
	int num_ordini_possibili(Ordine ord);
	vector<Components> getComponentsModelByOrder(Ordine ord);
	///////////////////////////////////////////////////////////////////////////////////
	//mancano da dichiarare ancora un paio di funzioni,tipo quella che decide quando///
	//fermarsi con gli ordini perche la cassa non riesce piu a coprire le spese ecc..//
	///////////////////////////////////////////////////////////////////////////////////


private:
	vector <Ordine> ordini_da_fare;		//vettore di ordini che sono ancora da evadere
	vector <Ordine> ordini_evasi;		//vettore di ordini che sono gia stati completati
	vector <Components> comp_catalogo;	//vettore che contiene tutti i componenti che è possibile ordinare
	vector<Components>comp_in_arrivo;	//vettore che contiene i componenti ordinati ma non ancora arrivati
	vector<Components> magazzino;		//magazzino che tiene i componenti gia arrivati e non ancora usati per la produzione
	vector <Model> mod_catalogo;		//vettore che contiene tutte le info sui possibili elettrodomestici che è possibile fare
	vector<Model> mod_fatti;			//vettore che contiene gli elettrodomestici gia prodotti
	vector<Ordine> costi_per_prodotto;	//vettore che contiene l id dell elettrodomestico e il costo totale
	vector<Components> comp_acquistati;
	Components GetById(int i);
										//(la somma dei prezzi dei vari componenti che servono per produrlo)



	int cassa;
	int mese;
	int tot_ordini;						//questo non so se è necessario 
};

