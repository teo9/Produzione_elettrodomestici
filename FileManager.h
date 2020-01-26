dunque i componenti necessari per costruirlo*/

#include "Model.h"
#include "Order.h"
#include <vector>
using std::vector;

class FileManager{
	public:
		FileManager();
		vector<ordini> getOrders(int mm);
	private:
		vector<Model> orderModels;
		vector<Components> modelComponents;



};
