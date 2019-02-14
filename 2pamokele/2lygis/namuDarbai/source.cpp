#include <iostream>
#include <fstream>

using namespace std;

void Skaityti(int & n, int pazymys[], string namuDarbas[]);
void Pazymys(int n, int pazymys[], string namuDarbas[]);
void Spausdinti(int n, int pazymys[]);

int main()
{
    int n, pazymys[100];
    string namuDarbas[100];

    Skaityti(n, pazymys, namuDarbas);
    Pazymys(n, pazymys, namuDarbas);
    Spausdinti(n, pazymys);

    return 0;
}

void Spausdinti(int n, int pazymys[])
{
    ofstream out("rez.txt");

    for(int i=0; i<n; i++){
        out << pazymys[i] << endl;
    }
    out.close();
}

void Pazymys(int n, int pazymys[], string namuDarbas[])
{
    for(int i=0; i<n; i++){
        if(namuDarbas[i]=="atliko" && pazymys[i]<10)
                pazymys[i]+=1;
        else if(namuDarbas[i]=="neatliko" && pazymys[i]>1)
                pazymys[i]-=1;
    }
}

void Skaityti(int & n, int pazymys[], string namuDarbas[])
{
    ifstream in("pazymiai.txt");

    in >> n;

    for(int i=0; i<n; i++){
        in >> pazymys[i] >> namuDarbas[i];
    }
    in.close();
}
