#include "Model.h"
#include "Order.h"
using std::vector;

class FileManager{
	public:
		class ReadFileError{};
		FileManager();
		double getAmmount() const;
		vector<Order> getOrders(int mm);
	private:
		vector<Model> orderModels;
		vector<Components> modelComponents;
		Model getModel(int idModel) const;
		Components getComponent(int idComponent) const;
};
