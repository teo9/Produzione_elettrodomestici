#include "Order.h"
#include "Components.h"

class OrdersManager{
	public:
		class DeficitException{};
		OrdersManager(double totBalance);
		void addOrder(Order nOrder); 				//aggiunge un ordine
		void get_acquired_components();				//componenti acquistati
		void get_warehouse();						//magazzino
		void get_delivered_orders();				//ordini evasi


	private:
		vector<Order> delivered_orders; //ordini evasi
		vector<Order> acquired_components; //componenti acquistati ma non arrivati per ogni ordine
		vector<Components> warehouse; //magazzino(componenti ordinati e arrivati)
		double total_balance; //cassa a disposizione
		int current_month; //mese da quale leggere gli ordini
};
