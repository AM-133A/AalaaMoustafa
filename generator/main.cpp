#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
map<ll, ll>mp;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

ll rand(ll a, ll b)
{
    return a + rng() % (b - a + 1);
}
void str(ll len){
    string s = "";
    for(int i=0; i<len; i++){
        s+= char('0'+ rand(0, 9));
    }
    cout << s;
}

void binary_string(ll len){
    string s="";
    for(int i=0; i<len; i++){
        s+= to_string(rand(0,1));
    }
    cout << s;
}
void genArray(ll n, ll a , ll b)
{
    ll num;
    for(int i = 0; i < n; i++)
    {
        num = rand(a, b);
        cout << num << " ";
    }
    cout << "\n";
}
int main()
{
    int idx = 3;
    char x[] = "out00000000000000000000000000000000.txt";
    for (int ii = 0; ii < 1; ii++)
    {
        if (x[idx] == '9')
            idx++;
        freopen(x, "w", stdout);
        x[idx]++;
        ll t_case = 1;
        //t_case = rand(1, 5);
        //cout << t_case << "\n";
        while(t_case--)
        {
            ll n = rand(2, 100000);
            n = 100000;
            cout << n << "\n";
            //q = rand(1, 100000);
            //cout << q << " " << n << "\n";
            genArray(n, -100000, 100000);
            /*while(q--)
            {
                //ll l = rand(1, 99999);
                //ll r = rand(l, 99999);
                cout << 1 << " " << 100000 << "\n";
            }*/
        }
    }
}