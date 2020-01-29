#include <iostream>
#include "Azienda.h"

using namespace std;

int main()
{
    Azienda a;
    a.carica_comp();
    cout << "Caricato Componenti" << endl;
    a.carica_modelli();
     cout << "Caricato Modelli" << endl;
    a.carica_ord();
     cout << "Caricato Ordini" << endl;

    
    return 0;
}
