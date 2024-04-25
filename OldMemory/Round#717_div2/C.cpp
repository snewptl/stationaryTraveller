#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,a[maxn],sum;
int d=(1<<20);
int dp[maxn];
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		d=gcd(d,a[i]);
		sum+=a[i];
	}
	int pos=0;
	for(int i=1;i<=n;i++){
		if((a[i]/d)%2!=0)pos=i;
	}
	dp[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=sum/2;j>=a[i];j--){
			if(dp[j-a[i]])dp[j]=1;
		}
	}
	if(dp[sum/2]&&sum%2==0)printf("1\n%d\n",pos);
	else printf("0\n");
    return 0;
}