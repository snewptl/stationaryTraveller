#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int main(){
    int T;scanf("%d",&T);
    while(T--){
        int n,k;
		scanf("%d%d",&n,&k);
		int t=0;
		for(int i=1;i<=n;i+=k){
			for(int j=i;j<=min(n,i+k-1);j++)
			printf("%c",t+'a');
			
			t++;t%=3;
		}printf("\n");
    }


    return 0;
}