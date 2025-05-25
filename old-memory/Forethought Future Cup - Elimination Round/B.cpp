#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
char s[maxn];
int cnt[maxn];
int main(){
    int T=1;
    while(T--){

        scanf("%s",s);
		int len=strlen(s),mx=0,prin=0;
		for(int i=1;i<=len;i++){
			cnt[i]=cnt[i-1];
			if(s[i-1]!='a')cnt[i]++;
			if(s[i-1]=='a')mx=i;
		}
		for(int i=mx;i<=len;i++){
			if(cnt[i]==len-i){
				int flag=1;
				for(int j=1,pos=i+1;j<=i,pos<=len;j++){
					if(s[j-1]=='a')continue;
					if(s[j-1]!=s[pos-1])flag=0;
					pos++;
				}
				if(flag){
					for(int j=0;j<i;j++)printf("%c",s[j]);
					prin=1;
					break;
				}
			}
		}
		if(!prin)printf(":(");
    }


    return 0;
}