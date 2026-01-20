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
const ll mod = 1e9 + 7;
std::set<int> s;
std::map<int, pll> mp;
int n;
pii doll[maxn];
struct tree {
    int min, max, empty;
    ll count;
}t[maxn << 2];
std::pair<int, ll> merge(std::pair<int, ll> x, std::pair<int, ll> y) {
    if (x.first < y.first) {
        return x;
    } else if (x.first > y.first) {
        return y;
    } else {
        return {x.first, (x.second + y.second) % mod};
    }
}
void push_up(int rt) {
    t[rt].min = std::min(t[rt << 1].min, t[rt << 1 | 1].min);
    t[rt].max = std::max(t[rt << 1].max, t[rt << 1 | 1].max);
    t[rt].empty = std::min(t[rt << 1].empty, t[rt << 1 | 1].empty);
    if (t[rt << 1].empty < t[rt << 1 | 1].empty) {
        t[rt].count = t[rt << 1].count;
    } else if (t[rt << 1].empty > t[rt << 1 | 1].empty) {
        t[rt].count = t[rt << 1 | 1].count;
    } else {
        t[rt].count = t[rt << 1].count + t[rt << 1 | 1].count;
        t[rt].count %= mod;
    }
}
void build(int rt, int l, int r) {
    if (l == r) {
        t[rt].min = t[rt].max = doll[l].second;
        t[rt].empty = doll[l].first - doll[l].second;
        t[rt].count = 1;    
        return;
    }
    int mid = (l + r) / 2;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    push_up(rt);
}
std::pair<int, ll> query(int rt, int l, int r, int in) {
    if (t[rt].min > in) {
        return {-1, 0};
    }
    if (l == r) {
        return {t[rt].empty + in, t[rt].count};
    }
    if (t[rt].max <= in) {
        return {t[rt].empty + in, t[rt].count};
    }
    int mid = (l + r) / 2;
    auto res1 = query(rt << 1, l, mid, in);
    auto res2 = query(rt << 1 | 1, mid + 1, r, in);
    if (res2.second == 0) return res1;
    else return merge(res1, res2);
}
void update(int rt, int l, int r, int pos, int empty, ll count) {
    if (l == r) {
        t[rt].empty = empty;
        t[rt].count = count;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) update(rt << 1, l, mid, pos, empty, count);
    else update(rt << 1 | 1, mid + 1, r, pos, empty, count);
    push_up(rt);
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    // std::cin >> T;
    while (T--) {
        std::cin >> n;
        for (int i = 1; i <= n; ++i) {
            std::cin >> doll[i].second >> doll[i].first;
        }
        s.clear();
        mp.clear();
        std::sort(doll + 1, doll + n + 1);
        build(1, 1, n);
        std::pair<int, ll> ans = {1e9, 0};
        for (int i = 1; i <= n; ++i) {
            auto [in, out] = doll[i];
            auto [empty, count] = query(1, 1, n, in);
            if (count) update(1, 1, n, i, empty - out, count);
            else {
                empty = in;
                count = 1;
            }
            if (out > doll[n].first) {
                if (empty < ans.first) {
                    ans = {empty, count};
                } else if (empty == ans.first) {
                    ans.second += count;
                }
            } 
        }

        std::cout << ans.second << '\n';
    }

    return 0;
}
// 21 : 36 - 22 : 34 