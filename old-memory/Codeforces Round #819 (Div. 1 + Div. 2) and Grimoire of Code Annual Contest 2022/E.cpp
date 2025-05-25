#include <bits/stdc++.h>
#ifdef LOCAL
#include "cp_debug.h"
#else
#define debug(...) 42
#endif
#define rep(i,a,b) for(int i = a; i < b; ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)x.size()
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;


template<typename T> void read(T &x){
    x = 0;char ch = getchar();ll f = 1;
    while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
    while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
template<typename T, typename... Args> void read(T &first, Args& ... args) {
    read(first);
    read(args...);
}
template<typename T> void write(T x) {
    if(x > 9) write(x/10);
    putchar(x%10 + '0');
}
typedef tuple<int,int,int> P3;
const int MOD = 998244353, N = 303030;
int add(int x, int y) { return x + y >= MOD ? x + y - MOD : x + y; }
int sub(int x, int y) { return x - y < 0 ? x - y + MOD : x - y; }
int mul(int x, int y) { return 1LL * x * y % MOD; }
int qpow(int x, int y) {
  int ret = 1;
  for(; y; y >>= 1, x = mul(x, x))
    if(y & 1) ret = mul(ret, x);
  return ret;
}
struct UF {
  vi e;
  UF(int n) : e(n, -1) {}
  bool sameSet(int a, int b) { return find(a) == find(b); }
  int size(int x) { return -e[find(x)]; }
  int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
  bool join(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return false;
    if (e[a] > e[b]) swap(a, b);
    e[a] += e[b]; e[b] = a;
    return true;
  }
};

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int f[N], g[N], fac[N], ifac[N];
int C(int n, int m) {
  if(m > n) return 0;
  return mul(fac[n], mul(ifac[m], ifac[n-m]));
}
void solve() {
  int n, ans = 0; read(n);
  for(int i = 0; i * 2 <= n; ++i) {
    debug(i, C(n-i, i), f[n-2*i], g[i]);
    ans = add(ans, mul(C(n-i, i), mul(f[n-2*i], g[i])));
  }
  cout << ans << '\n';
}
signed main() {
  fac[0] = ifac[0] = 1;
  rep(i, 1, N) {
    fac[i] = mul(fac[i-1], i);
    ifac[i] = qpow(fac[i], MOD-2);
  }
  f[0] = f[1] = g[0] = 1, g[1] = 0;
  rep(i, 2, N) {
    f[i] = add(f[i-1], mul(i-1, f[i-2]));
    g[i] = mul(i-1, mul(2, g[i-2]));
  }
  int T; read(T);
  while(T--) solve();
  return 0;
}

/*

[i, C(n-i, i), f[n-2*i], g[i]]: 0 1 10 1
[i, C(n-i, i), f[n-2*i], g[i]]: 1 3 2 0
[i, C(n-i, i), f[n-2*i], g[i]]: 2 1 1 1
11
*/