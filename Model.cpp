/** Riccardo Rampon  - 1195597 */     /** commenti da finire */
#include "Model.h"
using namespace std;

/** costruttore di parametri
 * @param
 * @param
 * @param
 * @param
 */
Model::Model(int model_id, string model_name, vector<int> model_components, int model_pr) {
	id= model_id;
	name= model_name;
	components= model_components;
	price= model_pr;
}//Model

/** costruttore di copia
 * @param
 */
Model::Model(const Model& m) {
	id= m.id;
	name= m.name;
	price= m.price;
	components= m.components;
}//Model

/** assegnamento di copia - overloading dell'operatore =
 * @param m const-reference all'oggetto model da copiare
 * @return this self-reference
 */
Model& Model::operator=(const Model& m){
	components.clear();
	id= m.id;
	name= m.name;
	price= m.price;
	components= m.components;
	return *this;
}//operator=

/** costruttore di spostamento
 * @param i rvalue-reference di tipo Image
 */
Model::Model(Model&& m){
	id= m.id;
	name= m.name;
	price= m.price;
	components= m.components;
	m.id= 0;
	m.name= "";
	m.price= 0;
	m.components.clear();
}//Model

/** assegnamento di spostamento - overloading dell'operatore =
 * @param i rvalue-reference
 * @return self-reference
 */
Model& Model::operator=(Model&& m) {
	components.clear();
	id= m.id;
	name= m.name;
	price= m.price;
	components= m.components;
	m.id= 0;
	m.name= "";
	m.price= 0;
	m.components.clear();
	return *this;
}//operator=

/** distruttore */
Model::~Model(){
	id= 0;
	name= "";
	price= 0;
	components.clear();
}//~Model

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
