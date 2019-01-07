#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

struct suo{
float svoris;
int maistas;
int amzius;
};

//diudis budis diudiudiu
void skaitytiDuomenis(int & mn, int & mx, int & n, suo S[]);
double maitinimosiSantykis(int m, float s);
double santykiuVidurkis(int n, suo S[]);

int main() //unfinished. blogas ats
{
    suo tiriamiejiSunys[100];
    double santykiai[100];
    int minTyrimoAmzius, maxTyrimoAmzius, n;

    skaitytiDuomenis(minTyrimoAmzius, maxTyrimoAmzius, n, tiriamiejiSunys);

    ofstream out("rez.txt");

    out << santykiuVidurkis(n, tiriamiejiSunys) << endl;

    out.close();

    return 0;
}

double santykiuVidurkis(int n, suo S[])
{
    double sum=0, vid;

    for(int i=0; i<n; i++)
        sum+=maitinimosiSantykis(S[i].maistas, S[i].svoris);

    vid= double(sum/n);
    return vid;
}

double maitinimosiSantykis(int m, float s) // maisto kiekis ir suns svoris
{
    double santykis= double(m/sqrt(s*1000));
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
