#include <iostream>
#include <fstream>

using namespace std;

struct dalyvis{
    string vardas;
    int numeris;
};

void Skaityti(int & n, dalyvis D[]);
void Spausdinti(int n );
int StartasPagalVarda(string v);
int StartasPagalNumeri(int n);
void Palyginimas(int n, dalyvis D[]);

int main()
{
    dalyvis lenktyniuDalyvis[100];
    int n;

    Skaityti(n, lenktyniuDalyvis);
    Palyginimas(n, lenktyniuDalyvis);

    return 0;
}

void Palyginimas(int n, dalyvis D[])
{
    int l, lMax, lIndex=0;

    if (D[0].numeris<10)
            lMax=StartasPagalNumeri(D[0].numeris);
        else
            lMax=StartasPagalVarda(D[0].vardas);

    for(int i=1; i<n; i++){
        if (D[i].numeris<10)
            l=StartasPagalNumeri(D[i].numeris);
        else
            l=StartasPagalVarda(D[i].vardas);
        if(l>lMax){
            lMax=l; lIndex=i;
        }
    }

    ofstream out("lenktynes_rez.txt");
    out << D[lIndex].vardas << " " << lMax << endl;
    out.close();
}

int StartasPagalNumeri(int n)
{
    int l= n*9;
    return l;
}

int StartasPagalVarda(string v)
{
    int l= (v[0]-64)*5;
    return l;
}

void Skaityti(int & n, dalyvis D[])
{
    ifstream in("lenktynes_data.txt");

    in >> n;

    for(int i=0; i<n; i++){
        in >> D[i].vardas >> D[i].numeris;
    }
    in.close();
}
