#include<bits/stdc++.h>
using namespace std;

int main()
{
    double X_MN,X_MX,Y_MN,Y_MX,x1,x2,y1,y2;
    int tc,bit1,bit2;
    cin>>X_MN>>X_MX>>Y_MN>>Y_MX;
    cin>>tc;
    while(tc--)
    {
        cin>>x1>>y1>>x2>>y2;
        bit1=bit2=0;
        if(x1>X_MX)
            bit1|=2;
        if(x1<X_MN)
            bit1|=1;
        if(y1>Y_MX)
            bit1|=8;
        if(y1<Y_MN)
            bit1|=4;
        if(x2>X_MX)
            bit2|=2;
        if(x2<X_MN)
            bit2|=1;
        if(y2>Y_MX)
            bit2|=8;
        if(y2<Y_MN)
            bit2|=4;
        if(bit1==0&&bit2==0)
            cout<<"Inside\n";
        else if(bit1&bit2)
            cout<<"Outside\n";
        else cout<<"Cliping Candidate\n";
    }
}
/*
2 4 6 8
3
1 2 3 4
*/
