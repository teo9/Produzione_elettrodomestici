/*Anna Camillo - 1188526*/

#include <iostream>
#include <string>

using namespace std;

struct Prezzi
{
    int a,b,c;
};


class Componenti
{
    int id;
    string nome;
    int tempo;
    Prezzi p;

    public:
        Componenti(int id, string nome, int tempo, Prezzi p);
        Componenti(string nome);
        Componenti(int id, string nome, int tempo, int a, int b, int c);
        int GetId();
        string GetNome();
        int GetTempo();
        //richiede numero di componenti voluto e prende dalla struct->scrivo nel metodo if(n comp)
        int GetPrezzo(int n);
};