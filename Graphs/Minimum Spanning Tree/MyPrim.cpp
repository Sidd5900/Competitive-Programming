#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define int long long
#define ll int
#define vi vector<int>
#define vvi vector<vector<int>>
#define fo(i,a,b) for(i=a;i<b;i++)
#define all(x) x.begin(),x.end()
#define trav(x) for(auto it=x.begin();it!=x.end();it++)
#define mod 1000000007
#define Endl endl
#define pb push_back
#define mp make_pair
#define inf 1e18
#define INF 1e18
#define ld long double
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug(a) cerr << #a << ": " << a << endl
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>//ii->multiset ,int->set
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define minheap priority_queue<int,vector<int>,greater<int>>
//#define minheap priority_queue<ii,vector<ii>,greater<ii>> //for min heap of pair



/***************************************************************************************************/
//PRIMS ALG0

ll i,j,k;
const int LIM= 200005;
const int N=1000005;
//int n,m;

vii adj[LIM];
int pre[LIM];
int dist[LIM];
bool visited[LIM];

void solve()
{
 int n,m,a,b,c;
  cin>>n>>m;
  fo(i,0,m)
  {
      cin>>a>>b>>c;
      adj[a].pb({b,c});
      adj[b].pb({a,c});
  }
   priority_queue<ii,vector<ii>,greater<ii>>q;
   for(int i=1;i<=n;i++)
    dist[i]=inf;

   dist[1]=0;
   q.push({0,1});//dist, idx
   while(!q.empty())
   {
       ii temp=q.top();
       q.pop();
       int u=temp.second;
       if(visited[u])
        continue;
       visited[u]=1;
       for(auto v:adj[u])
       {
           int w=v.second;
           int idx=v.first;
           if(!visited[idx] && dist[idx]>w)
           {
               dist[idx]=w;
               pre[idx]=u;
               q.push({w,idx});
           }
       }

   }
    int ans=0;
   for(int i=1;i<=n;i++)
    {ans+=dist[i];
    if(ans>=inf)
        {cout<<"IMPOSSIBLE"<<endl;
        return;
        }

    }
        cout<<ans<<endl;

}



int32_t main()
{
 //fastio
  int t=1;
//cin>>t;
  for(int i=1;i<=t;i++)
  {
    //cout<<"Case #"<<i<<": ";
    solve();
  }
 return 0;
}
