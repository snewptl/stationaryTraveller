#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int n;
ll sum,ans;
ll a[maxn];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%lld",&n);sum=0;
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		sort(a+1,a+n+1);
		for(int i=2;i<=n;i++)sum+=a[i];
		a[1]-=a[n]*(n-1)-sum;
		if(a[1]<=0)ans=-a[1];
		else{
			ans=(n-1-a[1]%(n-1))%(n-1);
		}
		printf("%lld\n",ans);
    }


    return 0;
}