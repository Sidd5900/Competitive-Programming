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
#define ld long double
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug(a) cerr << #a << ": " << a << endl
#define ordered_set tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update>
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define minheap priority_queue<int,vector<int>,greater<int>>



/***************************************************************************************************/

const int LIM   = 200005;
const int N=1000005;

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
int gcd(int a,int b)
{
      if(b == 0)return a;
      return gcd(b,a % b);
}
//int fac[1000001];
//int inv[1000001];

void create_fac(int n)
{
      vector<int> fac(N),inv(N);
      fac[0] = inv[0] = 1;
      for(int i=1;i<=n;i++)
      {
            fac[i] = fac[i-1]*i % mod;
            inv[i] = fpow(fac[i],mod-2);//inverse of i factorial wrt modulo m
      }
}

int ncr(int n,int r)
{
      vector<int> fac(N),inv(N);
      return fac[n] * (inv[r] * inv[n-r] %mod ) % mod;
      return fac[n] * (fpow(fac[r],mod-2) * fpow(fac[n-r],mod-2) % mod ) % mod;
}

// O(n)
/*bool prime[5*LIM];
void sieve(int n) {
    memset(prime, true, sizeof(prime));
    for (int p=2; p*p<=n; p++)
        if (prime[p] == true)
            for (int i=p*p; i<=n; i += p)
                prime[i] = false;
    prime[1]=0;}*/

// O(sqrt(n))
bool isPrime(int n){
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;}

/*int minPrime[LIM];
void minprimesieve(int n)
{
for(int i = 2; i * i <= n; ++i)
{

    if (minPrime[i] == 0)
    {         //If i is prime
        for (int j = i * i; j <= n; j += i)
        {
            if (minPrime[j] == 0)
            {
                minPrime[j] = i;
            }
        }
    }

}
//for (int i = 2; i <= n; ++i) {
  //  if (minPrime[i] == 0) {
    //    minPrime[i] = i;
    //}
//}
}*/


// O(logn * sqrt(n))
map<int,int> primeFactors(int n)
{
    map<int, int> mp;
    while (n % 2 == 0)
    {
        mp[2]++;
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            mp[i]++;
            n = n/i;
        }
    }
    if (n > 2)
    {
            mp[n]++;
    }
    return mp;
}

int fib(int n) {
  long double phi = (1 + (ld)sqrt(5)) / 2;
  return round(pow(phi, n) / (ld)sqrt(5));
}

ii extendedEuclid(int A, int B)
{
  if(B==0)
  return {1,0};
  ii temp=extendedEuclid(B,A%B);
  int x1=temp.first;
  int y1=temp.second;
  int x=y1;
  int y=x1-(A/B)*y1;
  return {x,y};
}

int modInverse(int A, int M)
{
    ii temp=extendedEuclid(A,M);
    int x=temp.first;
    return (x%M+M)%M;    //x may be negative
}

int32_t main()
{
    minprimesieve(100);
    for(int i=1;i<=30;i++)
        cout<<minPrime[i]<<" ";
    return 0;
}
