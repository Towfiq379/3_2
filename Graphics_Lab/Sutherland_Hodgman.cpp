#include<bits/stdc++.h>
#define F first
#define S second
#define pdd pair<double, double>
using namespace std;
const int MX = 100;
int P_SZ, C_SZ;

pdd Clipper[MX], Polygon[MX];

pdd Intersection(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
    double x = ((x1*y2 - y1*x2) * (x3-x4) - (x1-x2) * (x3*y4 - y3*x4)) / ((x1-x2) * (y3-y4) - (y1-y2) * (x3-x4));
    double y = ((x1*y2 - y1*x2) * (y3-y4) - (y1-y2) * (x3*y4 - y3*x4)) / ((x1-x2) * (y3-y4) - (y1-y2) * (x3-x4));
    return {x, y};
}

void Clip(double x1, double y1, double x2, double y2)
{
    pdd New_Points[MX];
    int New_SZ = 0;
    for(int i = 0; i < P_SZ; i++)
    {
        int j = (i + 1) % P_SZ;
        double x3 = Polygon[i].F, y3 = Polygon[i].S;
        double x4 = Polygon[j].F, y4 = Polygon[j].S;
        double pos1 = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
        double pos2 = (x2 - x1) * (y4 - y1) - (y2 - y1) * (x4 - x1);

        if(pos1 < 0 && pos2 < 0)
        {
            New_Points[New_SZ] = {x4, y4};
            New_SZ++;
        }

        else if(pos1 >=0 && pos2 < 0)
        {
            New_Points[New_SZ] = Intersection(x1, y1, x2, y2, x3, y3, x4, y4);
            New_SZ++;
            New_Points[New_SZ] = {x4, y4};
            New_SZ++;
        }

        else if(pos1 < 0 && pos2 >= 0)
        {
            New_Points[New_SZ] = Intersection(x1, y1, x2, y2, x3, y3, x4, y4);
            New_SZ++;
        }
    }
    P_SZ = New_SZ;
    cout << P_SZ << endl;
    for(int i = 0; i < P_SZ; i++)
        Polygon[i]=New_Points[i];
}

void Polygon_Clipping()
{
    for(int i = 0; i < C_SZ; i++)
    {
        int j = (i + 1) % C_SZ;
        Clip(Clipper[i].F, Clipper[i].S, Clipper[j].F, Clipper[j].S);
    }

    for(int i = 0; i < P_SZ; i++)
        cout << fixed << setprecision(2) << Polygon[i].F << ' ' << Polygon[i].S << endl;
}

int main()
{
    cin >> P_SZ;
    for(int i = 0; i < P_SZ; i++)
        cin >> Polygon[i].F >> Polygon[i].S;

    cin >> C_SZ;
    for(int i = 0; i < C_SZ; i++)
        cin >> Clipper[i].F >> Clipper[i].S;

    Polygon_Clipping();
}
/*
3
100 150
200 250
300 200
4
150 150
150 200
200 200
200 150
*/
