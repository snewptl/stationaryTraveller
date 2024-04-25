#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,k;
int mi[20],p;
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
		if(k>3){
			int m=n%k;int x=m;m=min(k/2,m);
			for(int i=1;i<=m;i++)printf("%d ",n/k*2);
			for(int i=m+1;i<=k-m;i++){
				printf("%d ",n/k);
			}
			for(int i=1;i<=x-m;i++){
				printf("%d ",2);
			}
			for(int i=x-m+1;i<=m;i++)
				printf("%d ",1);
			printf("\n");			
		}
		else {
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

    }


    return 0;
}