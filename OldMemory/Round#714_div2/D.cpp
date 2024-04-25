#include<bits/stdc++.h>
using namespace std;

void solveTestCase()
{
     int n,x;
     cin>>n>>x;
     vector<int> a(n);
     for(int i=0;i<n;i++)cin>>a[i];
     
     //tells whether vertices i and i+1 are connected for 0<=i<n-1
     vector<bool> isConnected(n);
     vector<pair<int,int>> vals;
     
     for(int i=0;i<n;i++)
     vals.push_back(make_pair(a[i],i));

     sort(vals.begin(),vals.end());
     long long int ans=0;
     for(auto p:vals)
     {
         int cur_val=p.first;
         int i=p.second;

         if(cur_val>=x)break;
         
         while(i>0)
         {
              if(isConnected[i-1])break;
              if(a[i-1]%cur_val==0)
              {
                   isConnected[i-1]=true;
                   ans+=cur_val;
                   i--;
              }
              else
              break;
         }
         
         i=p.second;
         while(i<n-1)
         {
             if(isConnected[i])break;
             if(a[i+1]%cur_val==0)
             {
                 isConnected[i]=true;
                 ans+=cur_val;
                 i++;
             }
             else
             break;
         }
         
     }

     for(int i=0;i<n-1;i++)
     {
         if(!isConnected[i])
         ans+=x;
     }

     cout<<ans<<endl;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
         solveTestCase();
    }  
    return 0;
}