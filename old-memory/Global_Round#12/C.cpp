#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
const int maxn=3e2+10;
int n;
char mp[maxn][maxn];
int vis[maxn][4]={{0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,1,0},{2,0,1}};
int sum[maxn],tot;
int main(){
    int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%s",mp[i]);
		}
		int st=0;
		for(int i=0;i<n;i++){
			int cnt=0,tmp=0;
			for(int j=0;j<n;j++)
				if(mp[i][j]=='X')cnt++;
			sum[i]=cnt;
			tot+=sum[i];
		}
		for(int i=0;i<6;i++){
			int ans=0;
			for(int j=0;j<n;j++){
				ans+=(sum[j]-1-vis[i][j%3])/3+1;
			}
			if(ans<=tot/3){
				for(int j=0;j<n;j++){
					int cnt=0;
					for(int k=0;k<n;k++){
						if(mp[j][k]=='X'){
							if(cnt%3==vis[i][j%3])mp[j][k]='X';
							cnt++;
						}
					}
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)printf("%c",mp[i][j]);
			printf("\n");
		}
	}
    return 0;
}