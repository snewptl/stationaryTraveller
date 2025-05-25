#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int a[maxn],n;
bool cmp(int x,int y){
	if(x%2!=y%2)return x%2<y%2;
	return x<y;
}
int ans;
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		sort(a+1,a+n+1,cmp);
		ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]%2==0)ans+=n-i;
			else {
				for(int j=i+1;j<=n;j++){
					if(gcd(a[i],a[j])!=1)ans++;
				}
			}
		}
		printf("%d\n",ans);
    }


    return 0;
}