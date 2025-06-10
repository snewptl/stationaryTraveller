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
int a[maxn];
int fw[maxn];
std::vector<int> vec[2];
ll inv[2];
int lowbit(int x) {
    return x & (-x);
}
int query(int x) {
    int res = 0;
    for (int i = x; i; i -= lowbit(i)) {
        res += fw[i];
    }
    return res;
}
void update(int x, int delta) {
    for (int i = x; i <= n; i += lowbit(i)) {
        fw[i] += delta;
    }
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
        std::cin >> n;
        vec[0].clear();
        vec[1].clear();
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
            vec[i % 2].push_back(a[i]);
        }
        
        for (int i = 0; i < 2; ++i) {
            for (int j = 1; j <= n; ++j) {
                fw[j] = 0;
            }
            for (auto it : vec[i]) update(it, 1);
            inv[i] = 0;
            for (auto it : vec[i]) {
                inv[i] += query(it - 1);
                update(it, -1);
            }
        }

        std::sort(all(vec[0]));
        std::sort(all(vec[1]));
        int m = n / 2;
        if ((inv[1] + inv[0]) % 2) {
            if (n % 2 == 0) std::swap(vec[0][m - 1], vec[0][m - 2]);
            else std::swap(vec[1][m], vec[1][m - 1]);
        }
        for (int i = 1; i <= m; ++i) {
            std::cout << vec[1][i - 1] << " " << vec[0][i - 1] << ' ';
        }
        if (n % 2) std::cout << vec[1][m];
        std::cout << '\n';
    }

    return 0;
}
