#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
char s[maxn];
char t[2][maxn];
int n;
bool check(char *str){
	int cnt0=0,cnt1=0;
	for(int i=0;i<n;i++){
		if(str[i]=='(')cnt0++;
		else cnt1++;
		if(cnt0<cnt1)return false;
	}
	if(cnt0>cnt1)return false;
	return true;
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%s",s);
		n=strlen(s);
		if(n%2)puts("NO");
		else {
			int cnt0=0,cnt1=0;
			for(int i=0;i<n;i++){
				if(s[i]=='(')cnt0++;
				else if(s[i]==')')cnt1++;
			}
			int k0=n/2-cnt0,k1=n/2-cnt1;
			if(k0<0||k1<0)puts("NO");
			else {
				int temp=k0;
				int lst=-1,nxt=-1;
				for(int i=0;i<n;i++){
					t[0][i]=s[i];
					if(s[i]=='?'){
						if(temp>0)t[0][i]='(';
						else t[0][i]=')';
						temp--;
						if(temp==0)lst=i;
						if(temp==-1)nxt=i;
					}
				}
				if(check(t[0])){
					if(lst==-1||nxt==-1)puts("YES");
					else {
						for(int i=0;i<n;i++)t[1][i]=t[0][i];
						swap(t[1][lst],t[1][nxt]);
						if(check(t[1]))puts("NO");
						else puts("YES");						
					}
				}
				else puts("NO");
			}
		}
	}


	return 0;
}