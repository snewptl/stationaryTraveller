#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,m;
vector<int>v[maxn];
char s[maxn];
int dp[maxn][10];
void get_ans(){
    memset(dp,0x3f3f3f3f,sizeof(dp));
    int ans=0x3f3f3f3f;
    if(n==2){
        dp[0][0]=((v[1][0]+v[0][0])==1);
        dp[0][1]=(!dp[0][0]);
        for(int i=1;i<m;i++){
            for(int j=0;j<4;j++){
                int tmp=0,cnt=0;
                for(int k=0;k<2;k++){
                    if((1<<k)&j)cnt++,tmp+=(!v[k][i]);
                    else tmp+=v[k][i];
                }
                tmp%=2;
                dp[i][tmp]=min(dp[i-1][(!tmp)]+cnt,dp[i][tmp]);
            }
        }
        for(int i=0;i<2;i++)ans=min(ans,dp[m-1][i]);
        printf("%d\n",ans);
    }
    if(n==3){
        for(int j=0;j<8;j++){
            int tmp1=0,tmp2=0,cnt=0;
            for(int k=0;k<2;k++){
                if((1<<k)&j)cnt++,tmp1+=(!v[k][0]);
                else tmp1+=v[k][0];
            }
            for(int k=1;k<3;k++){
                if((1<<k)&j)cnt++,tmp2+=(!v[k][0]);
                else tmp2+=v[k][0];
            }
            if((1<<1)&j)cnt--;
            tmp1%=2,tmp2%=2;
            dp[0][tmp1*2+tmp2]=min(dp[0][tmp1*2+tmp2],cnt);
        }
        for(int i=1;i<m;i++){
            for(int j=0;j<8;j++){
                int tmp1=0,tmp2=0,cnt=0;
                for(int k=0;k<2;k++){
                    if((1<<k)&j)cnt++,tmp1+=(!v[k][i]);
                    else tmp1+=v[k][i];
                }
                for(int k=1;k<3;k++){
                    if((1<<k)&j)cnt++,tmp2+=(!v[k][i]);
                    else tmp2+=v[k][i];
                }
                if((1<<1)&j)cnt--;
                tmp1%=2,tmp2%=2;
                dp[i][tmp1*2+tmp2]=min(dp[i-1][(!tmp1)*2+(!tmp2)]+cnt,dp[i][tmp1*2+tmp2]);
            }            
        }
        for(int i=0;i<4;i++)
            ans=min(ans,dp[m-1][i]);
        printf("%d\n",ans);
    }
}
int main(){
    // freopen("data.in","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%s",s+1);
        for(int j=1;j<=m;j++){
            int x=s[j]-'0';
            v[i].push_back(x);
        }
    }
    if(n>=4)printf("-1\n");
    else if(n==1)printf("0\n");
    else {
        get_ans();
        
    }
    // printf("1");
    return 0;
}