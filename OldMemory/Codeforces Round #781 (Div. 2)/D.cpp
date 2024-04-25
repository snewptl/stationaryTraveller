#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int ans[35];
int ad,x,pre;
void init(){
	pre=0;
	ad=0;
	x=0;
	for(int i=0;i<30;i++)ans[i]=0;
}
ll ask(int a,int b){
	printf("? %d %d\n",a,b);
	fflush(stdout);
	ll opt;
	scanf("%lld",&opt);
	return opt;
}
void solve(){
	for(int i=0;i<30;i++){
		int cur=1<<i;
		ll res;
		if(!ad)res=ask(cur,cur+cur*2);
		else res=ask(ad,cur*2+ad);
		if(res%(cur*2)==0){
			ans[i]=1;
			if(!ad)ad=cur;
		}
		else {
			ans[i]=0;
			if(ad)ad+=cur;
		}
		// printf("##%d %d\n",ad,ans[i]);
	}
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		init();
		solve();
		int pos=29;
		while(pos>=0&&!ans[pos])pos--;
		if(pos<0)pos=0;
		printf("! ");
		for(int i=pos;i>=0;i--){
			x*=2;
			x+=ans[i];
		}
		printf("%d\n",x);
		fflush(stdout);
	}


	return 0;
}