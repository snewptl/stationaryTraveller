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
const ll mod = 1e9 + 7;
int n;
std::string str;

std::vector<int> pri;
bool not_prime[maxn];
int phi[maxn];
int vis[maxn];
void pre() {
    phi[1] = 1;
    for (int i = 2; i <= 1e5; i++) {
        if (!not_prime[i]) {
            pri.push_back(i);
            phi[i] = i - 1;
        }
        for (int pri_j : pri) {
            if (i * pri_j > 1e5)
                break;
            not_prime[i * pri_j] = true;
            if (i % pri_j == 0) {
                phi[i * pri_j] = phi[i] * pri_j;
                break;
            }
            phi[i * pri_j] = phi[i] * phi[pri_j];
        }
    }
    phi[1] = 0;
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    pre();

    int T = 1;
    // std::cin >> T;
    while (T--) {
        std::cin >> n;
        ll ans = 0;
        for (int dn = 1; dn <= n; ++dn) {
            if (n % dn != 0) continue;
            for (int sum = dn; sum < n; sum += dn) { // (a + b)
                for (int i = 1; i * i <= sum / dn; ++i) {
                    if (sum / dn % i != 0) continue;
                    // if (std::__gcd(i, n / dn) != 1) continue;
                    if (std::__gcd(i, n / dn) == 1) {
                        ans += 1ll * phi[sum / dn / i] * i % mod * (n - sum) % mod;
                        ans %= mod;
                    }
                    if (i * i != sum / dn && std::__gcd(sum / dn / i, n / dn) == 1) {
                        ans += 1ll * phi[i] * (sum / dn / i) % mod * (n - sum) % mod;
                        ans %= mod;
                    }
                    
                }
            }
        }
        std::cout << ans << '\n';
    }

    return 0;
}

/*
1 1 3 
2 1 2 , 1 2 2
1 3 1, 3, 
*/