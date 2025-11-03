#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(...) (void)0
#endif

using i64 = int64_t;

constexpr int id(const char& c) {
    int t = -1;
    if (c == 'C') t = 0;
    if (c == 'W') t = 1;
    if (c == 'P') t = 2;
    return t;
}

std::string gen() {
    std::random_device seed;
    std::ranlux48 engine(seed());  // 利用种子生成随机数引擎
    int n = 20;
    std::string s;
    for (int i = 0; i < n; i++) {
        std::uniform_int_distribution<int> distrib(0, 10);

        int t = distrib(engine);
        if (t <= 5) s += 'C';
        if (t > 5 && t < 7) s += 'W';
        if (t >= 7) s += 'P';
    }
    return s;
}
void solve() {
    int n;
    std::cin >> n;
    // n = 20;
    std::string s;
    std::cin >> s;
    // s = gen();
    // debug(s);
    if (n == 1) {
        std::cout << "Beautiful\n";
        return;
    }

    std::vector<int> cnt(n - 1);  // s[i] == s[i + 1]
    std::vector<int> cntd(n - 1);
    std::vector<std::array<int, 3>> d(n);
    for (int i = 0; i + 1 < n; i++) {
        if (s[i] == s[i + 1]) {
            cnt[i] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        int t = id(s[i]);
        for (int j = 0; j < 3; j++) {
            if (j == t) {
                d[i][j] = ((i == 0) ? 0 : d[i - 1][j]) + 1;
            } else {
                d[i][j] = ((i == 0) ? 0 : d[i - 1][j]);
            }
        }
    }

    for (int i = 0; i < n - 1; i++) {
        if (i == 0) {
            cntd[i] = cnt[i];
        } else {
            cntd[i] = cntd[i - 1] + cnt[i];
        }
    }
    auto sum = [&](int l, int r, char c) -> int {
        int t = id(c);
        if (l == 0) return d[r][t];
        return d[r][t] - d[l - 1][t];
    };

    auto diff = [&](int l, int r) -> bool {
        if (l > r) return true;
        if (l == 0) {
            return (cntd[r] == 0);
        }

        return (cntd[r] - cntd[l - 1]) == 0;
    };
    if (std::find(cnt.begin(), cnt.end(), 1) == cnt.end()) {
        std::cout << "Beautiful\n";
        return;
    }

    int l = 2, r = n;

    auto check = [&](int x) -> std::tuple<bool, int, int> {
        for (int l = 0; l + x - 1 < n; l++) {
            // [l, l + x - 1]

            // [0, l - 1] cnt[0] .... cnt[l - 2] = 0
            // [l + x, n - 1] no cnt[l + x] .... cnt[n - 2] = 0;

            if (!diff(0, l - 2) || !diff(l + x, n - 2)) continue;
            int r = l + x - 1;
            int t = (x + 1) / 2;

            int s0 = sum(l, r, 'C');
            int s1 = sum(l, r, 'W');
            int s2 = sum(l, r, 'P');

            std::vector<std::pair<int, char>> g = std::vector<std::pair<int, char>>{{s0, 'C'}, {s1, 'W'}, {s2, 'P'}};

            std::sort(g.begin(), g.end(), std::greater<std::pair<int, char>>());
            // debug(x, l, r, g);
            if (g[0].first > t) {
                continue;
            }

            if (g[0].first < t) {
                return {true, l, r};
            }
            char prev = '#', nxt = '!';
            if (l > 0) prev = s[l - 1];
            if (r + 1 < n) nxt = s[r + 1];
            if (x % 2 == 1) {
                if (g[0].second == prev || g[0].second == nxt) {
                    continue;
                } else {
                    return {true, l, r};
                }
            }
            if (prev != nxt) {
                return {true, l, r};
            }

            if (g[0].first == g[1].first) {
                if (prev == g[0].second || prev == g[1].second) {
                    continue;
                }
            } else {
                if (prev == g[0].second) {
                    continue;
                }
            }

            return {true, l, r};
        }

        return {false, -1, -1};
    };
    while (l < r) {
        int m = (l + r) / 2;
        auto [ok, _, __] = check(m);
        if (ok)
            r = m;
        else
            l = m + 1;
    }
    int ans = l;
    auto [ok, L, R] = check(ans);
    // debug(l, L, R);

    if (!ok) {
        std::cout << "Impossible\n";
        return;
    }

    // return;
    auto construct = [&](int L, int R) -> std::vector<char> {
        int x = R - L + 1;

        std::vector<char> ret(3 * x, '!');
        char kt = '#', mw = '#';
        char prev = '!', nxt = '@';
        if (L > 0) prev = s[L - 1];
        if (R + 1 < n) nxt = s[R + 1];
        int s0 = sum(L, R, 'C');
        int s1 = sum(L, R, 'W');
        int s2 = sum(L, R, 'P');

        std::vector<std::pair<int, char>> g = std::vector<std::pair<int, char>>{{s0, 'C'}, {s1, 'W'}, {s2, 'P'}};

        std::sort(g.begin(), g.end(), std::greater<std::pair<int, char>>());
        s0 = g[0].first, s1 = g[1].first, s2 = g[2].first;
        // debug(L, R);
        // debug(g);
        if (g[0].first > g[1].first) {
            if (prev == g[0].second) {
                s2 -= 1;
                kt = g[2].second;
            }

            if (nxt == g[0].second) {
                s2 -= 1;
                mw = g[2].second;
            }

            assert(s2 >= 0);
            int p = 0;
            while (s0) {
                assert(ret[p] == '!');

                ret[p] = g[0].second;
                p += 3;
                s0--;
            }

            int last = p - 3;
            p = 1;
            while (s1) {
                assert(ret[p] == '!');

                ret[p] = g[1].second;
                p += 3;
                s1--;
            }
            p = 0;
            for (int i = 0; i + 1 < 3 * x; i += 3, p += 3) {
                if (ret[i] == g[0].second && ret[i + 1] == g[1].second) {
                    continue;
                }
                break;
            }

            p += 2;

            while (p < last) {
                assert(ret[p] == '!');

                ret[p] = g[2].second;
                p += 3;
                s2--;
            }

            p = 2;

            while (s2) {
                assert(ret[p] == '!');

                ret[p] = g[2].second;
                p += 3;
                s2--;
            }
        } else {
            if (prev == g[0].second) {
                std::swap(g[0], g[1]);
                std::swap(s0, s1);
            }
            if (s2 == 0) {
                if (nxt == g[1].second) {
                    std::swap(g[0], g[1]);
                    std::swap(s0, s1);
                }
            } else {
                if (nxt == g[1].second) {
                    s2 -= 1;
                    mw = g[2].second;
                }
            }

            assert(s2 >= 0);
            int p = 0;
            while (s0) {
                assert(ret[p] == '!');
                ret[p] = g[0].second;
                p += 3;
                s0--;
            }

            int last = p - 3;
            p = 1;
            while (s1) {
                assert(ret[p] == '!');

                ret[p] = g[1].second;
                p += 3;
                s1--;
            }
            p = 0;
            for (int i = 0; i + 1 < 3 * x; i += 3, p += 3) {
                if (ret[i] == g[0].second && ret[i + 1] == g[1].second) {
                    continue;
                }
                break;
            }

            p += 2;

            while (p < last) {
                assert(ret[p] == '!');
                ret[p] = g[2].second;
                p += 3;
                s2--;
            }

            p = 2;

            while (s2) {
                assert(ret[p] == '!');

                ret[p] = g[2].second;
                p += 3;
                s2--;
            }
        }

        std::vector<char> ans;

        if (kt != '#')
            ans.push_back(kt);
        for (int i = 0; i < 3 * x; i++) {
            if (ret[i] != '!') {
                ans.push_back(ret[i]);
            }
        }
        if (mw != '#')
            ans.push_back(mw);

        // if (ans.size() == R - L + 1) {
        //     std::cout << s << std::endl;
        // }

        assert(ans.size() == R - L + 1);
        for (int i = 0; i + 1 < ans.size(); i++) {
            assert(ans[i] != ans[i + 1]);
            if (ans[i] == ans[i + 1]) {
                // std::cerr << s << std::endl;
                debug(false);
            }
        }
        return ans;
    };

    std::cout << "Possible\n";
    auto ret = construct(L, R);
    std::cout << L + 1 << " " << R + 1 << '\n';
    for (int i = 0; i < L; i++) std::cout << s[i];
    for (auto c : ret) std::cout << c;
    for (int i = R + 1; i < n; i++) std::cout << s[i];
    std::cout << '\n';

    return;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;

    while (T--) {
        solve();
    }
    return 0;
}