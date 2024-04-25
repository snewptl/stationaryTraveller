#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int m,n;
char s[10][10];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%s",s[i]+1);
		}
		int flag=1,out=0;
		for(int i=1;i<=n;i++){
			if(out)break;
			for(int j=1;j<=m;j++){
				if(s[i][j]=='R'){
					for(int k=i+1;k<=n;k++){
						for(int t=1;t<j;t++){
							if(s[k][t]=='R')flag=0;
						}
					}
					out=1;
					break;
				}
			}
		}
		if(flag)puts("YES");
		else puts("NO");

	}


	return 0;
}