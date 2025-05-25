#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <cassert>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 2e5 + 5;
int n, a[maxn], ans;
std::vector<std::vector<pii>>list;
std::vector<int> indexes;
int vis[maxn];
void solve(int zero) {
    list.clear();
    std::vector<pii> current;
    assert(zero != -1);
    for (int i = (zero + 1) % n; ; i = (i + 1) % n) {
        if (a[i]) current.push_back({a[i], i});
        else if (!current.empty()){
            list.push_back(current);
            current.clear();
        }
        if (i == zero) break;
    }
    for (auto vec : list) {
        ans += 1;
        indexes.push_back(vec[0].second);
        if (vec.size() <= 2) {
            continue;
        } 
        if (vec[1].first <= vec[0].first) {
            ans += 1;
            indexes.push_back(vec[2].second);
            continue;
        }
        int remainder = vec[1].first % vec[0].first;
        int round = vec[1].first / vec[0].first - 1 + (remainder != 0);
        ll del = 1ll * ((remainder == 0 ? vec[0].first : remainder) + vec[1].first - vec[0].first) * round / 2;
        if (del < vec[2].first) {
            ans += 1;
            indexes.push_back(vec[2].second);
        }
    }
}
bool check() {
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) return true;
    }
    return false;
}
void bruteForce() {
    while(!check()) {
        for (int i = 0; ; i = (i + 1) % n) {
            a[(i + 1) % n] = std::max(a[(i + 1) % n] - a[i], 0);
            if (i == n - 1) break;
        }
    }
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
        indexes.clear();
        ans = 0;
        std::cin >> n;
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        if (n <= 3) {
            bruteForce();
        }
        int maxlen = n;
        while(maxlen >= 4) {
            maxlen = 0;
            int zero = -1;
            for (int i = 0; i < n; ++i) {
                a[(i + 1) % n] = std::max(a[(i + 1) % n] - a[i], 0);
                if (!a[(i + 1) % n]) {
                    zero = (i + 1) % n;
                }
            }
            if (zero == -1) {
                maxlen = n;
                continue;
            }
            int current = 0;
            for (int i = (zero + 1) % n; ; i = (i + 1) % n) {
                if (a[i]) current++;
                else {
                    maxlen = std::max(maxlen, current);
                    current = 0;
                }
                if (i == zero) break;
            } 
        }
        int zero = -1;
        for (int i = 0; i < n; ++i) {
            if (!a[i]) {
                zero = i;
                break;
            }
            a[(i + 1) % n] = std::max(a[(i + 1) % n] - a[i], 0);
        }
        solve(zero);
        for (auto it : indexes) {
            vis[it + 1] = 1;
        }
        std::cout << ans << '\n';
        for (int i = 1; i <= n; ++i) {
            if (vis[i]) std::cout << i << ' ';
        }
        std::cout << '\n';
        for (auto it : indexes) {
            vis[it + 1] = 0;
        }
    }

    return 0;
}

/*
x y z
x < y 
x y - x z

y - x < z
x y - x z - (y - x)
z - (y - x) < x 
x < y
y - x < z < y
z  < y
z - y - z 

z - (y - x) < y - x

y - x < z < 2(y - x)
3x < 2y 
0.5x < y - x < z < y

x y
x < y
x y - x 
y - x < x
x - y + x y - x
*/