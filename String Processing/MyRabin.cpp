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
int prime=31;

int p[N];
int h[N];

void power()
{
    p[0]=1;
    for(int i=1;i<=N;i++)
    {
        p[i]=(p[i-1]*prime)%mod;
    }
}

void findhash(string &s)
{
    int n=s.size();
    h[0]=((s[0]-'a'+1)*p[0])%mod;
    for(int i=1;i<n;i++)
    {
        h[i]=(h[i-1]+((s[i]-'a'+1)*p[i])%mod)%mod;
    }
}
int fpow(int x, int n)
{
      int res = 1;
      x %= mod;
      while(n)
      {
            if(n&1)res = res * x % mod;
            x = x * x % mod;
            n>>=1;
      }
      return res;
}

void solve()
{
  string a;
  string b;
  cin>>a>>b;
  int n=a.size();
  int m=b.size();
  if(n<m)
  {
      cout<<0<<Endl;
      return;
  }
  int ans=0;
  findhash(a);
  int hb=0;
    hb=((b[0]-'a'+1)*p[0])%mod;
    for(int i=1;i<m;i++)
    {
        hb=(hb+((b[i]-'a'+1)*p[i])%mod)%mod;
    }
  /*  cout<<hb<<endl;
    for(int i=0;i<n;i++)
        cout<<h[i]<<" ";
    cout<<endl;*/
  for(int i=0;i+m-1<n;i++)
  {
      int l=i;
      int r=i+m-1;
      //if(hash(l,r)==hashb
      if(hb*fpow(prime,l)%mod==(i==0?h[r]:(h[r]-h[l-1]+mod)%mod))
      {
          ans++;
      }
  }



  cout<<ans<<endl;

}


int32_t main()
{
 fastio
  int t=1;
// cin>>t;
power();

  for(int i=1;i<=t;i++)
  {
   // cout<<"Case #"<<i<<": ";


   solve();
  // cout<<endl;

  }

 return 0;

}
