#include<bits/stdc++.h>
using namespace std;
int vis[101];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        memset(vis,0,sizeof(vis));
        int n;scanf("%d",&n);
        int k=n;
        while(k){printf("%d ",k);vis[k]=1;k>>=1;}
        for(int i=1;i<=n;i++)
            if(!vis[i])printf("%d ",i);
        printf("\n");
    }
    
    return 0;
}