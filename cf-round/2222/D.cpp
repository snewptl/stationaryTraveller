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
int a[maxn];
int p[maxn];
namespace cnt {
    int t[maxn << 2];
    void push_up(int rt) {
        t[rt] = t[rt << 1] + t[rt << 1 | 1];
    }
    void build(int rt, int l, int r) {
        int mid = (l + r) / 2;
        if (l == r) {
            t[rt] = 1;
            return;
        }
        build(rt << 1, l, mid);
        build(rt << 1 | 1, mid + 1, r);
        push_up(rt);
    }
    void update(int rt, int l, int r, int xp) {
        int mid = (l + r) / 2;
        if (l == r) {
            t[rt] = 0;
            return;
        }
        if (xp <= mid) update(rt << 1, l, mid, xp);
        else update(rt << 1 | 1, mid + 1, r, xp);
        push_up(rt);
    } 
    int query(int rt, int l, int r, int x) {
        int mid = (l + r) / 2;
        if (l == r) {
            return l;
        }
        if (t[rt << 1 | 1] < x + 1) return query(rt << 1, l, mid, x - t[rt << 1 | 1]);
        else return query(rt << 1 | 1, mid + 1, r, x);
    }
}
namespace vec {
    std::vector<ll> vec;
    struct tree {
        ll max;
        int val;
    } t[maxn << 2];
    void push_up(int rt) {
        t[rt].val = t[rt << 1].val + t[rt << 1 | 1].val;
        t[rt].max = std::max(t[rt << 1].max, t[rt << 1 | 1].max);
    }
    void build(int rt, int l, int r) {
        int mid = (l + r) / 2;
        if (l == r) {
            t[rt].val = 1;
            t[rt].max = vec[l - 1];
            return;
        }
        build(rt << 1, l, mid);
        build(rt << 1 | 1, mid + 1, r);
        push_up(rt);
    }
    void update(int rt, int l, int r, ll x) {
        int mid = (l + r) / 2;
        if (l == r) {
            t[rt].val = 0;
            t[rt].max = -1e18;
            return;
        }
        if (t[rt << 1].max >= x && t[rt << 1].val) update(rt << 1, l, mid, x);
        else update(rt << 1 | 1, mid + 1, r, x);
        push_up(rt);
    } 
    int query(int rt, int l, int r, ll x) {
        int mid = (l + r) / 2;
        if (l == r) {
            if (t[rt].max >= x) return t[rt].val;
            else return 0;
        }
        if (t[rt << 1].max >= x) return query(rt << 1, l, mid, x) + t[rt << 1 | 1].val;
        else return query(rt << 1 | 1, mid + 1, r, x);
    }
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
        }
        if (n == 1) {
            std::cout << "1\n";
        } else {
            cnt::build(1, 1, n);
            vec::vec.clear();
            ll sum = 0;
            for (int i = n - 1; i >= 1; --i) {
                sum += a[i];
                vec::vec.push_back(sum);
            }
            std::sort(all(vec::vec));
            vec::build(1, 1, n - 1);
            ll cur = 0;
            for (int i = n - 1; i >= 1; --i) {
                int res = vec::query(1, 1, n - 1, cur);
                p[i + 1] = cnt::query(1, 1, n, res);
                cnt::update(1, 1, n, p[i + 1]);
                cur += a[i];
                vec::update(1, 1, n - 1, cur);
            }
            p[1] = cnt::query(1, 1, n, 0);
            for (int i = 1; i <= n; ++i) {
                std::cout << p[i] << ' ';
            }
            std::cout << '\n';
        }
    }

    return 0;
}
