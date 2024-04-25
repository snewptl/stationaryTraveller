#include<bits/stdc++.h>
using namespace std;
int n,m;int x,y;
int main(){
    scanf("%d%d%d%d",&n,&m,&x,&y);
    printf("%d %d\n",x,y);
    for(int i=2;i<=n;i++){
        if(i==x)continue;
        printf("%d %d\n",i,y);
    }
    printf("%d %d\n",1,y);
    for(int i=1;i<=n;i++){
        if(i%2==1)for(int j=1;j<=m;j++){
            if(j==y)continue;
            printf("%d %d\n",i,j);
        }
        else for(int j=m;j>=1;j--){
            if(j==y)continue;
            printf("%d %d\n",i,j);
        }
    }
    return 0;
}