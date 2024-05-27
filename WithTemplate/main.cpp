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
#define clr(v, val) memset(v, val, sizeof(v))
#define rall(v) v.rbegin(), v.rend()
#define pb(a) push_back(a)
#define fi first
#define se second
#define p_pair(a, b) push_back({a, b})
#define pi 3.14159265359
#define MAXNODES 100000 + 9
const ll mod =  998244353;
const ll oo = 1e9 + 9;
const ll MAX = 10000000009;
using namespace std;
// vector<vector<int>> v(1001);
// vector<bool> vis(1001);
// int dis[1001];
bool cmp(pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b)
{
    if (a.first != b.first)
    {
        return a.fi < b.fi;
    }
    else
    {
        if (a.se.fi != b.se.fi)
            return a.se.fi < b.se.fi;
        else
            return a.se.se < b.se.se;
    }
}
ll Ceil(ll a, ll b)
{
    return (a + b - 1) / b;
}
int binarySearch(int arr[], int l, int r, int x)
{
    if (l > r)
        return -1;
    int mid = (l + r) / 2;
    if (arr[mid] == x)
        return mid + 1;
    else if (arr[mid] > x)
        return binarySearch(arr, l, mid - 1, x);
    else
        return binarySearch(arr, mid + 1, r, x);
}
ll gcd(ll a, ll b)
{
    return __gcd(a, b);
}
ll lcm(ll a, ll b)
{
    return (b / (gcd(a, b))) * a;
}
struct myComp
{
    constexpr bool operator()(pair<int, int> const &a, pair<int, int> const &b)
    const noexcept
    {
        if (a.first != b.first)
            return a.first < b.first;
        else
            return a.second > b.second;
    }
};
long long Sub(long long x, long long y)
{
    long long z = x - y;
    if (z < 0)
    {
        z += mod;
    }
    return z;
}
long long fast_pow(long long a, long long p, long long mod)
{
    long long res = 1;
    while (p > 0)
    {
        if (p % 2 == 0)
        {
            a = (a * a) % mod;
            p /= 2;
        }
        else
        {
            res = (res * a) % mod;
            p--;
        }
    }
    return res;
}
long long add(long long a, long long b)
{
    a += b;
    if (a >= mod)
    {
        a -= mod;
    }
    return a;
}
long long mul(long long a, long long b)
{
    return (long long) ((long long) a * b % mod);
}
long long modinv(long long x)
{
    return fast_pow(x, mod - 2, mod);
}
long long Div(long long x, long long y)
{
    return mul(x, modinv(y));
}
ll NPR(ll n, ll r)
{
    ll ans = 1;
    for (ll i = (n - r) + 1; i <= n; i++)
    {
        ans *= i;
        ans %= mod;
    }
    return ans;
}
ll NCR(ll n, ll r)
{
    ll ans = 1;
    int div = 1; // r!
    for (ll i = r + 1; i <= n; i++)
    {
        ans = mul(ans, i);
        ans =Div(ans,div);
        div++;
    }
    return ans;
}
int main() {
    // freopen("tshirts.in", "r", stdin);
    // freopen("badsubs.out", "w", stdout);
    FAST
    int t = 1, n, m;
    //cin >> t;
    while (t--) {
        cin >> n >> m;
        //cin.ignore();
        string ans = "";
        lp(i, 1, m)
            ans += 'X';
        vector<string> rhymes(n), lines(m);
        vector<int> v(m, n);
        vector<char>vi(n+7, 'a');
        cin.ignore();
        lp(i, 0, n - 1)
        {
            getline(cin, rhymes[i]);
            vi[i] = 'a';
        }
        vi[n] = 'a';
        cin.ignore();
        lp(i, 0, m - 1)
             getline(cin, lines[i]);
        lp(i, 0, m - 1){
            string a = "";
            reverse(all(lines[i]));
            for(auto ch: lines[i]) {
                if (ch == ' ')
                    break;
                a += (char)tolower(ch);
            }
            reverse(all(a));
            lp(k, 0, n - 1){
                if (rhymes[k].find(a) != string::npos)
                {
                    v[i] = (int)k;
                    break;
                }
            }
        }
        /*lp(i, 0, m - 1)
        cout << v[i] << " ";
        cout << endd;*/
        char next = 'A';
        lp(i, 0, m - 2)
        {
            if(v[i] == n)
                continue;
            if(i == 0)
            {
                if(v[i] == v[i + 1])
                {
                    if(next == 'X')
                        next++;
                    ans[i] = ans[i + 1] = vi[v[i]] = next;
                    next++;
                }
                else
                {
                    //v[i] != -1 && next = 'A'
                    ans[i] = vi[v[i]] = next;
                    next++;
                }
            }
            else
            {
                if(v[i] == v[i - 1])
                {
                    if(vi[v[i]] != 'a')
                        ans[i] = ans[i - 1] = vi[v[i]];
                    else
                    {
                        if(next == 'X')
                            next++;
                        ans[i] = ans[i - 1] = vi[v[i]] = next;
                        next++;
                    }
                }
                if(v[i] == v[i + 1])
                {
                    if(next == 'X')
                        next++;
                    if(vi[v[i]]!='a')
                        ans[i] = ans[i + 1] = vi[v[i]];
                    else
                    {
                        ans[i] = ans[i + 1] = vi[v[i]] = next;
                        next++;
                    }
                }
                if(v[i] != v[i - 1] && v[i] != v[i + 1] && v[i] != n)
                {
                    if(next == 'X')
                        next++;
                    if(vi[v[i]]!='a')
                        ans[i] = vi[v[i]];
                    else {
                        ans[i] = vi[v[i]] = next;
                        next++;
                    }
                }
            }
        }
        //cout << next << endd;
        //cout << (char)vi[v[n - 1]]-'a' << endd;
        //cout << v[n -1] << endd;
        if(v[m - 1] != n)
        {
            if(vi[v[m - 1]] == 'a')
            {
                if(next == 'X')
                    next++;
                ans[m - 1] = next;
            }
            else
                ans[m - 1] = vi[v[m - 1]];
        }
        cout << ans << endd;
    }
    return 0;
}
/*2 3
hash
four
Waka waka bang splat tick tick hash
Bang splat equal at dollar underscore
Percent splat waka waka tilde number four
 */





