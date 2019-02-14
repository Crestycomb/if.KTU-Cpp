#include <iostream>
#include <fstream>
#include <iomanip>

/*
kaip isspresti be strukturos:
ciklas cikle; eiti per kiekviena issivaizduojama koordinate kiekviename staciakampyje ir isspausdinti
ta kuris paskutinis buvo ant virsaus, jei nei vieno nebuvo, spausdinti balta.
*/

using namespace std;

struct staciakampis{
    int x, y;
    int dx, dy;
    int r, g, b;
};

struct isklotine{
    int r, g, b;
};

void Skaityti(int & n, staciakampis S[]);
//void SpausdintiTest(int n, staciakampis S[]);
void Nusibalinti(isklotine X[][100]);
void RastiDidziausiasKoordinates(int n, staciakampis S[], int & didX, int & didY);
void Spalvinimas(int n, staciakampis S[], int didX, int didY, isklotine X[][100]);
void Spausdinti(int didX, int didY, isklotine X[][100]);

int main()
{
    int n, didX, didY;
    isklotine X[100][100];

    staciakampis S[100];
    Skaityti(n, S);
//    SpausdintiTest(n, S);

    RastiDidziausiasKoordinates(n, S, didX, didY);
    Nusibalinti(X);

    Spalvinimas(n, S, didX, didY, X);

    Spausdinti(didX, didY, X);

    return 0;
}
void Spausdinti(int didX, int didY, isklotine X[][100])
{
    ofstream out ("rez.txt");

    out << didY << " " << didX << endl;

    for(int i1=0; i1<didY; i1++){
        for(int i2=0; i2<didX; i2++){
            out << X[i2][i1].r << " " << X[i2][i1].g << " " << X[i2][i1].b << " " << endl;
        }
    }
    out.close();
}

void Spalvinimas(int n, staciakampis S[], int didX, int didY, isklotine X[][100])
{
    int absY, absX;
    // cikluojam per visus staciakampiukus is eiles
    // imam rgb vertes is to staciakampiuko ir spausdinam ant isklotines virsaus
    for(int i1=0; i1<n; i1++){
        absX=S[i1].x+S[i1].dx;
        absY=S[i1].y+S[i1].dy;
        for(int i2=S[i1].x; i2<absX; i2++){
            for(int i3=S[i1].y; i3<absY; i3++){
                X[i2][i3].r=S[i1].r; X[i2][i3].g=S[i1].g; X[i2][i3].b=S[i1].b;
            }
        }
    }
}

/*
rasau funkcija kuri rastu didz koordinates (kurios nera baltos), kad viska po ju galeciau veliau
nespausdinti atsakymuose. kad tai padaryti, teoriskai man dar reiketu patikrinti ar
tu staciakampiu spalva nera balta (255 255 255), nes jei taip, tai reikia atmesti tas didziausias
koordinates ir ieskoti ju kitur.
*/
void RastiDidziausiasKoordinates(int n, staciakampis S[], int & didX, int & didY)
{
    // surasti pirma staciakampiuka kuris nera baltas ir ji prisilyginti dx ir dy
    for(int i1=0; i1<n; i1++){
        if(S[i1].r !=255 && S[i1].g !=255 && S[i1].b !=255){
            didX=S[i1].dx+ S[i1].x;
            didY=S[i1].dy+ S[i1].y;
        }
    }
    // toliau ieskau ir lyginu kitus staciakampius ar jie siekia didesnias x ir y koordinates
    for(int i2=0; i2<n; i2++){
        if(S[i2].r !=255 || S[i2].g !=255 || S[i2].b !=255){
            if(S[i2].dx+S[i2].x>didX)
                didX=S[i2].dx+S[i2].x;
            if(S[i2].dx+S[i2].x>didY)
                didY=S[i2].dy+S[i2].y;
        }
    }
}

void Nusibalinti(isklotine X[][100])
{
    // nubalinu visas isklotines spalvas
    for(int i1=0; i1<100; i1++){
        for(int i2=0; i2<100; i2++){
            X[i1][i2].r=255;
            X[i1][i2].g=255;
            X[i1][i2].b=255;
        }
    }
}

//void SpausdintiTest(int n, staciakampis S[])
//{
//    cout << "n= " << n << endl;
//    for(int i=0; i<n; i++){
//        cout << S[i].x << " " << S[i].y << " " << S[i].dx << " " << S[i].dy << " ";
//        cout << S[i].r << " " <<S[i].g << " " << S[i].b << endl;
//    }
//}

void Skaityti(int & n, staciakampis S[])
{
    ifstream in ("data.txt");
    in >> n;

    for(int i=0; i<n; i++){
        in >> S[i].x >> S[i].y >> S[i].dx >> S[i].dy >> S[i].r >> S[i].g >> S[i].b;
    }
    in.close();
}
