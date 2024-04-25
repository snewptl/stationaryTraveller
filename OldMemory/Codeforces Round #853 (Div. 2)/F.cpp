#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
typedef double db;
typedef long double ldb;
const ll mod=998244353;
const int maxn=2e5+5;
const double eps=1e-10;
string s;
int ans,n;
int dp2[85][85];
void splite2(){
    for(int i=0;i<n-1;i++){
        string a,b;
        memset(dp2,0,sizeof(dp2));
        a.push_back('#');
        b.push_back('#');
        for(int j=0;j<=i;j++)a.push_back(s[j]);
        for(int j=i+1;j<n;j++)b.push_back(s[j]);
        for(int i=1;i<a.size();i++){
            for(int j=1;j<b.size();j++){
                if(a[i]==b[j])dp2[i][j]=max(dp2[i-1][j-1]+1,dp2[i][j]);
                dp2[i][j]=max(dp2[i][j],max(dp2[i-1][j],dp2[i][j-1]));
                ans=max(dp2[i][j]*2,ans);
            }
        }
    }
}
int dp3[85][85][85];
void splite3(){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            string a,b,c;
            a.push_back('#');
            b.push_back('#');
            c.push_back('#');
            for(int k=0;k<=i;k++)a.push_back(s[k]);
            for(int k=i+1;k<=j;k++)b.push_back(s[k]);
            for(int k=j+1;k<n;k++)c.push_back(s[k]);
            for(int st=1;st<a.size();st++){
                for(int nd=1;nd<b.size();nd++){
                    for(int rd=1;rd<c.size();rd++){
                        if(a[st]==b[nd]&&a[st]==c[rd])
                            dp3[st][nd][rd]=max(dp3[st-1][nd-1][rd-1]+1,dp3[st][nd][rd]);
                            dp3[st][nd][rd]=max(max(max(dp3[st-1][nd][rd],dp3[st][nd-1][rd]),dp3[st][nd][rd-1]),dp3[st][nd][rd]);
                    }
                }
            }
            for(int st=0;st<a.size();st++){
                for(int nd=0;nd<b.size();nd++){
                    for(int rd=0;rd<c.size();rd++){
                        ans=max(dp3[st][nd][rd]*3,ans);
                        dp3[st][nd][rd]=0;
                    }
                }
            }
            
        }
    }
}
void init(string &a,int l,int r){ 
    for(int i=l;i<=r;i++){
        a.push_back(s[i]);
    }
}
void splite5(){
    string a;
    for(int i=0;i<5;i++){
        a.clear();
        init(a,n/5*i,i==4?n-1:n/5*(i+1)-1);
        for(int j=0;j<(1<<a.size());j++){
            string temp;
            for(int k=0;k<a.size();k++){
                if((1<<k)&j)temp.push_back(a[k]);
            }
            int cnt=0,cur=0;
            for(int k=0;k<n;k++){
                if(s[k]==temp[cur]){
                    cur++;
                    if(cur>=temp.size())cur=0,cnt++;
                }
            }
            if(cnt>1)ans=max(cnt*(int)temp.size(),ans);
        }
    }
    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s;
    n=s.size();
    if(n>=2)splite2();
    if(n>=3)splite3();
    if(n>=5)splite5();
    cout<<ans<<'\n';
    return 0;
}