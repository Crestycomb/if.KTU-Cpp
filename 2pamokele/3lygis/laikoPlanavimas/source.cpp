#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct diena{
char veikla;
float laikas;
};

void Skaityti(int & n, diena D[]);
float VidutinesValandos(int n, diena D[], char x, float h)

int main()
{
    diena petriukoDiena[99];
    int n;
    Skaityti();
    return 0;
}

void Skaityti()
{
    ifstream in("veikla_data.txt");

    in >> n;

    for(int i=0; i<n; i++){
        in >> D[i].veikla >> D[i].laikas;
    }

    in.close();
}
