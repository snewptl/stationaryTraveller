#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
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
const ll mod = 998244353;
int n, q;
int a[maxn];
std::set<pii> s;
int count;
int ans[maxn];
struct query {
    int l, r, id;

    bool operator<(const query& x) const {  // 重载<运算符
        if (l / maxn != x.l / maxn)
            return l < x.l;
        return (l / maxn) & 1 ? r < x.r : r > x.r;
    }
};
query questions[maxn];

void update(std::vector<int> vec, int delta) {
    for (int i = 0; i < 5; ++i) {
        for (int j = i + 1; j < 5; ++j) {
            int flag = 1;
            if (vec[i] + vec[j] <= vec[5]) flag = 0;
            std::vector<int> t;
            for (int k = 0; k < 5; ++k) {
                if (k != i && k != j) t.push_back(vec[k]);
            }
            if (t[0] + t[1] <= t[2]) flag = 0;
            if (flag) {
                count += delta;
                return;
            }
        }
    }
}

void add (int x, int idx) {
    if (s.empty()) {
        s.insert({x, idx});
        return;
    }
    auto begin = s.lower_bound({x, idx});
    std::vector<int> vec;
    int del_time = 5;
    while (begin != s.begin() && del_time > 0) {
        --begin;
        --del_time;
    }
    int add_time = 4 - del_time;
    auto new_begin = begin;
    for (int i = 0; i <= add_time; ++i) {
        auto cur = new_begin;
        vec.clear();
        for (int j = 1; j <= 6; ++j) {
            if (cur == s.end()) break;
            vec.push_back(cur->first);
            ++cur;
        }
        if (vec.size() == 6) update(vec, -1);
        ++new_begin;
        if (new_begin == s.end()) break;
    }
    
    s.insert({x, idx});
    del_time = 5;
    begin = s.lower_bound({x, idx});
    while (begin != s.begin() && del_time > 0) {
        --begin;
        --del_time;
    }
    add_time = 5 - del_time;
    new_begin = begin;
    for (int i = 0; i <= add_time; ++i) {
        auto cur = new_begin;
        vec.clear();
        for (int j = 1; j <= 6; ++j) {
            if (cur == s.end()) break;
            vec.push_back(cur->first);
            ++cur;
        }
        if (vec.size() == 6) update(vec, 1);
        ++new_begin;
        if (new_begin == s.end()) break;
    }
}

void del (int x, int idx) {
    int del_time = 5;
    auto begin = s.lower_bound({x, idx});
    while (begin != s.begin() && del_time > 0) {
        --begin;
        --del_time;
    }
    int add_time = 5 - del_time;
    auto new_begin = begin;
    std::vector<int> vec;
    for (int i = 0; i <= add_time; ++i) {
        auto cur = new_begin;
        vec.clear();
        for (int j = 1; j <= 6; ++j) {
            if (cur == s.end()) break;
            vec.push_back(cur->first);
            ++cur;
        }
        if (vec.size() == 6) update(vec, -1);
        ++new_begin;
        if (new_begin == s.end()) break;
    }

    s.erase({x, idx});
    if (s.empty()) return;
    begin = s.lower_bound({x, idx});
    del_time = 5;
    while (begin != s.begin() && del_time > 0) {
        --del_time;
        --begin;
    }
    add_time = 4 - del_time;
    new_begin = begin;
    for (int i = 0; i <= add_time; ++i) {
        auto cur = new_begin;
        vec.clear();
        for (int j = 1; j <= 6; ++j) {
            if (cur == s.end()) break;
            vec.push_back(cur->first);
            ++cur;
        }
        if (vec.size() == 6) update(vec, 1);
        ++new_begin;
        if (new_begin == s.end()) break;
    }    
}

void solve() {
    s.clear();
    count = 0;
    for (int i = 1, l = 1, r = 0; i <= q; ++i) {
        while (l > questions[i].l) {
            --l;
            add(a[l], l);
        }
        while (r < questions[i].r) {
            ++r;
            add(a[r], r);
        }
        while (l < questions[i].l) {
            del(a[l], l);
            ++l;
        }
        while (r > questions[i].r) {
            del(a[r], r);
            --r;
        }
        ans[questions[i].id] = count;
    }
    for (int i = 1; i <= q; ++i) {
        if (ans[i]) std::cout << "YES\n";
        else std::cout << "NO\n";
    }
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    // std::cin >> T;
    while (T--) {
        std::cin >> n >> q;
        for (int i = 1; i <= n; ++i) std::cin >> a[i];
        for (int i = 1; i <= q; ++i) {
            int l, r;
            std::cin >> l >> r;
            questions[i] = {l, r, i};
        }
        std::sort(questions + 1, questions + q + 1);
        solve();
    }

    return 0;
}

// 20 min