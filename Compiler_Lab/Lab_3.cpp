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
            while(s[l]=='+'||s[l]=='*'||s[l]=='?')
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
        if(s[i-1]!='('&&s[i-1]!='['&&s[i-1]!='|'&&s[i]!='+'&&s[i]!='*'&&s[i]!='?'&&s[i]!='|'&&s[i]!=')'&&s[i]!=']')
            tmp.pb('&');
        tmp.pb(s[i]);
    }
    s=tmp;
}

void SingleSymbol()
{
    id1=++id;
    id2=++id;
    //cout<<"> "<<id1<<' '<<id2<<endl;
    adj[id1].pb({s[i],id2});
    accept.clear();
    accept.pb(id2);
    stk.push({id1,accept});
}

void PlusOperation()
{
    auto pre=stk.top();
    stk.pop();
    //cout<<"+ "<<pre.F<<endl;
    for(last:pre.S)
        adj[last].pb({NULL,pre.F});
    stk.push(pre);
}

void StarOperation()
{
    auto pre=stk.top();
    stk.pop();
    //cout<<"* "<<pre.F<<' ';
    start=pre.F;
    for(last:pre.S)
        adj[last].pb({NULL,start});
    pre.F=++id;
    //cout<<pre.F<<endl;
    adj[pre.F].pb({NULL,start});
    pre.S.pb(pre.F);
    stk.push(pre);
}

void QuestionOperation()
{
    auto pre=stk.top();
    stk.pop();
    start=pre.F;
    id1=++id;
    //cout<<"? "<<id1<<' '<<start<<endl;
    adj[id1].pb({NULL,start});
    pre.F=id1;
    pre.S.pb(id1);
    stk.push(pre);
}

void ANDOperation()
{
    auto pre1=stk.top();
    stk.pop();
    auto pre2=stk.top();
    stk.pop();
    //cout<<"& "<<pre1.F<<' '<<pre2.F<<endl;
    oper.pop();
    for(int last:pre2.S)
        adj[last].pb({NULL,pre1.F});
    stk.push({pre2.F,pre1.S});
}

void OROperation()
{
    auto pre1=stk.top();
    stk.pop();
    auto pre2=stk.top();
    stk.pop();
    oper.pop();
    start=++id;
    //cout<<"& "<<start<<' '<<pre1.F<<' '<<pre2.F<<endl;
    adj[start].pb({NULL,pre1.F});
    adj[start].pb({NULL,pre2.F});
    for(int last:pre2.S)
        pre1.S.pb(last);
    stk.push({start,pre1.S});
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
            SingleSymbol();
        else if(s[i]=='+')
            PlusOperation();
        else if(s[i]=='*')
            StarOperation();
        else if(s[i]=='?')
            QuestionOperation();
        else if(s[i]=='('||s[i]=='[')
            oper.push(s[i]);
        else if(s[i]==')'||s[i]==']')
        {
            while(oper.top()!=reverse(s[i]))
                if(oper.top()=='&')
                    ANDOperation();
                else
                    OROperation();
            oper.pop();
        }
        else
        {
            while(s[i]=='|'&&!oper.empty()&&oper.top()=='&')
                ANDOperation();
            oper.push(s[i]);
        }
    }
}

int search(int node,int sid)
{
    //cout<<node<<' '<<sid<<' '<<endl;
    if(sid==s.size()&&flag[node])
        return 1;
    int ret=0;
    for(int ii=0; ii<adj[node].size(); ii++)
    {
        auto p=adj[node][ii];
        if(p.S==node)
            continue;
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
        s="("+s+")";
        RangeExpand();
        ClearNegation();
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
NO, 0
YES, 2
*/

/*
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

INPUT 3:
1
a*b+c*++aa
11
abbcaa
*/
