/** Rampon Riccardo - 1195597 */
#include "OrdersManager.h"

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
	for(int i=0; i<warehouse.size(); i++)
		Component comp= warehouse[i].getComp();//prende il riferimento this di Components
    	std::cout << "\nComponent_Id: " << comp[i].getId() << "\nComponent_Name: " << comp[i].getName() << "Component_Quantity: " << comp[i].getName();
}//get_warehouse

/** get_delivered_orders() */
void OrdersManager::get_delivered_orders(){
	for(int i = 0; i<delivered_orders.size(); i++){
        Model m = delivered_orders[i].getModel();
        std::cout << "\nMonth: " << delivered_orders[i].getMonth() << "| Order Id: " << delivered_orders[i].getIdOrder() << "| Model Id: " << m.getId() << "| Model Name: " << m.getName() << "| Quantity: " << delivered_orders[i].getQuantity();
}//get_delivered_orders
