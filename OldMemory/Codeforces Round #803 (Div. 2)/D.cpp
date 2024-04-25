#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int a[maxn],n,ans;
void ask(int l,int r){
	printf("? %d %d\n",l,r);
	fflush(stdout);
	for(int i=l;i<=r;i++)scanf("%d",&a[i]);
}
bool check(int l,int r){
	ask(l,r);
	int cnt=0;
	for(int i=l;i<=r;i++)if(a[i]>r||a[i]<l)cnt++;
	int k=r-l+1;
	if((k-cnt)%2==0)return false;
	else return true;
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int l=1,r=n;
		while(l<r){
			int mid=l+r>>1;
			if(check(l,mid))r=mid;
			else l=mid+1;
		}
		printf("! %d\n",l);
		fflush(stdout);
	}


	return 0;
}