//Alberto Cappelletto 1196055

#include<iostream>
#include"Order.h"
#include "Components.h"

using namespace std;						

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
ostream& operator<<(ostream &os,const Ordine &ord) {
	os << "time= [" << ord.getTime() << "]\n" << "id= [" << ord.getId() << "]\n" << "quantity= [" << ord.getQuantity() << "]\n";
	return os;
}
Ordine::Ordine(string nome_)
{
	string* arr = new string[3];
	arr = divide(nome_,3);

	time = stoi(arr[0]);
	id= stoi(arr[1]);
	quantity = stoi(arr[2]);
	delete[] arr;
}

/*
string* divide(string s)                              //divide le stringhe caricate
{
	string a = "";
	int j = 0;
	string* arr = new string[3];
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
}

*/
