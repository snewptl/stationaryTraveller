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
int n, k;
std::string s;
int vis[maxn];
int len[maxn];
void flip(int i) {
    if (s[i] == 'W') s[i] = 'B';
    else s[i] = 'W';
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
        std::cin >> n >> k >> s;
        for (int i = 0; i < n; ++i) {
            vis[i] = 0;
            len[i] = 0;
        }
        for (int i = 0; i < n; ++i) {
            int pre = (i - 1 + n) % n;
            int nxt = (i + 1) % n;
            if (s[pre] == s[nxt] && s[pre] != s[i]) {
                vis[i] = 1;
            }
        }
        int flag = 0;
        for (int i = 1; i < n * 2; ++i) {
            int cur = i % n;
            int pre = (i - 1) % n;
            if (vis[cur]) len[cur] = len[pre] + 1;
            if (!vis[cur]) flag = 1;
        }
        if (!flag) {
            k %= 2;
            if (k) {
                for (int i = 0; i < n; ++i) {
                    flip(i);
                }
            }
        } else {
            for (int i = n * 2 - 2; i >= 0; --i) {
                int cur = i % n;
                int nxt = (i + 1) % n;
                if (vis[cur]) len[cur] = std::min(len[cur], len[nxt] + 1);
            }   
            for (int i = 0; i < n; ++i) {
                if (vis[i]) {
                    int temp = std::min(k, len[i]);
                    if (temp % 2) {
                        flip(i);
                    }
                }
            }
        }
        std::cout << s << '\n';
    }

    return 0;
}
// 10 : 28 - 11 : 10