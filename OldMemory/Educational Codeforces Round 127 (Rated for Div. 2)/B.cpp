#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,a[maxn],ans;
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=a[1]-1;i<=a[1]+1;i++){
			int cur=i,j=0,flag=1;
			for(;j<n;j++){
				int temp=abs(j+cur-a[j+1]);
				if(temp>1)flag=0;
			}
			if(flag)ans=1;
		}
		if(ans)puts("YES");
		else puts("NO");
	}


	return 0;
}