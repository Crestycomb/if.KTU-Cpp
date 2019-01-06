#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct lenktynininkas{
   string vardas;
   string pavarde;
   int valandos;
   int minutes;
};

const int d=760;

void skaityti(int & n, lenktynininkas D[]);
void greitis(int n, lenktynininkas D[], float G[]);
float vidurkis(int n, float G[]);
float laikas(int n, lenktynininkas D[]);
void spausdinti(int n, lenktynininkas D[], float G[]);

int main ()
{
    int n;
    float Greiciai [100];
    lenktynininkas Dakaras[100];

    skaityti(n, Dakaras);
    greitis(n, Dakaras, Greiciai);
    spausdinti(n, Dakaras, Greiciai);

    return 0;
}

void spausdinti(int n, lenktynininkas D[], float G[])
{
    ofstream out ("dakaras_rez.txt");

    float vid=vidurkis(n,G);

    for (int i=0; i<n; i++)
        if (G[i]>=vid){
            out << fixed << setprecision(2) << D[i].vardas << " " << D[i].pavarde;
            out << " " << G[i] << " km/h" << endl;
        }
    out << "Bendras laikas: " << laikas(n, D) << " h" << endl;
    out << "Greicio vidurkis: " << vid << " km/h" << endl;

    out.close();
}

float laikas(int n, lenktynininkas D[])
{
    float h=0;

    for (int i=0; i<n; i++)
        h+= D[i].minutes+ D[i].valandos*60;

    h=h/60;
    return h;
}

float vidurkis(int n, float G[])
{
    float sum=0, vid;

    for (int i=0; i<n; i++)
        sum+=G[i];

    vid= float(sum/n);

    return vid;
}

void greitis(int n, lenktynininkas D[], float G[])
{
    float h;
    for (int i=0; i<n; i++){
        h=D[i].minutes;
        h=h/60;
        h=h+D[i].valandos;

        G[i]=d/h;
    }
}

void skaityti(int & n, lenktynininkas D[])
{
    ifstream in ("dakaras_data.txt");

    in >> n;

    for (int i=0; i<n; i++){
        in >> D[i].vardas;
        in >> D[i].pavarde;
        in >> D[i].valandos;
        in >> D[i].minutes;
    }
    in.close();
}
