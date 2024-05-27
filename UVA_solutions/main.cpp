#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
/////////UVA: 10106.Product////////
/*
void solve()
{
    int sz1, sz2, pos, carry, x, y, val;
    string a, b;
    while(cin >> a >> b) {
        if(a == "0" || b == "0") {
            cout << 0 << endd;
            continue;
        }
        sz1 = (int) a.size();
        sz2 = (int) b.size();
        //cout << sz1 << ' ' << sz2 << endd;
        vector<int> res(sz1 + sz2 + 5);
        rlp(i, sz1 - 1, 0) {
            x = (int) (a[i] - '0'), carry = 0, pos = i;
            rlp(j, sz2 - 1, 0) {
                pos = i + j + 1;
                y = (int) (b[j] - '0');
                y *= x;
                y += carry;
                //cout << "x " << x << " y " << y << endd;
                carry = y / 10;//3
                //cout << "carry " << carry << endd;
                val = y % 10;//5
                if (res[pos] + val > 9) {
                    val += res[pos];
                    res[pos] = (val % 10);
                    res[pos - 1] += (val / 10);
                } else
                    res[pos] += val;
                //cout << i + j << ' ' << res[i + j] << endd;
            }
            if (carry) {
                if (res[pos - 1] + carry > 9) {
                    val = res[pos - 1] + carry;
                    res[pos - 1] = (val % 10);
                    res[pos - 2] += (val / 10);
                } else
                    res[pos - 1] += carry;
            }
        }
        lp(i, 0, (sz1 + sz2 - 1)) {
            if (res[0] == 0 && i == 0)
                continue;
            cout << res[i];
        }
        cout << endd;
    }
}
 * */

////////SPOJ: EASYMATH//////////
/*SPOJ: EASYMATH
 *
 * ll lcm(ll a, ll b)
{
    return (b / (gcd(a, b))) * a;
}
ll solution(ll arr[5], int cnt, int idx, int n, int d)
{
    if(idx >= 5)
    {
        if(cnt % 2)
            return -n/d;
        return n/d;
    }
    return solution(arr, cnt, idx + 1, n, d) + solution(arr, cnt + 1, idx + 1, n, lcm(d, arr[idx]));
}
void solve()
{
    ll n, m, a, d, divisible;
    cin >> n >> m >> a >> d;
    ll arr[] = {a, a + d, a + 2*d, a + 3*d, a + 4*d};
    divisible = solution(arr, 0, 0, m, 1) - solution(arr, 0, 0, n - 1, 1);
    cout << divisible << endd;
}*/

/////////SPOJ: MAKETREE - Hierarchy///////
/*
 * vector<bool>vis(1000001, false);
vector<int>topo;
void dfs(vector<vector<int>>&v, int node)
{
    vis[node] = true;
    for(auto child : v[node])
    {
        if(!vis[child])
            dfs(v, child);
    }
    topo.pb(node);
}
void solve()
{
    int n, m, a, k, last;
    cin >> n >> m;
    vector<vector<int>>v(n + 1);
    vector<int>ans(n + 1, -1);
    lp(i, 1, m)
    {
        cin >> k;
        while(k--) {
            cin >> a;
            v[i].pb(a);
        }
    }
    lp(i, 1, n)
    {
        if(!vis[i])
            dfs(v, i);
    }
    last = 0;
    rlp(i, n - 1, 0)
    {
        ans[topo[i]] = last;
        last = topo[i];
    }
    lp(i, 1, n)
       cout << ans[i]<< endd;
}
 * */

/////////UVA: 408.Uniform Generator////////
/* void solve()
{
    ll step, Mod, cnt = 0, val;
    while(cin >> step >> Mod) {
        vector<ll> vis(Mod, 0);
        val = 0, cnt = 0;
        for (ll i = 0; i < Mod; i++) {
            val = (val + step) % Mod;
            if (vis[val])
                break;
            vis[val]++;
            cnt++;
        }
        cout << setw(10) << step << setw(10) << Mod << "    ";
        if (cnt == Mod)
            cout << "Good Choice\n\n";
        else
            cout << "Bad Choice\n\n";
    }
}
 * */

/////////UVA: 11231.Black and white painting////////
/*void solve()
{
    ll n, m, c, whiteSquares;
    while(cin >> n >> m >> c) {
        if(n == 0 && m == 0 && c == 0)
            break;
        n -= 7, m -= 7;
        whiteSquares = (n * m);
        if(c == 1 && whiteSquares % 2 != 0)
            whiteSquares = (whiteSquares + 1) / 2;
        else
            whiteSquares/=2;
        if (whiteSquares == 0 && c == 1)
            whiteSquares = 1;
        cout << whiteSquares << endd;
    }
}
 * */

//////////UVA: 12148. Electricity/////////
/*int months[]{-1,31,28,31,30,31,30,31,31,30,31,30,31};
bool check(int d1, int m1, int y1, int d2, int m2, int y2)
{
    if(y2 == y1)
    {
        if(((y1 % 4 == 0 && y1 % 100) || y1 % 400 == 0) && m1 == 2)
        {
            if(m2 == 3){
                if (d1 - d2 == 28)
                    return true;
                else
                    return false;
            }
            else if(m2 == 2 && d2 - d1 == 1)
                return true;
            return false;
        }
        if((m1 == m2 && d2 - d1 == 1) || (m2 - m1 == 1 && (d1 - d2 == months[m1] - 1)))//two consecutive: days or months
            return true;
        return false;
    }
    else
    {
        if(y2 - y1 == 1 && m1 == 12 && m2 == 1 && d1 - d2 == months[12] - 1)
            return true;
        return false;
    }
}
void solve()
{
    int n;
    while(cin >> n && n != 0)
    {
    //cin >> n;
        ll cnt = 0, sum = 0;
        vector<int>d(n), m(n), y(n), c(n);
        lp(i, 0, n - 1)
        {
            cin >> d[i] >> m[i] >> y[i] >> c[i];
            if(i == 0)
                continue;
            if(check( d[i - 1], m[i - 1], y[i - 1], d[i], m[i], y[i]))
            {
                cnt++;
                sum+=c[i] - c[i - 1];
            }
        }
        cout<< cnt << ' ' << sum << endd;
    }
}
 *
 * */

