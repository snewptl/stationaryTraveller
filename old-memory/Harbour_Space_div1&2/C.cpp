#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
char s[15];
int ans;
void dfs(int dep){
	if(dep==10){
		int cnt1=0,cnt2=0;
		for(int i=0;i<10;i+=2){
			if(s[i]=='1'){
				cnt1++;
				if(cnt1-cnt2>(10-i-2)/2+1)ans=min(ans,i+1);
			}
			else if(cnt2-cnt1>(10-i-2)/2)ans=min(ans,i+1);
			if(s[i+1]=='1'){
				cnt2++;
				if(cnt2-cnt1>(10-i-2)/2)ans=min(ans,i+2);
			}
			else if(cnt1-cnt2>(10-i-2)/2)ans=min(ans,i+2);
		}
		return ;
	}
	if(s[dep]!='?')dfs(dep+1);
	else {
		s[dep]='1';
		dfs(dep+1);
		s[dep]='0';
		dfs(dep+1);
		s[dep]='?';
	}
}
int main(){
    int T;scanf("%d",&T);
    while(T--){
		ans=10;
		scanf("%s",s);
		dfs(0);
		printf("%d\n",ans);
    }


    return 0;
}