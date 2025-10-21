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
const int maxn = 1e6 + 5;
const ll mod = 998244353;
int trie[maxn][27];
int count;
int sum[maxn];
int n;
std::vector<std::string> s;
int rt;
std::vector<std::vector<int>> vec;
ll ans;
void update(int u, int dep, std::string& str) {
    sum[u] += 1;
    if (u) {
        for (auto it : vec[sum[u]]) {
            ans ^= sum[u] - it;
            ans ^= sum[u];
        }
    }
    if (dep == str.size()) return;
    int ch = str[dep] - 'a';
    if (!trie[rt][ch]) {
        trie[rt][ch] = ++count; 
    }
    update(trie[rt][ch], dep + 1, str);
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    vec.resize(1e6 + 1);
    for (int i = 1; i <= 1e6; ++i) {
        for (int j = i; j <= 1e6; j += i) {
            vec[j].push_back(i);
        }
    }
    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        s.clear();
        s.resize(n + 1);
        rt = 0;
        count = 0;
        for (int i = 0; i <= count; ++i) {
            for (int j = 0; j < 26; ++j) {
                trie[i][j] = 0;
            }
            sum[i] = 0;
        }
        ans = 0;
        for (int i = 1; i <= n; ++i) {
            std::cin >> s[i];
            update(rt, 0, s[i]);
            std::cout << ans << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}
