#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=1e5+5;
const ll mod=998244353;
const double eps=1e-10;
int a,b,c;
int pri[maxn];
void get_pri(){
	for(int i=2;i<=1000;i++){
		int flag=1;
		for(int j=2;j*j<=i;j++)
		if(i%j==0)flag=0;
		if(flag)pri[i]=1;
	}
}
int main(){
	get_pri();
	int T=1;scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		c=1;
		for(int i=2;i<=1000;i++){
			if(!pri[i])continue;
			if((n-1)%i!=0){
				a=i;break;
			}
		}
		b=n-a-c;
		printf("%d %d %d\n",a,b,c);
	}


	return 0;
}