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
const int maxn = 1e4 + 5;
const ll mod = 998244353;
int n, m;
int x[maxn];
int a[11][maxn];
int vis[11];
int count[maxn];
int ans, res[maxn], final[maxn];
bool cmp(pii x, pii y) {
    return x.first > y.first;
}
void solve() {
    int temp = 0;
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) temp -= x[i];
        else temp += x[i];
    }
    for (int i = 1; i <= m; ++i) count[i] = 0;
    std::vector<pii> pos, neg;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (!a[i][j]) continue;
            if (!vis[i]) --count[j];
            else ++count[j];
        }
    }
    for (int i = 1; i <= m; ++i) {
        if (count[i] >= 0) pos.push_back({count[i], i});
        else neg.push_back({-count[i], i});
    }
    std::sort(all(pos), cmp);
    std::sort(all(neg));
    int sz = neg.size();
    for (int i = m, cur = 0; i >= sz + 1; --i, ++cur) {
        res[pos[cur].second] = i;
        temp += i * pos[cur].first;
    }
    for (int i = sz, cur = 0; i >= 1; --i, ++cur) {
        res[neg[cur].second] = i;
        temp -= i * neg[cur].first;
    }
    if (ans < temp) {
        ans = temp;
        for (int i = 1; i <= m; ++i) final[i] = res[i];
    }
}
void dfs(int idx) {
    if (idx == n + 1) {
        solve();
        return;
    }
    vis[idx] = 0;
    dfs(idx + 1);
    vis[idx] = 1;
    dfs(idx + 1);
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
        std::cin >> n >> m;
        ans = -1;
        for (int i = 1; i <= n; ++i) std::cin >> x[i];
        for (int i = 1; i <= n; ++i) {
            std::string str;
            std::cin >> str;
            for (int j = 0; j < m; ++j) {
                a[i][j + 1] = str[j] - '0'; 
            }
        }
        dfs(1);
        for (int i = 1; i <= m; ++i) std::cout << final[i] << ' ';
        std::cout << '\n';
    }

    return 0;
}

// 9 : 37