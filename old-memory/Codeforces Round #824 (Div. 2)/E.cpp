#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,d[2][1005],len,p0=1e9,p1,sgn;
int pos[1005];
map<ll,int>vis[2];
void init(){
    p0=1e9;
    sgn=0;
}
void reld(){
    vis[0].clear();
    vis[1].clear();
    for(int i=0;i<2;i++){
        for(int j=1;j<=n;j++){
            vis[i][d[i][j]]++;
        }
    }
}
bool solve(){
    len=d[0][1]+d[1][n];
    int flag=1;
    for(int i=2;i<=n;i++){
        if(d[0][i]+d[1][n-i+1]!=len){
            flag=0;
            break;
        }
    }
    if(flag){
        for(int i=1;i<=n;i++){
            pos[i]=p0-d[0][i];
        }
        p1=p0-len;
        return true;
    }
    for(int i=n;i>=1;i--){
        flag=1;
        len=d[0][n]-d[1][i];
        p1=p0-len;
        reld();
        int r0=n,r1=n,cnt=0;
        while(d[0][r0]>len||d[1][r1]>len){
            if(d[0][r0]>=d[1][r1]){
                pos[++cnt]=p0-d[0][r0];
                vis[0][d[0][r0]]--;
                if(vis[1][d[0][r0]-len]<=0){
                    flag=0;
                    break;
                }
                vis[1][d[0][r0]-len]--;
                r0--;
            }
            else {
                pos[++cnt]=p1+d[1][r1];
                vis[1][d[1][r1]]--;
                if(vis[0][d[1][r1]-len]<=0){
                    flag=0;
                    break;
                }
                vis[0][d[1][r1]-len]--;
                r1--;
            }  
            while(r0&&vis[0][d[0][r0]]<=0)r0--;
            while(r1&&vis[1][d[1][r1]]<=0)r1--;
        }
        // printf("##%d %d\n",len,flag);
        for(int i=1;i<=n;i++){
            if(vis[0][d[0][i]]>0){
                // printf("%d %d\n",d[0][i],len-d[0][i]);
                vis[0][d[0][i]]--;
                if(vis[1][len-d[0][i]]<=0)flag=0;
                vis[1][len-d[0][i]]--;
                pos[++cnt]=p0-d[0][i];
            }
        }
        if(flag)return true;
    }
    return false;
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d",&n);
        init();
        for(int i=0;i<2;i++){
            for(int j=1;j<=n;j++){
                scanf("%d",&d[i][j]);
            }
            sort(d[i]+1,d[i]+n+1);
        }
        if(d[0][n]<d[1][n]){
            for(int i=1;i<=n;i++)swap(d[0][i],d[1][i]);
            sgn=1;
        }

        if(!solve())puts("NO");
        else {
            puts("YES");
            for(int i=1;i<=n;i++)printf("%d ",pos[i]);
            puts("");
            if(sgn)swap(p0,p1);
            printf("%d %d\n",p1,p0);
        }
	}


	return 0;
}
/*
1
2
10 33
26 69
*/