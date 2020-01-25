//Header
//Alberto Cappelletto 1196055
#include<iostream>
#include<string>
//#include<vector>

using namespace std;

class ordini {
public:

	ordini();
	ordini(int n, int t, int k, int f);
	ordini(string s);							//costruttore per il load del file ordini.dat

	int getTime() { return time; }				//funzioni get
	int getId() { return id; }
	int getQuantity() { return quantity; }
	int getCassa() { return cassa; }			

private:
	int cassa;
	int time;
	int id;
	int quantity;
	//vector<int> v;							

};