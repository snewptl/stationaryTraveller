#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e3+10;
int dp[maxn][maxn];
char s[maxn],t[maxn];
char ss[maxn],tt[maxn];
char temp[maxn];
int main(){
    int T;scanf("%d",&T);
    while(T--){
		scanf("%s%s",ss,tt);
		int len1=strlen(ss);
		int len2=strlen(tt);
		for(int i=0;i<len1;i++)s[i+1]=ss[i];
		for(int i=0;i<len2;i++)t[i+1]=tt[i];
		// for(int i=1;i<=len1+1;i++){
		// 	for(int j=1;j<=len2+1;j++)
		// 	dp[i][j]=0;
		// }
		// for(int i=1;i<=len1;i++){
		// 	if(s[i]==t[1])dp[i][1]=1;
		// }
		// for(int j=2;j<=len2;j++){
		// 	for(int i=1;i<=len1;i++){
		// 		if(s[i]!=t[j])continue;
		// 		dp[i][j]=dp[i-1][j-1]|dp[i+1][j-1];
		// 	}
		// }
		// int flag=0;
		// for(int i=1;i<=len1;i++){
		// 	if(dp[i][len2])flag=1;
		// }

		int flag=0;
		for(int k=1;k<=len1;k++){
			for(int i=1;i<=k;i++)temp[i]=s[i];
			for(int i=k+1;i<=k*2-1;i++){
				temp[i]=s[2*k-i];
			}
			for(int i=1;i<=2*k-1;i++){
				int st=1;
				for(int j=i;j>=1;j--){
					if(t[st]==temp[j])st++;
					else break;
					if(st==len2+1){flag=1;break;}
				}
				st=1;
				for(int j=i;j<=k*2-1;j++){
					if(t[st]==temp[j])st++;
					else break;
					if(st==len2+1){flag=1;break;}
				}
			}			
		}

		if(flag)printf("YES\n");
		else printf("NO\n");
    }


    return 0;
}