#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=1e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n;
int vis[maxn];
int opt[maxn];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)vis[i]=-1;
		printf("? 1 2 3\n");
		fflush(stdout);
		int cur;
		scanf("%d",&cur);
		int flag=0;
		for(int i=1;i<=n;i+=3){
			printf("%d %d %d\n",i,i+1,i+2);
			fflush(stdout);
			scanf("%d",&opt[i]);
		}
		for(int i=4;i<=n;i++){
			printf("? 1 2 %d\n",i);
			fflush(stdout);
			int temp;
			scanf("%d",&temp);
			if(temp!=cur)flag=1;
			if(temp==0)vis[i]=0;
			else vis[i]=1;
		}
		if(!flag){
			for(int i=4;i<=n;i++){
				printf("? 1 3%d\n",i);
				fflush(stdout);
				int temp;
				scanf("%d",&temp);
				if(temp!=cur)flag=1;
				if(temp==0)vis[i]=0;
				else vis[i]=1;				
			}
		}
	}


	return 0;
}