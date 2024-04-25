#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=5e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,a[maxn];
int b[maxn];

ll cal(int l,int r){
	if(l==r)return 0;
	int mid=l+r>>1;
	ll res=0;
	res=cal(l,mid)+cal(mid+1,r);
	int le=l,ri=mid+1;
	int cur=l;
	while(le<=mid&&ri<=r){
		while(le<=mid&&ri<=r&&a[le]<=a[ri])b[cur]=a[le],le++,cur++,res+=ri-mid-1;
		while(ri<=r&&le<=mid&&a[ri]<a[le])b[cur]=a[ri],ri++,cur++;
	}
	while(le<=mid)b[cur]=a[le],le++,cur++,res+=r-mid;
	while(ri<=r)b[cur]=a[ri],ri++,cur++;
	for(int i=l;i<=r;i++)a[i]=b[i];
	return res;
}

int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		if(cal(1,n)){
			int flag=0;
			for(int i=1;i<n;i++){
				if(a[i]==a[i+1]){
					flag=1;
				}
			}
			if(flag)puts("YES");
			else puts("NO");
		}
		else puts("YES");
	}


	return 0;
}