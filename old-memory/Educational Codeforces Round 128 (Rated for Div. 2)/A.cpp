#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int l1,l2,r1,r2;
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		cin>>l1>>r1>>l2>>r2;
		if(min(r1,r2)>=max(l1,l2))printf("%d\n",max(l1,l2));
		else printf("%d\n",l1+l2);
	}


	return 0;
}