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
const int maxn = 4e5 + 5;
std::string s, t;
std::vector<pii> up, down;
int len;
void prepare(std::vector<pii>& vec, std::string& str) {
    int flag = 0;
    pii cur = {-1, -1};
    for (int i = 0; i < len; ++i) {
        if (str[i] == '1') {
            if (flag) cur.second++;
            else {
                flag = 1;
                cur = {i, i};
            }
        } else {
            if (flag) {
                vec.push_back(cur);
                cur = {-1, -1};
                flag = 0;
            }   
        }
    }
    if (flag) vec.push_back(cur);
}
int get_len(pii p) {
    return p.second - p.first + 1;
}
int solve() {
    len = s.size();
    up.clear();
    down.clear();
    prepare(up, s);
    prepare(down, t);
    int ans = 0;
    if (1ll * up.size() * down.size() == 0 && up.size() != down.size()) return -1;
    int unmovable = 0;
    int end = len - 1;
    while(!down.empty()) {
        pii cur_down = down.back();
        if (up.empty()) return -1;
        pii cur_up = up.back();
        int len_up = get_len(cur_up);
        int len_down = get_len(cur_down);
        if (cur_up.second < cur_down.second) {
            if (unmovable) return -1;
            ++ans;
            unmovable = 1;
            up.pop_back();
            up.push_back({end - len_up + 1, end});
            end = end - len_up;
        } else if (cur_up.second == cur_down.second) {
            if (len_up > len_down) {
                up.pop_back();
                down.pop_back();
                up.push_back({cur_up.first, cur_up.second - len_down});
                unmovable = 1;
            } else if (len_up == len_down) {
                up.pop_back();
                down.pop_back();
                unmovable = 0;
            } else {
                up.pop_back();
                unmovable = 0;
                down.pop_back();
                down.push_back({cur_down.first, cur_down.second - len_up});
            }
            end = cur_up.first - 1;
        } else {
            if (unmovable) return -1;
            ++ans;
            up.pop_back();
            if (up.empty()) {
                unmovable = 1;
                up.push_back({0, len_up - 1});
                end = 0;
            } else {
                pii new_cur_up = up.back();
                if (new_cur_up.second >= cur_down.second - len_up) {
                    up.pop_back();
                    up.push_back({new_cur_up.first, new_cur_up.second + len_up});
                    end = new_cur_up.first - 1;
                } else {
                    return -1;
                }
            }

        }
    }
    if (!up.empty()) return -1;
    return ans;
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
        std::cin >> s >> t;
        std::cout << solve() << '\n';
    }

    return 0;
}
