#include <iostream>
#include <bits/stdc++.h>
#define FAST std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int main() {
    FAST
    int  n, x, a = 0, y = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> x;
        if(i == ceil(n/2.0))
            a = x;
    }
    cout << a;
    return 0;
}





//////////(B) Soltan and Squared Number////////////////
//int main() {
//    FAST
//    int n;
//    cin >> n;
//    //cout << n*n << "\n";
//    cout << (long long)pow(n, 2);
//    return 0;
//}

////////////////////////(C) Soltan's Advice/////////////////
//int main() {
//    FAST
//    int a,b, ans;
//    cin >> a >> b;
//    ans = a* b *3;
//    cout << ans << '\n';
//    return 0;
//}

////////////// D. Soltan's Challenge///////////////
//int main() {
//    FAST
//    int n, x, prev, ans = 1;
//    bool flag = false;
//    cin >> n;
//    for (int i = 0; i < n; ++i) {
//        cin >> x;//4
//        if(i == 0) {
//            prev = x;//3
//            continue;
//        }
//        if(x  >  prev && !flag)
//            ans++;
//        else
//            flag = true;
//        prev = x;
//    }
//    cout << ans << "\n";
//    return 0;
//}


///////////// (E) Soltan and Card Game////////////////////////
//int main() {
//    FAST
//    int n, x , a = 0, y = 0;
//    cin >> n;
//    for(int i = 1; i <= n; i++)
//    {
//        cin >> x;
//        if(i % 2)
//            y +=x;
//        else
//            a+=x;
//    }
//    if(y > a)
//        cout << "Yousef wins\n";
//    else if (y < a)
//        cout << "Ashraf wins\n";
//    else
//        cout << "Draw\n";
//    return 0;
//}


//////////////////////// (F) Soltan's Mid Number//////////////////////
//int main() {
//    FAST
//    int n, x, val;
//    bool flag = false;
//    cin >> n;
//    for(int i = 1; i <= n; i++)
//    {
//        cin >> x;
//        if(i == ceil(n/2.0) && !flag)
//            val = x, flag = true;
//    }
//    cout << val << '\n';
//    return 0;
//}