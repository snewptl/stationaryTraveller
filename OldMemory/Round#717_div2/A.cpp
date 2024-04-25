#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,a[maxn];
int k;
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
		int temp=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			int x=min(a[i],k);
			a[i]-=x;
			temp+=x;
			k-=x;
		}
		for(int i=1;i<n;i++){
			printf("%d ",a[i]);
		}
		printf("%d\n",a[n]+temp);
    }


    return 0;
}