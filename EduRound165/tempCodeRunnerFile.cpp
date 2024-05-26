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
const int maxn = 3e5 + 5;
int n, a[maxn];
int pre[maxn], nxt[maxn];
int minLeft[maxn];
std::map<int, int> mp;
namespace Tree {
    int t[maxn << 2];
    void merge(int rt, int l, int r) {
        int mid = l + r >> 1;
        t[rt] = t[rt << 1 | 1];
        if (t[rt]) return;

        std::set<int> s;
        for (int i = mid + 1; i <= r; ++i) {
            if (pre[i] <= mid) {
                s.insert(pre[i]);
            } else {
                if (s.count(pre[pre[i]])) {
                    s.erase(pre[pre[i]]);
                }
            }
            minLeft[i] = *s.begin();
        }
        for (int i = r - 1; i > mid; --i) {
            minLeft[i] = std::max(minLeft[i], minLeft[i + 1]);
        }
    
        std::set<int, std::greater<int>> greaterS;
        for (int i = mid; i >= l; --i) {
            if (nxt[i] > mid) {
                greaterS.insert(nxt[i]);
            } else {
                if (greaterS.count(nxt[nxt[i]])) {
                    greaterS.erase(nxt[nxt[i]]);
                }
            }
            if (!greaterS.empty()) {
                int cur = *greaterS.begin();
                if (cur <= r && minLeft[cur] >= i) {
                    t[rt] = std::max(t[rt << 1], i);
                    return;
                } 
            }
        }
        t[rt] = t[rt << 1];
    }
    void build(int rt, int l, int r) {
        int mid = l + r >> 1;
        if (l == r) {
            t[rt] = 0;
            return;
        }
        build(rt << 1, l, mid);
        build(rt << 1 | 1, mid + 1, r);
        merge(rt, l, r);
    }
    void modify(int rt, int l, int r, int x) {
        int mid = l + r >> 1;
        if (l == r) {
            int oldPre = pre[l];
            int oldNxt = nxt[l];
            if (oldPre) {
                nxt[oldPre] = oldNxt;
            }
            if (oldNxt != n + 1) {
                pre[oldNxt] = oldPre;
            }
            pre[l] = 0;
            nxt[l] = n + 1;
            return; 
        }
        if (x <= mid) modify(rt << 1, l, mid, x);
        else modify(rt << 1 | 1, mid + 1, r, x);
        merge(rt, l, r);
    }
};
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
        std::cin >> n;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
        }
        mp.clear();
        for (int i = 1; i <= n; ++i) {
            pre[i] = mp[a[i]];
            mp[a[i]] = i;
        }
        mp.clear();
        for (int i = n; i >= 1; --i) {
            if (mp.count(a[i])) {
                nxt[i] = mp[a[i]];
            } else {
                nxt[i] = n + 1;
            }
            mp[a[i]] = i;
        }
        int ans = 0;
        Tree::build(1, 1, n);
        while(Tree::t[1]) {
            Tree::modify(1, 1, n, Tree::t[1]);
            ++ans;
        }
        std::cout << ans << '\n';
    }

    return 0;
}
/*
1
4
27
256
120
*/