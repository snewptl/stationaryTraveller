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
int n;
ll r;
pll p[maxn];
ll x;
bool circle(pll x, pll y) {
    return (x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second) <= r * r;
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> r;
    for (int i = 1; i <= n; ++i) {
        std::cin >> p[i].first >> p[i].second;
        x = std::max(std::abs(p[i].first), x);
        x = std::max(std::abs(p[i].second), x);
    }
    std::sort(p + 1, p + n + 1);
    pll s = {-x,  -x};
    pll cur = s;
    ll h = r * sqrt(3.0) + 1;
    ll w = r * 2;
    int round = 0;
    std::vector<pll> vec;
    while (cur.first <= x + r) {
        auto it = std::lower_bound(p + 1, p + n + 1, std::make_pair(cur.first - r, cur.second - r)) - p;
        int count =  0;
        while (it <= n) {
            if (p[it].first > cur.first + r) break;
            if (circle(p[it], cur)) {
                count += 1;
                break;
            }
            ++it;
        }
        if (count) vec.push_back(cur);
        cur.second += w;
        if (cur.second > x + r) {
            cur.second = s.first - round * r;
            cur.first += h;
            round ^= 1;
        }
    } 
    std::cout << vec.size() << '\n';
    for (auto [x, y] : vec) {
        std::cout << x << ' ' << y << '\n';
    }

    return 0;
}

/*
all 1 all + 1 0
*/