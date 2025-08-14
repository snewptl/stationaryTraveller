ll fac[maxn];
ll quick_pow(ll x, ll y) {
    ll res = 1;
    while (y) {
        if (y & 1) res *= x, res %= mod;
        x *= x, x %= mod;
        y /= 2;
    }
    return res;
}
ll inv(ll x) {
    return quick_pow(x, mod - 2);
}
ll C(ll x, ll y) {
    if (y > x) return 0;
    return fac[x] * inv(fac[y]) % mod * inv(fac[x - y]) % mod;
} 
fac[0] = 1;
for (int i = 1; i <= 1e6; ++i) {
    fac[i] = fac[i - 1] * i % mod;
}