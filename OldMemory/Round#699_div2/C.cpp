#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int n,m,cur;
int a[maxn],b[maxn],c[maxn];
int mp[maxn],nxt[maxn],h[maxn],ans[maxn];
bool check(){
	for(int i=1;i<=n;i++)
		if(b[i]==c[m]){
			return true;
		}
	return false;
}
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
		int flag=1;
		for(int i=1;i<=n;i++)mp[i]=0;
		for(int i=1;i<=m;i++)ans[i]=0;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)scanf("%d",&b[i]);
		for(int i=1;i<=m;i++)scanf("%d",&c[i]);
		for(int i=m;i>=1;i--){
			mp[c[i]]++;
			nxt[i]=h[c[i]];
			h[c[i]]=i;
		}
		for(int i=1;i<=n;i++){
			if(a[i]!=b[i]){
				mp[b[i]]--;
				if(mp[b[i]]<0)flag=0;
			}
		}
		if(!check())flag=0;
		for(int i=1;i<=n;i++){
			if(b[i]==a[i])continue;
			ans[h[b[i]]]=i;
			if(h[b[i]]==m)cur=i;
			h[b[i]]=nxt[h[b[i]]];
		}
		for(int i=1;i<=n;i++){
			if(b[i]==c[m]&&(!ans[m])){
				cur=i;
				break;
			}
		}
		for(int i=1;i<=m;i++){
			if(!ans[i])ans[i]=cur;
		}
		if(!flag)printf("NO\n");
		else {
			printf("YES\n");
			for(int i=1;i<=m;i++)printf("%d ",ans[i]);
			printf("\n");
		}
    }


    return 0;
}