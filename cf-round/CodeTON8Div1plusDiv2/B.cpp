#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 2e5 + 5;
int n, a[maxn], p[maxn], vis[maxn];
int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
        }
        int mex = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i] >= 0) {
                p[i] = mex;
                vis[p[i]] = 1;
                while (vis[mex]) mex++;
            } else {
                p[i] = mex - a[i];
                vis[p[i]] = 1;
            }
        }
        for (int i = 1; i <= n; ++i) std::cout << p[i] << ' ';
        std::cout << '\n';
        for (int i  = 0; i <= n; ++i) vis[i] = 0;
    }

    return 0;
}
