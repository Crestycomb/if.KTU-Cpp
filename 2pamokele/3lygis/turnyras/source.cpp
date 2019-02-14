#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct runktynes{
string pavadinimas;
int zioguTaskai;
int varzovuTaskai;
};

void skaityti(int & n, runktynes R[]);
void skaiciavimai(int n, runktynes R[], int& sum, float& vid);
void spausdinti(int sum, float vid);

int main()
{
    runktynes klasiuTurnyras[10];

    int n, sum;
    float vid;

    skaityti (n, klasiuTurnyras);
    skaiciavimai(n, klasiuTurnyras, sum, vid);
    spausdinti(sum, vid);

    return 0;
}

void spausdinti(int sum, float vid)
{
    ofstream out("turnyras_res.txt");

    out << fixed << setprecision(2) << vid << endl;
    out << sum << endl;

    out.close();
}

void skaityti(int & n, runktynes R[])
{
    ifstream in("turnyras_data.txt");

    in >> n;

    for(int i=0; i<n; i++)
        in >> R[i].pavadinimas >> R[i].zioguTaskai >> R[i].varzovuTaskai;

    in.close();
}


void skaiciavimai(int n, runktynes R[], int & sum, float & vid)
{
    sum=0;
    vid=0;

    for(int i=0; i<n; i++)
        sum+=R[i].zioguTaskai;

    vid=float(sum)/float(n);
}