//////////////////////////DP/////////////////////////////////////
/*ll Vacation(int i, int last)
{
    if(i == n)
      return 0;
    ll &ans = mem[i][last];
    if(mem[i][last] != -1)
        return mem[i][last];
    ans = 0;
    if(last != 0)
      ans = max(ans, a[i] + Vacation(i + 1, 0));

    if(last != 1)
      ans = max(ans, b[i] + Vacation(i + 1, 1));

    if(last != 2)
      ans = max(ans, c[i] + Vacation(i + 1, 2));

    return ans;
}*/


/*ll maxProduct(int i, int r)
{
    if(i == k)
    {
        if(r == 0)
          return 1;
        else
          return 0;
    }
    if(r == 0)
      return 0;

    ll &mx = dp[i][r];
    if(mx != -1)
       return mx;
    mx = 0;

    for(int j = 1; j <= r; j++)
       mx = max(mx, maxProduct(i + 1, r - j) * j);
    return mx;
}*/


/*ll LIS(int i, int prev)//pick or leave
{
    if(i == n)
      return 0;

    ll & mx = dp[i][prev];
    if(mx != -1)
       return mx;
    int choice1 = LIS(i+1, prev), choice2 = 0;

    if(arr[i] >= arr[prev] || prev == n)
       choice2 = 1+LIS(i+1, i);
    mx = max(choice1, choice2);

    return mx;
}*/

