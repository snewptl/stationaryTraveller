#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int n,k,flag;
char s[maxn],s1[maxn],ans[maxn];
int sum[maxn][28];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
		flag=1;
		scanf("%s",s1);
		for(int i=1;i<=n;i++){
			s[i]=s1[i-1];
		}
		for(int i=1;i<=n;i++){
			ans[i]=s[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<26;j++){
				sum[i][j]=sum[i-1][j];
				if(s[i]-'a'==j)sum[i][j]++;
				if(i==n&&sum[i][j]%k!=0)flag=0;
			}
		}
		if(!flag)for(int i=n;i>=1;i--){
			sum[i][s[i]-'a']--;
			for(int j=s[i]-'a'+1;j<26;j++){
				if(flag)break;
				sum[i][j]++;
				int tmp=0;
				for(int p=25;p>=0;p--){
					tmp+=(k-sum[i][p]%k)%k;
				}
				if(tmp<=n-i&&(n-i-tmp)%k==0){
					flag=1;
					ans[i]=j+'a';
					int t=n;
					for(int p=25;p>=0;p--){
						if(sum[i][p]%k==0)continue;
						for(int q=1;q<=k-sum[i][p]%k;q++){
							ans[t-q+1]=p+'a';
						}
						t-=k-sum[i][p]%k;
					}
					for(int p=i+1;p<=t;p++){
						ans[p]='a';
					}
				}
				sum[i][j]--;
			}
		}
		if(flag)for(int i=1;i<=n;i++)printf("%c",ans[i]);
		else printf("-1");
		printf("\n");
    }


    return 0;
}