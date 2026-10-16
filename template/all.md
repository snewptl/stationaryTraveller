```C++
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <assert.h>
#include <memory.h>
#include <cmath>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 2e5 + 5;
const ll mod = 998244353;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
    }

    return 0;
}

```
```C++
//kmp
std::vector<int> prefix_function(std::string s) {
    int n = (int)s.length();
    std::vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
std::vector<int> find_occurrences(string text, string pattern) {
    string cur = pattern + '#' + text;
    int sz1 = text.size(), sz2 = pattern.size();
    vector<int> v;
    vector<int> lps = prefix_function(cur);
    for (int i = sz2 + 1; i <= sz1 + sz2; i++) {
        if (lps[i] == sz2)
            v.push_back(i - 2 * sz2);
    }
    return v;
}
```
```c++
// tarjan
struct dsu {
	vector<int> ds, wt;
	dsu(int n) {
		ds.assign(n, -1);
		wt.assign(n, INT_MAX);
	}
	int find(int i) {
		return ds[i] < 0 ? i : find(ds[i]);
	}
	void merge(int i, int j, int weight) {
		i = find(i), j = find(j);
		if (i != j) {
			if (ds[i] > ds[j])
				swap(i, j);
			ds[i] += ds[j], ds[j] = i;
			wt[j] = weight;
		}
	}
	int weight(int i, int j) {
		int w = 0;
 
		while (i != j) {
			if (wt[i] < wt[j])
				w = wt[i], i = ds[i];
			else
				w = wt[j], j = ds[j];
		}
		return w;
	}
};
```

```C++
int ternary_search_int(int l, int r) {
    while (r - l + 1 > 3) {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        
        if (f(m1) < f(m2)) {
            l = m1 + 1;
        } else {
            r = m2;
        }
    }
    
    for (int i = l; i <= r; ++i) {
        max_val = max(max_val, f(i));
    }
    return max_val;
}
```

```C++
// euler's totient func
vector<int> pri;
bool not_prime[N];
int phi[N];

void pre(int n) {
    phi[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!not_prime[i]) {
            pri.push_back(i);
            phi[i] = i - 1;
        }
        for (int pri_j : pri) {
            if (i * pri_j > n)
                break;
            not_prime[i * pri_j] = true;
            if (i % pri_j == 0) {
                phi[i * pri_j] = phi[i] * pri_j;
                break;
            }
            phi[i * pri_j] = phi[i] * phi[pri_j];
        }
    }
}
```

```C++
// dataGenerator.cpp - 随机数据生成器
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <assert.h>
#include <memory.h>
#include <cmath>
#include <random>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int randInt(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

int main() {
    freopen("0_input.txt", "w", stdout);
    // 设置随机种子
    srand(time(0));
    
    // 生成测试数据示例：n个数和m个询问
    int T = 1;
    int n = randInt(1, 10);
    int h = randInt(1, 10);
    
    cout << T << '\n' << n << " " << h << endl;
    
    // 生成数组
    for (int i = 0; i < n; i++) {
        cout << randInt(1, h) << " \n"[i == n-1];
    }
    
    return 0;
}

// myCode.cpp
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <assert.h>
#include <memory.h>
#include <cmath>
using namespace std;

int main() {
    int testCase = 1;
    // 生成测试数据
    system("g++ --std=c++17 std.cpp -o std");
    system("g++ --std=c++17 myCode.cpp -o myCode");
    system("g++ --std=c++17 dataGenerator.cpp -o dataGenerator");
    while (true) {
        system("./dataGenerator");
        system("./std");
        system("./myCode");
        
        // 对比结果
        if (system("diff stdOut.txt 0_output.txt")) {
            cout << "Wrong Answer on test " << testCase << endl;
            break;
        }
        cout << "Accepted on test " << testCase << endl;
        testCase++;
    }
    return 0;
}
```