/*ll Knapsack1(int i, int r)
{
    if (r == 0 || i == n)
        return 0;
    if (mem[i][r] != -1)
        return mem[i][r];
    mem[i][r] = 0;
    ll choice1 = Knapsack1(i + 1, r);
    ll choice2 = 0;
    if(r - w[i] >= 0)
      choice2 = max(choice2, v[i] + Knapsack1(i + 1, r - w[i]));
    mem[i][r] = max(choice1, choice2);

    return mem[i][r];
}*/
/*ll frog1(int i)
{
    if(i+1 == n)
      return 0;

    if(mem[i] != -1)
       return mem[i];
    mem[i] = oo;
    mem[i] = min(mem[i], abs(arr[i] - arr[i+1])+ frog1(i+1));
    if(i + 2 < n)
        mem[i] = min(mem[i], abs(arr[i] - arr[i+2])+frog1(i+2));
    return mem[i];
}*/

//////////////////////////GRAPH//////////////////////////////////
/*
// void bfs(int node)
// {
//     queue<int> q;
//     q.push(node);
//     while(!q.empty())
//     {
//         int u = q.front();
//         q.pop();
//         for (int i = 0; i < (int)v[u].size(); i++)
//         {
//             if(dis[v[u][i]] == -1)
//             {
//                 dis[v[u][i]] = dis[u]+ 6;
//                 q.push(v[u][i]);
//             }
//         }
//     }
// }
// void dfs(int node)
// {
//     vis[node] = true;
//     cout << node << ' ';
//     lp(i, 0, v[node].size()-1)
//     {
//         if(!vis[v[node][i]])
//             dfs(v[node][i]);
//     }
//}
*/
/*bool isPalindrome(string s, int n, int i)
{
    if (i == n)
        return true;
    if (s[i] != s[n - 1])
        return false;
    if(i < n)
       return isPalindrome(s, n - 1, i + 1);
    return true;
}
void Generating_palindromic_substrings(string s, int i, int n)
{
    if(i == n)
      return;
    string t = "";
    for(int j = i; j < n; j++)
    {
        t+=s[j];
        if(isPalindrome(t, (int)t.size(), 0))
            ans.pb(t);
    }
    Generating_palindromic_substrings(s, i + 1, n);
}*/

/*ll MyPow(ll val, ll p)
{
    if (p == 0)
        return 1;
    return (val%mod * MyPow(val, p - 1)%mod)%mod;
}
int mxElement(int arr[], int n)
{
    if (n == 0)
        return arr[0];
    return max(arr[n - 1], mxElement(arr, n - 1));
}
int sumArray(int arr[], int n)
{
    if (n == 0)
        return 0;
    return arr[n - 1] + sumArray(arr, n - 1);
}
double arrayAvg(int arr[], int n, int sz)
{
    if (n == 0)
        return 0;
    return (arr[n - 1] / (double)sz + arrayAvg(arr, n - 1, sz));
}
void arrayInc(int arr[], int n)
{
    if (n == 0)
        return;
    arrayInc(arr, n - 1);
    arr[n - 1] += n - 1;
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endd;
}
int arrayAccumulation(int arr[], int n)
{
    if (n == 0)
        return 0;
    return arr[n - 1] += arrayAccumulation(arr, n - 1);
}
int leftMax(int arr[], int n)
{
    if (n == 0)
        return arr[0];
    return arr[n - 1] = max(arr[n - 1], leftMax(arr, n - 1));
}
int RightMax(int arr[], int n, int startPos)
{
    if (startPos == n)
        return arr[n - 1];
    return arr[startPos + 1] = max(arr[startPos + 1], RightMax(arr, n, startPos + 1));
}
int suffixSum(int arr[], int n, int num)
{
    if (num == 0)
        return 0;
    return arr[n - num] + suffixSum(arr, n, num - 1);
}
int prefixSum(int arr[], int n, int num)
{
    if (n - num == 0)
        return arr[0];
    return arr[n - num] + prefixSum(arr, n, num + 1);
}
bool isPalindrome(int arr[], int n, int i)
{
    if (i == n)
        return true;
    if (arr[i] != arr[n - 1])
        return false;
    isPalindrome(arr, n - 1, i + 1);
}
bool isPrefix(string s, string ss, int i)
{
    if (i+1 == (int)ss.size())
        return true;
    if (ss[i] != s[i])
        return false;
    isPrefix(s, ss, i + 1);
    return true;
}
bool isPrime(int n, int start, int end)
{
    if(start == end)
      return true;
    if(n % start == 0) return false;
    isPrime(n, start + 1, end);
}
void countPrimes(int l, int r)
{
    if(l+1 == r)
      return;
    if(isPrime(l, 2, (int)sqrtl(l)))
       cnt++;
    countPrimes(l+1, r);
}*/

