#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    int a[101];
    scanf("%d",&t);
    while(t--){
        int mn=0x3f3f3f;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            mn=min(mn,a[i]);
        }
        int flag=0;
        for(int i=1;i<=n;i++){
            if((a[i]-mn)%2){
                flag=1;
            }
        }
        if(flag)printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}