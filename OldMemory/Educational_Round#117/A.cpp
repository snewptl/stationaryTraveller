#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=1e5+5;
const ll mod=998244353;
const double eps=1e-10;
int x,y;
void solve(){
	for(int i=0;i<=x;i++){
		for(int j=0;j<=y;j++){
			if((i+j)*2==x+y&&(x-i+y-j)*2==x+y){
				printf("%d %d\n",i,j);
				return ;				
			}

		}
	}	
	printf("-1 -1\n");
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){

		scanf("%d%d",&x,&y);
		solve();
	}


	return 0;
}