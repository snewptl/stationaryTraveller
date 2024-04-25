#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n;
ll sum;
int a[maxn];
double ans;
int main(){
    int T;scanf("%d",&T);
    while(T--){
		sum=0;
		ans=-1e18;
        scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		sort(a+1,a+n+1);
		ll temp=0;
		for(int i=1;i<n;i++){
			temp+=a[i];
			ans=max(ans,1.0*temp/i+1.0*(sum-temp)/(n-i));
		}
		printf("%.8lf\n",ans);
    }


    return 0;
}