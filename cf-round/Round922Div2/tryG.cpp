#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#define all(x) x.begin(), x.end()
typedef int64_t ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 2e5 + 5;
bool check(std::vector<int> vec) {
    std::map<int, int> mp1, mp2;
    for (int i = 0; i < vec.size(); ++i) {
        mp1[vec[i]]++;
        if (i == 0)
            mp2[vec[1]]++;
        else if (i == vec.size() - 1)
            mp2[vec[vec.size() - 2]]++;
        else 
            mp2[vec[i - 1] + vec[i + 1]]++;
    }
    for (auto it : mp1) {
        if (mp2[it.first] != it.second) return false;
    }
    return true;
}
void dfs(int remain, std::vector<int> vec) {
    if (!remain) {
        if (check(vec)) {
            for (int i = 0; i < vec.size(); ++i) {
                std::cout << vec[i] << ' ';
            }
            std::cout << '\n';
        }
        return;
    }
    for (int i = -4; i <= 4; ++i) {
        if (!i) continue;
        vec.push_back(i);
        dfs(remain - 1, vec);
        vec.pop_back();
    }
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    for (int i = 1; i <= 8; i += 2) {
        std::cout << "====== case: "<< i <<" ======\n";
        dfs(i, std::vector<int>{});
    }

    return 0;
}
