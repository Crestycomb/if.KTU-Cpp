#include <iostream>
#include <fstream>

using namespace std;

void SkaitytiPirma(int & n, float & k, string & klase);
void KiekDovanu(int n, int & k);
void DezuciuKainaIrSuma(int k, float kainaPries , float & kainaPo, float & suma);

int main()
{
    string klase;
    int n, kiekDovanu;
    float kainaPriesNuolaida, kainaPoNuolaidos, suma;

    SkaitytiPirma(n, kainaPriesNuolaida, klase);
    KiekDovanu(n, kiekDovanu);
    DezuciuKainaIrSuma(kiekDovanu, kainaPriesNuolaida, kainaPoNuolaidos, suma);


    ofstream out("rezultatai.txt");
    out << klase << endl;
    out << kiekDovanu << endl;
    out << kainaPoNuolaidos << endl;
    out << suma << endl;
    out.close();

    return 0;
}

void DezuciuKainaIrSuma(int k, float kainaPries , float & kainaPo, float & suma)
{
    if(k>10)
        kainaPo=kainaPries*.6;
    else if(k>=7)
        kainaPo=kainaPries*.65;
    else if(k>=4)
        kainaPo=kainaPries*.75;

    suma=kainaPo*k;
}

void SkaitytiPirma(int & n, float & k, string & klase)
{
    ifstream in("klase.txt");

    in >> klase >> n >> k;

    in.close();
}

void KiekDovanu(int n, int & k)
{
    ifstream in("salDezute.txt");

    int sum,x, n2;
    float vid;
    k=0;
    for(int i1=0; i1<n; i1++){
        sum=0;
        in >> n2;
        for(int i2=0; i2<n2; i2++){
            in >> x;
            sum+=x;
        }
        vid=float(sum)/float(n2);
        if(vid>8)
            k++;
    }
    in.close();
}
