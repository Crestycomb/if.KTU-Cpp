#include <iostream>
#include <fstream>

using namespace std;

void Isbraukti(int n, int X[], int & did, int & maz, string & komanda);

int main()
{
    ifstream in("komanda.txt");
    ofstream out("komandarez.txt");

    string komanda;
    int n, X[3];
    int did, maz;
    in >> n;

    for(int i=0; i<n; i++){
        in >> X[0] >> X[1] >> X[2];
        //cout << X[0] << " " << X[1] << " " << X[2] << endl;
        Isbraukti(n, X, did, maz, komanda);
        out << maz << " " << did << " " << komanda << endl;
    }

    in.close();
    out.close();
    return 0;
}

void Isbraukti(int n, int X[], int & did, int & maz, string & komanda)
{
    did=X[0]; maz=X[0];

    for(int i=0; i<3; i++){
        if(did<X[i])
            did=X[i];
        if(maz>X[i])
            maz=X[i];
    }

    if((maz+did)%2==0)
        komanda="pirma";
    else
        komanda="antra";
}
