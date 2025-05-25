#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=4e5+10;
char s[5][maxn];
char ans[maxn];
int cnt[5],n;
pair<int,int>pii[5];
int main(){
    int T;scanf("%d",&T);
    while(T--){
		scanf("%d",&n);
		memset(cnt,0,sizeof(cnt));
        for(int i=0;i<3;i++){
			scanf("%s",s[i]);
			for(int j=0;j<2*n;j++)if(s[i][j]=='1')cnt[i]++;
			pii[i]=make_pair(cnt[i],i);
		}
		sort(pii,pii+3);
		int tot=0;
		if(pii[1].first<=n){
			int pa=pii[0].second,ppa=0;
			int son=pii[1].second,pson=0;
			while(pson<2*n){
				if(s[son][pson]=='0'){
					while(s[pa][ppa]!='0')ans[tot++]=s[pa][ppa],ppa++;
					ans[tot++]=s[pa][ppa],ppa++;
					pson++;
				}
				else if(s[son][pson]=='1'){
					ans[tot++]=s[son][pson],pson++;
				}
			}
			for(int i=ppa;i<2*n;i++)ans[tot++]=s[pa][i];
		}
		else {
			int pa=pii[2].second,ppa=0;
			int son=pii[1].second,pson=0;
			while(pson<2*n){
				if(s[son][pson]=='1'){
					while(s[pa][ppa]!='1')ans[tot++]=s[pa][ppa],ppa++;
					ans[tot++]=s[pa][ppa],ppa++;
					pson++;
				}
				else if(s[son][pson]=='0'){
					ans[tot++]=s[son][pson],pson++;
				}
			}
			for(int i=ppa;i<2*n;i++)ans[tot++]=s[pa][i];
		}
		for(int i=0;i<tot;i++)printf("%c",ans[i]);
		printf("\n");
    }


    return 0;
}