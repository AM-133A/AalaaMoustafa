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
int dy[8] {0 , 0 , -1 , 1 , 1 , 1 , -1 , -1};
bool check(string s)
{
    /*012
     *345
     *678*/

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
bool complete(string s)
{
    lp(i, 0, 8)
    {
        if(s[i] == '.')
            return false;
    }
    return true;
}
void solve()
{
    string board, curr;
    while (cin >> board && board != "end") {
        int turn = 1;
        bool ans = false, winning = false;
        curr = ".........";
        queue<pair<string, bool>> q;
        q.push(make_pair(curr, turn));//1 means X's turn
        while (!q.empty()){
            curr = q.front().first;
            turn = q.front().second;
            q.pop();
            if(curr == board){
                if(check(board))
                    winning = true;
                ans = true;
                break;
            }
            if (check(curr)) continue;//no more
            lp(i, 0, 8) {
                if (curr[i] == '.') {
                    curr[i] = turn ? 'X' : 'O';
                    if (board[i] == curr[i])
                        q.push(make_pair(curr, (1 ^ turn)));
                    curr[i] = '.';
                }
            }
        }
        if(ans)
        {
            if(winning)
                cout << "valid\n";
            else
            {
                if(complete(board))
                    cout << "valid\n";
                else
                    cout << "invalid\n";
            }
        }
        else
            cout << "invalid\n";
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