#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <assert.h>
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
int n;
ll a[maxn];
ll sum;
std::vector<pli> vec;
ll left[maxn], right[maxn];
struct treenode {
    int idx, count;
    ll maxval, lazy, sum;
} t[2][maxn << 2];
void push_up(int sgn, int rt) {
    if (!sgn) t[sgn][rt].idx = std::min(t[sgn][rt << 1].idx, t[sgn][rt << 1 | 1].idx);
    else t[sgn][rt].idx = std::max(t[sgn][rt << 1].idx, t[sgn][rt << 1 | 1].idx);
    t[sgn][rt].count = t[sgn][rt << 1].count + t[sgn][rt << 1 | 1].count;
    t[sgn][rt].maxval = std::max(t[sgn][rt << 1].maxval, t[sgn][rt << 1 | 1].maxval);
    t[sgn][rt].sum = t[sgn][rt << 1].sum + t[sgn][rt << 1 | 1].sum;
}
void push_dn(int sgn, int rt) {
    t[sgn][rt << 1].lazy += t[sgn][rt].lazy;
    t[sgn][rt << 1 | 1].lazy += t[sgn][rt].lazy;
    t[sgn][rt << 1].maxval -= t[sgn][rt].lazy;
    t[sgn][rt << 1 | 1].maxval -= t[sgn][rt].lazy;
    t[sgn][rt].lazy = 0;
}
void build(int sgn, int rt, int l, int r) {
    int mid = (l + r) / 2;
    if (l == r) {
        auto [val, pos] = vec[l - 1];
        t[sgn][rt].idx = pos;
        t[sgn][rt].count = 1;
        t[sgn][rt].maxval = val;
        t[sgn][rt].lazy = 0;
        t[sgn][rt].sum = t[sgn][rt].idx;
        return;
    }
    build(sgn, rt << 1, l, mid);
    build(sgn, rt << 1 | 1, mid +1, r);
    push_up(sgn, rt);
}
pll query(int sgn, int rt, int l, int r) {
    int mid = (l + r) / 2;
    if (t[sgn][rt].maxval < 0) return {0, 0};
    if (l == r) {
        return {t[sgn][rt].sum, t[sgn][rt].count};
    }
    push_dn(sgn, rt);
    pll res1 = query(sgn, rt << 1, l, mid);
    if (res1 != std::make_pair(0ll, 0ll)) {
        return {res1.first + t[sgn][rt << 1 | 1].sum, res1.second + t[sgn][rt << 1 | 1].count};
    } else {
        return query(sgn, rt << 1 | 1, mid + 1, r);
    }
}
void lock(int sgn, int rt, int l, int r, int final_idx) {
    int mid = (l + r) / 2;
    if (l == r) {
        t[sgn][rt].idx = sgn ? 0 : 1e9;
        t[sgn][rt].count = 0;
        t[sgn][rt].maxval = -1e18;
        t[sgn][rt].lazy = 0;
        t[sgn][rt].sum = 0;
        return;
    }
    push_dn(sgn, rt);

    if (t[sgn][rt << 1].idx == final_idx) lock(sgn, rt << 1, l, mid, final_idx);
    else {
        assert(t[sgn][rt << 1 | 1].idx == final_idx);
        lock(sgn, rt << 1 | 1, mid + 1, r, final_idx);
    }
    

    push_up(sgn, rt);
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    for (int i = 1; i <= n; ++i) std::cin >> a[i], sum += a[i];
    
    vec.clear();
    for (int i = n; i >= 1; --i) {
        vec.push_back({sum, i});
        sum -= a[i];
    }
    std::sort(all(vec));
    build(0, 1, 1, n);
    for (int i = 1; i <= n; ++i) {
        auto [val, count] = query(0, 1, 1, n);
        left[i] = val - count * (i - 1);
        t[0][1].maxval -= a[i];
        t[0][1].lazy -= a[i];
        lock(0, 1, 1, n, i);
    }

    vec.clear();
    sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += a[i];
    }
    for (int i = 1; i <= n; ++i) {
        vec.push_back({sum, i});
        sum -= a[i];
    }
    std::sort(all(vec));
    build(1, 1, 1, n);
    for (int i = n; i >= 1; --i) {
        auto [val, count] = query(1, 1, 1, n);
        right[i] = count * (i + 1) - val;
        t[1][1].maxval -= a[i];
        t[1][1].lazy -= a[i];
        lock(1, 1, 1, n, i);
    }

    for (int i = 1; i <= n; ++i) {
        
    }
 
    return 0;
}

// 10 : 10
// maxval idx lazy sum_of_idx available_idx_count