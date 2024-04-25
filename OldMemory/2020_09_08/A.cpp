#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
int n,sum1,sum2;
int a[maxn],b[maxn],sum[3][maxn];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int flag=0,k=0;
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        for(int i=1;i<=n;i+=2)k+=a[i]-a[i+1];
        if(k==0){
            printf("%d\n",n);
            for(int i=1;i<=n;i++)printf("%d ",a[i]);
            printf("\n");
        }
        else for(int i=1;i<=n;i++){
            if(flag)break;
            k=0;
            for(int j=1;j<i;j++)b[j]=a[j];
            for(int j=i+1;j<=n;j++)b[j-1]=a[j];
            for(int j=0;j<n;j+=2)k+=b[j]-b[j+1];
            if(k==0){
                flag=1;
                printf("%d\n",n-1);
                for(int j=1;j<=n;j++){
                    if(j==i)continue;
                    printf("%d ",a[j]);
                }
                printf("\n");
            }
        }
    }

    return 0;
}