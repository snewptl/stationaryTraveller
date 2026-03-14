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
const ll ind = 13;
int n, m;
std::string s;
std::vector<std::vector<int>> vec;
std::vector<std::vector<ll>> prefix;
ll pw[maxn];

ll qp(ll x, ll y) {
    ll res = 1;
    while (y) {
        if (y & 1) res *= x, res %= mod;
        x *= x, x %= mod;
        y /= 2;
    }
    return res;
}
ll inv(ll x) {
    return qp(x, mod - 2);
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    // std::cin >> T;
    while (T--) {
        std::cin >> n >> m >> s;
        vec.resize(26);
        prefix.resize(26);
        pw[0] = 1;
        for (int i = 1; i <= n; ++i) {
            pw[i] = pw[i - 1] * ind % mod;
        }
        for (int i = 0; i < n; ++i) {
            int cur = s[i] - 'a';
            vec[cur].push_back(i);
        }
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < vec[i].size(); ++j) {
                prefix[i].push_back(0);
                if (j) prefix[i][j] = (prefix[i][j - 1] +  (vec[i][j] - vec[i][j - 1]) * pw[j - 1]) % mod;
            }
        }
        for (int i = 0; i < m; ++i) {
            int x, y, len;
            std::cin >> x >> y >> len;
            x--, y--;
            if (x > y) std::swap(x, y); 
            int flag = 1;
            for (int j = 0; j < 26; ++j) {
                if (!flag) {
                    break;
                }
                auto start = std::lower_bound(all(vec[j]), x);
                auto end = std::lower_bound(all(vec[j]), x + len);
                if (start != end) {
                    int nx = y;
                    int k = s[*start - x + nx] - 'a';
                    auto nstart = std::lower_bound(all(vec[k]), y);
                    auto nend = std::lower_bound(all(vec[k]), y + len);
                    if (nstart == nend) {
                        flag = 0;
                        break;
                    }
                    if (s[*nstart] != 'a' + k) {
                        flag = 0;
                        break;
                    }
                    if (nend - nstart != end - start) {
                        flag = 0;
                        break;
                    }
                    --end;
                    --nend;
                    ll sum = (prefix[j][end - vec[j].begin()] - prefix[j][start - vec[j].begin()] + mod) % mod;
                    sum *= qp(inv(13), start - vec[j].begin()), sum %= mod;
                    ll nsum = (prefix[k][nend - vec[k].begin()] - prefix[k][nstart - vec[k].begin()] + mod) % mod;
                    nsum *= qp(inv(13), nstart - vec[k].begin()), nsum %= mod;
                    if (sum != nsum) flag = 0;
                }    
            }
            if (flag) std::cout << "YES\n";
            else std::cout << "NO\n";
            
        }
    }

    return 0;
}
// 16 : 05 - 