#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,k;
int a[maxn],b[maxn];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			b[i]=a[i];
		}
		sort(a+1,a+n+1);
		int x=(n+k-1)/2+1;
		int ans=1e9,l,r;
		for(int i=1;i<=n;i++){
			if(i+x-1>n)break;
			if(ans>a[i+x-1]-a[i]){
				ans=a[i+x-1]-a[i];
				l=a[i],r=a[i+x-1];
			}
		}
		int cnt=0,cur=0,pre=0;
		printf("%d %d\n",l,r);
		for(int i=1;i<=n;i++){
			if(cur==k-1){
				printf("%d %d\n",i,n);
				break;
			}
			if(b[i]<l||b[i]>r)cnt--;
			else cnt++;
			if(cnt==1){
				printf("%d %d\n",pre+1,i);
				pre=i;
				cnt=0;
				cur++;
			}
		}
	}


	return 0;
}