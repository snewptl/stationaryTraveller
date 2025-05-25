#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n;
int ans[4];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<4;i++)ans[i]=0;
		for(int i=1;i<=n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			if(x){
				if(x<=0)ans[0]=max(ans[0],abs(x));
				else ans[1]=max(ans[1],abs(x));
			}
			else {
				if(y<=0)ans[2]=max(ans[2],abs(y));
				else ans[3]=max(ans[3],abs(y));
			}
		}
		int res=0;
		for(int i=0;i<4;i++)res+=ans[i];
		printf("%d\n",res*2);
	}


	return 0;
}