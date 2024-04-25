#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
char s[maxn],t[maxn];
int re[maxn],rev[maxn];
int main(){
    int n,m;
	scanf("%d%d",&n,&m);
	scanf("%s%s",s,t);
	int j=0;
	for(int i=0;i<m;i++){
		while(s[j]!=t[i])j++;
		re[i]=j,j++;
	}
	j=n-1;
	for(int i=m-1;i>=0;i--){
		while(s[j]!=t[i])j--;
		rev[i]=j,j--;
	}
	int ans=0;
	for(int i=0;i<m-1;i++){
		ans=max(ans,rev[i+1]-re[i]);
	}
	printf("%d\n",ans);
    return 0;
}