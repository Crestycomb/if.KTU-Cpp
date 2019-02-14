#include <iostream>
#include <fstream>

/*

Senovės Anglijoje buvo trys piniginiai matavimo vienetai: svarai, šilingai ir pensai.
Vienas svaras – 20 šilingų, šilingas – 12 pensų. Parašykite programą,
skaičiuojančią dviejų skirtingų pinigų kiekių, išreikštų svarais, šilingais ir pensais,
sumą ir skirtumą, išreikštą svarais, šilingais ir pensais.

Pradinių duomenų failo pinigai.txt pirmoje eilutėje įrašyta, kelių pinigų rinkinių sumą
ir skirtumą reikia apskaičiuoti. Tolesnėse n eilučių įrašyta po 6 sveikuosius skaičius:
pirmieji trys skaičiai reiškia pirmojo pinigų kiekio svarus sv1, šilingus s1 ir pensus p1,
paskutinieji trys skaičiai – antrojo pinigų kiekio svarus sv2, šilingus s2 ir pensus p2.

Rezultatų faile pinigairez.txt turi būti n eilučių su 6 sveikaisiais skaičiais kiekvienoje
eilutėje: pirmieji trys skaičiai reiškia sumos svarus ssv, sumos šilingus ss, sumos pensus sp;
paskutinieji trys skaičiai – skirtumo svarus sksv, skirtumo šilingus sks, skirtumo pensus skp.

*/
using namespace std;

void Skaityti();
void Suma(int sv1, int s1, int p1, int sv2, int s2, int p2, int & ssv, int & ss, int & sp);
void Skirtumas(int sv1, int s1, int p1, int sv2, int s2, int p2, int & sksv, int & sks, int & skp);

int main()
{
    Skaityti();

    return 0;
}

void Skirtumas(int sv1, int s1, int p1, int sv2, int s2, int p2, int & sksv, int & sks, int & skp)
{
//    p1=p1+s1*12+sv1*12*20;
//    cout << endl << "p1= " << p1 << endl;
//
//    p2=p2+s2*12+sv2*12*20;
//    cout << "p2= " << p2 << endl;
    sks=0;
    sksv=0;
    skp=(p1+s1*12+sv1*12*20) -  (p2+s2*12+sv2*12*20);

    if(skp>12)
    {
        sks= (skp/12);
        skp= skp-(skp/12)*12;
    }
    if(sksv>20){
        sksv= (sks/20);
        sks= sks-(sks/20)*20;
    }
}

void Suma(int sv1, int s1, int p1, int sv2, int s2, int p2, int & ssv, int & ss, int & sp)
{
    ssv=sv1+sv2;
    ss=s1+s2;
    sp=p1+p2;

    if(sp>12){
        ss=ss+(sp/12);
        sp=sp-(sp/12)*12;
    }
    if(ss>20){
        ssv=ssv+(ss/20);
        ss=ss-(ss/20)*20;
    }
}

void Skaityti()
{
    ifstream in("pinigai.txt");
    ofstream out("pinigairez.txt");
    int n;
    int sv1, s1, p1, sv2, s2, p2;
    int ssv, ss, sp, sksv, sks, skp;

    in >> n;

    for(int i=0; i<n; i++){
        in >> sv1 >> s1 >> p1 >> sv2 >> s2 >> p2;
        Suma(sv1, s1, p1, sv2, s2, p2, ssv, ss, sp);
        out << ssv << " " << ss << " " << sp << " ";
        Skirtumas(sv1, s1, p1, sv2, s2, p2, sksv, sks, skp);
        out << sksv << " " << sks << " " << skp << endl;
    }
    in.close();
    out.close();
}