/*bool is_palindrome(string v) {
    int n = v.size();
    for (int i = 0; i < n / 2; i++) {
        if (v[i] != v[n - i - 1]) {
            return false;
        }
    }
    return true;
}*/
/*///////Mod functions/////////////
long long Sub(long long x, long long y)
{
    long long z = x - y;
    if (z < 0)
    {
        z += mod;
    }
    return z;
}
long long fast_pow(long long a, long long p, long long mod)
{
    long long res = 1;
    while (p > 0)
    {
        if (p % 2 == 0)
        {
            a = (a * a) % mod;
            p /= 2;
        }
        else
        {
            res = (res * a) % mod;
            p--;
        }
    }
    return res;
}
long long add(long long a, long long b)
{
    a += b;
    if (a >= mod)
    {
        a -= mod;
    }
    return a;
}
long long mul(long long a, long long b)
{
    return (long long) ((long long) a * b % mod);
}
long long modinv(long long x)
{
    return fast_pow(x, mod - 2, mod);
}
long long Div(long long x, long long y)
{
    return mul(x, modinv(y));
}
ll NPR(ll n, ll r)
{
    ll ans = 1;
    for (ll i = (n - r) + 1; i <= n; i++)
    {
        ans *= i;
        ans %= mod;
    }
    return ans;
}
ll NCR(ll n, ll r)
{
    ll ans = 1;
    int div = 1; // r!
    for (ll i = r + 1; i <= n; i++)
    {
        ans = mul(ans, i);
        ans =Div(ans,div);
        div++;
    }
    return ans;
}*/

/*bool isPrime(ll n)
{
    if (n <= 1 || (n % 2 == 0 && n != 2))
        return false;

    if (n == 2 || n == 3)
        return true;

    for (ll i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
           return false;
        }
    return true;
}
ll factorial(ll x) {
    ll ans = 1;
    for (int i = 1; i <= x; i++)
        ans *= i;
    return ans;
}
ll permutation(ll n, ll r) {
    return (factorial(n) / factorial(n - r));
}
ll combination(ll n, ll r) {
    return permutation(n, r) / factorial(r);
}
bool isSubArray(vector <int> A, vector <int> B, int n, int m)
{
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (A[i] == B[j]) {
            i++;
            j++;
            if (j == m)
                return true;
        }
        else
            i++;
    }
    return false;
}
bool isSubSequence(string str1, string str2, int m, int n)
{
    if (m == 0)
        return true;
    if (n == 0)
        return false;
    if (str1[m - 1] == str2[n - 1])
        return isSubSequence(str1, str2, m - 1, n - 1);
    return isSubSequence(str1, str2, m, n - 1);

}
long long sum_OddNumbers(long long x)
{
    long long terms,sum;
    terms=(x+1)/2;
    sum=terms*terms;
    return sum;
}
long long sum_EvenNumbers(long long x)
{
    long long terms,sum;
    terms=x/2;
    sum=terms*(terms+1);
    return sum;
}
long long gcd(long long a, long long b)
{
    //gcd(a,b)= gcd(b,a%b),until b=0
    if (a < b)
        swap(a, b);
    while (b != 0)
    {
        long long x = a;
        a = b;
        b = x % b;
    }
    return a;
}
long long lcm(long long a, long long b)
{
    //gcd(a,b)*lcm(a,b)=a*b
    return(b / (gcd(a, b))) * a;
}*/

