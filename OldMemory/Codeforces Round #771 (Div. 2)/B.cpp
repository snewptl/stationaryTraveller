#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=1e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,a[maxn];
int flag1,flag0;
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		flag0=flag1=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		int pre0=0,pre1=0,flag=1;
		for(int i=1;i<=n;i++){
			if(a[i]%2){
				if(pre1>a[i])flag=0;
				pre1=a[i];
			}
			if(a[i]%2==0){
				if(pre0>a[i])flag=0;
				pre0=a[i];
			}
		}
		if(flag)puts("YES");
		else puts("NO");
	}


	return 0;
}