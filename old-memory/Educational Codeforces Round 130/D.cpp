#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,lst[maxn][30];
char s[maxn];
int ask(int l,int r){
	printf("? 2 %d %d\n",l,r);
	fflush(stdout);
	int res;
	scanf("%d",&res);
	return res;
}
void getch(int x){
	printf("? 1 %d\n",x);
	fflush(stdout);
	char ch[2];
	scanf("%s",ch);
	s[x]=ch[0];
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)s[i]='#';
	for(int i=1;i<=n;i++){
		lst[i][1]=i;
		if(i>1){
			int l=1,r=26,res=27;
			while(!lst[i-1][r])r--;
			while(l<=r){
				int mid=l+r>>1;
				int temp=ask(lst[i-1][mid],i);
				if(temp==mid)res=min(res,mid),r=mid-1;
				else l=mid+1;
			}
			if(res!=27)s[i]=s[lst[i-1][res]];
			for(int j=26;j>=1;j--){
				if(j>=res)lst[i][j]=lst[i-1][j];
				else lst[i][j+1]=lst[i-1][j];
			}
		}
		if(s[i]=='#'){
			getch(i);
		}

	}
	printf("! ");
	for(int i=1;i<=n;i++)putchar(s[i]);
	puts("");
	fflush(stdout);

	return 0;
}