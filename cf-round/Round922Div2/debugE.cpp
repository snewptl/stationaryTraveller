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
const ll mod = 998244353;
const int maxn = 2e5 + 5;
const double eps = 1e-10;
int a[maxn], n;
int x, b[maxn];
int askWith(int pos) {
    std::cout << "? " << pos << '\n';
    std::cout.flush();
    char ch[2];
    // std::cin >> ch;
    // if (ch[0] == '>')
    //     return 1;
    // else if (ch[0] == '=')
    //     return 0;
    // else
    //     return -1;
    // <<<<< debug
    if (x == b[pos])
        return 0;
    else {
        int diff = (b[pos] - x) / std::abs(x - b[pos]);
        x += diff;
        return diff;
    }
    // debug >>>>>
}
void output() {
    std::cout << "! ";
    for (int i = 1; i <= n; ++i)
        std::cout << a[i] << ' ';
    std::cout << "\n";
    std::cout.flush();
}

int randomSelect(std::vector<int> vec) {
    // return vec[rand() % vec.size()];
    return vec[0];
}
void setXEqualTo(int pos) {
    while (askWith(pos));
}
void bruteForce(std::vector<int> vec, int nearestKownPosition) {
    setXEqualTo(nearestKownPosition);
    int last = a[nearestKownPosition];
    for (auto it : vec) {
        setXEqualTo(it);
        a[it] = x;
    }
}
/*
记录nearestKownPosition 主要是为了尽量减少调用bruteForce时产生的询问次数。
*/
void solve(std::vector<int> vec, int min, int max, int nearestKownPosition) {
    // 如果solve进行了至少一次调用，nearKownPosition就不可能为0，为0说明此时n小于等于10
    // 如果n小于10，先强制走一遍solve的流程
    if (max - min + 1 <= 10 && nearestKownPosition) {
        if (min > max)
            return;
        bruteForce(vec, nearestKownPosition);
        return;
    }
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
    solve(SmallerVec, min, a[pos] - 1, pos);
    solve(BiggerVec, a[pos] + 1, max, pos);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    srand(time(0));
    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        // <<<<< debug
        std::cin >> x;
        for (int i = 1; i <= n; ++i)
            std::cin >> b[i];
        // debug >>>>>
        std::vector<int> vec;
        for (int i = 1; i <= n; ++i)
            vec.push_back(i);
        for (int i = 1; i <= n; ++i)
            a[i] = 0;
        solve(vec, 1, n, 0);
        output();
    }

    return 0;
}
