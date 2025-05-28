#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 2e5 + 5;
int n, q;
std::string temp_str;
std::vector<char> str;
std::set<int> s[2];
int val[maxn];
namespace T {
    struct TreeNode {
        int lazy, min;
    };
    TreeNode t[maxn << 2];

    void push_up(int rt) {
        t[rt].min = std::min(t[rt << 1].min, t[rt << 1 | 1].min);
        t[rt].lazy = 0;
    }

    void build(int rt, int l, int r) {
        if (l == r) {
            t[rt].min = val[l];
            t[rt].lazy = 0;
            return;
        }
        int mid = (l + r) >> 1;
        build(rt << 1, l, mid);
        build(rt << 1 | 1, mid + 1, r);
        push_up(rt);
    }

    void push_down(int rt) {
        t[rt << 1].lazy += t[rt].lazy;
        t[rt << 1].min += t[rt].lazy;
        t[rt << 1 | 1].lazy += t[rt].lazy;
        t[rt << 1 | 1].min += t[rt].lazy;
        t[rt].lazy = 0;
    }

    int query(int rt, int l, int r, int xl, int xr) {
        if (xl == l && xr == r) {
            return t[rt].min;
        }
        if (t[rt].lazy) push_down(rt);
        int mid = l + r >> 1;
        int res = 1e9;
        if (mid >= xl) {
            res = std::min(res, query(rt << 1, l, mid, xl, std::min(xr, mid)));
        } 
        if (mid < xr) {
            res = std::min(res, query(rt << 1 | 1, mid + 1, r, std::max(mid + 1, xl), xr));
        }
        return res;
    }

    void update(int rt, int l, int r, int xl, int xr, int delta) {
        if (xl == l && xr == r) {
            t[rt].lazy += delta;
            t[rt].min += delta;
            return;
        }
        if (t[rt].lazy) push_down(rt);
        int mid = l + r >> 1;
        if (mid >= xl) {
            update(rt << 1, l, mid, xl, std::min(xr, mid), delta);
        } 
        if (mid < xr) {
            update(rt << 1 | 1, mid + 1, r, std::max(mid + 1, xl), xr, delta);
        }
        push_up(rt);
    }
}

bool solve() {
    if (str[1] == ')') return false;
    if (val[n] % 2) return false;
    if (!s[1].empty()) {
        if (s[0].empty()) return false;
        if (*s[0].begin() > *s[1].begin()) return false;
    }
    int pos = 1;
    if (!s[1].empty()) pos = *(--s[1].end());
    int all_min = T::query(1, 1, n, pos, n);
    int last = T::query(1, 1, n, n, n);
    if (last != all_min) return false;
    return true;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    // std::cin >> T;
    while (T--) {
        std::cin >> n >> q >> temp_str;
        str.resize(n + 1);
        for (int i = n; i >= 1; --i) str[i] = temp_str[i - 1];
        for (int i = 1; i <= n; ++i) {
            if (i > 1) val[i] = val[i - 1];
            if (str[i] == '(') val[i] += 1;
            else val[i] -= 1;
            if (i > 1 && str[i] == str[i - 1]) {
                if (str[i] == '(') {
                    s[0].insert(i);
                } else {
                    s[1].insert(i);
                }
            }
        }
        
        T::build(1, 1, n);
        for (int t = 1; t <= q; ++t) {
            int i;
            std::cin >> i;
            if (str[i] == '(') {
                T::update(1, 1, n, i, n, -2);
                s[0].erase(i);
                s[0].erase(i + 1);
                str[i] = ')';
                if (i > 1 && str[i - 1] == str[i]) s[1].insert(i);
                if (i < n && str[i + 1] == str[i]) s[1].insert(i + 1);
            } else {
                T::update(1, 1, n, i, n, 2);
                s[1].erase(i);
                s[1].erase(i + 1);
                str[i] = '(';
                if (i > 1 && str[i - 1] == str[i]) s[0].insert(i);
                if (i < n && str[i + 1] == str[i]) s[0].insert(i + 1);
            }
            if (solve()) std::cout << "YES\n";
            else std::cout << "NO\n";
        }
    }

    return 0;
}

