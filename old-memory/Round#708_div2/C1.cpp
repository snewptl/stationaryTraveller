#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,k;
int tot,a[maxn];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
		if(n%2==1){
			printf("%d %d %d\n",n/2,n/2,1);
		}
		else {
			if(n/2%2==1)
				printf("%d %d %d\n",n/2-1,n/2-1,2);
			else 
				printf("%d %d %d\n",n/2/2,n/2/2,n/2);
		}

    }


    return 0;
}