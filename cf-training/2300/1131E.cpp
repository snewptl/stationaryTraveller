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
int len[26];
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    for (int cs = 1; cs <= n; ++cs) {
        std::string str; 
        std::cin >> str;
        int cur[26];
        memset(cur, 0, sizeof(cur));
        std::vector<int> last(str.size(), 0);
        for (int j = 0; j < str.size(); ++j) {
            last[j] = 1;
            if (j && str[j] == str[j - 1]) last[j] += last[j - 1];
            cur[str[j] - 'a'] = std::max(cur[str[j] - 'a'], last[j]);
        }
        if (cur[str[0] - 'a'] == str.size()) {
            for (int i = 0; i < 26; ++i) {
                if (len[i]) {
                    if (i == str[0] - 'a') {
                        len[i] = (len[i] + 1) * cur[str[0] - 'a'] + len[i];
                    } else {
                        len[i] = 1;
                    }
                }
            }
        } else {
            int end = str.back() - 'a', start = str[0] - 'a';
            int end_len = last[str.size() - 1];
            int start_len = 0;
            for (int i = 0; i < str.size(); ++i) {
                if (str[0] == str[i]) ++start_len;
                else break;
            }
            for (int i = 0; i < 26; ++i) {
                if (len[i]) {
                    len[i] = 1;
                    if (start == i) {
                        len[i] += start_len;
                    } 
                    if (end == i) {
                        len[i] += end_len;
                    }
                }
            }
        }
        for (int i = 0; i < 26; ++i) {
            len[i] = std::max(len[i], cur[i]);
        }
    }
    int ans = 0;
    for (int i = 0; i < 26; ++i) {
        ans = std::max(ans, len[i]);
    }
    std::cout << ans << '\n';

    return 0;
}
// 18 : 30 - 
