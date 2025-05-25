#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> get(int n){
        vector<vector<int>> ans;
        if(n==1){
            ans.push_back({1,-1,9});
            return ans;
        }
        for(int x=1;x<n;++x){
            int y=n-x;
            auto lf=get(x);
            auto rg=get(y);
            for(auto &v:lf){
                for(auto &u:rg){
                    vector<int> res;
                    res.push_back(1);
                    for(auto w:v)
                        res.push_back(w);
                    for(auto w:u)
                        res.push_back(w);
                    res.push_back(9);
                    ans.push_back(res);
                }
            }
        }
        return ans;
    }
    int treeOfInfiniteSouls(vector<int>& gem, int p, int target) {
        int n=gem.size();
        auto res=get(n);
        vector<int> pl(n);
        for(int i=0;i<n;++i)
            pl[i]=i;
        #define ll long long
        auto getLen=[&](int x){
            int res=0;
            do{
                x=x/10;
                ++res;
            }while(x);
            return res;
        };
        vector<ll> pw(11,0);
        pw[0]=1;
        for(int i=1;i<=10;++i)
            pw[i]=pw[i-1]*10%p;
        int ans=0;
        do{
            for(auto &v:res){
                ll now=0;
                int x=0;
                for(auto u:v){
                    if(u==-1){
                        int tmp=gem[pl[x++]];
                        now=(now*pw[getLen(tmp)]+tmp)%p;
                    }else{
                        now=(now*10+u)%p;
                    }
                }
                if(now==target)
                    ++ans;
            }
        }while(0);//while(next_permutation(pl.begin(),pl.end()));
        return ans;
    }
};