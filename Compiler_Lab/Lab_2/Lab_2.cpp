#include<bits/stdc++.h>
#define pb push_back
using namespace std;
map<string,int>val,mp;
stack<string>sign;
stack<int>iden;

int doit(int a,int b,string s)
{
    if(s=="+")
        return a+b;
    if(s=="-")
       return a-b;
    if(s=="*")
        return a*b;
    else return a/b;
}

int convert(string s)
{
    int ret=0;
    for(int i=0;i<s.size();i++)
        ret=ret*10+s[i]-'0';
    return ret;
}

int main()
{
    int n,q,i,j,k,l,a,b,c;
    bool sgn,flag;
    string s,t;
    mp["+"]=1;
    mp["-"]=2;
    mp["*"]=3;
    mp["/"]=4;
    cin>>n;
    getchar();
    for(i=1;i<=n;i++)
    {
        getline(cin,s);
        t.clear();
        for(j=0;j<s.size();j++)
            if(s[j]=='=')
                t.pb(' '),t.pb(s[j]),t.pb(' ');
            else t.pb(s[j]);
        stringstream ss(t);
        ss>>s;
        ss>>t;
        ss>>t;
        val[s]=convert(t);
        mp[s]=1;
    }
    cin>>q;
    getchar();
    for(i=1;i<=q;i++)
    {
        getline(cin,s);
        t.clear();
        for(k=0;k<s.size();k++)
            if(s[k]=='+'||s[k]=='-'||s[k]=='*'||s[k]=='/')
                t.pb(' '),t.pb(s[k]),t.pb(' ');
            else t.pb(s[k]);

        stringstream ss(t);
        flag=false;
        sgn=true;
        while(ss>>s)
        {
            if(s=="+"||s=="-"||s=="*"||s=="/")
            {
                if(sgn)
                {
                    flag=true;
                    break;
                }
                while(!sign.empty()&&mp[sign.top()]>mp[s])
                {
                    t=sign.top();
                    sign.pop();
                    a=iden.top();
                    iden.pop();
                    b=iden.top();
                    iden.pop();
                    c=doit(b,a,t);
                    iden.push(c);
                }
                sign.push(s);
                sgn=true;
            }
            else if(mp[s])
            {
                if(!sgn)
                {
                    flag=true;
                    break;
                }
                iden.push(val[s]);
                sgn=false;
            }
            else
            {
                flag=true;
                break;
            }
        }
        if(flag)
            cout<<"Compilation Error\n";
        else
        {
            while(!sign.empty())
            {
                t=sign.top();
                sign.pop();
                a=iden.top();
                iden.pop();
                b=iden.top();
                iden.pop();
                c=doit(b,a,t);
                iden.push(c);
            }
            cout<<iden.top()<<endl;
        }
    }
}
/*
3
a=1
b=2
c=2
2
a*b+a*c+b*c
a*c-b/c+c*c

4
g=2
p=3
t=1
w=2
3
g+p*t-w*p
t-g+t-w
e+t*t-m
*/
