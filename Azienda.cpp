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


Components::Components() 
{
	id = 0;
	nome ="";
	tempo = 0;
	p[0] = 0;
	p[1] = 0;
	p[2] = 0;
	quantità = 0;
}

Components::Components(int q,string w,int e,int r,int t,int y,int u) {
	id = q;
	nome = w;
	tempo = e;
	quantità = r;
	p[0] = t;
	p[1] = y;
	p[2] = u;
}

Components::Components(int id_, string nome_, int tempo_, int a, int b, int c)
{
	id = id_;
	nome = nome_;
	tempo = tempo_;
	p[0] = a;
	p[1] = b;
	p[2] = c;
	quantità = 0;
}

/*Components::Components(string nome_)		///non so se serve
{
	string* arr = new string[6];
	arr = divide(nome_);

	id = stoi(arr[0]);
	nome = arr[1];
	tempo = stoi(arr[2]);
	p.a = stoi(arr[3]);
	p.b = stoi(arr[4]);
	p.c = stoi(arr[5]);

	delete[] arr;
}*/

Components::Components(const Components& c)                                                    //costruttore di copia
{
	id = c.id;
	nome = c.nome;
	tempo = c.tempo;
	quantità = c.quantità;
	p[0] = c.p[0];
	p[1] = c.p[1];
	p[2] = c.p[2];
}

Components& Components::operator =(const Components& c)                                         //assegnamento di copia
{
	id = c.id;
	nome = c.nome;
	tempo = c.tempo;
	quantità = c.quantità;
	p[0] = c.p[0];
	p[1] = c.p[1];
	p[2] = c.p[2];
	return *this;
}

Components::Components(Components&& c)                                                          //costruttore di spostamento
{
	id = c.id;
	nome = c.nome;
	tempo = c.tempo;
	quantità = c.quantità;
	p[0] = c.p[0];
	p[1] = c.p[1];
	p[2] = c.p[2];
	c.id = 0;
	c.nome = "";
	c.tempo = 0;
	c.quantità = 0;
	c.p[0] = 0;
	c.p[1] = 0;
	c.p[2] = 0;
}

Components& Components::operator =(Components&& c)                                              //assegnamento di spostamento
{
	id = c.id;
	nome = c.nome;
	tempo = c.tempo;
	quantità = c.quantità;
	p[0] = c.p[0];
	p[1] = c.p[1];
	p[2] = c.p[2];
	c.id = 0;
	c.nome = "";
	c.tempo = 0;
	c.quantità = 0;
	c.p[0] = 0;
	c.p[1] = 0;
	c.p[2] = 0;
	return *this;
}

int Components::GetId() const
{
	return id;
}

string Components::GetNome() const
{
	return nome;
}

int Components::GetTempo() const
{
	return tempo;
}
vector<int> Components::GetPrezzi() const 
{
	return p;
}

int Components::GetPrezzo(int n) const
{
	if (n > 0 && n <= 10)
		return p[0];
	else if (n > 10 && n <= 50)
		return p[1];
	else if (n > 50)
		return p[2];
	else
		return 0;
}

ostream& operator<< (ostream& os, Components& c)
{
	return os << c.GetId() << " " << c.GetNome() << " " << c.GetTempo() << " " << c.GetPrezzo(1) << " " << c.GetPrezzo(11) << " " << c.GetPrezzo(51);
}


/*vector<Components> load(string NomeFile)                    //carica l'intero file non so se serve anche questo
{
	string s = "";
	vector<Components> componenti{};
	//ifstream comp(NomeFile);
	fstream iff;
	iff.open(NomeFile);
	//comp.open("r");
	if (iff.is_open())
		while (!iff.eof())
		{
			//getline(comp, s);
			iff >> s;
			Components b(s);
			componenti.push_back(b);
		}
	else
		cout << "file non leggibile";
	iff.close();
	return componenti;

}*/

/*string* divide(string s)                              //divide le stringhe caricate (non so se serve)
{
	string a = "";
	int j = 0;
	string* arr = new string[6];
	for (int i = 0; i < s.length(); i++)
	{
		if (s.at(i) == '[')
			a = "";
		else if (s.at(i) == ']')
		{
			arr[j] = a;
			j++;
		}
		else
			a += s.at(i);
	}
	return arr;
}*/


