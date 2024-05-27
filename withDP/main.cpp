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
const int MAX = 1e+5 + 10;
using namespace std;
// ll mem[MAX], a[MAX];
//  ll Boredom(ll i)
//  {
//      if (i >= MAX)
//          return 0;

//     if (mem[i] != -1)
//         return mem[i];

//     return mem[i] = max(Boredom(i + 1), Boredom(i + 2) + i * a[i]);
// }
bool cmp(pair<pair<int, int>, pair<int, int>> &a, pair<pair<int, int>, pair<int, int>> &b)
{
    if (a.se.fi != b.se.fi)
        return a.se.fi < b.se.fi;
    else
        return a.fi.se < b.fi.se;
}
struct exam
{
    int idx, s, d, c;
    bool operator < (const exam &x) const
    {
        if (d != x.d)
            return d < x.d;
    }
};
int main()
{
    // freopen("badsubs.in", "r", stdin);
    // freopen("badsubs.out", "w", stdout);
    FAST
    ll t = 1, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<int> p(n + 1), q(n + 1, -1), a(n + 1);
        vector<bool> token(n + 1, false);
        bool possible = true, sorted = true;
        map<int, int> mpA;
        lp(i, 1, n)
        {
            cin >> a[i];
            if(a[i] != i)
                sorted = false;
            mpA[a[i]] = i;
        }
        lp(i, 1, n)
        {
            lp(j, 1, n)
            {
                if(j != i && j != mpA[i] && !token[j])
                {
                    q[i] = j;
                    token[j] = true;
                    break;
                }
            }
            if (q[i] == -1)
            {
                possible = false;
                break;
            }
        }
        if (!possible)
        {
            if(n == 3 && sorted)
                cout << "Possible\n3 1 2\n2 3 1\n";
            else
                cout << "Impossible\n";
            continue;
        }
        lp(i, 1, n)
            p[q[i]] = mpA[i];
        cout << "Possible\n";
        lp(i, 1, n)
            cout << p[i] << ' ';
        cout << endd;
        lp(i, 1, n)
            cout << q[i] << ' ';
        cout << endd;
    }
    return 0;
}

