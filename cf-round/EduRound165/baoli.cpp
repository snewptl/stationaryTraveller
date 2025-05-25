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
std::vector<std::vector<int>>vec;
void dfs(int index, int len, std::vector<int> cur) {
    if (index > len) {
        vec.push_back(cur);
        return;
    }
    for (int i = 1; i <= std::min(len, 3); ++i) {
        cur.push_back(i);
        dfs(index + 1, len, cur);
        cur.pop_back();
    }
}
int main() {
    #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    freopen("input.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    while (T--) {
        for (int i = 1; i <= 10; ++i) {
            dfs(1, i, std::vector<int>());
        }
        std::cout << 1180 << '\n';
        for (int i = 0; i < 1180; ++i) {
            std::cout << vec[i].size() << '\n';
            for (int j = 0; j < vec[i].size(); ++j) {
                std::cout << vec[i][j] << ' ';
            }
            std::cout << '\n';
        }
    }

    return 0;
}
