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
int n, q;
int sum, between, empty;
std::string s;
std::vector<int> I, XV;
int ci, cv, cx;
int add() {
    int res = 0;
    int remain = empty - ci;
    if (cv >= remain) {
        res += remain * 5;
    } else {
        res += cv * 5 + (remain - cv) * 10;
    }
    return res;
}
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
        sum = 0;
        I.clear();
        XV.clear();
        between = empty = 0;
        std::cin >> n >> q >> s;
        s.push_back('#');
        int len = 0;
        char start = ' ';
        for (int i = 0; i < n + 1; ++i) {
            if (s[i] == '?') {
                empty += 1;
                if (!len) {
                    start = i ? s[i - 1] : ' ';
                }
                len += 1;                
            } else {
                if (start == 'I') {
                    if (s[i] == 'X' || s[i] == 'V') {
                        between += len;
                        sum -= 1;
                    } else {
                        I.push_back(len);
                    }
                } else {
                    if (s[i] == 'X' || s[i] == 'V') {
                        XV.push_back(len);
                    } else {
                        between += len;
                    }
                }
                len = 0;
                if (s[i] == 'X') {
                    sum += 10;
                } else if (s[i] == 'V') {
                    sum += 5;
                } else if (s[i] == 'I') {
                    if (s[i + 1] == 'X' || s[i + 1] == 'V') {
                        sum -= 1;
                    } else {
                        sum += 1;
                    }
                }
            }
        }
        std::sort(all(I));
        std::sort(all(XV));
        for (int i = 1; i < I.size(); ++i) {
            I[i] += I[i - 1];
        }
        for (int i = 1; i < XV.size(); ++i) {
            XV[i] += XV[i - 1];
        }        
        while (q--) {
            int ans = sum;
            std::cin >> cx >> cv >> ci;
            std::cout << ans << '\n';
        }
    }

    return 0;
}
