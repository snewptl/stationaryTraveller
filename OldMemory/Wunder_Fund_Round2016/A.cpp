#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int main(){
        int n;scanf("%d",&n);
		for(int i=30;i>=0;i--){
			if(n&(1<<i)){
				printf("%d ",i+1);
			}
		}
		printf("\n");

    return 0;
}