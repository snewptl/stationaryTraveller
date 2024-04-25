#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <cassert>
#define all(x) x.begin(), x.end()
typedef int64_t ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 2e5 + 5;
int a[maxn], n;
int askWith(int pos) {
    std::cout << "? " << pos << std::endl;
    char ch[2];
    std::cin >> ch;
    if (ch[0] == '>')
        return 1;
    else if (ch[0] == '=')
        return 0;
    else
        return -1;
}
void output() {
    std::cout << "! ";
    for (int i = 1; i <= n; ++i)
        std::cout << a[i] << ' ';
    std::cout << std::endl;
}

int randomSelect(std::vector<int> vec) {
    return vec[rand() % vec.size()];
}
void setXEqualTo(int pos) {
    while (askWith(pos));
}
void solve(std::vector<int> vec, int min, int max) {
    if (min > max) return;
    int pos = randomSelect(vec);
    setXEqualTo(pos);
    std::vector<int> BiggerVec, SmallerVec;
    int cnt = 0;
    for (int it : vec) {
        if (it == pos)
            continue;
        if (askWith(it) == 1) {
            // 还原X的值
            askWith(pos);
            BiggerVec.push_back(it);
            ++cnt;
        } else {
            askWith(pos);
            SmallerVec.push_back(it);
        }
    }
    a[pos] = max - cnt;
    solve(SmallerVec, min, a[pos] - 1);
    solve(BiggerVec, a[pos] + 1, max);
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    srand(time(0));
    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        std::vector<int> vec;
        for (int i = 1; i <= n; ++i)
            vec.push_back(i);
        for (int i = 1; i <= n; ++i)
            a[i] = 0;
        solve(vec, 1, n);
        output();
    }

    return 0;
}
/*
2 4 1 5 3

x = 3

2 1 

x = 1
*/