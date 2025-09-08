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
int n, m, k;
std::map<std::string, int> mp;
std::string p[maxn], s[maxn];
int mt[maxn];
std::vector<std::vector<int>> e;
int count, in[maxn];
void dfs(std::string str, int cur, int id) {
    if (cur == k) {
        if (mp.count(str)) {
            if (mt[id] == mp[str]) ++count;
            else e[mt[id]].push_back(mp[str]), in[mp[str]] += 1;
        }
        return;
    }
    str += '_';
    dfs(str, cur + 1, id);
    str[cur] = s[id][cur];
    dfs(str, cur + 1, id);
}
void bfs() {
    std::queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (in[i] == 0) q.push(i); 
    }
    std::vector<int> vec;
    while (!q.empty()) {
        int p = q.front(); q.pop();
        vec.push_back(p);
        for (auto v : e[p]) {
            in[v] -= 1;
            if (!in[v]) {
                q.push(v);
            }
        }
    }
    if (vec.size() == n && count == m) {
        std::cout << "YES\n";
        for (auto it : vec) std::cout << it << ' ';
        std::cout << '\n';
    } else {
        std::cout << "NO\n";
    }
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        std::cin >> p[i];
        mp[p[i]] = i;
    }
    e.resize(n + 1);
    for (int i = 1; i <= m; ++i) {
        std::cin >> s[i] >> mt[i];
        std::string str;
        dfs(str, 0, i);
    }
    bfs();
    return 0;
}
// 17 : 08 - 17 : 39