//////////UVA: 10452. Marcus///////////
/*
 *string s = "IEHOVA#";
vector<string> ans;
void go(int idx, char arr[10][10], int i, int j, int n, int m)
{
    if(idx > 7)
        return;
    if(i - 1 >= 0 && j < m && j >= 0 && i - 1 < n && arr[i - 1][j] == s[idx]){
        ans.pb("forth");
        go(idx + 1, arr, i - 1, j, n, m);
    }
    if(i >= 0 && j + 1 < m && j + 1 >= 0 && i < n && arr[i][j + 1] == s[idx]){
        ans.pb("right");
        go(idx + 1, arr, i, j + 1, n, m);
    }
    if (i >= 0 && j - 1 < m && j - 1 >= 0 && i < n && arr[i][j - 1] == s[idx])
    {
        ans.pb("left");
        go(idx + 1, arr, i, j - 1, n, m);
    }
}
void solve()
{
    int n, m, r, c;
    cin >> n >> m;
    char a[10][10];
    lp(i, 0, n - 1)
    {
        lp(j, 0, m - 1)
        {
            cin >> a[i][j];
            if(a[i][j] == '@')
                r = i, c = j;
        }
    }
    ans.clear();
    go(0, a, r, c, n, m);
    cout << ans[0];
    lp(i, 1, (int)ans.size() - 1)
        cout << ' ' << ans[i];
    cout << endd;
}
 * */

//////////UVA: 11953. Battleslships//////////
/*
 *int visited[101][101];
void go(char a[101][101], int n, int i, int j)
{
    if(i < 0 || i >= n || j < 0 || j >= n || visited[i][j] || a[i][j] == '.')
        return;
    visited[i][j]++;
    go(a, n, i - 1, j);
    go(a, n, i + 1, j);
    go(a, n, i, j + 1);
    go(a, n, i, j - 1);
}
void solve()
{
     ll ans = 0;
     clr(visited, 0);
     int n;
     cin >> n;
     char a[101][101];
     lp(i, 0, n - 1)
     {
         lp(j, 0, n - 1)
             cin >> a[i][j];
     }
     lp(i, 0, n - 1)
     {
        lp(j, 0, n - 1)
        {
            if(!visited[i][j] && a[i][j] == 'x')
            {
                ans++;
                go(a, n, i, j);
            }
        }
     }
     cout << ans << endd;
}
int main(){
    //freopen("Bumble.in", "r", stdin);
    //freopen("Bumble.out", "w", stdout);
    FAST
    ll t = 1;
    cin >> t;
    for(int i = 1; i<=t; i++)
    {
        cout << "Case " << i << ": ";
        solve();
    }
    return 0;
} */

///////////UVA: 10305.  Ordering Tasks/////
/*
 * vector<int>topo;
vector<vector<int>> v(101);
bool vis[101];
void dfs(int node)
{
    vis[node] = true;
    for(auto child : v[node])
    {
        if(!vis[child])
            dfs(child);
    }
    topo.pb(node);
}
void solve()
{
    int n, m, a, b;
    while(cin >> n >> m && n != 0) {
        topo.clear();
        v.clear();
        clr(vis, false);
        while (m--) {
            cin >> a >> b;
            v[a].pb(b);
        }
        lp(i, 1, n)
        {
            if(!vis[i])
                dfs(i);
        }
        cout << topo[n - 1];
        rlp(i, n - 2, 0)
            cout << ' ' << topo[i];
        cout << endd;
    }
}*/

//////////Spoj: TOE1 - Tic-Tac-Toe ( I )
/*
 * bool check(string s)
{
    ///rows
    if((s[0] != '.' && s[0] == s[1] && s[1] == s[2]) ||
    (s[3] != '.' && s[3] == s[4] && s[4] == s[5]) ||
    (s[6] != '.' && s[6] == s[7] && s[7] == s[8])) return true;

    //////columns
    if((s[0] != '.' && s[0] == s[3] && s[3] == s[6]) ||
            (s[1] != '.' && s[1] == s[4] && s[7] == s[4])||
       (s[2] != '.' && s[2] == s[5] && s[5] == s[8])) return true;

    //////diagonals
    if((s[0] != '.' && s[0] == s[4] && s[4] == s[8]) ||
       (s[2] != '.' && s[2] == s[4] && s[4] == s[6])) return true;

    return false;
}
void solve()
{
    string board = "", s, curr = ".........";
    int turn = 1;
    bool ans = false;
    lp(i, 1, 3)
    {
        cin >> s;
        board += s;
    }
    queue<pair<string, bool>>q;
    q.push({curr, turn});//1 means X's turn
    while(!q.empty())
    {
        curr = q.front().first;
        turn = q.front().second;
        q.pop();
        if(curr == board)
        {
            ans = true;
            break;
        }
        if(check(curr)) continue;//no more
        lp(i, 0, 8)
        {
            if(curr[i] == '.')
            {
                curr[i] = turn? 'X' : 'O';
                if(board[i] == curr[i])
                    q.push({curr, (1^turn)});
                    curr[i] = '.';
            }
        }
    }
    (ans)? cout << "yes\n" : cout << "no\n";
}
 * */

