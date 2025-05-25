#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,m,q;
int a[maxn];
int st[maxn][25];
int main(){
	int T=1;//scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++){
			scanf("%d",&a[i]);
			st[i][0]=a[i];
		}
		for(int i=1;i<20;i++){
			int sz=(1<<(i-1));
			for(int j=1;j<=m;j++){
				if(sz+j>=maxn)break;
				st[j][i]=max(st[j][i-1],st[j+sz][i-1]);
			}
		}
		scanf("%d",&q);
		while(q--){
			pii s,t;
			int k;
			scanf("%d%d%d%d%d",&s.first,&s.second,&t.first,&t.second,&k);
			if(s.second>t.second)swap(s,t);
			if(abs(s.first-t.first)%k||abs(s.second-t.second)%k)puts("NO");
			else {
				int mx=(n-s.first)/k*k+s.first,res=0;
				for(int i=20;i>=0;i--){
					int sz=(1<<i);
					if(sz+s.second<=t.second){
						res=max(res,st[s.second][i]);
						s.second+=sz;
					}
				}
				if(mx>res)puts("YES");
				else puts("NO");
			}
		}
	}


	return 0;
}