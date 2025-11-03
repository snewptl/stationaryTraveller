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
int n, a[maxn];
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }
    std::sort(a + 1, a + n + 1);
    int s = 0;
    for (int i = 1; i <= n; ++i) {
        if (s >= a[i]) s += 1;
        else s -= 1;
    }
    std::cout << s << ' ';
    s = 0;
    for (int i = n; i >= 1; --i) {
        if (s >= a[i]) s += 1;
        else s -= 1;
    }
    std::cout << s << '\n';

    return 0;
}
