/** Rampon Riccardo - 1195597 */
#include "Azienda.h"

/** get_acquired_components() */
void Azienda::get_acquired_component(){
	for(int i=0; i<comp_acquistati.size(); i++)
		Model m= (comp_acquistati)[i].getModel();
		vector<Components> comp= m.getComponents();
		for(int j=0; j<comp.size(); j++)
			//stampa id, nome, .... std::cout <<
}//get_acquired_components

/** get_warehouse() */
void Azienda::get_warehouse(){
	for(int i=0; i<magazzino.size(); i++)
		Components comp= warehouse[i].getComp();
		//stampa id, nome, ... std::cout <<
}//get_warehouse

/** get_delivered_orders() */
void Azienda::get_delivered_orders(){
	for(int i=0; i<ordini_evasi.size(); i++)
		Model m= (ordini_evasi)[i];
		//stampa id, nome, .... std::cout <<	
}//get_delivered_orders
