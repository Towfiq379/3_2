#include<bits/stdc++.h>
using namespace std;
const double X_MN=4,X_MX=10,Y_MN=4,Y_MX=8;
int calculate(double x,double y)
{
    int bit=0;
    if(x>X_MX)
        bit|=2;
    if(x<X_MN)
        bit|=1;
    if(y>Y_MX)
        bit|=8;
    if(y<Y_MN)
        bit|=4;
    return bit;
}
void COHEN(double x1,double y1,double x2,double y2)
{
    int bit1=calculate(x1,y1);
    int bit2=calculate(x2,y2);
    if(bit1==0&&bit2==0)
    {
        cout<<"Accepted from ("<<x1<<','<<y1<<") "<<"to ("<<x2<<','<<y2<<")\n";
        return;
    }
    else if(bit1&bit2)
    {
        cout<<"Rejected\n";
        return;
    }
    else
    {
        int bit;
        double x,y;
        if(bit1)bit=bit1;
        else bit=bit2;
        if(bit&1)
        {
            x=X_MN;
            y=y1+(x-x1)*(y1-y2)/(x1-x2);
        }
        else if(bit&2)
        {
            x=X_MX;
            y=y1+(x-x1)*(y1-y2)/(x1-x2);
        }
        else if(bit&4)
        {
            y=Y_MN;
            x=x1+(y-y1)*(x1-x2)/(y1-y2);
        }
        else if(bit&8)
        {
            y=Y_MX;
            x=x1+(y-y1)*(x1-x2)/(y1-y2);
        }
        if(bit==bit1)
            x1=x,y1=y;
        else
            x2=x,y2=y;
        COHEN(x1,y1,x2,y2);
    }
}

int main()
{
    double x1,x2,y1,y2;
    int tc,bit1,bit2;
    cin>>tc;
    while(tc--)
    {
        cin>>x1>>y1>>x2>>y2;
        COHEN(x1,y1,x2,y2);
    }
}

