/** Riccardo Rampon  - 1195597 */
#ifndef MODEL_H
#define MODEL_H

#include "Components.h"
#include <vector>
#include <iostream>
using std::ostream;

class Model{
	public:
		Model(int id, std::string name, std::vector<Components> c);          				//costruttore di parametri
		Model(const Model& m);
		Model(string nomeFile);                                        			      					//costruttore di copia
		Model& operator=(const Model& m);                                             					//operatore assegnamento di copia
		Model(Model&& m);                                                             					//costruttore di spostamento
		Model& operator=(Model&& m);                                                					//operatore assegnamento di spostamento
		~Model();																																								//distruttore
		int getId() const;
		std::string getName() const;
		int getQuantity() const;
		std::vector<Components> getComponents() const;
		bool getBuild() const;
		void setModelBuilt();
	private:
		int id;
		std::string name;
		std::vector<Components> components;
		int qta;
		bool isBuild;
}; //Model

//string* divide(string s);
ostream& operator<<(ostream os,const Model& m);

#endif // MODEL_H
