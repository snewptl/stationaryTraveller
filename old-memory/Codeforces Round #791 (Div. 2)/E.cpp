#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=4e5+5;
const ll mod=998244353;
const double eps=1e-10;
ll f[maxn][20],dp[maxn][20],mi[1005];
int n,q;
char s[maxn],t[maxn];
void solve(int sz){
	int cnt=0;
	mi[0]=1;
	for(int i=1;i<=1000;i++)mi[i]=mi[i-1]*sz,mi[i]%=mod;
	for(int i=1;i<2*n;i++)t[i]='#';
	for(int i=1;i<=n;i++){
		t[i*2-1]=s[i];
		if(s[i]=='?')cnt++;
	}
	for(int i=1;i<2*n;i++){
		int l=i,r=i,cur=0,tot=0;
		ll temp=1;
		while(l>=1&&r<2*n){
			if(t[l]=='#')l--,r++;
			else {
				if(t[l]==t[r]){
					if(t[l]=='?'){
						temp*=sz,temp%=mod;
						if(l!=r)tot+=2;
						else tot++;
						f[cur][sz]+=temp*mi[cnt-tot];
						f[cur][sz]%=mod;
					}
					else f[cur][sz]+=temp*mi[cnt-tot],f[cur][sz]%=mod;
				}
				else {
					if(t[l]!='?'&&t[r]!='?')break;
					if(t[l]=='?')cur|=(1<<(t[r]-'a'));
					else cur|=(1<<(t[l]-'a'));
					tot++;
					f[cur][sz]+=temp*mi[cnt-tot];
					f[cur][sz]%=mod;
				}
				l--,r++;
			}
		}
	}
	for(int i=0;i<17;i++){
		for(int j=0;j<(1<<17);j++){
			if(j&(1<<i))
				f[j][sz]+=f[j^(1<<i)][sz];
				f[j][sz]%=mod;
		}
	}

}
int main(){
	scanf("%d%s%d",&n,s+1,&q);
	for(int i=1;i<=17;i++)solve(i);
	while(q--){
		scanf("%s",s+1);
		int len=strlen(s+1);
		int cur=0;
		for(int i=1;i<=len;i++){
			cur+=(1<<(s[i]-'a'));
		}
		printf("%lld\n",f[cur][len]);
	}


	return 0;
}