//Header
//Alberto Cappelletto 1196055
#include<iostream>
#include<string>
#include"Model.h"

using namespace std;

class Order{
public:
	Order();							//costruttore di default
	Order(int t, int k, int n);					//costruttore di parametri
	Order(const Order& ord);					//costruttore di copia
	Order(Order&& ord);						//costruttore di spostamento
	//ordini(string s);						costruttore per il load del file ordini.dat
	~Order();							//distruttore

	Order& operator=(const Order& ord);				//operatore = per costruttore di copia
	Order& operator=(Order&& ord);				//operatore = per costruttore di spostamento

	int getTime() const;						//funzioni get
	int getId() const;
	int getQuantity() const;
	Model getModel() const;

private:
	int time;
	int id;
	int quantity;
	Model mod;

};

ostream& operator<<(ostream os,const Order& ord);			//overload operatore <<
