#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[101],b[101];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        for(int i=1;i<=n;i+=2){
            b[i]=-a[i+1];
            b[i+1]=a[i];
        }
        for(int i=1;i<=n;i++){
            printf("%d ",b[i]);
        }
        printf("\n");
    }


    return 0;
}