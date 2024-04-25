#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T;scanf("%d",&T);
    while(T--){
        int n,flag=0;
        scanf("%d",&n);
        for(int i=0;i<=2;i++){
            if(flag)break;
            for(int j=0;j<=2;j++){
                if(flag)break;
                int x=i*5+j*7;
                if(x<=n&&(n-x)%3==0){
                    printf("%d %d %d\n",(n-x)/3,i,j);
                    flag=1;
                }
            }
        }
        if(!flag)printf("-1\n");
    }

    return 0;
}