/*/////////////Bitwise functions//////////////////
bool getBit(int num, int idx) {
    //return ((num >> idx) & 1);
    return ((1 << idx) & num) == (1 << idx);
}
ll setBit(ll num, int idx, bool val) {
    return val ? (num | (1LL << idx)) : (num & ~(1LL << idx));
}
ll flipBit(ll num, int idx) {
    return (num ^ (1LL << idx));
}
ll leastBit(ll num) {
    return (num & -num);
}
//num%mod, mod is a power of 2
ll Mod(ll num, ll mod) {
    return (num & (mod - 1));
}
bool isPowerOfTwo(ll num) {
    return (num & (num - 1)) == 0;
}
int turnOnLastZero(int S) {
    return S | (S + 1);
}
int turnOffLastBit(int S) {
    return S & (S - 1);
}
int turnOnLastConsecutiveZeroes(int S) {
    return S | (S - 1);
}
int turnOffLastConsecutiveBits(int S) {
    return S & (S + 1);
}*/

/*////////////////////////////Sort functions///////////////////////////
void merge(vector<int>&arr, vector<int>&left, vector<int>&right) {
    int i = 0, j = 0, k = 0, leftSize = left.size(), rightSize = right.size();

    // Merge the two sub-arrays into a single sorted array
    while (i < leftSize && j < rightSize)
    {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }

    // Copy the remaining elements of the left sub-array, if any
    while (i < leftSize)
        arr[k++] = left[i++];

    // Copy the remaining elements of the right sub-array, if any
    while (j < rightSize)
        arr[k++] = right[j++];
}
// Function to perform Merge Sort on an array
void mergeSort(vector<int>& arr, int n) {
    if (n < 2)
        return;
    // Divide the array into two sub-arrays
    int mid = n / 2;
    vector<int> left(mid);
    vector<int> right(n - mid);
    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    for (int i = mid; i < n; i++) {
        right[i - mid] = arr[i];
    }
    // Recursively sort the sub-arrays
    mergeSort(left, mid);//left half
    mergeSort(right, n - mid);//right half

    // Merge the sorted sub-arrays
    merge(arr, left, right);
//**************Complexity*************
    //worst case: O(n logn)
    //space complexity = O(n)
    //This algo. is stable && out of place
}
int partition(vector<int> &v, int l, int h)
{
   int j = l;
   for (int i = l; i < h; i++)
   {
        if (v[i] < v[h])
        {
            swap(v[j++], v[i]);
            //j++;
        }
   }
   swap(v[j], v[h]);
   return j;
}
void quickSort(vector<int> &v, int l, int r)
{
    if(l < r)
    {
        int idx = partition(v, l, r);
        quickSort(v, l, idx-1); //left partition
        quickSort(v, idx+1, r); //right partition
    }
//**************Complexity*************
    //worst case: O(n^2)
    //best case: Ω(n logn)
    //average case: θ(n logn)
    //space complexity = O(1)
    //This algo. is not stable && It's in place
}
void selectionSort(vector<int> &v, int n)
{
    int mn;
    for (int i = 0; i < n - 1; i++)
    {
        mn = i;
        for (int j = i + 1; j < n; j++)
        {
            if (v[j] < v[mn])
                mn = j;
        }
        swap(v[i], v[mn]);
    }
//**************Complexity*************
    //worst case: O(n^2)
    //best case: Ω(n^2)
    //average case: θ(n^2)
    //space complexity = O(1)
    //This algo. is not stable && in place
}
void insertionSort(vector<int> &v, int n)
{
    for(int i = 1; i < n; i++)
    {
        for(int j = i; j > 0; j--)
        {
            if(v[j] < v[j-1])
              swap(v[j-1], v[j]);
            else
               break;
        }
    }
///**************Complexity*************
    ///worst case: O(n^2)
    //best case: Ω(n)
    //average case: θ(n^2)
    //space complexity = O(1)
    //This algo. is stable && in place
}*/
