#include "FileManager.h"
#include <fstream>

using namespace std;

FileManager::FileManager() {

	//lettura dei modelli dell'ordine da models.dat
	ifstream file("dats/models/models.dat", ios::in);
	//if (!file.is_open())
		//

	int idModel;
	while (file >> idModel)
		list_idModels.push_back(idModel);
	file.close();

	//lettura dei componenti del modello da components_info.dat
	file.open("dats/components_info.dat", ios::in);
	/*if (!file.is_open())
		throw OpenFileError{};*/

	int c_id, c_time;
	string c_name;
	Prezzo p;

	//aggiungo i componenti nel vettore 'components'
	while (file >> c_id >> c_name >> c_time >> p.a >> p.b >> p.c) {
		Components comp{c_id, c_name, c_time, p.a, p.b, p.c};
		components.push_back(comp);
	}
	file.close();

	//aggiungo i modelli nel vettore 'models'
	for (int i = 0; i < list_idModels.size(); i++) {
		models.push_back(getModel(list_idModels[i]));
	}
}

/*double FileManager::getAmmount() const {
	double ammount;

	ifstream file("resources/orders.dat");
	if (!file.is_open())
		throw ErrorInFileReading();
	file >> ammount;
	file.close();

	return ammount;
}*/

/*std::vector<ordini> FileManager::getOrders(int month) {
	vector<ordini> order;
	ifstream file("dats/orders.dat", ios::in);
	if (!file.is_open())
		throw OpenFileError();

	/*string unnecessaryLine;
	// line of the ammount in bank, non needed
	std::getline(file, unnecessaryLine);

	// lines of orders that are already readed
	for (int i = 0; i < ordersReaded; i++)
		std::getline(file, unnecessaryLine);*/

	int mm, quantity;
	string idModel;
	bool hasNext = true;
	while (hasNext) {
		file >> month >> idModel >> quantity;
		// Finish if we havent other ordes of this month or if we reached the eof
		if (month > aMonth || file.eof())
			hasNext = false;
		else if (month == aMonth) {
			int indexOfModel;
			bool found = false;
			for (indexOfModel = 0; indexOfModel < modelsAvailable.size() && !found; indexOfModel++) {
				if (modelsAvailable[indexOfModel] == (idModel+".dat"))
					found = true;
			}
			indexOfModel--;
			if (!found)
				throw UnknownModel();
			// cosa stranissima viene invocato sia il costruttore di spostamento che di copia!!
			vector.push_back(Order(ordersReaded,month, Pair<Model>{models[indexOfModel], quantity}));
			ordersReaded++;
		}
	}
	file.close();
	return vector;
}*/

/*Model FileManager::getModel(string idModel) const {
	string modelId, nome;
	double prezzo;
	ifstream file("resources/models/" + idModel, ios::in);
	if (!file.is_open())
		throw ErrorInFileReading();
	//Reading first line = general info about model
	file >> modelId >> nome >> prezzo;

	//Reading remaing line = info about components
	string componentId, componentName;
	int quantity;
	vector<Pair<Component>> components;
	while (file >> componentId >> componentName >> quantity) {
		components.push_back(Pair<Component>(getComponent(componentId), quantity));
	}
	Model m(modelId, nome, prezzo, components);
	file.close();
	return m;
}*/

/*Component FileManager::getComponent(string idComponent) const {
	bool found = false;
	int i;
	for (i = 0; i < allComponents.size() && !found; ++i) {
		if (allComponents[i].id() == idComponent)
			found = true;
	}
	if (!found)
		throw UnknownComponent();
	else {
		return allComponents[((__int64)i - 1)];
	}
}*/
