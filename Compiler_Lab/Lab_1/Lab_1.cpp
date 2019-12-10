#include<bits/stdc++.h>
#define pb push_back
using namespace std;
string s,str,tmp;
vector<string>key,num,other,math,logic,iden;

void print()
{
    sort(key.begin(),key.end());
    sort(num.begin(),num.end());
    sort(other.begin(),other.end());
    sort(math.begin(),math.end());
    sort(logic.begin(),logic.end());
    sort(iden.begin(),iden.end());
    cout<<"Keywords: ";
    for(int i=0;i<key.size();i++)
        if(i==0)
            cout<<"\""<<key[i]<<"\"";
        else if(key[i]!=key[i-1])
            cout<<" , \""<<key[i]<<"\"";
    cout<<"\nIdentifiers: ";
    for(int i=0;i<iden.size();i++)
        if(i==0)
            cout<<"\""<<iden[i]<<"\"";
        else if(iden[i]!=iden[i-1])
            cout<<" , \""<<iden[i]<<"\"";
    cout<<"\nMath operators: ";
    for(int i=0;i<math.size();i++)
        if(i==0)
            cout<<"\""<<math[i]<<"\"";
        else if(math[i]!=math[i-1])
            cout<<" , \""<<math[i]<<"\"";
    cout<<"\nLogical operators: ";
    for(int i=0;i<logic.size();i++)
        if(i==0)
            cout<<"\""<<logic[i]<<"\"";
        else if(logic[i]!=logic[i-1])
            cout<<" , \""<<logic[i]<<"\"";
    cout<<"\nNumerical operators: ";
    for(int i=0;i<num.size();i++)
        if(i==0)
            cout<<"\""<<num[i]<<"\"";
        else if(num[i]!=num[i-1])
            cout<<" , \""<<num[i]<<"\"";
    cout<<"\nOthers: ";
    for(int i=0;i<other.size();i++)
        if(i==0)
            cout<<"\""<<other[i]<<"\"";
        else if(other[i]!=other[i-1])
            cout<<" , \""<<other[i]<<"\"";
}

int main()
{
    getline(cin,s);
    stringstream ss(s);
    while(ss>>str)
    {
        if(str.back()==','||str.back()==';')
        {
            tmp.clear();
            tmp.pb(str.back());
            other.pb(tmp);
            str.pop_back();
        }
        if (str=="if" || str=="else" ||str=="while" || str=="do" ||str=="break" ||str=="continue" ||
                str=="int"|| str=="double" || str=="float"|| str=="return" || str=="char"|| str=="case" ||
                str=="char"|| str=="sizeof" || str=="long"|| str=="short" || str=="typedef"|| str=="switch" ||
                str=="unsigned"|| str=="void" || str=="static"|| str=="struct" || str=="goto")
            key.pb(str);
        else if((str[0]>='0'&&str[0]<='9')||str[0]=='.')
            num.pb(str);
        else if(str=="+"||str=="-"||str=="*"||str=="/"||str=="%"||str=="++"||str=="--"||str=="="||str=="+="||str=="-="||str=="*="||str=="/="||str=="%=")
            math.pb(str);
        else if(str=="=="||str=="<"||str==">"||str=="!="||str=="<="||str==">="||str=="&&"||str=="||"||str=="!")
            logic.pb(str);
        else if((str[0]>='a'&&str[0]<='z')||(str[0]>='A'&&str[0]<='Z'))
            iden.pb(str);
        else other.pb(str);
    }
    print();
}

