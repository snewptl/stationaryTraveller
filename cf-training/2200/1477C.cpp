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
pll a[maxn];
int ranking[maxn];
bool check(int i) {
    pll x = {a[ranking[i - 1]].first - a[ranking[i]].first, a[ranking[i - 1]].second - a[ranking[i]].second};
    pll y = {a[ranking[i + 1]].first - a[ranking[i]].first, a[ranking[i + 1]].second - a[ranking[i]].second};
    // if (x.first * y.first > 0 && x.second * y.second > 0) return false;
    // if (x.first * y.first < 0 && x.second * y.second < 0) return true;
    return (x.first * y.first + x.second * y.second <= 0);
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i].first >> a[i].second;
    }
    for (int i = 1; i <= n; ++i) ranking[i] = i;
    for (int i = 2; i < n; ++i) {
        if (check(i)) {
            std::swap(ranking[i], ranking[i + 1]);
            for (int j = i - 1; j > 1; --j) {
                if (check(j)) {
                    std::swap(ranking[j - 1], ranking[j]);
                }
            }
        } 
    }
    for (int i = 2; i < n; ++i) {
        assert(check(i) == false);
    }
    for (int i = 1; i <= n; ++i) std::cout << ranking[i] << ' ';
    std::cout << '\n';

    return 0;
}

// 15 : 56 - 16 : 30