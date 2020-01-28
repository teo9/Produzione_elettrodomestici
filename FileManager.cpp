#include "FileManager.h"
#include <fstream>

FileManager::FileManager(){
	//lettura del modelli dal file models.dat
	string name_models= "";
	ifstream file_models("dats/models.dat", ios::in);
	if(!file_models.is_open())
		throw FileManager::OpenFileError{};
	while(file_models>>name_models)
		models_InFile.push_back(name_models);
	file_models.close();

	//dai vari file modelli letti, inserisco i

}//FileManager

/** ritorno il modello completo dei componenti partendo dai file letti */
Model FileManager::getModel(string model_fileName){
	ifstream file_models("dats/models/" + model_fileName, ios::in);
	if(!file_models.is_open())
		throw FileManager::OpenFileError{};

	//variabili per la lettura delle informazioni relative al modello $model_fileName.dat
	int model_id;
	double model_pr;
	string model_name;

	//leggo la prima linea del file per l'id, il nome e il prezzo del modello
	file_models >> model_id >> model_name >> model_pr;

	//variabili per la lettura delle informazioni relative ai componenti del modello
	/*int comp_id, comp_quantity;
	string comp_name;


	//leggo le restanti linee per l'id, il nome e la quantità dei componenti
	while(file_models >> comp_id >> comp_name >> comp_quantity)
		//model_components.push_back(Pair<Components>(getComponent(comp_id)), comp_quantity);
	file_models.close();*/
	vector<Components> model_components;
	Model m(model_id, model_name, model_components, model_pr);
	return m;
}//getModel




int main(void){
	FileManager fm();


	return 0;
}//main



void FileManager::carica_comp() {
	ifstream componenti("components_info.dat");
	if (componenti.is_open()) {
		while (componenti.good()) {
			int id;
			componenti >> id;
			componenti.clear();
			string s;
			componenti >> s;
			int time;
			componenti >> time;
			double prezzi[3];
			for (int i = 0; i < 3; i++) {
				componenti >> prezzi[i];
			}
			components c(id, s, time, prezzi[0], prezzi[1], prezzi[2]);
			comp_arrivati.push_back(c);
		}
		componenti.close();
	}
}
void FileManager::carica_ord() {
	ifstream orders("orders.dat");
	if (orders.is_open()) {
		int c;
		orders >> c;
		cassa = c;
		while (orders.good()) {
			int time;
			orders >> time;
			int id;
			orders >> id;
			int quantity;
			orders >> quantity;
			arrivi.push_back(ordini(time,id,quantity));
		}
		orders.close();
	}
}
<<<<<<< HEAD
=======

>>>>>>> c4702f8af52351beacd2a05c51cc1b5362396011
