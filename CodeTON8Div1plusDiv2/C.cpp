#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 2e5 + 5;
int n, x, y, a[maxn];
std::vector<pii> vec;
int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        int cnt = 0;
        vec.clear();
        std::cin >> n >> x >> y;
        for (int i = 1; i <= x; ++i) {
            std::cin >> a[i];
            a[i] -= 1;
        }
        std::sort(a + 1, a + x + 1);
        for (int i = 1; i <= x; ++i) {
            int j = i + 1;
            if (j > x) j = 1;
            if (a[j] == (a[i] + 2) % n) cnt++;
            int dis = (a[j] - a[i] + n) % n;
            if (dis <= 2) {
                continue;
            }
            vec.push_back(std::make_pair(dis % 2, dis / 2));
        }
        cnt += x - 2;
        sort(all(vec));
        for (auto it : vec) {
            int len = it.second;
            if (it.first == 0) {
                int temp = std::min(len - 1, y);
                if (temp == len - 1) cnt += temp * 2 + 1;
                else cnt += temp * 2;
                y -= temp;
            } else {
                int temp = std::min(len, y);
                cnt += temp * 2;
                y -= temp;
            }
            if (y <= 0) break;
        }
        std::cout << cnt << '\n';
    }

    return 0;
}
