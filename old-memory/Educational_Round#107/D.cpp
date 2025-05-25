#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,k;
char ans[maxn];
char ch[5003];
int main(){
    scanf("%d%d",&n,&k);
	if(k==1)for(int i=1;i<=n;i++)printf("%c",'a');
	else {	
		int cnt=0;
		for(int i=0;i<k;i++){
			ch[cnt++]='a'+i;
			ch[cnt++]='a'+i;
		}
		ch[cnt++]='a'+k-2;
		for(int i=k-3;i>=0;i--){
			ch[cnt++]='a'+i;
			for(int j=i+2;j<k;j++)
			ch[cnt++]='a'+j,ch[cnt++]='a'+i;
		}
		int temp=0;
		ans[++temp]='a';
		for(int i=1;i;i++){
			if(temp==n)break;
			for(int j=1;j<cnt;j++){
				if(temp==n)break;
				ans[++temp]=ch[j];
			}
		}
		for(int i=1;i<=temp;i++)printf("%c",ans[i]);		
	}



    return 0;
}