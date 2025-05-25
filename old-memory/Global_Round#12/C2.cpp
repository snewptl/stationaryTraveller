#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
const int maxn=3e2+10;
int n;
char mp[maxn][maxn];
int vis[maxn][maxn];
bool check(int x,int y){
	for(int i=0;i<=n;i++){
		for(int j=)
	}
}
int main(){
    int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=maxn;i++){
			for(int j=1;j<=maxn;j++)mp[i][j]='#';
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)vis[i][j]=0;
		}
		for(int i=1;i<=n;i++){
			scanf("%s",mp[i]+1);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(check(i,j,'X')){
					mp[i][j]='O';vis[i][j]=1;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(check2(i,j,'X')){
					mp[i][j]='O';vis[i][j]=1;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)printf("%c",mp[i][j]);
			printf("\n");
		}
	}
    return 0;
}