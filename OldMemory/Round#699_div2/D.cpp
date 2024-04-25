#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,m;
char mp[1005][1005],s[1005];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%s",s);
			for(int j=0;j<n;j++)
				mp[i][j+1]=s[j];
		}
		if(m%2==1){
			printf("YES\n");
			for(int i=1;i<=m/2;i++){
				printf("1 2 ");
			}
			printf("1 2\n");
		}
		else {
			int flag=0;
			int x,y;
			for(int i=1;i<=n;i++){
				if(flag)break;
				for(int j=1;j<=n;j++){
					if(flag)break;
					if(i==j)continue;
					if(mp[i][j]==mp[j][i]){
						printf("YES\n");
						x=i,y=j;
						flag=1;
					}
				}
			}
			if(flag){
				for(int i=1;i<=m/2;i++){
				printf("%d %d ",x,y);
			}
			printf("%d\n",x);
			}
			else printf("NO\n");
		}
    }


    return 0;
}