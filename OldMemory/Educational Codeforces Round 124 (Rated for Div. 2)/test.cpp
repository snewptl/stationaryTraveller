#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

struct node{
	node *l, *r;
	long long sumc, sumr;
	node() : l(NULL), r(NULL), sumc(0), sumr(0) {}
	node(node* l, node* r, long long sumc, long long sumr) : l(l), r(r), sumc(sumc), sumr(sumr) {}
};

node* build(int l, int r, vector<int> &c){
	if (l == r - 1)
		return new node(NULL, NULL, c[l], 0);
	int m = (l + r) / 2;
	node* nw = new node();
	nw->l = build(l, m, c);
	nw->r = build(m, r, c);
	nw->sumc = nw->l->sumc + nw->r->sumc;
	return nw;
}

node* upd(node* v, int l, int r, int pos, int val){
	if (l == r - 1)
		return new node(NULL, NULL, 0, val);
	int m = (l + r) / 2;
	node* nw = new node(v->l, v->r, 0, 0);
	if (pos < m)
		nw->l = upd(v->l, l, m, pos, val);
	else
		nw->r = upd(v->r, m, r, pos, val);
	nw->sumc = nw->l->sumc + nw->r->sumc;
	nw->sumr = nw->l->sumr + nw->r->sumr;
	return nw;
}

long long getsum(node *v, int mult){
	return v->sumc + v->sumr * mult;
}

int trav(node *v, int l, int r, int L, int R, long long &lft, int mult){
	if (L >= R){
		return 0;
	}
	if (l == L && r == R && lft - getsum(v, mult) >= 0){
		lft -= getsum(v, mult);
		return r - l;
	}
	if (l == r - 1){
		return 0;
	}
	int m = (l + r) / 2;
	int cnt = trav(v->l, l, m, L, min(m, R), lft, mult);
	if (cnt == max(0, min(m, R) - L))
		cnt += trav(v->r, m, r, max(m, L), R, lft, mult);
	return cnt;
}

struct seg{
	int l, r, lst, cur;
};

int main() {
	int n;
	scanf("%d", &n);
	vector<int> c(n), r(n);
	forn(i, n) scanf("%d%d", &c[i], &r[i]);
	
	vector<int> ord(n);
	iota(ord.begin(), ord.end(), 0);
	sort(ord.begin(), ord.end(), [&](int x, int y){
		return c[x] / r[x] > c[y] / r[y];
	});
	vector<int> vals;
	for (int i : ord) vals.push_back(c[i] / r[i]);
	
	vector<node*> root(1, build(0, n, c));
	for (int i : ord)
		root.push_back(upd(root.back(), 0, n, i, r[i]));
	
	vector<seg> st;
	for (int i = n - 1; i >= 0; --i)
		st.push_back({i, i + 1, 0, c[i]});
	
	long long ans = 0;
	int q;
	scanf("%d", &q);
	forn(_, q){
		int t;
		long long h;
		scanf("%d%lld", &t, &h);
		while (!st.empty()){
			auto it = st.back();
			st.pop_back();
			if (it.r - it.l == 1){
				it.cur = min((long long)c[it.l], it.cur + (t - it.lst) * 1ll * r[it.l]);
				if (it.cur <= h){
					h -= it.cur;
				}
				else{
					st.push_back({it.l, it.r, t, int(it.cur - h)});
					h = 0;
				}
			}
			
			else{
				int mx = vals.rend() - lower_bound(vals.rbegin(), vals.rend(), t - it.lst);
				int res = it.l + trav(root[mx], 0, n, it.l, it.r, h, t - it.lst);
				assert(res <= it.r);
				if (res != it.r){
					if (it.r - res > 1)
						st.push_back({res + 1, it.r, it.lst, 0});
					int nw = min((long long)c[res], r[res] * 1ll * (t - it.lst));
					assert(nw - h > 0);
					st.push_back({res, res + 1, t, int(nw - h)});
					h = 0;
				}
			}
			if (h == 0){
				break;
			}
		}
		if (st.empty()){
			st.push_back({0, n, t, 0});
		}
		else if (st.back().l != 0){
			st.push_back({0, st.back().l, t, 0});
		}
		ans += h;
	}
	
	printf("%lld\n", ans);
	return 0;
}