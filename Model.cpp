/** Riccardo Rampon  - 1195597 */
#include "Model.h"
using namespace std;

/** costruttore di parametri */
Model::Model(int model_id, string model_name, vector<int> model_components, int pr) {
	id= model_id;
	name= model_name;
	components= model_components;
	price= pr;
}//Model

/** getId() */
int Model::getId()const{ return id; }//getId

/** getPrice() */
int Model::getPrice()const{ return price; }//getPrice

/** getName() */
string Model::getName()const{ return name; }//getName

vector<int> Model::getComponents()const{ return components; }//getComponents

ostream& operator<<(ostream& os, const Model& m){
	os<<"id: ["<<m.getId()<<"]\nname: ["<<m.getName()<<"]\ncomponents: [";
	for(unsigned int i=0; i<m.getComponents().size(); i++)
		os<<(m.getComponents())[i]<<"-";
	os<<"]\nprice: ["<<m.getPrice()<<"]";
	return os;
}//operator<<

int main(){
	vector<int> c;
	c.push_back(10);
	c.push_back(20);
	c.push_back(30);
	c.push_back(40);
	Model m{1, "frigo", c, 80};
	cout<<m;
	return 0;
}
