#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=50+10;
int k;
int a[maxn];
char s[maxn];
int vis[maxn];
int ans;
int book[maxn];
int mi[maxn];
int cnt=0;
int main(){
    int T;scanf("%d",&T);
	vis[2]=vis[3]=vis[5]=vis[7]=1;
	mi[0]=1;
	for(int i=1;i<=5;i++)mi[i]=mi[i-1]*2;
    while(T--){
        scanf("%d",&k);
		scanf("%s",s);
		int len=strlen(s);
		cnt=1e9;
		for(int i=1;i<=9;i++)book[i]=0;
		for(int i=0;i<len;i++){
			book[s[i]-'0']++;
			if(!vis[s[i]-'0']){
				cnt=1;
				ans=s[i]-'0';break;
			}
		}
		if(cnt!=1){
			if(len>=5){
				for(int i=1;i<=9;i++){
					if(book[i]>=2){
						cnt=2;
						ans=i*11;
						break;
					}
				}
			}
			else {
				int tmp=1<<len;
				for(int i=0;i<tmp;i++){
					int cur=0,tot=0;
					for(int j=0;j<len;j++){
						if((mi[j])&i){
							cur*=10;
							tot++;
							cur+=s[j]-'0';
						}
					}
					int flag=0;
					for(int j=2;j*j<=cur;j++){
						if(cur%j==0)flag=1;
					}
					if(flag&&cnt>tot){
						cnt=tot;
						ans=cur;
					}
				}
			}			
		}
		printf("%d\n%d\n",cnt,ans);

    }


    return 0;
}