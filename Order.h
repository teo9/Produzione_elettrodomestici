//Header
//Alberto Cappelletto 1196055
#include<iostream>
#include<string>

using namespace std;

class ordini {
public:
	ordini();							//costruttore di default
	ordini(int t, int k, int n);					//costruttore di parametri
	ordini(const ordini& ord);					//costruttore di copia
	ordini(ordini&& ord);						//costruttore di spostamento
	//ordini(string s);						costruttore per il load del file ordini.dat
	~ordini();							//distruttore

	ordini& operator=(const ordini& ord);				//operatore = per costruttore di copia
	ordini& operator=(ordini&& ord);				//operatore = per costruttore di spostamento

	int getTime() const;						//funzioni get
	int getId() const;
	int getQuantity() const;		

private:
	int time;
	int id;
	int quantity;							

};

ostream& operator<<(ostream os,const ordini& ord);			//overload operatore <<
