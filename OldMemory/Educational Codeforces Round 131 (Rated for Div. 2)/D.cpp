#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=5e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,b[maxn],a[maxn];
struct Seg{
	int l,r,idx;
}seg[maxn];
bool cmp(Seg x,Seg y){
	return x.r==y.r?x.l<y.l:x.r<y.r;
}
set<pii>s[maxn],cur;
void init(){
	for(int i=1;i<=n;i++)s[i].clear();
	cur.clear();
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		init();
		for(int i=1;i<=n;i++)scanf("%d",&b[i]);
		for(int i=1;i<=n;i++){
			int l,r;
			if(b[i])l=i/(b[i]+1)+1,r=i/b[i];
			else l=i+1,r=1e9;
			// seg[i]={l,r,i};
			s[l].insert({r,i});
		}
		// sort(seg+1,seg+n+1,cmp);
		for(int i=1;i<=n;i++){
			for(auto it:s[i]){
				cur.insert(it);
			}
			auto temp=*cur.begin();
			a[temp.second]=i;
			cur.erase(cur.begin());
		}
		for(int i=1;i<=n;i++)printf("%d ",a[i]);
		puts("");
	}


	return 0;
}