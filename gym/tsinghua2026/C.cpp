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
const int maxn = 1e4 + 5;
const ll mod = 998244353;
std::string dig[2];
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
        std::cin >> dig[0] >> dig[1];
        if (s1.size() > s2.size()) {
            std::cout << "-1\n";
        } else {
            len[0] = s1.size();
            for (int i = 1, j = len[0] - 1; i <= len[0]; ++i, --j) {
                dig[0][i] = s1[j] - '0';
            }
            len[1] = s2.size();
            for (int i = 1, j = len[1] - 1; i <= len[1]; ++i, --j) {
                dig[1][i] = s2[j] - '0';
            }
            for (int diff = 0; diff <= 1e4 + 1 - len[0]; ++diff) {
                
                for (int i = 0; i <= 1; ++i) {
                    int temp[maxn], res[maxn];
                    for (int j = 1; j <= 1e4 + 1; ++j) {
                        temp[j] = 0;
                        res[j] = 0;
                    }
                    for (int j = 1; j <= 1e4 + 1 - diff; ++j) {
                        temp[j] = dig[1][j + diff];
                    } 
                    add(temp);
                    del(temp, dig[0], res);
                }
            }
        }
    }

    return 0;
}
