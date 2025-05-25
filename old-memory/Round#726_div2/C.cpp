#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,mn,p;
int a[maxn];
int main(){
    int T;scanf("%d",&T);
    while(T--){
		mn=1e9;
        scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		sort(a+1,a+n+1);
		for(int i=1;i<n;i++){
			if(a[i+1]-a[i]<mn)mn=a[i+1]-a[i],p=i;
		}
		if(mn==a[n]-a[1]){
			for(int i=1;i<=n;i++){
				printf("%d ",a[i]);
			}			
		}
		else {
			for(int i=p+1;i<=n;i++)printf("%d ",a[i]);
			for(int i=1;i<=p;i++)printf("%d ",a[i]);
		}

		printf("\n");
    }


    return 0;
}