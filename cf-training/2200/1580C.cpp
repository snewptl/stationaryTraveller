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
const int maxn = 2e5 + 5;
const int sub = 500;
const ll mod = 998244353;
int n, m;
pii train[maxn];
ll len[maxn];
int prefix[maxn];
int small[sub][sub];
int last_pos[maxn];
bool is_small(int idx) {
    return len[idx] < sub;
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int x, y;
        std::cin >> x >> y;
        train[i] = {x, y};
        len[i] = train[i].first + train[i].second;
    }
    for (int day = 1; day <= m; ++day) {
        int opt, idx;
        std::cin >> opt >> idx;
        int cur = 0;
        if (is_small(idx)) {
            if (opt == 1) last_pos[idx] = day;
            int start = (last_pos[idx] + train[idx].first) % len[idx], end = last_pos[idx] % len[idx];
            for (int j = start; j != end; j = (j + 1) % len[idx]) {
                small[len[idx]][j] += (opt == 1 ? 1 : -1);
            }
        } else {
            if (opt == 1) {
                last_pos[idx] = day;
                for (int j = day + train[idx].first; j <= m; j += len[idx]) {
                    prefix[j] += 1;
                    prefix[std::min(j + train[idx].second, m + 1)] -= 1;
                }
            } else {
                for (int j = last_pos[idx] + train[idx].first; j <= m; j += len[idx]) {
                    if (j + train[idx].second <= day) continue;
                    if (j < day) {
                        prefix[day] -= 1;
                        prefix[std::min(j + train[idx].second, m + 1)] += 1;
                    } else {
                        prefix[j] -= 1;
                        prefix[std::min(j + train[idx].second, m + 1)] += 1; 
                    }
                }
            }
        }
        for (int j = 1; j < sub; ++j) {
            cur += small[j][day % j];
        }
        prefix[day] += prefix[day - 1];
        cur += prefix[day];
        std::cout << cur << '\n';
    }
    

    return 0;
}
