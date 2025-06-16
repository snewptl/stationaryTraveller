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
int n, m, k;
ll x[maxn];
struct ladder {
    int a, b, c, d;
    ll h;
}lad[maxn];
std::vector<std::vector<int>> vec;
std::vector<std::vector<pli>> dp;
bool cmp(int x, int y) {
    return lad[x].b < lad[y].b;
}
bool solve() {
    dp[1].push_back({0, 1});
    for (int floor = 1; floor < n; ++floor) {
        if (dp[floor].empty()) continue;
        std::map<int, ll> mp;
        std::vector<int> bucket;
        for (auto it : dp[floor]) {
            if (!mp.count(it.second)) {
                mp[it.second] = it.first;
            } else {
                mp[it.second] = std::min(mp[it.second], it.first);
            }
            bucket.push_back(it.second);
        } 
        std::sort(all(bucket));
        bucket.resize(std::unique(all(bucket)) - bucket.begin());
        dp[floor].clear();
        for (auto it : bucket) {
            dp[floor].push_back({mp[it], it});
        }
        
        std::set<pli> left, right;
        int sz = dp[floor].size(), cur = 0;
        for (int i = 0; i < sz; ++i) {
            right.insert({dp[floor][i].first + dp[floor][i].second * x[floor], i});
        }
        for (auto idx : vec[floor]) {
            while (cur < sz && dp[floor][cur].second < lad[idx].b) {
                right.erase({dp[floor][cur].first + dp[floor][cur].second * x[floor], cur});
                left.insert({dp[floor][cur].first + (m - dp[floor][cur].second) * x[floor], cur});
                ++cur;
            }
            ll res = 1e18;
            if (!right.empty()) {
                int pos = right.begin()->second;
                ll temp = dp[floor][pos].first + std::abs(dp[floor][pos].second - lad[idx].b) * x[floor];
                res = temp;
            } 
            if (!left.empty()) {
                int pos = left.begin()->second;
                ll temp = dp[floor][pos].first + std::abs(dp[floor][pos].second - lad[idx].b) * x[floor];
                res = std::min(res, temp);
            }
            dp[lad[idx].c].push_back({res - lad[idx].h, lad[idx].d});
        }
    }
    if (dp[n].empty()) return false;
    else {
        ll ans = 1e18;
        for (auto it : dp[n]) {
            ans = std::min(ans, it.first + std::abs(it.second - m) * x[n]);
        }
        std::cout << ans << '\n';
        return true;
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
        std::cin >> n >> m >> k;
        vec.clear();
        vec.resize(n + 1);
        dp.clear();
        dp.resize(n + 1);
        for (int i = 1; i <= n; ++i) std::cin >> x[i];
        for (int i = 1; i <= k; ++i) {
            int a, b, c, d;
            ll h;
            std::cin >> a >> b >> c >> d >> h;
            lad[i] = {a, b, c, d, h};
            vec[a].push_back(i);
        }
        for (int i = 1; i <= n; ++i) {
            std::sort(all(vec[i]), cmp);
        }
        if (!solve()) std::cout << "NO ESCAPE\n";
    }

    return 0;
}