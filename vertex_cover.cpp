// HEY STALKER
#include<iostream>
#define ll long long int 
#include<string>
using namespace std;
#include<vector>
#include<set>
#include<algorithm>
#define MOD 1000000007
vector<vector<ll> > v(1000000);
vector<ll> f(100000),g(100000);
void dfs(ll node,ll parent)
{
    ll i;
    /*if(v[node][0]==parent&&v[node].size()==1)
    {
        f[node]=1;
    }*/
    f[node]=1;
    for(i=0;i<v[node].size();i=i+1)
    {
        if(v[node][i]!=parent)
        {
            dfs(v[node][i],node);
            g[node]=g[node]+f[v[node][i]];
            f[node]=f[node]+min(f[v[node][i]],g[v[node][i]]);
            //cout<<" \n node "<<node<<" "<<f[node]<<" "<<g[node];
        }
    }
    return ;
}
 
int main()
{
    ll n,a,b,i;
    cin>>n;
    for(i=0;i<n-1;i=i+1)
    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1,-1);
    cout<<min(f[1],g[1])<<"\n";
    return 0;
} 
