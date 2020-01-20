#include "Componenti.h"

#include <iostream>
using namespace std;


int main()
{
    Componenti c(10 , "pippo" , 12, 4,5,6);

    cout << c.GetPrezzo(45) << "\n";
    cout << c.GetNome() << "\n";

}