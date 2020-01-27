/** Rampon Riccardo - 1195597 */
#include "OrdersManager.h"

	/*vector<Order> delivered_orders; //ordini evasi
		vector<Components> warehouse; //magazzino(componenti ordinati e arrivati)*/

/** get_acquired_components() */
void OrdersManager::get_acquired_components(){
	for(int i=0; i<acquired_components.size(); i++)
		Model m= (acquired_components)[i].getModel();
		vector<Components> comp= m.getComponents();
		for(int j=0; j<comp.size(); j++)
			std::cout << "\nComponent_Id: " << comp[j].getId() << "\nComponent_Name: " << comp[j].getName() << "Component_Quantity: " << comp[j].getName();
}//get_acquired_components

/** get_warehouse() */
void OrdersManager::get_warehouse(){

}//get_warehouse

/** get_delivered_orders() */
void OrdersManager::get_delivered_orders(){

}//get_delivered_orders
