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

int main() {
    #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

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
        s.resize(n + 2);
        for (int i = 1; i <= n; i += 2) {
            std::vector<int> vec;
            vec.push_back(pos);
            vec.push_back(pos);
            vec.push_back(i);
            vec.push_back(i);
            if (i + 1 <= n) {
                vec.push_back(pos);
                vec.push_back(i + 1);
            }
            int res = ask(vec);
            if (res == 4) {
                assert(i + 1 <= n);
                s[i] = ')';
                s[i + 1] = ')';
            } else if (res == 2) {
                s[i] = ')';
                s[i + 1] = '(';
            } else if (res == 1) {
                assert(i + 1 <= n);
                s[i] = '(';
                s[i + 1] = ')';
            } else {
                s[i] = s[i + 1] = '(';
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
