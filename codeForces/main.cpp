#include <bits/stdc++.h>
#include <unordered_map>
#include <fstream>
#define FAST std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define endd "\n"
#define lp(i, x, n) for (ll i = x; i <= n; i++)
#define rlp(i, n, x) for (ll i = n; i >= x; i--)
//#define f(arr, len, val) fill(arr, arr + len, val)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define clr(v, val) memset(v, val, sizeof(v))
#define pb(a) push_back(a)
#define p_pair(a, b) push_back({a, b})
#define priorty_greater(pq) priority_queue<ll, vector<ll>, greater<ll>> pq;
#define oo (ll)1e+9
using namespace std;
ll const mod = 1e9 + 7;
//int dx[] {-1 , 1 , 0 , 0 , 1 , -1 , 1 , -1};
//int dy[] {0 , 0 , -1 , 1 , 1 , 1 , -1 , -1};
int dx[] = { 1, 1, -1, -1, 2, 2, -2, -2 };
int dy[] = { 2, -2, 2, -2, 1, -1, 1, -1 };
map<pair<int, int>, vector<pair<int, int>>> adjList;
bool isValid(int r, int c) {
    return (r >= 0 & c >= 0 && r < 8 && c < 8);
}
int BFSPath(int sr, int sc, int dr, int dc) {
    queue<pair<int, int>> q;
    map<pair<int, int>, int>vis;
    q.push(make_pair(sr, sc));
    int dep = 0, sz = 1;
    pair<int, int>cur = q.front();
    for ( ; !q.empty();	++dep, sz = (int)q.size()) {//1
        while(sz--){
            cur = q.front(), q.pop();
            vis[cur]++;
            for(auto & pos:adjList[cur]) if (!vis[pos])
            {
                q.push(pos);
                if(pos.first == dr && pos.second == dc)	// we found target no need to continue
                    return dep + 1;
            }
        }
    }
    return dep + 1;
}
void solve()
{
    string s, d;
    while(cin >> s >> d){
    //cin >> s >> d;
        if (s == d)
            cout << "To get from " << s << " to " << d << " takes " << 0 << " knight moves.\n";
        else
            cout << "To get from " << s << " to " << d << " takes " <<
                 BFSPath(s[1] - '1', s[0] - 'a', d[1] - '1', d[0] - 'a') << " knight moves.\n";
    }
}
int main(){
    //freopen("doroob.in", "r", stdin);
    //freopen("Bumble.out", "w", stdout);
    FAST
    ll t = 1;
    for(string ch = "a"; ch <= "h"; ch[0]++)
    {
        for(int i = 1; i <= 8; i++)
        {
            string node = ch[0] + to_string(i);
            pair<int, int> p;
            p.first = node[1] - '1',p.second = node[0] - 'a';
            for (int k = 0; k < 8; k++){ // try all 8 moves
                int nr = p.first + dx[k]; // new row
                int nc = p.second + dy[k]; // new column
                if (!isValid(nr, nc)) continue; // if out of boar
                adjList[p].push_back(make_pair(nr, nc));
            }
        }
    }
    //cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}