#include<cstdio>
#include<algorithm>
#include<iostream>
#include<set>
typedef long long ll;
typedef std::pair<int, int> pii;
const int maxn = 2e5 + 5;
int n, m;
ll a[maxn], b[maxn];
int pre[maxn], nxt[maxn];
int last[maxn];
int main() {
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        last[i] = 0;
    }
    for (int i = 1; i <= m; ++i) {
        nxt[i] = pre[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 1; i <= m; ++i) {
        std::cin >> b[i];
        pre[i] = last[b[i]];
        nxt[last[b[i]]] = i;
        last[b[i]] = i;
    }
    ll ans = 0;
    ll sum = 0;
    std::set<pii> le, ri;
    for (int i = 1; i <= m; ++i) {
        if (!pre[i]) {
            ans += sum;
            sum += a[b[i]];
        }
        while (ri.begin()->first <= i) {
            auto [y, x] = *ri.begin();
            ri.erase(ri.begin());
            le.erase({x, y});
        }
        if (pre[i]) {
            auto it = le.lower_bound({pre[i] + 1, 0});
            ans += (ll)s.size() * a[b[i]];
        }

        if (nxt[i]) {
            s.insert(nxt[i]);
        }
    }
    std::cout << ans << '\n';

}