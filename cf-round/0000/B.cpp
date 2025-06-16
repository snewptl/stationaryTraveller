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
int a, b, w, h;
int X1, Y1, x2, y2;
bool solve() {
    if (X1 == x2) {
        if (std::abs(Y1 - y2) % b) return false;
    } else {
        if (Y1 == y2 && std::abs(X1 - x2) % a) return false;
        if (std::abs(X1 - x2) % a && std::abs(Y1 - y2) % b) return false;
    }
    return true;
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> w >> h >> a >> b;
        std::cin >> X1 >> Y1 >> x2 >> y2;
        if (solve()) std::cout << "YES\n";
        else std::cout << "NO\n";

    }

    return 0;
}
