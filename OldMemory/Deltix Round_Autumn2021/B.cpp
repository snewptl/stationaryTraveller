#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=1e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,q;
char s[maxn];
int in[maxn];
string to="abc";
int main(){
	int T=1;//scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&q);
		scanf("%s",s+1);
		for(int i=1;i<=n;i++)in[i]=0;
		int cnt=0;
		for(int i=1;i<=n-2;i++){
			int flag=1;
			for(int j=0;j<3;j++){
				if(to[j]!=s[i+j])flag=0;
			}
			if(flag){
				cnt++;
				for(int j=0;j<3;j++){
					in[j+i]=j+1;
				}
			}
		}
		while(q--){
			int x;
			char ch[10];
			scanf("%d%s",&x,ch);
			if(s[x]==ch[0]){
				printf("%d\n",cnt);
				continue;
			}
			else {
				if(in[x]){
					int pos=in[x];
					for(int i=x-pos+1;i<=x-pos+3;i++){
						in[i]=0;
					}
					cnt--;
				}
				s[x]=ch[0];
				for(int i=max(x-2,1);i<=min(x,n-2);i++){
					int flag=1;
					for(int j=0;j<3;j++){
						if(to[j]!=s[i+j])flag=0;
					}
					if(flag){
						cnt++;
						for(int j=0;j<3;j++){
							in[j+i]=j+1;
						}
						break;
					}
				}
				printf("%d\n",cnt);
			}
		}
	}


	return 0;
}