#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        printf("2\n");
        int x=n;
        for(int i=n-1;i>=1;i--){
            printf("%d %d\n",i,x);
            x=(i+x-1)/2+1;
        }
    }

    return 0;
}