#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

struct keleivis{
string pavarde;
float bagazas[15];
int bagazoKiekis;
};

void Skaityti(int & n, int & m, int & x, int & y, keleivis K[]);
int KiekisKeleiviuDaugiauMBagazo(int n, int m, keleivis K[]);
int KiekisKeleiviuKiekvienoBagazoMaseDaugiauNeiX(int n, int x, keleivis K[]); // susiapvalinti bagazo mase iki .0 ir tada ziureti
int KiekisKeleiviuBagazoMaseDaugiauNeiVid(int n, keleivis K[]);
void KurieKeleiviuBagazoMaseDaugiauNeiYint(int n, int y, keleivis K[]);


int main()
{
    keleivis lektuvoKeleivis[500];
    int n, m, x, y;

    Skaityti(n, m, x, y, lektuvoKeleivis);

    ofstream out("lektuvas_res.txt");

    out << KiekisKeleiviuDaugiauMBagazo(n, m, lektuvoKeleivis) << endl;
    out << KiekisKeleiviuKiekvienoBagazoMaseDaugiauNeiX(n, x, lektuvoKeleivis) << endl;
    out << KiekisKeleiviuBagazoMaseDaugiauNeiVid(n, lektuvoKeleivis) << endl;
    KurieKeleiviuBagazoMaseDaugiauNeiYint(n, y, lektuvoKeleivis);

    out.close();

    return 0;
}

void KurieKeleiviuBagazoMaseDaugiauNeiYint(int n, int y, keleivis K[])
{
    ofstream out("lektuvas_res.txt", ios::app);

    float didMas=-1, sum=0;
    int k;

    for(int i1=0; i1<n; i1++){
        sum=0;
        for(int i2=0; i2<K[i1].bagazoKiekis; i2++){
            sum+=K[i1].bagazas[i2];
        }
        if(sum>didMas)
            didMas=sum;
    }

    for(int i1=0; i1<n; i1++){
        sum=0;
        for(int i2=0; i2<K[i1].bagazoKiekis; i2++){
            sum+=K[i1].bagazas[i2];
        }
        if(sum+y==didMas || sum-y==didMas)
            out << K[i1].pavarde << endl;
    }
    out.close();
}

int KiekisKeleiviuBagazoMaseDaugiauNeiVid(int n, keleivis K[])
{
    float vid, sum=0;
    int k=0;
    for(int i1=0; i1<n; i1++){
        for(int i2=0; i2<K[i1].bagazoKiekis; i2++){
            sum+= K[i1].bagazas[i2];
        }
    }

    vid=float(sum/n);

    for(int i1=0; i1<n; i1++){
        sum=0;
        for(int i2=0; i2<K[i1].bagazoKiekis; i2++){
            sum+= K[i1].bagazas[i2];
            if(trunc(sum)>trunc(vid))
                k++;
        }
    }
    return k;
}

int KiekisKeleiviuKiekvienoBagazoMaseDaugiauNeiX(int n, int x, keleivis K[])
{
    /*
    uzduotyje rasoma:
    "antroje eilutėje įrašytas skaičius keleivių,
    kurių kiekvieno bagažo masė viršija x kilogramų 0.1 kg. tikslumu;"

    taciau atsakymas duotas 2, bet taip gaunama tik jei as kiekvieno zmogaus bagazo mase sumuociau ir
    tik tada lyginciau, o ne lyginciau atskirus bagazo mases...
    */
    int k=0;
    int sum;

    for(int i1=0; i1<n; i1++){
        sum=0;
        for(int i2=0; i2<K[i1].bagazoKiekis; i2++){
            sum+=K[i1].bagazas[i2];
        }
        if (trunc(sum)>x)
            k++;
    }
    return k;
}

int KiekisKeleiviuDaugiauMBagazo(int n, int m, keleivis K[])
{
    int k=0;

    for (int i1=0; i1<n; i1++){
        if (K[i1].bagazoKiekis<=m)
            k++;
    }
    return k;
}
void Skaityti(int & n, int & m, int & x, int & y, keleivis K[])
{
    ifstream in("lektuvas_data.txt");

    in >> n;

    for(int i1=0; i1<n; i1++){
        in >> K[i1].pavarde >> K[i1].bagazoKiekis;
        for (int i2=0; i2<K[i1].bagazoKiekis; i2++){
            in >> K[i1].bagazas[i2];
        }
    }
    in >> m >> x >> y;
    in.close();
}
