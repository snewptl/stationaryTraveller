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
const int maxn = 1e6 + 5;
const ll mod = 998244353;
int a[maxn];
std::vector<std::vector<int>> pos;
std::vector<std::vector<pii>> ques;
std::set<pii> s;
ll dp[maxn], delta, ans[maxn];
int n, q;
void del(pii p) {
    auto [id, x] = p;
    auto pre = s.upper_bound(p), nxt = pre;
    --pre;
    if (pre != s.begin()) {
        --pre;
        if(pre->second > x) delta -= pre->second - x;
        if (nxt != s.end()) {
            if (nxt->second < pre->second) {
                delta += pre->second - nxt->second;
            }
        }
    }
    if (nxt != s.end()) {
        if (nxt->second < x) delta -= x - nxt->second;
    }
}
void add(pii p) {
    auto [id, x] = p;
    auto pre = s.upper_bound(p), nxt = pre;
    if (pre != s.begin()) {
        --pre;
        if(pre->second > x) dp[x] += pre->second - x;
        if (nxt != s.end()) {
            if (nxt->second < pre->second) {
                dp[x] -= pre->second - nxt->second;
            }
        }
    }
    if (nxt != s.end()) {
        if (nxt->second < x) dp[x] += x - nxt->second;
    }
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> q;
    pos.resize(n + 1);
    ques.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        pos[a[i]].push_back(i);
    }
    s.insert({n + 1, 0});
    for (int i = 1; i <= n; ++i) {
        for (auto it : pos[i]) {
            add({it, i});
        }
    }
    for (int i = 1; i <= n; ++i) {
        dp[i] += dp[i - 1];
    }
    for (int i = 1; i <= q; ++i) {
        int l, r;
        ques[l].push_back({r, i});
    }
    for (int l = 1; l <= n; ++l) {
        for (auto [r, id] : ques[l]) {
            ans[id] = dp[r] + delta;
        }
        for (auto it : pos[l]) {
            del({it, l});
        }
    }


    return 0;
}
// 14 : 13 - 