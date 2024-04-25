#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=1e5+5;
const ll mod=998244353;
const double eps=1e-10;
char s[maxn][15],t[maxn][15];
int main(){
	int T=1;//scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)scanf("%s",s[i]);
		for(int i=0;i<m;i++)scanf("%s",t[i]);
		int q;
		scanf("%d",&q);
		while(q--){
			int y;
			scanf("%d",&y);y--;
			printf("%s%s\n",s[y%n],t[y%m]);
		}
	}


	return 0;
}