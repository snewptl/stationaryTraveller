#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <bitset>
#include <memory.h>
#include <assert.h>
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
std::vector<char> s;
int exp_len[100], sum[100];
int ask(std::vector<int> &vec) {
    std::cout << "? " << vec.size() << ' ';
    for (auto it : vec) std::cout << it << ' ';
    std::cout << std::endl;
    int x;
    std::cin >> x;
    return x;
}
int ask_seq(int l, int r) {
    std::vector<int> vec;
    for (int i = l; i <= r; ++i) vec.push_back(i);
    return ask(vec);
}
int cal(int x) {
    return x * (x + 1) / 2;
}

int main() {
    #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    exp_len[0] = 1;
    sum[0] = 1;
    for (int i = 1; i <= 12; ++i) {
        for (int j = exp_len[i - 1] + 1;; ++j) {
            if (cal(j) <= sum[i - 1]) continue;
            exp_len[i] = j;
            sum[i] = sum[i - 1] +  cal(exp_len[i]);
            break;
        }
    }
    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        int l = 1, r = n, pos = 0;
        if (ask_seq(l, r) == 0) pos = n;
        else {
            while (l < r) {
                int mid = (l + r) / 2;
                int left = ask_seq(l, mid);
                int right = ask_seq(mid + 1, r);
                if (left == 0) {
                    if (right == 0) {
                        pos = mid;
                        break;
                    }
                    else {
                        l = mid + 1;
                    }
                } else {
                    r = mid;
                }
            }   
        }
        assert(pos);
        s.clear();
        s.resize(n + 10);
        for (int i = 1; i <= n; i += 13) {
            std::vector<int> vec;
            for (int j = 0; j < std::min(13, n - i + 1); ++j) {
                int len = exp_len[j];
                for (int k = 1; k <= len; ++k) {
                    vec.push_back(pos);
                    vec.push_back(i + j);
                }
                vec.push_back(pos);
            }
            int res = ask(vec);
            for (int j = std::min(13, n - i + 1) - 1; j >= 0; --j) {
                if (res >= cal(exp_len[j])) s[i + j] = ')', res -= cal(exp_len[j]);
                else s[i + j] = '(';
            }
        }
        std::cout << '!' << ' ';
        for (int i = 1; i <= n; ++i) {
            std::cout << s[i];
        }
        std::cout << std::endl;
    }

    return 0;
}
