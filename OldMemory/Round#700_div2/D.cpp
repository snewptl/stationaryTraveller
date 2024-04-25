#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int n,ans;
int a[maxn];
int st[maxn],ed[maxn];
int cnt;
int main(){
    scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	a[n+1]=0;
	for(int i=1;i<=n;i++){
		int flag=0;
		if(a[i+1]==a[i]){
			st[++cnt]=i;
			while(i<=n&&a[i+1]==a[i]){
				i++;flag=1;
			}
			ed[cnt]=i;
		}
		ans++;	
	}
	for(int i=1;i<cnt;i++){

		if(a[st[i]]!=a[st[i+1]])ans++;
		else {
			for(int j=ed[i]+2;j<st[i+1];j+=2){
				if(a[j]!=a[st[i]]){
					ans++;break;
				}
			}
		}
	}
	if(cnt)ans++;
	printf("%d",ans);
    return 0;
}