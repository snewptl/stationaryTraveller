#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#define all(x) x.begin(), x.end()
typedef int64_t ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 2e5 + 5;
int k, n;
std::vector<int> distanceDiff;
std::vector<int> edge[maxn];
int depth[maxn], deepestLeaf[maxn];
ll total;
void dfs(int u) {
    deepestLeaf[u] = depth[u];
    std::vector<int> vec;
    for (auto v : edge[u]) {
        depth[v] = depth[u] + 1;
        dfs(v);
        deepestLeaf[u] = std::max(deepestLeaf[u], deepestLeaf[v]);
        vec.push_back(deepestLeaf[v]);
    }
    sort(all(vec));
    // vec.size()是无符号的，如果vec为空，减1会溢出
    for (int i = 0 ; i < (int)vec.size() - 1; ++i) {
        total += vec[i] - depth[u];
        distanceDiff.push_back(std::max(0, vec[i] - depth[u] * 2));
    }
}
bool cmp(int x, int y) {
    return x > y;
}
int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    // std::cin >> T; 
    while (T--) {
        std::cin >> n >> k;
        for (int i = 2; i <= n; ++i) {
            int j;
            std::cin >> j;
            edge[j].push_back(i);
        }
        dfs(1);
        sort(distanceDiff.begin(), distanceDiff.end(), cmp);
        for (int i = 0; i < std::min(k, (int)distanceDiff.size()); ++i)
            total -= distanceDiff[i];
        std::cout << total + n - 1 << '\n';
    }

    return 0;
}
