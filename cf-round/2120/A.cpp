#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <bitset>
#include <memory.h>
#include <assert.h>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 2e5 + 5;
const ll mod = 998244353;
pii a, b, c;
bool is_square(pii d, pii c) {
    int flag = 0;
    if (d.first == c.first) {
        if (d.second + c.second == c.first) flag = 1;
    }
    if (d.second == c.second) {
        if (d.first + c.first == c.second) flag = 1;
    }
    return flag;
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
        int flag = 0;
        std::cin >> c.first >> c.second >> a.first >> a.second >> b.first >> b.second ;
        if (a.first == b.first) {
            pii d = {a.first, a.second + b.second};
            flag |= is_square(d, c);
        }
        if (a.second == b.second) {
            pii d = {a.first + b.first, a.second};
            flag |= is_square(d, c);
        }
        if (flag) std::cout << "YES\n";
        else std::cout << "NO\n";
    }

    return 0;
}
