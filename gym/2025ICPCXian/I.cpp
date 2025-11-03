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
const int maxn = 2e3 + 5;
const ll mod = 998244353;
int n;
int a[maxn][maxn];
std::vector<pii> e;
std::vector<std::vector<int>> vec;
int dep[maxn];
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    vec.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            std::cin >> a[i][j];
            a[j][i] = a[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if ((a[i][1] ^ a[j][1] ^ i) == a[i][j]) {
                dep[j] += 1;
            } else if ((a[i][1] ^ a[j][1] ^ j) == a[i][j]) {
                dep[i] += 1;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        vec[dep[i]].push_back(i);
    }
    for (int i = 1; i <= n; ++i) {
        if (vec[i].empty()) break;
        for (auto v : vec[i]) {
            for (auto u : vec[i - 1]) {
                if ((a[u][1] ^ a[v][1] ^ u) == a[u][v]) {
                    e.push_back({u, v});
                }
            }
        }
    }
    for (auto [u, v] : e) {
        std::cout << u << ' ' << v << '\n'; 
    }
    

    return 0;
}
