//Header
//Alberto Cappelletto 1196055
#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;

class Ordine {
public:

	Ordine();										//costruttore di default
	Ordine(int t, int k, int n);					//costruttore di parametri
	Ordine(const Ordine& ord);						//costruttore di copia
	Ordine(Ordine&& ord);							//costruttore di spostamento
	~Ordine();										//distruttore
	Ordine(string s);

	Ordine& operator=(const Ordine& ord);			//overloading operatore = per costruttore di copia
	Ordine& operator=(Ordine&& ord);				//overloading operatore = per costruttore di spostamento
	bool operator<(const Ordine& o);				//overloading operatore <

	int getTime() const;									//funzioni get
	int getId() const;
	int getQuantity() const;

private:
	int time;
	int id;
	int quantity;							

};
string* divide(string s);
ostream& operator<<(ostream os,const Ordine& ord);


