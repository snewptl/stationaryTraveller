#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 2e5 + 5;
int n, q;
std::string str;
std::set<int> vec[10];
int hash(char a, char b) {
    return (a - 'a') * 3 + b - 'a';
}
void solve() {
    for (int i = 0; i < n; ++i) {
        if (str[i] == 'a') continue;
        if (str[i] == 'b') {
            int cur = hash('b', 'a');
            if (!vec[cur].empty()) {
                vec[cur].erase(vec[cur].begin());
                str[i] = 'a';
            } else {
                int pre = hash('b', 'c');
                int nxt = hash('c', 'a');
                if (!vec[pre].empty() && !vec[nxt].empty()) {
                    auto it = vec[pre].begin();
                    auto that = vec[nxt].lower_bound(*it);
                    if (that != vec[nxt].end()) {
                        vec[pre].erase(it);
                        vec[nxt].erase(that);
                        str[i] = 'a';
                    }
                } 
            }
        } else {
            int cur = hash('c', 'a');
            if (!vec[cur].empty()) {
                vec[cur].erase(vec[cur].begin());
                str[i] = 'a';
            } else {
                int pre = hash('c', 'b');
                if (!vec[pre].empty()) {
                    auto it = vec[pre].begin();                   
                    str[i] = 'b';
                    int nxt = hash('b', 'a');
                    if (!vec[nxt].empty()) {
                        auto that = vec[nxt].lower_bound(*it);
                        if (that != vec[nxt].end()) {
                            str[i] = 'a';
                            vec[nxt].erase(that);
                        }
                    }
                    vec[pre].erase(it);
                }
               
            }            
        }
    }
    std::cout << str << '\n';
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n >> q;
        std::cin >> str;
        for (int i = 0; i <= 9; ++i) {
            vec[i].clear();
        }
        for (int i = 1; i <= q; ++i) {
            std::string a, b;
            std::cin >> a >> b;
            int x = a[0] - 'a';
            int y = b[0] - 'a';
            vec[x * 3 + y].insert(i);
        }
        solve();
    }

    return 0;
}

4 * n / n * n

4 / n   - >   n * 2 + 2 / n

n = 1  : 4 / 1
n = 2 :  6 / 2
n = 3 : 8 / 3

