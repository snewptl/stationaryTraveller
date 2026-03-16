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
const int maxn = 1e6 + 5;
const ll mod = 998244353;
std::string s;
int f[maxn][10];
bool check(std::vector<int> count, int x) {
    for (int i = 0; i <= 9; ++i) {
        count[i] -= f[x][i];
        if (count[i] < 0) return false;
    }
    int sum = 0;
    for (int i = 1; i <= 9; ++i) {
        sum += i * count[i];
    }
    if (sum != x) return false;
    return true;
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    for (int i = 1; i <= 9; ++i) {
        f[i][i] = 1;
    }
    for (int i = 10; i <= 1e6; ++i) {
        int cur = i, temp = 0;
        while (cur) {
            f[i][cur % 10] += 1;
            temp += cur % 10;
            cur /= 10;
        }
        for (int j = 0; j <= 9; ++j) {
            f[i][j] += f[temp][j];
        }
    }

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> s;
        std::vector<int> count(10, 0);
        int sum = 0;
        for (int i = 0; i < s.size(); ++i) {
            sum += s[i] - '0';
            count[s[i] - '0'] += 1;
        }
        assert(sum <= 1e6);
        if (s.size() == 1) {
            std::cout << s[0] << '\n';
            continue;
        }
        for (int i = std::max(sum - 500, 0); i <= sum; ++i) {
            if (check(count, i)) {
                for (int j = 0; j <= 9; ++j) {
                    count[j] -= f[i][j];
                }
                int sum = 0;
                for (int j = 1; j <= 9; ++j) {
                    for (int t = 1; t <= count[j]; ++t) {
                        std::cout << j;
                    }
                    sum += j * count[j];
                }
                for (int t = 1; t <= count[0]; ++t) {
                    std::cout << 0;
                }
                while (sum > 9) {
                    std::cout << sum;
                    int cur = sum;
                    sum = 0;
                    while (cur) {
                        sum += cur % 10;
                        cur /= 10;
                    }
                }
                std::cout << sum << '\n';
                break;
            }
        }

    }

    return 0;
}
