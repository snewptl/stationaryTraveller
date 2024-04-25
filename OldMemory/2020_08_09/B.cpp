#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
char s[105],mp[105][105];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        memset(mp,0,sizeof(mp));ans=0;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            scanf("%s",s+1);
            for(int j=1;j<=m;j++){
                if(s[j]=='R')mp[i][j]=1;
                else mp[i][j]=0;
            }
        }
        mp[n][m]=2;
        for(int i=1;i<=n;i++)
            if(mp[i][m]==1)ans++;
        for(int i=1;i<=m;i++)
            if(mp[n][i]==0)ans++;
        printf("%d\n",ans);
    }
    
    return 0;
}