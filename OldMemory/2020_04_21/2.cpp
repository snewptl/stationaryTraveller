#include<bits/stdc++.h>
using namespace std;
int n,a[200000+10];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        if(n%4)printf("NO\n");
        else {
            printf("YES\n");
            for(int i=1;i<=n/2;i++){
                printf("%d ",i*2);
            }
            for(int i=1;i<n/2;i++){
                printf("%d ",i*2-1);
            }
            printf("%d\n",n/2-1+n);
        }
        
    }
    return 0;
}