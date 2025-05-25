#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,m,ans;
char s[505];
int mp[505][505],sum[505][505];
int main(){
    int T;scanf("%d",&T);
    while(T--){
		ans=0;
        scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%s",s);
			for(int j=1;j<=m;j++){
				if(s[j-1]=='*')mp[i][j]=1;
				else mp[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)sum[i][j]=0;
			for(int j=1;j<=m;j++){
				if(mp[i][j])sum[i][j]=sum[i][j-1]+1;
				else sum[i][j]=sum[i][j-1];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				for(int k=1;k+i-1<=n;k++){
					if(j-k+1<1||j+k-1>m)break;
					if(sum[i+k-1][j+k-1]-sum[i+k-1][j-k]!=2*k-1)break;
					ans++;
				}
			}
		}
		printf("%d\n",ans);
    }


    return 0;
}