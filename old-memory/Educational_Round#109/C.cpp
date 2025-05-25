#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
char s[maxn];
int l[maxn],r[maxn];
int pre[maxn],nxt[maxn];
int st;
ll ans;
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%s",s);
		int pos=0,last=0;
		int n=strlen(s);
		for(int i=0;i<=n;i++){
			l[i]=r[i]=0;
			pre[i]=0,nxt[i]=n;
		}
		while(pos<n&&s[pos]=='?')pos++;
		last=pos;
		l[pos]=pos;
		st=pos;
		ans=0;
		while(pos<n){
			pos++;
			while(pos<n&&s[pos]=='?')pos++;
			r[last]=l[pos]=pos-last-1;
			nxt[last]=pos;pre[pos]=last;
			last=pos;
		}
		ll temp=l[st];
		for(int i=st;i<n;i=nxt[i]){
			if((s[nxt[i]]==s[i]&&(nxt[i]-i-1)%2==1)||(s[nxt[i]]!=s[i]&&(nxt[i]-i-1)%2==0)){
				temp+=nxt[i]-i;
			}
			else {
				temp+=r[i]+1;
				ans+=temp*(temp+1)/2;
				temp=r[i];
				ans-=1LL*(r[i]+1)*r[i]/2;
			}
		}
		ans+=temp*(temp+1)/2;
		printf("%lld\n",ans);
    }


    return 0;
}