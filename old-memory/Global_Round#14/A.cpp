#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,x;
int a[maxn],b[maxn];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&x);
		int sum=0,ans=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			ans+=a[i];
		}
		if(x==ans)printf("NO\n");
		
		else {
			sum=0;
			printf("YES\n");
			for(int i=1;i<n;i++){
				sum+=a[i];
				if(sum==x){
					swap(a[i],a[i+1]);
					break;
				}
			}
			for(int i=1;i<=n;i++)printf("%d ",a[i]);
			printf("\n");			
		}

    }


    return 0;
}