#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=25e4+10;
int n,m;
int h[maxn],l[maxn];
int mp[501][501];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        int x;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%d",&x);
                l[x]=j;
            }
            
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                scanf("%d",&x);
                h[x]=j;
            }
            
        }
        for(int i=1;i<=m*n;i++){
            mp[h[i]][l[i]]=i;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)
            printf("%d ",mp[i][j]);
            printf("\n");
        }
    }
    

    return 0;
}