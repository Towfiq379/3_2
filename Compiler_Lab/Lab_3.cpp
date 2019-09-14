#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
int id,id1,id2,n,m,i,j,k,l,sum,start,last;
int root[1005],flag[1000007];
char ch;
string s,tmp,tmp2;
stack< pair< int,vector<int> > >stk;
stack<int>oper;
map<char,int>mp;
vector<pair<char,int>>adj[1000007];
vector<int>accept;
void RangeExpand()
{
    tmp.clear();
    for(i=0; i<s.size(); i++)
    {
        if(s[i]=='-')
            for(ch=s[i-1]+1; ch<s[i+1]; ch++)
                tmp.pb(ch);
        else
            tmp.pb(s[i]);
    }
    s=tmp;
}

void ClearNegation()
{
    tmp.clear();
    for(i=0; i<s.size(); i++)
    {
        if(s[i]=='^')
        {
            mp.clear();
            for(i=i+1; s[i]!=']'; i++)
                mp[s[i]]=1;
            for(ch='0'; ch<='9'; ch++)
                if(!mp[ch])
                    tmp.pb(ch);
            for(ch='a'; ch<='z'; ch++)
                if(!mp[ch])
                    tmp.pb(ch);
            for(ch='A'; ch<='Z'; ch++)
                if(!mp[ch])
                    tmp.pb(ch);
            tmp.pb(s[i]);
        }
        else
            tmp.pb(s[i]);
    }
    s=tmp;
}

void ClearPlus()
{
    tmp.clear();
    for(i=0; i<s.size(); i++)
    {
        if(s[i]=='+')
        {
            if(s[i-1]==']')
                for(j=i-2; s[j]!='['; j--);
            else if(s[i-1]==')')
                for(j=i-2; s[j]!='('; j--);
            else
                j=i-1;
            for(k=j; k<i; k++)
                tmp.pb(s[k]);
            tmp.pb('*');
        }
        else
            tmp.pb(s[i]);
    }
    s=tmp;
}

void ClearMultiple()
{
    tmp.clear();
    for(i=0; i<s.size(); i++)
    {
        if(s[i]=='{')
        {
            l=k=i-1;
            for(i=i+1,sum=0; s[i]!='}'; i++)
                sum=sum*10+s[i]-'0';
            if(s[k]=='*'||s[k]=='?')
                l--;
            if(s[l]==']')
                for(j=l-1; s[j]!='['; j--);
            else if(s[l]==')')
                for(j=l-1; s[j]!='('; j--);
            else
                j=l;
            tmp2.clear();
            for(; j<=k; j++)
                tmp2.pb(s[j]);
            for(j=1; j<sum; j++)
                tmp+=tmp2;
        }
        else
            tmp.pb(s[i]);
    }
    s=tmp;
}

void AddOR()
{
    tmp.clear();
    for(i=0; i<s.size(); i++)
    {
        if(s[i]=='[')
        {
            tmp.pb(s[i]);
            tmp.pb(s[i+1]);
            for(i=i+2; s[i]!=']'; i++)
                tmp.pb('|'),tmp.pb(s[i]);
        }
        tmp.pb(s[i]);
    }
    s=tmp;
}

void AddAND()
{
    tmp.clear();
    tmp.pb(s[0]);
    for(i=1; i<s.size(); i++)
    {
        if(s[i-1]!='('&&s[i-1]!='['&&s[i-1]!='|'&&s[i]!='*'&&s[i]!='?'&&s[i]!='|'&&s[i]!=')'&&s[i]!=']')
            tmp.pb('&');
        tmp.pb(s[i]);
    }
    s=tmp;
}

char reverse(char ch)
{
    if(ch==')')
        return '(';
    return '[';
}

