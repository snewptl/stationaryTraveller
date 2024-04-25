#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int MOD = 998244353;
const int K = 161;
const int AL = 26;

struct node{
	int nxt[AL];
	bool term;
	node(){
		memset(nxt, -1, sizeof(nxt));
		term = false;
	};
	int& operator [](const int x){
		return nxt[x];
	}
};

vector<node> trie;

int tot;

void add(const string &s){
	int cur = 0;
	int d = 1;
	for (const char &c : s){
		++d;
		if (trie[cur][c - 'a'] == -1){
			trie[cur][c - 'a'] = trie.size();
			trie.push_back(node());
			tot += d;
		}
		cur = trie[cur][c - 'a'];
	}
	trie[cur].term = true;
}

int add(int a, int b){
	a += b;
	if (a >= MOD)
		a -= MOD;
	return a;
}

int mul(int a, int b){
	return a * 1ll * b % MOD;
}

typedef array<array<int, K>, K> mat;

mat operator *(const mat &a, const mat &b){
	mat c;
	forn(i, K) forn(j, K) c[i][j] = 0;
	forn(i, K) forn(j, K) forn(k, K)
		c[i][j] = add(c[i][j], mul(a[i][k], b[k][j]));
	return c;
}

mat binpow(mat a, long long b){
	mat res;
	forn(i, K) forn(j, K) res[i][j] = i == j;
	while (b){
		if (b & 1)
			res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}

map<pair<int, int>, int> num;
queue<pair<int, int>> q;

int get(int v, int u){
	if (v > u) swap(v, u);
	if (!num.count({v, u})){
		int k = num.size();
		assert(k < K);
		num[{v, u}] = k;
		q.push({v, u});
	}
	return num[{v, u}];
}

int main() {
	int n;
	long long m;
	cin >> n >> m;
	trie = vector<node>(1, node());
	tot = 1;
	forn(i, n){
		string s;
		cin >> s;
		add(s);
	}
	q.push({0, 0});
	num[q.front()] = 0;
	mat init;
	forn(i, K) forn(j, K) init[i][j] = 0;
	while (!q.empty()){
		int v = q.front().first;
		int u = q.front().second;
		q.pop();
		int x = get(v, u);
		forn(c, AL){
			int tov = trie[v][c];
			int tou = trie[u][c];
			if (tov == -1 || tou == -1) continue;
			++init[x][get(tov, tou)];
			if (trie[tov].term) ++init[x][get(0, tou)];
			if (trie[tou].term) ++init[x][get(tov, 0)];
			if (trie[tov].term && trie[tou].term) ++init[x][0];
		}
	}
	init = binpow(init, m);
	printf("%d\n", init[0][0]);
	return 0;
}