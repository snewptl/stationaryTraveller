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
int n;
std::string s;
int count[2];
bool solve() {
    int max = std::max(count[0], count[1]);
    int min = std::min(count[0], count[1]);
    if ((max - min) % 4) return false;
    if (s[n - 1] == '(') {
        for (int i = n - 1; i >= 1; --i) {
            if (s[i - 1] == s[i]) {
                if (s[i - 1] == '(' ) s[i - 1] = ')';
                else s[i - 1] = '(';
                s[n - 1] = ')';
                break;
            }
        }
    }
    for (int i = n - 1; i > 0; --i) {
        if (s[i] == s[i - 1] && s[i] == '(') {
            s[i] = ')';
            s[i - 1] = ')';
        }
    }
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') cur += 1;
        else {
            if (!cur) {
                for (int j = i; j < n - 1; ++j) {
                    if (s[j] == s[j + 1]) {
                        for (int k = j + 1; k > i; --k) {
                            if (s[k] == ')') {
                                s[k] = s[k - 1] = '(';
                            } else {
                                s[k] = s[k - 1] = ')';
                            }
                        }
                        if (s[j + 1] == '(' && j + 2 < n && s[j + 2] == '(') {
                            s[j + 1] = s[j + 2] = ')';
                        }
                        --i;
                        break;
                    }
                }
            } else {
                --cur;
            }
        }
    }
    cur = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            cur += 1;
        } else {
            cur -= 1;
        }
        if (cur < 0) return false;
    }
    if (cur) return false;
    return true;
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
        std::cin >> n >> s;
        count[0] = count[1] = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') count[0] += 1;
            else count[1] += 1;
        }
        if (!solve()) std::cout << "-1\n";
        else std::cout << s << '\n';
    }

    return 0;
}
