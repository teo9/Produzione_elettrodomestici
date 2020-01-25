//Alberto Cappelletto 1196055

#include<iostream>
#include"ordini.h"

using namespace std;	

ordini::ordini() {					//costruttore di default
	time = 0;
	id = 0;
	quantity = 0;
}
ordini::ordini(int t,int k,int n) {			//costruttore di parametri
	time = t;
	id = k;
	quantity = n;
}
/*ordini::ordini(string s) {				//costruttore per il load del file
	//load file
}*/
ordini::ordini(const ordini& ord) {			//costruttore di copia
	time = ord.time;
	id = ord.id;
	quantity = ord.quantity;
}
ordini::ordini(ordini&& ord) {				//costruttore di spostamento
	time = ord.time;
	id = ord.id;
	quantity = ord.quantity;
	ord.time = 0;
	ord.id = 0;
	ord.quantity = 0;
}
ordini::~ordini() {					//distruttore
	time = 0;
	id = 0;
	quantity = 0;
}
//metodi get della classe ordini
int ordini::getId()const { return id; }
int ordini::getTime()const { return time; }
int ordini::getQuantity()const { return quantity; }
//overload operatore = per copia
ordini& ordini::operator=(const ordini& ord) {
	time = ord.time;
	id = ord.id;
	quantity = ord.quantity;
	return *this;
}
//overload operatore = per spostamento
ordini& ordini::operator=(ordini&& ord) {
	time = ord.time;
	id = ord.id;
	quantity = ord.quantity;
	ord.time = 0;
	ord.id = 0;
	ord.quantity = 0;
	return *this;
}
//overload operatore <<
ostream& operator<<(ostream os,const ordini ord) {
	os << "time= [" << ord.getTime() << "]\n" << "id= [" << ord.getId() << "]\n" << "quantity= [" << ord.getQuantity() << "]\n";
}










