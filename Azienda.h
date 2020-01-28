//Header
#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;


class Azienda {
public:
	Azienda();
	//Azienda(int q,vector<Ordine> w,vector<Components> e,vector<Model> r,vector<Ordine> t,vector<Components> y);
	~Azienda();

	void carica_ord();					//funzioni che caricano i vettori prendendo info dai file
	void carica_comp();
	void carica_modelli();
	
	void stato_corrente();					//funzione che stampa lo stato corrente
	void sort_ord_in_arrivo();				//funzione che ordina gli ordini in arrivo secondo il time_stamp
	void sposta();						//funzione che sposta il componente arrivato in magazzino
	void guadagno();					//funzione che calcola il guadagno e lo aggiunge alla cassa
	void tolgo_magazzino();					//funzione che toglie un componente dal magazzino
	int next_mese();					//ritorna il mese successivo
	void print_mese();					//stampa a video il mese corrente
	bool cerca_comp();					//funzione che controlla se ci sono i componenti in magazzino per produrre un elettrodomestico
	bool ordina_comp();					//funzione che ordina il componente necessario
	int getComp_info(int k) const;				//funzione che mi restituisce il numero di riga del vettore di componenti dato l id 



private:
	vector <Ordine> ordini_arrivati;
	vector <Ordine> ordini_in_arrivo;
	vector <Components> comp_info;
	vector<Components>comp_arrivati;
	vector <Model> mod_info;
	Vector <Model> mod_catalogo;
	int cassa;
	int mese;
	int tot_ordini;
};
