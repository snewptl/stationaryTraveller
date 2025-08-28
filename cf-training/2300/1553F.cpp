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
const int len = 600;
const ll mod = 998244353;
int n, a[maxn];
ll sum[605][605], prefix[605], real_sum[605][605], real_prefix[605];
ll ans[maxn];
int seg_ind[maxn * 2], pos_ind[maxn * 2];
int which_seg(int x) {
    return (x - 1) / len + 1; 
}
int which_pos(int x) {
    return (x - 1) % len + 1;
}
ll count(int l, int r) {
    if (l > r) return 0;
    pii le = {seg_ind[l], pos_ind[l]}, ri = {seg_ind[r], pos_ind[r]};
    if (le.first == ri.first) {
        return sum[ri.first][ri.second] - sum[ri.first][le.second - 1];
    } else {
        return sum[le.first][len] - sum[le.first][le.second - 1] + sum[ri.first][ri.second] + prefix[ri.first - 1] - prefix[le.first];
    }
}
ll get_sum(int l, int r) {
    if (l > r) return 0;
    pii le = {seg_ind[l], pos_ind[l]}, ri = {seg_ind[r], pos_ind[r]};
    if (le.first == ri.first) {
        return real_sum[ri.first][ri.second] - real_sum[ri.first][le.second - 1];
    } else {
        return real_sum[le.first][len] - real_sum[le.first][le.second - 1] + real_sum[ri.first][ri.second] + real_prefix[ri.first - 1] - real_prefix[le.first];
    }
}
void update(int x) {
    int seg = seg_ind[x], pos = pos_ind[x];
    for (int i = pos; i <= len; ++i) {
        sum[seg][i] += 1;
        real_sum[seg][i] += x;
    }
    for (int i = seg; i <= len; ++i) {
        prefix[i] += 1;
        real_prefix[i] += x;
    }
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    for (int i = 1; i <= 3e5; ++i) {
        seg_ind[i] = which_seg(i);
        pos_ind[i] = which_pos(i);
    }
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        ll add = 0;
        for (ll j = 1; j <= a[i];) {
            
            ll temp = a[i] / j;
            ll l = j, r = a[i] / temp; 
            ll num = count(l, r);
            ll del = temp * get_sum(l, r);
            add += num * a[i] - del;
            
            j = r + 1;
        }
        add += get_sum(1, a[i] - 1);
        for (ll j = a[i], times = 1; j <= 3e5; j += a[i], times += 1) {
            ll l = j, r = std::min(j + a[i] - 1, (ll)3e5);
            ll num = count(l, r);
            ll del = times * a[i] * num;
            add += get_sum(l, r) - del;
            add += num * a[i];
        }
        update(a[i]);
        ans[i] = ans[i - 1] + add;
    }
    for (int i = 1; i <= n; ++i) {
        std::cout << ans[i] << ' ';
    }
    std::cout << '\n';

    return 0;
}
// 20 : 40 - 