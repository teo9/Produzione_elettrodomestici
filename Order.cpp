//Alberto Cappelletto 1196055

#include<iostream>
#include"Header.h"

using namespace std;						// le funzionni get sono definite nell' header

ordini::ordini() {							//costruttore di default
	cassa = 0;
	time = 0;
	id = 0;
	quantity = 0;
}

ordini::ordini(int n,int t,int k,int f) {
	cassa = n;
	time = t;
	id = k;
	quantity = f;
}

ordini::ordini(string s) {
	//load file
}