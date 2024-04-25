#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;scanf("%d",&n);
        int x=2;
        for(int i=2;x-1<=n;i++){
            x*=2;
            if(n%(x-1)==0){
                printf("%d\n",n/(x-1));
                break;
            }
        }
    }
    return 0;
}