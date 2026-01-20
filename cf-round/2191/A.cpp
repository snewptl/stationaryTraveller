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
int a[maxn], b[maxn];
int col[maxn];
int n;
bool check() {
    for (int i = 1; i < n; ++i) {
        if (col[a[i]] == col[a[i + 1]]) return false;
    }
    return true;
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
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
            b[i] = a[i];
        }
        std::sort(b + 1, b + n + 1);
        for (int i = 1; i <= n; ++i) {
            col[b[i]] = i % 2;
        }
        if (check()) std::cout << "Yes\n";
        else std::cout << "No\n";
    }

    return 0;
}
