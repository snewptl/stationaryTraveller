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
std::pair<pll, int> a[maxn];
ll f;
int vis[maxn];
std::vector<int> seq;
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
        std::cin >> n >> f;
        seq.clear();
        for (int i = 1; i <= n; ++i) vis[i] = 0;
        ll ans = 0;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i].first.first>> a[i].first.second;
            ans += a[i].first.second - a[i].first.first;
            a[i].second = i;
        }
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; ++i) {
            if (a[i].first.first <= f && a[i].first.second > f) {
                f = a[i].first.second;
                vis[i] = 1;
                seq.push_back(a[i].second);
            } else if (a[i].first.first > f) {
                ans += a[i].first.first - f;
                f = a[i].first.second;
                vis[i] = 1;
                seq.push_back(a[i].second);
            }
        }
        std::cout << ans << '\n';
        for (int i = n; i >= 1; --i) {
            if (vis[i]) continue;
            seq.push_back(a[i].second);
        }
        for (auto it : seq) std::cout << it << ' ';
        std::cout << '\n';
    }

    return 0;
}

/*
5 12
6 7

12 -6
7 - 5


2 10

3 12

3 -> 3 -> 12 -> 2 -> 10
*/