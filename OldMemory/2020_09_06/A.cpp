#include<bits/stdc++.h>
using namespace std;
const int maxn=101;
int n,a[maxn];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        for(int i=n;i>=1;i--)printf("%d ",a[i]);
        printf("\n");
    }

    return 0;
}