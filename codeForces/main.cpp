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
int dx[] {-1 , 1 , 0 , 0 , 1 , -1 , 1 , -1};
int dy[] {0 , 0 , -1 , 1 , 1 , 1 , -1 , -1};
vector<int>jobs(501);
vector<vector<int>>dep(501), dep2(501);
int vis[501];
int dfs(int task)//min completion time for "task"
{
    if(vis[task])
        return 0;
    vis[task]++;
    int sum = jobs[task];
    for(auto child: dep[task])
        sum+= dfs(child);
    return sum;
}
int dfs2(int task)//min completion time for "task"
{
    if(vis[task])
        return 0;
    vis[task]++;
    int sum = jobs[task];
    for(auto child: dep2[task])
        sum+= dfs2(child);
    return sum;
}
void solve()
{
    //ans = total durations (except for the given task) - sum of deq[task];
    int v, e, x, y, q, tot = 0, ans, cnt = 1;
    while(cin >> v >> e && v!=0)
    {
        tot = 0;
        lp(i, 1, v) {
            cin >> jobs[i];
            tot += jobs[i];
            dep[i].clear();
            dep2[i].clear();
        }
        while (e--) {
            cin >> x >> y;
            dep[y].pb(x);//MIN: children are results
            dep2[x].pb(y);//children are priors
        }
        cin >> q;
        cout << "Case #" << cnt << ":\n";
        while (q--) {
            cin >> x;
            clr(vis, 0);
            //cout << "MAX: " << dfs2(x)<< '\n';
            ans = (tot - dfs2(x) + jobs[x]);//complete all (tot - dfs2(x)) then complete x (+jobs[x])
            clr(vis, 0);
            //cout << "MIN: " << dfs(x) << endd;
            ans -= dfs(x);
            cout << ans << endd;
        }
        cout << endd;
        cnt++;
    }
}
int main(){
    //freopen("doroob.in", "r", stdin);
    //freopen("Bumble.out", "w", stdout);
    FAST
    ll t = 1;
    //cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}