#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int main(){
    int T;scanf("%d",&T);
    while(T--){
        int n;scanf("%d",&n);
        for(int i=2*n+2;i<=4*n;i+=2){
            printf("%d ",i);
        }
        printf("\n");
    }


    return 0;
}