#include <vector>
#include "Model.h"

using namespace std;

class FileManager{
	public:
		class OpenFileError{};
		FileManager();
		Model getModel(string model_fileName);

	private:
		vector<string> models_InFile;
};
