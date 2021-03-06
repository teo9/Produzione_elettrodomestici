/** Riccardo Rampon  - 1195597 */
#include "Model.h"

/** costruttore di parametri
 * @param model_id identificativo del modello
 * @param model_name nome del modello
 * @param model_components vettore di componenti associati al modello $model_id
 * @param model_pr prezzo del modello
 * @param model_built indicazione se il modello e` stato costruito
 */
Model::Model(int model_id, std::string model_name, std::vector<Components> model_components) {
	id= model_id;
	name= model_name;
	components= model_components;
	
	isBuild= false;
}//Model

/**
 * @param nome_ nome file del modello
*/
Model::Model(string nome_){
	cout << nome_ << endl;
	string* arr = new string[2];
	arr = divide(nome_,2);
	id= stoi(arr[0]);
	name = arr[1];
	delete[] arr;
}//Model

/** costruttore di copia
 * @param const-reference all'oggetto Model da copiare
 */
Model::Model(const Model& m) {
	id= m.id;
	name= m.name;
	components= m.components;
	qta= m.qta;
	isBuild= m.isBuild;
}//Model

/** assegnamento di copia - overloading dell'operatore =
 * @param m const-reference all'oggetto model da copiare
 * @return this self-reference
 */
Model& Model::operator=(const Model& m){
	components.clear();
	id= m.id;
	name= m.name;
	qta= m.qta;
	components= m.components;
	isBuild= m.isBuild;
	return *this;
}//operator=

/** costruttore di spostamento
 * @param m rvalue-reference di tipo Model
 */
Model::Model(Model&& m){
	id= m.id;
	name= m.name;
	qta= m.qta;
	isBuild= m.isBuild;
	components= m.components;
	m.id= 0;
	m.name= "";
	m.qta= 0;
	m.components.clear();
	m.isBuild= false;
}//Model

/** assegnamento di spostamento - overloading dell'operatore =
 * @param m rvalue-reference
 * @return self-reference
 */
Model& Model::operator=(Model&& m) {
	components.clear();
	id= m.id;
	name= m.name;
	qta= m.qta;
	isBuild= m.isBuild;
	components= m.components;
	m.id= 0;
	m.name= "";
	m.qta= 0;
	m.isBuild= false;
	m.components.clear();
	return *this;
}//operator=

/** distruttore */
Model::~Model(){
	id= 0;
	name= "";
	qta= 0;
	components.clear();
	isBuild= false;
}//~Model

/** getId() */
int Model::getId() const{
	return id;
}//getId

/** getPrice() */
int Model::getQuantity() const{
	return qta;
}//getPrice

/** getName() */
std::string Model::getName() const{
	return name;
}//getName

/** getComponents() */
std::vector<Components> Model::getComponents() const{
	return components;
}//getComponents

/** getIsBuilt() */
bool Model::getBuild() const{
	return isBuild;
}//getIsBuilt

/** setModelBuilt() */
void Model::setModelBuilt(){
	isBuild= true;
}//getIsBuilt

/** operator<<
 * @param os oggetto ti tipo ostream
 * @param m oggetto di tipo Model
 * @return stampa su video dello stato dell'oggetto
*/
ostream& operator<<(ostream& os, const Model& m) {
	os<<"Id: "<<m.getId()<<"Name: "<<m.getName()<<"Qta: "<<m.getQuantity();
	for(int i=0; i<m.getComponents().size(); i++)
		os<<"Component"<<i<<": "<<m.getComponents().at(i);
	return os;
}//operator<<

/** divide()
 * @param s linea del file da cui leggere i dati
*/

/*
string* divide(string s){
	string a = "";
	int j = 0;
	string* arr = new string[3];
	for (int i = 0; i < s.length(); i++){
		if (s.at(i) == '[')
			a = "";
		else if (s.at(i) == ']'){
			arr[j] = a;
			j++;
		}//else-if
		else
			a += s.at(i);
	}//for
	return arr;
}//divide
*/