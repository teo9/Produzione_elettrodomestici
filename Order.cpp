//Alberto Cappelletto 1196055

#include<iostream>
#include"Order.h"
#include"Model.h"

using namespace std;

Order::Order() {					//costruttore di default
	time = 0;
	id = 0;
	quantity = 0;
}
Order::Order(int t,int k,int n) {			//costruttore di parametri
	time = t;
	id = k;
	quantity = n;
}
/*Order::Order(string s) {				//costruttore per il load del file
	//load file
}*/
Order::Order(const Order& ord) {			//costruttore di copia
	time = ord.time;
	id = ord.id;
	quantity = ord.quantity;
}
Order::Order(Order&& ord) {				//costruttore di spostamento
	time = ord.time;
	id = ord.id;
	quantity = ord.quantity;
	ord.time = 0;
	ord.id = 0;
	ord.quantity = 0;
}
Order::~Order() {					//distruttore
	time = 0;
	id = 0;
	quantity = 0;
}
//metodi get della classe Order
int Order::getId()const { return id; }
int Order::getTime()const { return time; }
int Order::getQuantity()const { return quantity; }
Model Order::getModel()const {return mod;}

//overload operatore = per copia
Order& Order::operator=(const Order& ord) {
	time = ord.time;
	id = ord.id;
	quantity = ord.quantity;
	return *this;
}
//overload operatore = per spostamento
Order& Order::operator=(Order&& ord) {
	time = ord.time;
	id = ord.id;
	quantity = ord.quantity;
	ord.time = 0;
	ord.id = 0;
	ord.quantity = 0;
	return *this;
}
//overload operatore <<
ostream& operator<<(ostream os,const Order ord) {
	os << "time= [" << ord.getTime() << "]\n" << "id= [" << ord.getId() << "]\n" << "quantity= [" << ord.getQuantity() << "]\n";
}
