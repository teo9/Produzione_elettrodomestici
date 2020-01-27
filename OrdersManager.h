#include "Order.h"
#include "Components.h"

class OrdersManager{
	public:
		class DeficitException{};
		OrdersManager(double totBalance);
		void addOrder(Order nOrder); //metodo per aggiungere un ordine

	private:
		vector<Order> delivered_orders; //ordini evasi
		vector<Components> acquired_components; //componenti acquistati ma non arrivati
		vector<Components> warehouse; //magazzino(componenti ordinati e arrivati)
		double total_balance; //cassa a disposizione
		int month; //mese da quale leggere gli ordini
};
