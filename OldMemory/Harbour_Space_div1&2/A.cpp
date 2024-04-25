#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n;
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
		printf("%d\n",n/10+(n%10==9));
    }


    return 0;
}