#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct zmogus{
    string vardas;
    int amzius;
};

void Skaityti(int & n, zmogus Z[]);
void Rusiuoti(int n, zmogus Z[]);
void Spausdinti(int & n, zmogus Z[]);

int main()
{
    int n;
    zmogus Z[100];

    Skaityti(n, Z);
    Rusiuoti(n, Z);
    Spausdinti(n, Z);

    return 0;
}

void Spausdinti(int & n, zmogus Z[])
{
    ofstream out ("rez.txt");
    cout << n<< endl;
    for(int i=0; i<n; i++){
        cout << Z[i].vardas << " " << Z[i].amzius << endl;
    }
    out.close();
}

void Skaityti(int & n, zmogus Z[])
{
    ifstream in ("data.txt");
    in >> n;
    for(int i=0; i<n; i++){
        in >> Z[i].vardas >> Z[i].amzius;
    }
    in.close();
}

void Rusiuoti(int n, zmogus Z[]) // rusiuoja pagal abecles tvarka, jei vardas tas pats, pagal amziu
{

    for(int i1=0; i1<n-1; i1++){
        for(int i2=i1+1; i2<n; i2++){
            if (Z[i1].vardas>Z[i2].vardas || Z[i1].vardas==Z[i2].vardas && Z[i1].amzius< Z[i2].amzius)
                swap(Z[i1],Z[i2]);
        }
    }
}
