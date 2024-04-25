#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,k;
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
		int ans=k-1-(k-1)/2+n-k;
		printf("%d\n",ans);
		for(int i=n;i>k;i--)printf("%d ",i);
		for(int i=k-1;i>(k-1)/2;i--){
			printf("%d ",i);
		}
		printf("\n");
    }


    return 0;
}