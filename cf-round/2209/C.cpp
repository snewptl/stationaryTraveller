#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <assert.h>
#include <memory.h>
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
int ask(int x, int y) {
    std::cout << "? " << x << ' ' << y << std::endl;
    int res;
    std::cin >> res;
    return res;
}
void output(int x) {
    std::cout << "! " << x << std::endl;
}
void solve() {
    for (int i = 1; i <= n * 2 - 5; i += 2) {
        int cur = ask(i, i + 1);
        if (cur) {
            output(i);
            return;
        }
    }
    int res1 = ask(n * 2 - 3, n * 2 - 2);
    int res2 = ask(n * 2 - 3, n * 2 - 1);
    int res3 = ask(n * 2 - 2, n * 2 - 1);
    if (res1) {
        output(n * 2 - 3);
    } else if (res2) {
        output(n * 2 - 3);
    } else if (res3) {
        output(n * 2 - 2);
    } else {
        output(n * 2);
    }

}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
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
