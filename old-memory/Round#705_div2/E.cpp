#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int n,flag;
int ans[maxn];
int l[maxn],r[maxn];
char s[maxn];
bool check(){
	for(int i=1;i<=n;i++)if(l[i]!=r[i])return false;
	return true;
}
int main(){
	scanf("%d%s",&n,s);
	for(int i=1;i<=n;i++)
		l[i]=s[i-1]-'0';
	scanf("%s",s);
	for(int i=1;i<=n;i++)
		r[i]=s[i-1]-'0';
	if(l[1]==r[1]&&l[1]==0)ans[1]=0;
	else if(l[1]==0){
		for(int i=1;i<=n;i++)ans[i]=1;
	}
	else {
		if(r[n]==1)for(int i=1;i<=n;i++)ans[i]=r[i];
		else {
			if(check())for(int i=1;i<=n;i++)ans[i]=r[i];
			else {
				int p=n;
				l[n]+=1;
				while(p>=1&&l[p]==2)l[p]=0,l[p-1]++,p--;
				if(!check())r[n]=1;
				for(int i=1;i<=n;i++)ans[i]=r[i];
			}
			
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d",ans[i]);
	}
	printf("\n");

    return 0;
}