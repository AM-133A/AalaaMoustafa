#include <bits/stdc++.h>
#include <unordered_map>
#define FAST std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define yes cout << "yes\n";
#define Yes cout << "Yes\n";
#define YES cout << "YES\n";
#define no cout << "no\n";
#define No cout << "No\n";
#define NO cout << "NO\n";
#define ll long long
#define ld long double
#define endd "\n"
#define sp " "
#define lp(i, x, n) for (ll i = x; i <= n; i++)
#define rlp(i, n, x) for (ll i = n; i >= x; i--)
#define f(arr, len, val) fill(arr, arr + len, val)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define clr(v, val) memset(v, val, sizeof(v))
#define pb(a) push_back(a)
#define fi first
#define se second
#define p_pair(a, b) push_back({a, b})
#define priorty_greater(pq) priority_queue<ll, vector<ll>, greater<ll>> pq;
#define pi 3.14159265359
const ll mod = 1e9 + 7;
const ll oo = 1e10 + 9;
const int MAX = 1001;
using namespace std;
int main() {
    cout << " Hello World..." << "\n";
    return 0;
}
///////////////////section 17 STL ////////////////////
//Homework 1-6 Medium challenges ------->
/*
 //all words prefix (1)
        map<string, vector<string>>mp;
        int n, m, q;
        string  s, curr = "";
        cin >> n;
        while(n--)
        {
            curr = "";
            vector<string>v;
            cin >> s;
            for(auto ch: s)
            {
                curr +=ch;
                v.pb(curr);
            }
            for(auto name : v){
                mp[name].pb(curr);
            }
        }
        cin >> q;
        while(q--)
        {
            cin >> s;
            for (auto name:mp[s]) {
                cout << name << ' ';
            }
            cout << endd;
        }
*/
/*
       //all words prefix (2)
        map<string, set<string>>mp;
        int n, m, q;
        string  s, curr = "";
        cin >> n;
        while(n--)
        {
            curr = "";
            vector<string>v;
            cin >> s;
            for(auto ch: s)
            {
                curr +=ch;
                v.pb(curr);
            }
            for(auto name : v){
                mp[name].insert(curr);
            }
        }
        cin >> q;
        while(q--)
        {
            cin >> s;
            for (auto name:mp[s]) {
                cout << name << ' ';
            }
            cout << endd;
        }
*/
/*
 //Homework 6: Remove All Adjacent Duplicates In String
       string ans = "", s;
       cin >> s;
       for(auto ch : s)
       {
            if(!ans.empty() && ch == ans.back())
                ans.pop_back();
            else
               ans+=ch;
       }
       cout << ans;
 */
