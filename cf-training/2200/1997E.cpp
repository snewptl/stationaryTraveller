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
int a[maxn];
int fw[maxn];
int ans[maxn];
std::vector<pii> questions[maxn];
std::set<int> s[maxn];
int end_points[maxn];
int lowbit(int x) {
    return x & (-x);
}
void update(int p, int x) {
    for (int i = p; i <= n; i += lowbit(i)) {
        fw[i] += x;
    }
}
int query(int p) {
    int res = 0;
    for (int i = p; i; i -= lowbit(i)) {
       res += fw[i]; 
    }
    return res;
}
int min_pos(int K, int cur, int start) {
    int l = start, r = n;
    int res = n + 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (query(mid) - query(start - 1) >= K) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return res;
}
void remove_all(int cur, int start) {
    while (!s[cur].empty()) {
        auto it = s[cur].lower_bound(start);
        if (it != s[cur].end()) {
            update(*it, -1);
            s[cur].erase(it);
        } else {
            break;
        }
    }
}
void solve() {
    for (int i = 1; i <= 2e5; ++i) end_points[i] = n + 1;
    for (int K = n; K >= 1; --K) {
        int cur = 1;
        for (int j = 1; ; ++j) {
            end_points[j] = min_pos(K, j, cur); // end_point
            if (end_points[j] >= n) break;
            remove_all(j, end_points[j] + 1);;
            cur = end_points[j] + 1;
            
        }
        for (auto it : questions[K]) {
            if (it.second <= end_points[a[it.second]]) ans[it.first] = 1;
            else ans[it.first] = 0;
        }
    }
    for (int i = 1; i <= q; ++i) {
        std::cout << (ans[i] ? ("YES") : ("NO")) << '\n';
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
    // std::cin >> T;
    while (T--) {
        std::cin >> n >> q;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
            update(i, 1);
            s[a[i]].insert(i);
        }
        for (int i = 1; i <= q; ++i) {
            int x1, x2;
            std::cin >> x1 >> x2;
            questions[x2].push_back({i, x1});
        }
        solve();

    }

    return 0;
}
