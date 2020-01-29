/*Anna Camillo - 1188526 */
#include "Components.h"

using namespace std;

Components::Components (int id_, string nome_, int tempo_, Prezzi p_)
    :id{id_}, nome{nome_}, tempo{tempo_}, p{p_}{}

Components::Components (int id_, string nome_, int tempo_, int a, int b, int c)
    :id{id_}, nome{nome_}, tempo{tempo_}
{
    p.a = a;
    p.b = b;
    p.c = c;
}

Components::Components(string nome_)
    {
			string* arr = new string[6];
			arr=divide(nome_, 6);

            id = stoi(arr[0]);
            nome = arr[1];
            tempo = stoi(arr[2]);
            p.a = stoi(arr[3]);
            p.b = stoi(arr[4]);
            p.c = stoi(arr[5]);

			delete[] arr;
    }

Components::Components(const Components& c)                                                    //costruttore di copia
{
    id = c.id;
    nome = c.nome;
    tempo = c.tempo;
    p.a = c.p.a;
    p.b = c.p.b;
    p.c = c.p.c;
}

Components& Components::operator =(const Components& c)                                         //assegnamento di copia
{
    id = c.id;
    nome = c.nome;
    tempo = c.tempo;
    p.a = c.p.a;
    p.b = c.p.b;
    p.c = c.p.c;
    return *this;
}

Components::Components(Components&& c)                                                          //costruttore di spostamento
{
    id = c.id;
    nome = c.nome;
    tempo = c.tempo;
    p.a = c.p.a;
    p.b = c.p.b;
    p.c = c.p.c;
    c.id = 0;
    c.nome = "";
    c.tempo = 0;
    c.p.a = 0;
    c.p.b = 0;
    c.p.c = 0;
}

Components& Components::operator =(Components&& c)                                              //assegnamento di spostamento
{
    id = c.id;
    nome = c.nome;
    tempo = c.tempo;
    p.a = c.p.a;
    p.b = c.p.b;
    p.c = c.p.c;
    c.id = 0;
    c.nome = "";
    c.tempo = 0;
    c.p.a = 0;
    c.p.b = 0;
    c.p.c = 0;
    return *this;
}

int Components::GetId() const
{
    return id;
}

string Components::GetNome() const
{
    return nome;
}

int Components::GetTempo() const
{
    return tempo;
}

int Components::GetPrezzo(int n) const
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

 ostream& operator<< ( ostream& os , Components& c )
 {
     return os << c.GetId() << " " << c.GetNome() << " " << c.GetTempo() << " " << c.GetPrezzo(1) << " " << c.GetPrezzo(11) << " " << c.GetPrezzo(51);
 }


vector<Components> load(string NomeFile)                    //carica l'intero file
{
    string s = "";
    vector<Components> componenti {};
	
    fstream iff;
    iff.open(NomeFile);
    
    if(iff.is_open())
        while(!iff.eof())
            {
                
                iff >> s;
                Components b (s);
                componenti.push_back(b);
            }
    else
        cout << "file non leggibile";
        iff.close();
        return componenti;

}

string* divide(string s , int nelem)                              //divide le stringhe caricate
{
    string a="";
    int j=0;
    string* arr = new string[nelem];
    for (int i=0; i < s.length();i++)
    {
        if(s.at(i)=='[')
            a="";
		else if(s.at(i)==']')
            {
                arr[j]= a;
                j++;
            }
        else
            a+=s.at(i);
    }
        return arr;
}
