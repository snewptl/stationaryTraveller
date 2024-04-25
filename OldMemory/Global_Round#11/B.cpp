#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
const int maxn=1e5+10;
int n,k,cnt,pos,sum,st,ed,ans;
char s[maxn];
int len[maxn];
bitset<maxn>a;
int main(){
    // freopen("data.in","r",stdin);
    // freopen("data.out","w",stdout);
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
        scanf("%s",s);
        cnt=0,pos=0,st=0,sum=0,ed=n-1,ans=0;
        for(int i=0;i<n;i++){
            if(i==0&&s[i]=='W')ans++;
            else if(s[i]=='W'){
                if(s[i-1]=='W')ans+=2;
                else ans+=1;
            }
        }
        while(st<n&&s[st]=='L')st++;
        while(ed>=0&&s[ed]=='L')ed--;
        for(int i=st;i<=ed;i++){
            if(s[i]=='L')sum++;
        }
        if(k==0)printf("%d\n",ans);
        else if(st==n)printf("%d\n",ans+min(k*2-1,n*2-1)); 
        else {
            if(sum+n-1-ed+st<k)k=sum+n-1-ed+st;
            pos=st;
            while(pos<=ed){
                while(pos<ed&&s[pos]=='W')pos++;
                if(pos==ed)break;
                int x=pos;
                while(pos<ed&&s[pos]=='L')pos++;
                int y=pos;
                len[cnt++]=y-x;
            }        
            sort(len,len+cnt);
            int m=0;
            for(int i=0;i<cnt;i++){
                if(k<len[i]+m)break;
                ans+=1;
                m+=len[i];
            }
            printf("%d\n",ans+k*2);
        }

    }

    return 0;
}