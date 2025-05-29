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
int n, k;
int a[maxn];
std::vector<std::vector<int>> vec;
int vis[maxn];
void solve() {
    ll ans = 1ll * (k / 2) * (n - k + 1);
    for (int i = 1; i <= n; ++i) {
        int head[2] = {0, 0};
        int tail[2] = {0, 0};
        std::vector<int> seq[2];
        std::queue<int> q;
        for (auto cur : vec[i]) {
            while(!q.empty() && cur - q.front() + 1 > k) {
                int p = q.front();
                ++head[p % 2];
                q.pop();
            }
            int sgn = cur % 2;
            if (head[sgn] != tail[sgn]) {
                ans -= std::upper_bound(seq[sgn].begin() + head[sgn], seq[sgn].begin() + tail[sgn], (n - k / 2) - (cur - (n - k / 2))) - std::lower_bound(seq[sgn].begin() + head[sgn], seq[sgn].begin() + tail[sgn], k + 1 - cur);
            }
            q.push(cur);
            seq[sgn].push_back(cur);
            ++tail[sgn];
        }
    }
    std::cout << ans << '\n';
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
        std::cin >> n >> k;
        vec.resize(n + 1);
        int count = 0;
        for (int i = 1; i <= n; ++i) {
            int x; std::cin >> x;
            if (!vis[x]) vis[x] = ++count;
            vec[vis[x]].push_back(i);
        }
        solve();
    }

    return 0;
}
