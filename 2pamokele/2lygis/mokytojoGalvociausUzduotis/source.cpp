#include <iostream>
#include <fstream>

using namespace std;

void Skaityti(int & a, int & b);
void Atvirksciai(int & a, int & b);
bool Pirminis(int x);
int Suma(int x);

int main()
{
    int a,b;

    Skaityti(a,b);
    Atvirksciai(a,b);

    ofstream out("Rezultatai.txt");
    out << a << " " << b << endl;
    if(Pirminis(a)==1 && Pirminis(b)==1)
        if(a>b)
            out << Suma(a) << endl;
        else
            out << Suma(b) << endl;
    else
        if(a<b)
            out << Suma(a) << endl;
        else
            out << Suma(b) << endl;
    out.close();

    return 0;
}

int Suma(int x)
{
    int sum=0;

    while(x!=0){
        sum+=x%10;
        x=x/10;
    }
    return sum;
}

bool Pirminis(int x)
{
    int k=0;
    for(int i=2; i<x; i++){
        if(x%i==0)
            k++;
    }
    if (k>1 || x==1)
        return 0;
    else
        return 1;
}

void Atvirksciai(int & a, int & b)
{
    int aNew, bNew;

    aNew=a%10;
    a=a/10;
    while(a!=0){
        aNew=aNew*10;
        aNew=aNew+a%10;
        a=a/10;
    }

    bNew=b%10;
    b=b/10;
    while(b!=0){
        bNew=bNew*10;
        bNew=bNew+b%10;
        b=b/10;
    }

    a=aNew;
    b=bNew;
}

void Skaityti(int & a, int & b)
{
    ifstream in("Skaitmenys.txt");

    in >> a >> b;

    in.close();
}
