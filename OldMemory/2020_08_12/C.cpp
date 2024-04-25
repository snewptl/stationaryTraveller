#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[205],b[205];
int mp[205][205];
const int inf=511;
int ans;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)scanf("%d",&b[i]);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            mp[i][j]=a[i]&b[j];
        }
    }
    for(int k=8;k>=0;k--){
        int x=(1<<k),flag=0;
        for(int i=1;i<=n;i++){
            int tmp=0;
            for(int j=1;j<=m;j++){
                if((mp[i][j]&x)==0)tmp=1;
            }
            if(!tmp)flag=1;
        }
        if(!flag){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(mp[i][j]&x)mp[i][j]=inf;
                }
            }
        }
        else ans+=x;
    }
    printf("%d",ans);
    return 0;
}