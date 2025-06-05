#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <assert.h>
#include <cmath>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 2e5 + 5;
const ll mod = 998244353;
int n;
void digit() {
    std::cout << "digit" << std::endl;
    int x;
    std::cin >> x;
}
int div(int x) {
    std::cout << "div " << x << std::endl;
    int res;
    std::cin >> res;
    return res;
}
int mul(int x) {
    std::cout << "mul " << x << std::endl;
    int res;
    std::cin >> res;
    return res;
}
int output() {
    std::cout << "!" << std::endl;
    int x;
    std::cin >> x;
    return x;
}
void solve() {
    digit();
    digit();
    digit();
    int prime[4] = {2, 3, 5, 7};
    int cnt = 0;
    for (int i = 0; i < 4; ++i) {
        while (cnt < 3) {
            ++cnt;
            if(div(prime[i]) != 1) break;
        }
        if (cnt >= 3) break;
    }
    mul(n);
    output();
}
int main() {
    #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        solve();
    }

    return 0;
}
81 
1 :79
2 : [1, 16] 
/2 
+1
/2

3 : + 11 - > 

3 : 7
/2 1, 3, 5, 7, 9
+1 2, 4, 6, 8, 10

1, 9

1, 5
1, 3

/2 
+ 1
/ 2
/3
5 7 
