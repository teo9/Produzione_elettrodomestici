/** Riccardo Rampon  - 1195597 */
#include "Model.h"

/** costruttore di parametri
 * @param model_id identificativo del modello
 * @param model_name nome del modello
 * @param model_components vettore di componenti associati al modello $model_id
 * @param model_pr prezzo del modello
 */
Model::Model(int model_id, std::string model_name, std::vector<Pair<Components>> model_components, double model_pr) {
	id= model_id;
	name= model_name;
	components= model_components;
	price= model_pr;
}//Model

/** costruttore di copia
 * @param const-reference all'oggetto Model da copiare
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
 * @param m rvalue-reference di tipo Model
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
 * @param m rvalue-reference
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
	m.components= vector<Pair<Components>>();
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
int Model::getId()const{
	return id;
}//getId

/** getPrice() */
double Model::getPrice()const{
	return price;
}//getPrice

/** getName() */
std::string Model::getName()const{
	return name;
}//getName

/** getComponents() */
std::vector<Pair<Components>> Model::getComponents()const{
	return components;
}//getComponents

/** getIsBuilt() */
bool Model::getBuild() const{
	return isBuild;
}//getIsBuilt

/** setIsBuilt() */
bool Model::modelBuilt(){
	isBuild= true;
}//getIsBuilt

ostream& operator<<(ostream& os, const Model& m){
	os<<"id: ["<<m.getId()<<"]\nname: ["<<m.getName()<<"]\ncomponents: [";
	//errore - da sistemare
	os<<"]\nprice: ["<<m.getPrice()<<"]";
	return os;
}//operator<<
