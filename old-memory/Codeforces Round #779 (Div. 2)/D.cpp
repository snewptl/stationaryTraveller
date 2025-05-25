#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n;
int c[maxn];
pii a[maxn];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int pos=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&c[i]);
			if(c[i]==1)pos=i;
		}
		int flag=1;
		if(!pos)flag=0;
		else {
			for(int i=pos+1;;i++){
				if(i>n)i-=n;
				if(i==pos)break;
				int pre=i-1;
				if(!pre)pre=n;
				if(c[i]>c[pre]){
					if(c[i]-c[pre]>1)flag=0;
				}
				if(c[i]==1)flag=0;
			}
		}	
		if(!flag)puts("NO");
		else puts("YES");
	}


	return 0;
}