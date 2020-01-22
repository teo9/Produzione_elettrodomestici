/** Riccardo Rampon  - 1195597 */
#include <vector>
#include <iostream>
using std::ostream;

class Model{
	public:
		Model(int id, std::string name, std::vector<int> c, int pr);  //costruttore di parametri
		Model(const Model& m);                                        //costruttore di copia
		Model& operator=(const Model& m);                             //operatore assegnamento di copia
		Model(Model&& m);                                             //costruttore di spostamento
		Model& operator=(Model&& m);                                  //operatore assegnamento di spostamento
		~Model();                                                     //distruttore
		int getId() const;
		std::string getName() const;
		int getPrice() const;
		std::vector<int> getComponents() const;
	private:
		int id;
		std::string name;
		std::vector<int> components;
		int price;
}; //Model

ostream& operator<<(ostream& ost, const Model& m);
