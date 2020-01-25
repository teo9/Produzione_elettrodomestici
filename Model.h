/** Riccardo Rampon  - 1195597 */
#include "Pair.h"
#include "Componenti.h"
#include <vector>
#include <iostream>
using std::ostream;

class Model{
	public:
		Model(int id, std::string name, std::vector<Pair<Componenti>> c, double pr);  //costruttore di parametri
		Model(const Model& m);                                        			      //costruttore di copia
		Model& operator=(const Model& m);                                             //operatore assegnamento di copia
		Model(Model&& m);                                                             //costruttore di spostamento
		Model& operator=(Model&& m);                                                  //operatore assegnamento di spostamento
		~Model();                                                                     //distruttore
		int getId() const;
		std::string getName() const;
		double getPrice() const;
		std::vector<Pair<Componenti>> getComponents() const;
	private:
		int id;
		std::string name;
		std::vector<Pair<Componenti>> components;
		double price;
}; //Model

ostream& operator<<(ostream& ost, const Model& m);
