#include <iostream>
#include <fstream>
#include <tgmath.h>

using namespace std;

struct armija {
    int pretorionas, legionierius, lankininkas, barbaras, centurionas;
};

void Skaityti(armija & p, armija & g);
void GynejoStatusas(armija p, armija g, bool & gynejuLaimejimas, int & PS, int & GT);
void GynejoAukos(armija p, armija g, armija & gAukos, bool gynejuLaimejimas, int PS, int GT);
void Spausdinti(armija gAukos, bool gynejuLaimejimas);

/*
Kario pavadinimas	Puolimo taškai	Gynybos taškai
Pretorionas	            20	            64
Legionierius 	        54	            54
Lankininkas	            44	            64
Barbaras	            82	            12
Centurionas	            137	            62
*/

int main()
{
    armija puolejai, gynejai, gynejuAukuSkaicius;
    int PS, GT;
    bool gynejuLaimejimas;

    Skaityti(puolejai, gynejai);
    GynejoStatusas(puolejai, gynejai, gynejuLaimejimas, PS, GT);
    GynejoAukos(puolejai, gynejai, gynejuAukuSkaicius, gynejuLaimejimas, PS, GT);
    Spausdinti(gynejuAukuSkaicius, gynejuLaimejimas);

    return 0;
}

void Spausdinti(armija gAukos, bool gynejuLaimejimas)
{
    ofstream out("data_output.txt");

    if (gynejuLaimejimas==1)
        out << "true"  << endl;
    else
        out << "false" << endl;

    out << gAukos.pretorionas  << endl;
    out << gAukos.legionierius << endl;
    out << gAukos.lankininkas  << endl;
    out << gAukos.barbaras     << endl;
    out << gAukos.centurionas  << endl;

    out.close();
}

void GynejoAukos(armija p, armija g, armija & gAukos, bool gynejuLaimejimas, int PS, int GT)
{
    float SE;

    if(gynejuLaimejimas==1){
        SE= float(PS)/float(GT);
        SE= round(SE*10000)/10000;
    }
    else{
        SE= float(GT)/float(PS);
        SE= round(SE*10000)/10000;
    }
    if(gynejuLaimejimas==1){
        gAukos.pretorionas   = g.pretorionas  *SE;
        gAukos.legionierius  = g.legionierius *SE;
        gAukos.lankininkas   = g.lankininkas  *SE;
        gAukos.barbaras      = g.barbaras     *SE;
        gAukos.centurionas   = g.centurionas  *SE;
    }
    else{
        gAukos.pretorionas   = g.pretorionas  *(1-SE);
        gAukos.legionierius  = g.legionierius *(1-SE);
        gAukos.lankininkas   = g.lankininkas  *(1-SE);
        gAukos.barbaras      = g.barbaras     *(1-SE);
        gAukos.centurionas   = g.centurionas  *(1-SE);
    }
}

void GynejoStatusas(armija p, armija g, bool & gynejuLaimejimas, int & PS, int & GT)
{
    PS= p.pretorionas*20 + p.legionierius*54 + p.lankininkas*44 + p.barbaras*82 + p.centurionas*137;
    GT= g.pretorionas*64 + g.legionierius*54 + g.lankininkas*64 + g.barbaras*12 + g.centurionas*62;

    if(PS>=GT)
        gynejuLaimejimas= false;
    else
        gynejuLaimejimas= true;
}

void Skaityti(armija & p, armija & g)
{
    ifstream in("data_input.txt");

    in >> p.pretorionas >> p.legionierius >> p.lankininkas >> p.barbaras >> p.centurionas;
    in >> g.pretorionas >> g.legionierius >> g.lankininkas >> g.barbaras >> g.centurionas;

    in.close();
}
