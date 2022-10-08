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



/***************************************************************************************************/
ll i,j,k;
const int LIM   = 200005;
const int N=1000005;
int cap[505][505];
int par[505];
vi adj[505];
int n,m;
int flow,maxflow;

void bfs()
{
    fill(par,par+505,0);
    par[1]=-1;
    queue<pair<int,int>>q;
    q.push({inf,1});
    while(!q.empty())
    {
        ii temp=q.front();
        q.pop();
        int f=temp.first;
        int idx=temp.second;
        for(auto v:adj[idx])
        {
            if(par[v]==0 && cap[idx][v]!=0)
            {
                par[v]=idx;
                q.push({min(f,cap[idx][v]),v});
                if(v==n)
                {
                    flow=min(f,cap[idx][v]);
                    return;
                }
            }
        }

    }
}

void solve()
{
 // int n,m;
  cin>>n>>m;
  int a,b,c;
  fo(i,0,m)
  {
      cin>>a>>b>>c;
      adj[a].pb(b);
      adj[b].pb(a);
      cap[a][b]+=c;
  }
   flow=0;
  maxflow=0;
  while(1)
  {
      flow=0;
      bfs();
    //  cout<<flow<<endl;
      if(flow==0)
      {
          break;
      }
      maxflow+=flow;
   //   flow += new_flow;
        int cur = n;
        while (cur != 1)
        {
            int prev = par[cur];
            cap[prev][cur] -= flow;
            cap[cur][prev] += flow;
            cur = prev;

        }
  }
  cout<<maxflow<<endl;
}




int32_t main()
{
 fastio
  int t=1;
// cin>>t;
  for(int i=1;i<=t;i++)
  {
   // cout<<"Case #"<<i<<": ";
   solve();
  // cout<<endl;
  }
 return 0;
}
