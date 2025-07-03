#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <bitset>
#include <memory.h>
#include <assert.h>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 1e6 + 5;
const ll mod = 998244353;
int n, k, q;
std::string s;
int pos[26];
int next[maxn][26];
int dis[maxn];
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> k >> s;
    for (int i = 0; i < k; ++i) pos[i] = n, next[n][i] = n;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < k; ++j) {
            next[i][j] = pos[j];
        }
        pos[s[i] - 'a'] = i;
    }
    for (int i = n - 1; i >= 0; --i) {
        int max = 0;
        for (int j = 0; j < k; ++j) {
            max = std::max(next[i][j], max);
        }
        if (max >= n) dis[i] = 1;
        else dis[i] = dis[max] + 1;
    }
    std::cin >> q;
    for (int i = 1; i <= q; ++i) {
        std::string t;
        std::cin >> t;
        int len = t.size();
        int cur = pos[t[0] - 'a'];
        for (int j = 1; j < len; ++j) {
            cur = next[cur][t[j] - 'a'];
        }
        if (cur == n) {
            std::cout << "0\n";
            continue;
        }
        std::cout << dis[cur] << '\n';
    }

    return 0;
}
