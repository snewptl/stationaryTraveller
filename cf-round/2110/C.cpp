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
int n, d[maxn];
pii seq[maxn];
std::queue<int> pos;
bool solve() {
    pii flexible = {0, 0};
    for (int i = 1; i <= n; ++i) {
        if (d[i] != -1) {
            flexible.first += d[i];
            flexible.second += d[i];
        } else {
            flexible.second += 1;
            pos.push(i);
        }
        while(!pos.empty() && flexible.first < seq[i].first) {
            int p = pos.front(); pos.pop();
            d[p] = 1;
            flexible.first += 1;
        }
        while(!pos.empty() && flexible.second > seq[i].second) {
            int p = pos.front(); pos.pop();
            d[p] = 0;
            flexible.second -= 1;
        }
        if (flexible.first < seq[i].first || flexible.second > seq[i].second) return false;
    }
    while (!pos.empty()) {
        int p = pos.front(); pos.pop();
        d[p] = 0;
    }
    for (int i = 1; i <= n; ++i) std::cout << d[i] << ' ';
    std::cout << '\n';
    return true;
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
        std::cin >> n;
        for (int i = 1; i <= n; ++i) std::cin >> d[i];
        for (int i = 1; i <= n; ++i) {
            int l, r;
            std::cin >> l >> r;
            seq[i] = {l, r};
        }

        if (!solve()) std::cout << "-1\n";

    }

    return 0;
}
