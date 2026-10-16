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
const int maxn = 3e5 + 5;
const ll mod = 998244353;
int n;
std::string s;
int dig[maxn];
int nxt[maxn][10];
int pos[10];
ll sum[maxn];
ll fix[maxn];
ll seg_count[maxn];
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n >> s;
        for (int i = 1; i <= n; ++i) {
            dig[i] = s[i - 1] - '0';
        }
        for (int i = 1; i <= n + 1; ++i) {
            sum[i] = seg_count[i] = fix[i] = 0;
        }
        for (int i = 0; i < 10; ++i) {
            pos[i] = n + 1;
            nxt[n + 1][i] = n + 1;
        }
        for (int i = n; i >= 1; --i) {
            pos[dig[i]] = i;
            for (int j =  0; j < 10; ++j) {
                nxt[i][j] = pos[j];
            }
        }
        for (int i = 1; i <= n; ++i) {
            int l = nxt[nxt[nxt[nxt[i][2]][0]][2]][5];
            int r = nxt[nxt[nxt[nxt[i][2]][0]][2]][6];
            if (l < r) {
                seg_count[l] += 1;
                seg_count[r + 1] -= 1;
                sum[l] += r - l + 1;
                fix[i] += r - l;
                fix[l] -= r - l;
            }
        }
        for (int i = 1; i <= n; ++i) {
            seg_count[i] += seg_count[i - 1];
            sum[i] += sum[i - 1] - seg_count[i];
            fix[i] += fix[i - 1];
            std::cout << 1ll * (n - i + 1) * i  - sum[i] - fix[i] << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}
