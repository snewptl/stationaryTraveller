#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
char s[maxn];
int main(){
    int T;scanf("%d",&T);
    while(T--){
		scanf("%s",s);
		int n=strlen(s);
		int cnt0=0,cnt1=0;
		for(int i=0;i<n;i++){
			if(s[i]=='0')cnt0++;
			else cnt1++;
		}
		int ans=2;
		if(cnt0==0)ans=0;
		else if(cnt1==0)ans=1;
		else {
			int i=0;
			while(i<n&&s[i]=='1')i++;
			int flag=1;
			for(int j=0;j<cnt0;i++,j++){
				if(s[i]=='1')flag=0;
			}
			if(flag)ans=1;
		}
		printf("%d\n",ans);

    }


    return 0;
}