#include<bits/stdc++.h>
using namespace std;
int n, q, i, j;
string expr1, expr2, s;
map < char, int> mp;
int main()
{
    mp['a'] = mp['e'] = mp['i'] = mp['o'] = mp['u'] = 1;
    cin >> expr1 >> expr2;
    cin >> q;
    while(q--)
    {
        cin >> s;
        int L = s.size();
        if(L == 1 && !mp[s[0]])
            cout << "Valid" << endl;
        else if(L == 6)
        {
            for(i = 0; i < L; i++)
                if(mp[s[i]])
                    break;
            if(i == L)
                    cout << "Valid" << endl;
            else
                cout << "Invalid" << endl;
        }
        else if(L >= 3)
        {
            if(s[0] == 'a' && s[L - 2] == 'd' && s[L - 1] == 'e')
            {
                if(L == 3)
                {
                    cout << "Valid" << endl;
                    continue;
                }
                for(i = 2; i < L - 2; i += 2)
                    if(s[i - 1] != 'b' || s[i] != 'c')
                        break;
                if(i == L - 1)
                    cout << "Valid" << endl;
                else
                    cout << "Invalid" << endl;
            }
            else
                cout << "Invalid" << endl;
        }
        else
            cout << "Invalid" << endl;
    }
}
/*
a(bc)*de
[^aeiou]
11
ade
abcbcde
abde
abcbde
b
c
a
e

*/
