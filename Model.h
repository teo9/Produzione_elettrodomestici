/** Riccardo Rampon  - 1195597 */
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Model{
	public:
		Model(int id, string name, vector<int> c, int pr);
		int getId() const;
		int getPrice() const;
		string getName() const;
		vector<int> getComponents() const;
	private:
		int id;
		string name;
		vector<int> components;
		int price;
}; //Model

ostream& operator<<(ostream& ost, const Model& m);
