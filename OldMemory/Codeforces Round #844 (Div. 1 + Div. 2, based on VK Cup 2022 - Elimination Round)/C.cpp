#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,char>pic;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int hsh(char x){
    return x-'a';
}
int n;
char s[maxn];
int cnt[30],vis[30];
pic a[30];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        memset(cnt,0,sizeof(cnt));
        memset(vis,0,sizeof(vis));
        scanf("%d",&n);
        scanf("%s",s);
        for(int i=0;i<n;i++)cnt[hsh(s[i])]++;
        for(int i=0;i<26;i++)a[i]={cnt[i],i};
        sort(cnt,cnt+26,greater<int>{});
        sort(a,a+26,greater<pic>{});
        int ans=1e9,pos=0;
        for(int i=1;i<=min(26,n);i++){
            int temp=0;
            if(n%i)continue;
            int to=n/i,sum=0;
            for(int j=0;j<i;j++){
                if(to<cnt[j])temp+=cnt[j]-to;
                sum+=cnt[j];
            }
            temp+=max(0,n-sum);
            if(ans>temp)ans=temp,pos=i;
        }
        for(int i=0;i<pos;i++){
            vis[a[i].second]=n/pos;
        }
        for(int i=0;i<n;i++){
            if(vis[hsh(s[i])])vis[hsh(s[i])]--;
            else s[i]='#';
        }
        for(int i=0;i<n;i++){
            if(s[i]=='#'){
                for(int j=0;j<26;j++){
                    if(vis[j]){
                        vis[j]--;
                        s[i]=j+'a';
                        break;
                    }
                }
            }
        }
        printf("%d\n%s\n",ans,s);
	}


	return 0;
}