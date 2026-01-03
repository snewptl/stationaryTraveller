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
std::vector<std::vector<int>> col, row;
pii lim_row, lim_col;
std::map<pii, int> mp;
bool check(pii left, pii right) {
    for (int i = left.first; i <= right.first; ++i) {
        for (int j = left.second; j <= right.second; ++j) {
            if (!mp.count({i, j})) return false;
        }
    }
    return true;
}
bool should_break() {
    return lim_row.first > lim_row.second || lim_col.first > lim_col.second;
}
bool solve() {
    while(lim_row.first <= lim_row.second && lim_col.first <= lim_col.second) {
        auto &vec = row[lim_row.first];
        auto it = std::lower_bound(all(vec), lim_col.first);
        if (it != vec.end() && *it <= lim_col.second) {
            if (!check({lim_row.first, *it}, {lim_row.second, lim_col.second})) return false;
            lim_col.second = *it - 1;
        }
        lim_row.first += 1;
        if (should_break()) break;
        vec = col[lim_col.second];
        it = std::lower_bound(all(vec), lim_row.first);
        if (it != vec.end() && *it <= lim_row.second) {
            if (!check({*it, lim_col.first}, {lim_row.second, lim_col.second})) return false;
            lim_row.second = *it - 1;
        }
        lim_col.second -= 1;
        if (should_break()) break;
        vec = row[lim_row.second];
        it = std::upper_bound(all(vec), lim_col.second);
        if (it != vec.begin() && *(--it) >= lim_col.first) {
            if (!check({lim_row.first, lim_col.first}, {lim_row.second, *it})) return false;
            lim_col.first = *it + 1;
        }
        lim_row.second -= 1;
        if (should_break()) break;
        vec = col[lim_col.first];
        it = std::upper_bound(all(vec), lim_row.second);
        if (it != vec.begin() && *(--it) >= lim_row.first) {
            if (!check({lim_row.first, lim_col.first}, {*it, lim_col.second})) return false;
            lim_row.first = *it + 1;
        }
        lim_col.first += 1;
    }
    return true;
    
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::cin >> n >> m >> k;
    row.clear();
    col.clear();
    row.resize(n + 1);
    col.resize(m + 1);
    lim_row = {1, n};
    lim_col = {1, m}; 
    mp.clear();
    for (int i = 1; i <= k; ++i) {
        int x, y; 
        std::cin >> x >> y;
        row[x].push_back(y);
        col[y].push_back(x);
        mp[{x, y}] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        std::sort(all(row[i]));
    }
    for (int i = 1; i <= m; ++i) {
        std::sort(all(col[i]));
    }
    if (solve()) std::cout << "Yes\n";
    else std::cout << "No\n";

    return 0;
}
// 19 : 20 - 20 : 37