#include "Componenti.h"

using namespace std;

Componenti::Componenti (int id_, string nome_, int tempo_, Prezzi p_)
    :id{id_}, nome{nome_}, tempo{tempo_}, p{p_}{}

Componenti::Componenti (int id_, string nome_, int tempo_, int a, int b, int c)
    :id{id_}, nome{nome_}, tempo{tempo_}
{
    p.a = a;
    p.b = b;
    p.c = c;
}

Componenti::Componenti(string riga)
{
    //load
}

int Componenti::GetId()
{
    return id;
}

string Componenti::GetNome()
{
    return nome;
}

int Componenti::GetTempo()
{
    return tempo;
}

int Componenti::GetPrezzo(int n)
{
    if(n>0 && n<=10)
        return p.a;
    else if(n>10 && n<=50)
        return p.b;
    else if(n>50)
        return p.c;
    else 
        return 0;
}


