//https://cses.fi/problemset/task/1753/
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
int ans;
int m;

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n+1);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
        if(pi[i]==m)
            ans++;
    }
    return pi;
}


void solve()
{
  string a;
  string b;
  cin>>a>>b;
  int n=a.size();
  m=b.size();
  if(n<m)
  {
      cout<<0<<Endl;
      return;
  }

  string temp=b+"."+a;
  //cout<<temp<<endl;

  vi pi=prefix_function(temp);


  cout<<ans<<endl;

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
