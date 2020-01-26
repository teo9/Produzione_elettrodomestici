#include "Components.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main()
{
    Components c(10 , "pippo" , 12, 4,5,6);

    cout << c.GetPrezzo(45) << "\n";
    cout << c.GetNome() << "\n";

    vector<Components> v = load("./dats/components_info.dat");
    
    for (int i = 0; i <v.size() ; i++)
    {
        cout << "Componenti:  " << v.at(i) << "\n";
    }
    

}