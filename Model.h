/** Riccardo Rampon  - 1195597 */
#include "Components.h"
#include <vector>
#include <iostream>
using std::ostream;

class Model{
	public:
		Model(int id, std::string name, std::vector<Components> c, double pr);          //costruttore di parametri
		Model(const Model& m);                                        			      					//costruttore di copia
		Model& operator=(const Model& m);                                             					//operatore assegnamento di copia
		Model(Model&& m);                                                             					//costruttore di spostamento
		Model& operator=(Model&& m);                                                  					//operatore assegnamento di spostamento
		~Model();																						//distruttore
		int getId() const;
		std::string getName() const;
		double getPrice() const;
		std::vector<Components> getComponents() const;
		bool getBuild() const;
		void modelBuilt();
	private:
		int id;
		std::string name;
		std::vector<Components> components;
		double price;
		bool isBuild;
}; //Model

ostream& operator<<(ostream& ost, const Model& m);