/** costruttore di parametri
 * @param model_id identificativo del modello
 * @param model_name nome del modello
 * @param model_components vettore di componenti associati al modello $model_id
 * @param model_pr prezzo del modello
 * @param model_built indicazione se il modello e` stato costruito
 */
Model::Model(int model_id,string model_name,vector<Components> model_components, double model_pr) {
	id = model_id;
	name = model_name;
	components = model_components;
	price = model_pr;
	isBuild = false;
}//Model

/** costruttore di copia
 * @param const-reference all'oggetto Model da copiare
 */
Model::Model(const Model& m) {
	id = m.id;
	name = m.name;
	components = m.components;
	price = m.price;
	isBuild = m.isBuild;
}//Model

/** assegnamento di copia - overloading dell'operatore =
 * @param m const-reference all'oggetto model da copiare
 * @return this self-reference
 */
Model& Model::operator=(const Model& m) {
	components.clear();
	id = m.id;
	name = m.name;
	price = m.price;
	components = m.components;
	isBuild = m.isBuild;
	return *this;
}//operator=

/** costruttore di spostamento
 * @param m rvalue-reference di tipo Model
 */
Model::Model(Model&& m) {
	id = m.id;
	name = m.name;
	price = m.price;
	isBuild = m.isBuild;
	components = m.components;
	m.id = 0;
	m.name = "";
	m.price = 0;
	m.components.clear();
	m.isBuild = false;
}//Model

/** assegnamento di spostamento - overloading dell'operatore =
 * @param m rvalue-reference
 * @return self-reference
 */
Model& Model::operator=(Model&& m) {
	components.clear();
	id = m.id;
	name = m.name;
	price = m.price;
	isBuild = m.isBuild;
	components = m.components;
	m.id = 0;
	m.name = "";
	m.price = 0;
	m.isBuild = false;
	m.components.clear();
	return *this;
}//operator=

/** distruttore */
Model::~Model() {
	id = 0;
	name = "";
	price = 0;
	components.clear();
	isBuild = false;
}//~Model

/** getId() */
int Model::getId() const {
	return id;
}//getId

/** getPrice() */
double Model::getPrice() const {
	return price;
}//getPrice

/** getName() */
string Model::getName() const {
	return name;
}//getName

/** getComponents() */
vector<Components> Model::getComponents() const {
	return components;
}//getComponents

/** getIsBuilt() */
bool Model::getBuild() const {
	return isBuild;
}//getIsBuilt

/** setIsBuilt() */
void Model::modelBuilt() {
	isBuild = true;
}//getIsBuilt
						
Ordine::Ordine() {							//costruttore di default
	time = 0;
	id = 0;
	quantity = 0;
}

Ordine::Ordine(int t,int k,int n) {
	time = t;
	id = k;
	quantity = n;
}

Ordine::Ordine(const Ordine& ord) {			//costruttore di copia
	time = ord.time;
	id = ord.id;
	quantity = ord.quantity;
}
Ordine::Ordine(Ordine&& ord) {				//costruttore di spostamento
	time = ord.time;
	id = ord.id;
	quantity = ord.quantity;
	ord.time = 0;
	ord.id = 0;
	ord.quantity = 0;
}
Ordine::~Ordine() {							//distruttore
	time = 0;
	id = 0;
	quantity = 0;
}
//metodi get della classe ordini
int Ordine::getId()const { return id; }
int Ordine::getTime()const { return time; }
int Ordine::getQuantity()const { return quantity; }

//overload operatore = per copia
Ordine& Ordine::operator=(const Ordine& ord) {
	time = ord.time;
	id = ord.id;
	quantity = ord.quantity;
	return *this;
}
//overload operatore = per spostamento
Ordine& Ordine::operator=(Ordine&& ord) {
	time = ord.time;
	id = ord.id;
	quantity = ord.quantity;
	ord.time = 0;
	ord.id = 0;
	ord.quantity = 0;
	return *this;
}
bool Ordine::operator<(const Ordine& o) {
	return (time < o.time);
}
//overload operatore <<
ostream& operator<<(ostream os,const Ordine ord) {
	os << "time= [" << ord.getTime() << "]\n" << "id= [" << ord.getId() << "]\n" << "quantity= [" << ord.getQuantity() << "]\n";
}

