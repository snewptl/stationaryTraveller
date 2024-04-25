#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
ll a[maxn];
int n;
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
		ll sum=0,flag=1,j=0;
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(int i=1;i<=n;i++){
			sum+=a[i];j+=i-1;
			if(sum<j)flag=0;
			
		}
		if(flag)printf("YES\n");
		else printf("NO\n");
    }


    return 0;
}