#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n;
int r[4],c[4];
int x,y;
int vis[2][2];
int cnt[2][2];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d",&n);
        memset(vis,0,sizeof(vis));
        memset(cnt,0,sizeof(cnt));
        int flag=0;
        for(int i=0;i<3;i++){
            scanf("%d%d",&r[i],&c[i]);
            if(r[i]==n)cnt[0][1]++;
            if(r[i]==1)cnt[0][0]++;
            if(c[i]==n)cnt[1][1]++;
            if(c[i]==1)cnt[1][0]++;
            r[i]--,c[i]--;
            vis[r[i]%2][c[i]%2]=1;
        }
        scanf("%d%d",&x,&y);
        x--,y--;
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++){
                if(flag)break;
                if(cnt[0][i]>=2&&cnt[1][j]>=2)flag=1;
                if(flag){
                    if(x!=i*(n-1)&&y!=j*(n-1))puts("NO");
                    else puts("YES");                    
                }
            }
        x%=2,y%=2;
        if(!flag){
            if(vis[x][y])puts("YES");
            else puts("NO");            
        }

	}


	return 0;
}