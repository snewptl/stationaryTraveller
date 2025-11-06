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
int n, a[maxn];
std::vector<std::pair<int, pii>> vec_le[maxn], vec_ri[maxn];
std::vector<int> e_le[maxn], e_ri[maxn];
int ans;
void solve() {
    for (int i = 1; i <= n; ++i) {
        vec_le[i].clear();
        e_le[i].clear();
    }
    for (int i = 1; i <= n; ++i) {
        vec_ri[i].clear();
        e_ri[i].clear();
    }
    std::set<pii> s_le;
    std::set<std::pair<int, pii>, std::greater<std::pair<int, pii>>> fin;
    std::set<pii, std::greater<pii>> s_ri;
    for (int i = n; i >= 1; --i) {
        while (s_le.size() > 3) s_le.erase(s_le.begin());
        for (auto it : s_le) {
            auto [val, j] = it;
            vec_le[i].push_back({val - a[i], {i, j}});
        }
        std::sort(all(vec_le[i]));
        if (!vec_le[i].empty()) {
            e_le[vec_le[i].back().second.second].push_back(i);
            vec_le[i].pop_back();
        }
        if (!vec_le[i].empty()) {
            e_le[vec_le[i].back().second.second].push_back(i);
            fin.insert(vec_le[i].back());
        }
        s_le.insert({a[i], i});
    }
    for (int i = 1; i <= n; ++i) {
        while (s_ri.size() > 3) s_ri.erase(s_ri.begin());
        for (auto it : s_ri) {
            auto [val, j] = it;
            vec_ri[i].push_back({a[i] - val, {i, j}});
        }
        std::sort(all(vec_ri[i]));
        if (!vec_ri[i].empty()) {
            e_ri[vec_ri[i].back().second.second].push_back(i);
            vec_ri[i].pop_back();
        }
        if (!vec_ri[i].empty()) {
            fin.insert(vec_ri[i].back());
            e_ri[vec_ri[i].back().second.second].push_back(i);
        }
        s_ri.insert({a[i], i});
    }

    for (int i = 1; i <= n; ++i) {
        for (auto j : e_le[i]) {
            if (vec_le[j].size()) fin.erase(vec_le[j].back());
            if (vec_le[j].size() >= 2) {
                auto it =  vec_le[j].end();
                --it;
                --it;
                fin.insert(*it);
            } 
        }
        for (auto j : e_ri[i]) {
            if (vec_ri[j].size()) fin.erase(vec_ri[j].back());
            if (vec_ri[j].size() >= 2) {
                auto it =  vec_ri[j].end();
                --it;
                --it;
                fin.insert(*it);
            } 
        }
        if (!vec_le[i].empty()) fin.erase(vec_le[i].back());
        if (!vec_ri[i].empty()) fin.erase(vec_ri[i].back());
        ans = std::min(ans, fin.begin()->first);
        for (auto j : e_le[i]) {
            if (vec_le[j].size()) fin.insert(vec_le[j].back());
            if (vec_le[j].size() >= 2) {
                auto it =  vec_le[j].end();
                --it;
                --it;
                fin.erase(*it);
            } 
        }    
        for (auto j : e_ri[i]) {
            if (vec_ri[j].size()) fin.insert(vec_ri[j].back());
            if (vec_ri[j].size() >= 2) {
                auto it =  vec_ri[j].end();
                --it;
                --it;
                fin.erase(*it);
            } 
        } 
        if (!vec_le[i].empty()) fin.insert(vec_le[i].back());       
        if (!vec_ri[i].empty()) fin.insert(vec_ri[i].back());
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
    for (int i = 1; i <= T; ++i) {
        ans = 1e9;
        std::cin >> n;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
        }
        solve();
        if (i == 56) {
            std::cout << n << ' ';
            for (int i = 1; i <= n; ++i) {
                std::cout << a[i] << ' ';
            }
            std::cout << '\n';
        }
        std::cout << ans << '\n';
        
    }

    return 0;
}
