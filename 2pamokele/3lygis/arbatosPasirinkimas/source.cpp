#include <iostream>
#include <fstream>

using namespace std;

struct arbata{
    string pavadinimas;
    int kiekis;
    float kaina;
};

void Skaityti(int & n, arbata A[], float & sum);
float VidutinePakelioKaina(int n, arbata A[]);
void KasTelpaIBiudzeta(int n, arbata A[], float sum, string X[], int & k);

int main()
{
    ofstream out("arbata_rezultatai.txt");

    arbata A[100];
    int n, k;
    float sum;

    Skaityti(n,A,sum);
    out << VidutinePakelioKaina(n,A) << endl;

    string tinkamosArbatos[100]; // pavadinimai arbatu, kurie telpa i biudzeta
    KasTelpaIBiudzeta(n,A,sum, tinkamosArbatos, k);

    out << k << endl;

    for(int i=0; i<k; i++){
        out << tinkamosArbatos[i] << endl;
    }

    out.close();

    return 0;
}

void KasTelpaIBiudzeta(int n, arbata A[], float sum, string X[], int & k)
{
    int t;

    k=0;
    for(int i=0; i<n; i++){
        t=A[i].kaina*A[i].kiekis;
        if(t<=sum){
            X[k]=A[i].pavadinimas; k++;
        }
    }
}

float VidutinePakelioKaina(int n, arbata A[])
{
    float sum=0;

    for(int i=0; i<n; i++){
        sum+=A[i].kaina;
    }
    return float(sum/n);
}

void Skaityti(int & n, arbata A[], float & sum)
{
    ifstream in("arbata_duomenys.txt");

    in >> n >> sum;

    for(int i=0; i<n; i++){
        in >> A[i].pavadinimas >> A[i].kiekis >> A[i].kaina;
    }
    in.close();
}
