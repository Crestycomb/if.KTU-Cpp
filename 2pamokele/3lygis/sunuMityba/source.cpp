#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

struct suo{
float svoris;
int maistas;
int amzius;
};

void skaitytiDuomenis(int & mn, int & mx, int & n, suo S[]);
double maitinimosiSantykis(int m, float s);
double santykiuVidurkis(int n, double sum);

int main() //unfinished. blogas ats
{
    suo tiriamiejiSunys[100];
    double santykiai[100];
    int minTyrimoAmzius, maxTyrimoAmzius, n;

    skaitytiDuomenis(minTyrimoAmzius, maxTyrimoAmzius, n, tiriamiejiSunys);

    double sum=0;
    for(int i=0; i<n; i++){
        sum+=maitinimosiSantykis(tiriamiejiSunys[i].maistas, tiriamiejiSunys[i].svoris);
    }
    cout << santykiuVidurkis(n, sum) << endl;

    return 0;
}

double santykiuVidurkis(int n, double sum)
{
    double vid= float(sum/n);
    return vid;
}

double maitinimosiSantykis(int m, float s) // maisto kiekis ir suns svoris
{
    double santykis= m/sqrt(s);

    return santykis;
}

void skaitytiDuomenis(int & mn, int & mx, int & n, suo S[])
{
    ifstream in("data.txt");

    in >> mn >> mx >> n;

    for(int i=0; i<n; i++){
        in >> S[i].svoris >> S[i].maistas >> S[i].amzius;
    }

    in.close();
}
