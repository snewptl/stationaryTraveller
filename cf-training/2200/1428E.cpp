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
int n, k;
ll a[maxn];
std::set<std::pair<ll, pii>> s;
ll sum;
ll cal(int i, int piece) {
    ll remain = a[i] % piece;
    ll len = a[i] / piece;
    return remain * (len + 1) * (len + 1) + len * len * (piece - remain);
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> k;
    for (int i = 1; i <= n; ++i) std::cin >> a[i], sum += a[i] * a[i];
    for (int i = 1; i <= n; ++i) {
        if (a[i] < 2) continue;
        s.insert(std::make_pair(-cal(i, 1) + cal(i, 2), std::make_pair(i, 2)));
    }
    k -= n;
    while (k-- && !s.empty()) {
        auto [delta, p] = *s.begin();
        auto [i, piece] = p;
        s.erase(s.begin());
        sum += delta;
        if (a[i] >= piece + 1) {
            s.insert({cal(i, piece + 1) - cal(i, piece), {i, piece + 1}});
        }
    }
    std::cout << sum << '\n';

    return 0;
}
// 20 : 38 - 20 : 56