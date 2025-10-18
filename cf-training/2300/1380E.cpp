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
int n, m;
std::vector<std::vector<int>> vec;
std::set<pii, std::greater<pii>> s;
std::vector<std::set<pii>> seg;
int val[maxn], piece[maxn];
pii top[maxn];
ll sum;
int loc[maxn];
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m;
    vec.clear();
    vec.resize(m + 1);
    s.clear();
    seg.clear();
    seg.resize(m + 1);
    sum = 0;
    for (int i = 1; i <= m; ++i) {
        top[i] = {0, 0};
        piece[i] = 0;
        val[i] = 0;
        loc[i] = i;
    }
    for (int i = 1; i <= n; ++i) {
        int x; std::cin >> x;
        vec[x].push_back(i);
        top[x] = {i, x};
    }
    std::sort(top + 1, top + m + 1);
    std::reverse(top + 1, top + m + 1);
    for (int i = 1; i <= m; ++i) {
        int real_i = top[i].second;
        if (vec[real_i].empty()) break;
        int last = -1, count = 0;
        pii cur = {-1, -1};
        for (auto it : vec[real_i]) {
            if (last != it - 1) {
                if (last != -1) {
                    seg[i].insert(cur);
                }
                last = it;
                ++count;
                cur = {it, it};
            } else {
                cur.second = it;
            }
        }
        seg[i].insert(cur);
        piece[real_i] = count;
        val[real_i] = count * 2 + i;
        s.insert({val[real_i], real_i});
        sum += count;
    }
    std::cout << sum * 2 + 1 - s.begin()->first << '\n';
    for (int i = 1; i < m; ++i) {
        int a, b;
        std::cin >> a >> b;
        s.erase({val[a], a});
        s.erase({val[b], b});
        int from = loc[a], to = loc[b];
        if (seg[from].size() > seg[to].size()) std::swap(from, to);
        int count = piece[a] + piece[b];
        for (auto cur : seg[from]) {
            
            auto it = seg[to].lower_bound(cur);
            if (it != seg[to].begin()) {
                --it;
                if (it->second == cur.first - 1) count -= 1;
                ++it;
            }
            if (it != seg[to].end()) {
                if (it->first == cur.second + 1) count -= 1;
            }
        }
        for (auto cur : seg[from]) {
            seg[to].insert(cur);
        }
        piece[a] = count;
        loc[a] = to;
        val[a] = count * 2 
        s.insert({});
    }
    

    return 0;
}
// 20 : 03 - 