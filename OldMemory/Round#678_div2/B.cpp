#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int a[105][105],n;
bool is_prime(int x){
    if(x==0||x==1)return false;
    for(int i=2;i*i<=x;i++){
        if(x%i==0)return false;
    }
    return true;
}
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                a[i][j]=1;
            }
        }
        int x=0;
        for(int i=n;i<=maxn-10;i++){
            if(is_prime(i)){
                if(!is_prime(i-n+1)){
                    x=i-n+1;break;
                }
            }
        }
        for(int i=1;i<=n;i++)a[i][i]=x;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
            printf("%d ",a[i][j]);
            printf("\n");
        }
    }


    return 0;
}