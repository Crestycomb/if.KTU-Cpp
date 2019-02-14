#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct diena{
char veikla;
float laikas;
};

void Skaityti(int & n, diena D[]);
float VidutinesValandos(int n, diena D[], char x);
int LaikoKiekis(int n, diena D[], char x);
int DienuDaugiauVidKiekis(int n, diena D[], float vid, char x);
void Spausdinti(int n, diena D[], char x);

int main()
{
    diena petriukoDiena[99];
    int n;

    Skaityti(n, petriukoDiena);

    Spausdinti (n, petriukoDiena, 'D');
    Spausdinti (n, petriukoDiena, 'K');
    Spausdinti (n, petriukoDiena, 'T');

    return 0;
}

void Spausdinti(int n, diena D[], char x)
{
    ofstream out("veikla_rez.txt");

    if(x=='D')
        cout << "DRAUGAI: " << endl;
    else if(x=='K')
        cout << "KOMPIUTERINIAI ZAIDIMAI: " << endl;
    else if(x=='T')
        cout << "TINKLINIS: " << endl;

    int LK, DDK;
    float VV;

    LK=LaikoKiekis(n,D,x);
    if (LK!=0){
        VV=VidutinesValandos(n, D, x);
        DDK=DienuDaugiauVidKiekis(n, D, VV, x);
        cout << LK << " " << VV << " " << DDK << endl;
    }
    else
        cout << "NE" << endl;

    out.close();
}

int DienuDaugiauVidKiekis(int n, diena D[], float vid, char x) // kazkas cia blogai? arba su VV funkcija
{
    int k=0;

    for(int i=0; i<n; i++){
        if(D[i].veikla==x && D[i].laikas>vid){
            k++;
        }
    }
    return k;
}

int LaikoKiekis(int n, diena D[], char x)
{
    int k;

    for (int i=0; i<n; i++){
        if(D[i].veikla==x){
            k++;
            //cout << "sum= " << sum <<  endl;
            //cout << "k= " << k << endl;
        }
    }
    return k;
}

float VidutinesValandos(int n, diena D[], char x)
{
    float sum=0;
    int k=0;

    for (int i=0; i<n; i++){
        if(D[i].veikla==x){
            sum+=D[i].laikas;
            k++;
            //cout << "sum= " << sum <<  endl;
            //cout << "k= " << k << endl;
        }
    }
    float vid=float(sum/k);
    return vid;
}

void Skaityti(int & n, diena D[])
{
    ifstream in("veikla_data.txt");

    in >> n;

    for(int i=0; i<n; i++){
        in >> D[i].veikla >> D[i].laikas;
        //cout << D[i].veikla << D[i].laikas << endl;
    }
    in.close();
}
