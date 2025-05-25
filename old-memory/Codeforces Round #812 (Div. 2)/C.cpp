#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n;
int a[maxn];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int i=n-1;
		for(int i=0;i<n;i++)a[i]=i;
		while(i>=0){
			int x=sqrt(i);
			while(x*x<i)x++;
			int len=2*i-x*x+1;
			reverse(a+i-len+1,a+i+1);
			i-=len;
		}
		for(int i=0;i<n;i++)printf("%d ",a[i]);
		puts("");
	}


	return 0;
}