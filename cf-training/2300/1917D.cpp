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
int n, K;
std::vector<ll> p, q, temp, ind;
std::vector<ll> even;
ll ans;
ll merge_sort(std::vector<ll>& vec, int l, int r) {
    if (l == r) {
        return 0;
    }
    int mid = (l + r) / 2;
    ll res = merge_sort(vec, l, mid);
    res += merge_sort(vec, mid + 1, r);
    int i, j, cur = l;
    for (i = l, j = mid + 1; i <= mid && j <= r;) {
        if (vec[i] < vec[j]) temp[cur++] = vec[i], ++i;
        else temp[cur++] = vec[j], res += mid - l + 1, ++j;
    }
    while (i <= mid) temp[cur++] = vec[i], ++i;
    while (j <= r) temp[cur++] = vec[j], ++j;
    for (int t = l; t <= r; ++t) vec[t] = temp[t];
    return res % mod;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n >> K;
        ind.resize(n);
        p.resize(n);
        q.resize(K);
        for (int i = 0; i < n; ++i)
            std::cin >> p[i];
        for (int i = 0; i < K; ++i)
            std::cin >> q[i];
        temp.clear();
        temp.resize(K);
        ans = merge_sort(q, 0, K - 1) * n % mod;
        std::vector<ll> count;
        count.clear();
        count.resize(20);
        even.clear();
        int mx = 0, mn = 20;
        for (int i = 0; i < n; ++i) {
            int cur = p[i], times = 0;
            while (cur) {
                cur /= 2;
                ++times;
            }
            --times;
            ind[i] = times;
            mx = std::max(mx, times);
            mn = std::min(mn, times);
            for (int j = 0; j <= times; ++j) {
                ll len = K - 1 - (times - j + 1) + 1;
                if (len <= 0) continue;
                ans += count[j] * ((len + 1) * len / 2 % mod) % mod;
                ans %= mod;
            }
            for (int j = times + 1; j < 20; ++j) {
                ans += count[j] * K % mod * K % mod;
                ans %= mod; 
                ll len = K - 1 - (j - times + 1) + 1;
                if (len <= 0) continue;
                ans -= count[j] * ((len + 1) * len / 2 % mod) % mod;
                ans %= mod;
            }        
            ++count[times];    
            cur = p[i];
        }
        for (int i = mn; i < mx; ++i) {
            even.clear();
            for (int j = 0; j < n; ++j) {
                int delta = i - ind[j];
                if (delta >= 0 && K - 1 >= delta) {
                    even.push_back(p[j] * (1 << delta));
                }
            }
            temp.clear();
            temp.resize(even.size());
            ans += merge_sort(even, 0, even.size() - 1);
            ans %= mod;
        }
        int start = mx;
        int end = mn + K - 1;
        if (start <= end) {
            for (int j = 0; j < n; ++j) {
                int delta = start - ind[j];
                even.push_back(p[j] * (1 << delta));
            }
            temp.clear();
            temp.resize(even.size());
            ans += merge_sort(even, 0, even.size() - 1) * (end - start + 1) % mod;
            ans %= mod;
        }
        for (int i = std::max(end + 1, mx); i <= mx + K - 1; ++i) {
            even.clear();
            for (int j = 0; j < n; ++j) {
                int delta = i - ind[j];
                if (delta >= 0 && K - 1 >= delta) {
                    even.push_back(p[j] * (1 << delta));
                }
            }
            temp.clear();
            temp.resize(even.size());
            ans += merge_sort(even, 0, even.size() - 1);
            ans %= mod;
        }
        std::cout << (ans + mod) % mod << '\n';
    }

    return 0;
}
// 20 : 10 - 