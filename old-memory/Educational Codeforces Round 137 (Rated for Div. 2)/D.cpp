#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=1e6+5;
const ll mod=998244353;
const double eps=1e-10;
int n,mx,st,cnt,sz;
char s[maxn];
int ans[maxn],temp[maxn];
bool check(){
    for(int i=0;i<sz;i++){
        if(ans[i]>temp[i])return false;
        else if(ans[i]<temp[i])return true;
    }
    return false;
}
int main(){
	scanf("%d%s",&n,s);
    while(st<n&&s[st]=='0')st++;
    for(int i=st;i<n;i++)s[i-st]=s[i];
    n-=st;
    while(cnt<n&&s[cnt]=='1')cnt++;
    sz=n-cnt;
    for(int i=0;i<cnt;i++){
        for(int j=i;j<i+sz;j++){
            temp[j-i]=((s[j]-'0')|(s[j-i+cnt]-'0'));
        }
        if(check()){
            for(int j=0;j<sz;j++)ans[j]=temp[j];
        }
    }
    if(!cnt){
        puts("0");
    }
    else {
        for(int i=1;i<=cnt;i++)printf("1");
        for(int i=0;i<sz;i++)printf("%d",ans[i]);
        puts("");
    }


	return 0;
}