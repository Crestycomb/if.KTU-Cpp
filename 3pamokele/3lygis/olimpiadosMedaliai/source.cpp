#include <iostream>
#include <fstream>

using namespace std;

struct valstybe{
    string pavadinimas;
    int bronza, sidabras, auksas;
};

void Skaityti(int & n, valstybe V[]);
void Spausdinti(int n, valstybe V[]);


int main()
{
    int n;
    valstybe V[100];

    Skaityti(n, V);
    Spausdinti(n, V);

    return 0;
}

void Spausdinti(int n, valstybe V[])
{
    for(int i=0; i<n; i++){
        cout << V[i].pavadinimas << " " << V[i].auksas <<
        " " << V[i].sidabras << " " << V[i].bronza << endl;
    }
}

void Skaityti(int & n, valstybe V[])
{
    ifstream in("olimpiada_data.txt");

    int m, x;

    in >> n;

    char C[15];

    for(int i=0; i<n; i++){
        in.ignore(80,'\n');
        in.get(C,15);

        V[i].pavadinimas=C;

        in >> m;

        V[i].auksas=0;
        V[i].sidabras=0;
        V[i].bronza=0;
        x=0;

        for(int i2=0; i2<m; i2++){
            in >> x;
            V[i].auksas+=x;
            in >> x;
            V[i].sidabras+=x;
            in >> x;
            V[i].bronza+=x;
        }
    }

    in.close();
}