void NFA()
{
    for(i=0; i<s.size(); i++)
    {
        if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')||(s[i]>='0'&&s[i]<='9'))
        {
            id1=++id;
            id2=++id;
            adj[id1].pb({s[i],id2});
            accept.clear();
            accept.pb(id2);
            stk.push({id1,accept});
        }
        else if(s[i]=='*')
        {
            auto pre=stk.top();
            stk.pop();
            start=pre.F;
            for(last:pre.S)
                adj[last].pb({NULL,start});
            pre.F=++id;
            adj[pre.F].pb({NULL,start});
            pre.S.pb(pre.F);
            stk.push(pre);
        }
        else if(s[i]=='?')
        {
            auto pre=stk.top();
            stk.pop();
            start=pre.F;
            id1=++id;
            adj[id1].pb({NULL,start});
            pre.F=id1;
            pre.S.pb(id1);
            stk.push(pre);
        }
        else if(s[i]=='('||s[i]=='[')
            oper.push(s[i]);
        else if(s[i]==')'||s[i]==']')
        {
            while(oper.top()!=reverse(s[i]))
            {
                if(oper.top()=='&')
                {
                    auto pre1=stk.top();
                    stk.pop();
                    auto pre2=stk.top();
                    stk.pop();
                    for(int last:pre2.S)
                        adj[last].pb({NULL,pre1.F});
                    stk.push({pre2.F,pre1.S});
                }
                else
                {
                    auto pre1=stk.top();
                    stk.pop();
                    auto pre2=stk.top();
                    stk.pop();
                    start=++id;
                    adj[start].pb({NULL,pre1.F});
                    adj[start].pb({NULL,pre2.F});
                    for(int last:pre2.S)
                        pre1.S.pb(last);
                    stk.push({start,pre1.S});
                }
                oper.pop();
            }
            oper.pop();
        }
        else
        {
            while(s[i]=='|'&&!oper.empty()&&oper.top()=='&')
            {
                auto pre1=stk.top();
                stk.pop();
                auto pre2=stk.top();
                stk.pop();
                oper.pop();
                for(int last:pre2.S)
                    adj[last].pb({NULL,pre1.F});
                stk.push({pre2.F,pre1.S});
            }
            oper.push(s[i]);
        }
    }
    while(!oper.empty())
    {
        if(oper.top()=='&')
        {
            auto pre1=stk.top();
            stk.pop();
            auto pre2=stk.top();
            stk.pop();
            for(int last:pre2.S)
                adj[last].pb({NULL,pre1.F});
            stk.push({pre2.F,pre1.S});
        }
        else
        {
            auto pre1=stk.top();
            stk.pop();
            auto pre2=stk.top();
            stk.pop();
            start=++id;
            adj[start].pb({NULL,pre1.F});
            adj[start].pb({NULL,pre2.F});
            for(int last:pre2.S)
                pre1.S.pb(last);
            stk.push({start,pre1.S});
        }
        oper.pop();
    }
}

int search(int node,int sid)
{
    //cout<<node<<' '<<sid<<' '<<adj[node].size()<<endl;
    if(sid==s.size()&&flag[node])
        return 1;
    int ret=0;
    for(int ii=0; ii<adj[node].size(); ii++)
    {
        auto p=adj[node][ii];
        if(p.F==NULL)
            ret=max(ret,search(p.S,sid));
        else if(sid<s.size()&&s[sid]==p.F)
            ret=max(ret,search(p.S,sid+1));
    }
    return ret;
}

int main()
{
    int t;
    cin>>n;
    for(t=1; t<=n; t++)
    {
        cin>>s;
        RangeExpand();
        ClearNegation();
        ClearPlus();
        ClearMultiple();
        AddOR();
        AddAND();
        //cout<<s<<endl;
        NFA();
        root[t]=stk.top().F;
        for(a:stk.top().S)
            flag[a]=1;
    }
    cin>>m;
    while(m--)
    {
        cin>>s;
        for(t=1; t<=n; t++)
            if(search(root[t],0))
                break;
        if(t==n+1)
            cout<<"NO, "<<0<<endl;
        else
            cout<<"YES, "<<t<<endl;
    }
}
/*
INPUT 1:
2
ab*c*d
a*b(cd)+e?f
3
acccd
abbbbbcccc
bcdcdef

OUTPUT 1:
YES, 1
N), 0
YES, 2

INPUT 2:
3
[a-c]{3}cab+(da)*f
db*a[^def]{2}gh
def[k-p]*p+
5
defkmnpmpp
acbcabbf
pqrstdd
dbaabggh
dbbbbamkgh

OUTPUT 2:
YES, 3
YES, 1
NO, 0
NO, 0
YES, 2
*/
