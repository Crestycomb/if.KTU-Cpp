#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct savaitesIslaidos{
    float kaina;
    int kiekis;
};

void skaityti(int & n, savaitesIslaidos S[]);
float modeliukuKaina(int n, savaitesIslaidos S[]);
int modeliukuKiekis(int n, savaitesIslaidos S[]);
float modeliukuVid(int k, float sum);
float spausdinti(float x);

int main ()
{
    int n;
    savaitesIslaidos ignoSavaite[100];

    skaityti(n, ignoSavaite);

    float kaina;
    kaina= modeliukuKaina(n, ignoSavaite);
    int kiekis;
    kiekis= modeliukuKiekis(n, ignoSavaite);
    float vid;
    vid= modeliukuVid(kiekis, kaina);

    spausdinti(vid);

    return 0;
}

float spausdinti(float x)
{
    ofstream out ("rezultatai.txt");

    out << fixed << setprecision(2) << x << endl;

    out.close();
}

float modeliukuVid(int k, float sum)
{
    float vid=(float)(sum/k);
    return vid;
}

int modeliukuKiekis(int n, savaitesIslaidos S[])
{
    int k=0;
    for(int i=0; i<n; i++){
        k+=S[i].kiekis;
    }
    return k;
}

float modeliukuKaina(int n, savaitesIslaidos S[])
{
    float sum=0;
    for(int i=0; i<n; i++){
        sum+=S[i].kaina;
    }
    return sum;
}

void skaityti(int & n, savaitesIslaidos S[])
{
    ifstream in ("duomenys.txt");

    in >> n;

    for (int i=0; i<n; i++){
        in >> S[i].kaina;
        in >> S[i].kiekis;
    }
    in.close();
}
