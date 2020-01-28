/*Anna Camillo - 1188526*/
#ifndef COMPONENTS_H
#define COMPONENTS_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Prezzi
{
    int a,b,c;
};


class Components
{
    int id;
    string nome;
    int tempo;
    Prezzi p;

    public:
        Components(int id, string nome, int tempo, Prezzi p);
        Components(string nome);
        Components(int id, string nome, int tempo, int a, int b, int c);
        int GetId() const;
        string GetNome() const;
        int GetTempo() const;
        int GetPrezzo(int n) const;
        Components(const Components& c);                                            //costruttore di copia
        Components& operator =(const Components& c);                                //assegnamento di copia
        Components(Components&& c);                                                 //costruttore di spostamento
        Components& operator =(Components&& c);                                     //assegnamento di spostamento


    
};
    ostream& operator<< ( ostream& os , Components& c );                            //overloading operator <<
    vector<Components> load(string NomeFile);                                       //metodo per caricare leggere file .dat
    string* divide(string s);                                                       //metodo per dividere la stringa letta e caricarla in un array

    #endif