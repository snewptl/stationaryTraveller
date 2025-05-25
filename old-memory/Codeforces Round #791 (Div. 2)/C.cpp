#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,q;
int val[2][maxn],vis[2][maxn];
int lowbit(int x){
	return x&(-x);
}
int query(int sgn,int x){
	int res=0;
	while(x){
		res+=val[sgn][x];
		x-=lowbit(x);
	}
	return res;
}
void update(int sgn,int x,int p){
	while(x&&x<=n){
		val[sgn][x]+=p;
		x+=lowbit(x);
	}
}
int main(){
	int T=1;//scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&q);
		for(int i=1;i<=q;i++){
			int opt,x,y;
			scanf("%d",&opt);
			if(opt==1){
				scanf("%d%d",&x,&y);
				if(!vis[0][x])update(0,x,1);
				if(!vis[1][y])update(1,y,1);
				vis[0][x]++;
				vis[1][y]++;
			}
			if(opt==2){
				scanf("%d%d",&x,&y);
				vis[0][x]--;
				vis[1][y]--;				
				if(!vis[0][x])update(0,x,-1);
				if(!vis[1][y])update(1,y,-1);
			}
			if(opt==3){
				int x1,x2,y1,y2;
				scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
				int sum1=query(1,y2)-query(1,y1-1);
				int sum0=query(0,x2)-query(0,x1-1);
				if(sum1!=y2-y1+1&&sum0!=x2-x1+1)puts("NO");
				else puts("YES");
			}			
		}
	}


	return 0;
}