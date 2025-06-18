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
const int maxn = 1e5 + 5;
const ll mod = 998244353;
int n, q;
struct tree_node {
    int count;
    char min_element;
}t[maxn << 2];
std::string s, new_s;
void push_up(int rt) {
    t[rt].count = t[rt << 1].count + t[rt << 1 | 1].count;
    t[rt].min_element = 'z';
    if (t[rt << 1].count) t[rt].min_element = std::min(t[rt].min_element, t[rt << 1].min_element);
    if (t[rt << 1 | 1].count) t[rt].min_element = std::min(t[rt].min_element, t[rt << 1 | 1].min_element);
}
void build(int rt, int l, int r) {
    int mid = (l + r) / 2;
    if (l == r) {
        t[rt].count = 1;
        t[rt].min_element = s[l - 1];
        return;
    }
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    push_up(rt);
}
void update(int rt, int l, int r, int tot) {
    int mid = (l + r) / 2;
    if (l == r) {
        assert(t[rt].count == 1);
        assert(tot == 1);
        t[rt].count = 0;
        t[rt].min_element = '#';
        return;
    }
    if (t[rt << 1].count >= tot) update(rt << 1, l, mid, tot);
    else {
        update(rt << 1 | 1, mid + 1, r, tot - t[rt << 1].count);
    }
    push_up(rt);
}
char get_min(int rt, int l, int r, int tot) {
    int mid = (l + r) / 2;
    if (l == r) {
        assert(t[rt].count == 1);
        assert(tot == 1);
        return t[rt].min_element;
    }
    if (t[rt << 1].count >= tot) return get_min(rt << 1, l, mid, tot);
    else {
        char res = get_min(rt << 1 | 1, mid + 1, r, tot - t[rt << 1].count);
        if (t[rt << 1].count) res = std::min(res, t[rt << 1].min_element);
        return res;
    }
}
int find(int i, char ch) {
    int l = 1, r = n - i, res = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (get_min(1, 1, n, mid) <= ch) res = mid, r = mid - 1;
        else l = mid + 1;
    }
    return res;
}
void solve() {
    ll ans = 1e18, cur = 0;
    for (int i = 0; i < n; ++i) {
        if (new_s[i] != 'a') {
            int min_coast = find(i, new_s[i] - 1);
            if (min_coast) 
                ans = std::min(ans, cur + min_coast - 1);
        }
        int min_coast = find(i, new_s[i]);
        if (!min_coast) {
            std::cout << (ans == 1e18 ? -1 : ans) << '\n';
            return;
        }
        cur += min_coast - 1;
        update(1, 1, n, min_coast);
    }
    std::cout << (ans == 1e18 ? -1 : ans) << '\n';
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; std::cin >> T;
    while (T--) {
        std::cin >> n >> s >> new_s;
        build(1, 1, n);
        solve();
    }

    return 0;
}
// 13:45