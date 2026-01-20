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
const int maxn = 2e5 + 10;
const ll mod = 998244353;
std::set<pii> seg;
std::vector<std::vector<int>> e;
std::map<pii, int> mp;
pii inv[maxn];
int dep[maxn];
int left[maxn];
int node_count;
int n;
std::string s;
bool unfin;
void dfs(int u) {
    for (auto v : e[u]) {
        dep[v] = dep[u] + 1;
        dfs(v);
        if (left[u] == 1) left[u] = left[v] + 1;
    }
}
void solve(int u) {
    for (auto v : e[u]) {
        solve(v);
    }
    if (left[u] + dep[u] - 1 > left[node_count] && unfin) {
        std::cout <<  n - (inv[u].first - dep[u]) - 2 << '\n';
        unfin = 0;
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
        std::cin >> n >> s;
        n += 2;
        s = "(" + s + ")";
        seg.clear();
        e.clear();
        e.resize(n + 1);
        mp.clear();
        node_count = 0;
        unfin = 1;
        for (int i = 1; i <= n; ++i) {
            dep[i] = 0;
            left[i] = 1;
        }
        std::vector<int> vec;
        for (int i = 1; i <= n; ++i) {
            if (s[i - 1] == '(') {
                vec.push_back(i);
            } else { 
                int le = vec.back();
                pii cur = {le, i};
                mp[cur] = ++node_count;
                inv[node_count] = cur;
                vec.pop_back();
                auto it = seg.lower_bound({le, 0});
                while (it != seg.end() && it->second < i) {
                    e[node_count].push_back(mp[*it]);
                    seg.erase(it);
                    it = seg.lower_bound({le, 0});
                }
                seg.insert(cur);
            }
        }
        dep[node_count] = 1;
        dfs(node_count);
        solve(node_count);
        if (unfin) std::cout << "-1\n";
    }

    return 0;
}