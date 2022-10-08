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
#define inf 1e9
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
const int LIM   = 200005;
const int MAXN=100005;
const int N=1000005;
int i,j,k;

//disjoint set union find-----------------------------------------------
int parent[LIM];
int rnk[LIM];
int siz[LIM];
void make_set(int v) {
    parent[v] = v;
   //rnk[v] = 0;
   siz[v]=1;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (siz[a] < siz[b])
            swap(a, b);
        parent[b] = a;
     //   if (rnk[a] == rnk[b])
          //  rnk[a]++;
          siz[a]+=siz[b];
    }
}
//sparse table-----------------------------------------------------
const int K=25;
int loga[MAXN+1];
int st[MAXN][K + 1];
void sparse(int arr[],int N)
{

loga[1] = 0;
for (int i = 2; i <= MAXN; i++)
    loga[i] = loga[i/2] + 1;



for (int i = 0; i < N; i++)
    st[i][0] = arr[i];

for (int j = 1; j <= K; j++)
    for (int i = 0; i + (1 << j) <= N; i++)
        st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);

/*cin>>L>>R;
       int j = loga[R - L + 1];
       int minimum = min(st[L][j], st[R - (1 << j) + 1][j]);
       cout<<minimum<<endl;*/
}
//segment tree--------------------------------------------------------------
int arr[LIM];
int stree[4*LIM];
void build(int node, int start, int end)
{
    if(start == end)
    {
        // Leaf node will have a single element
        stree[node] = arr[start];
    }
    else
    {
        int mid = (start + end) / 2;
        // Recurse on the left child
        build(2*node, start, mid);
        // Recurse on the right child
        build(2*node+1, mid+1, end);
        // Internal node will have the sum of both of its children
        stree[node] = stree[2*node] + stree[2*node+1];
    }
}

void update(int node, int start, int end, int idx, int val)
{
    if(start == end)
    {
        // Leaf node
        arr[idx] += val;
        stree[node] += val;
    }
    else
    {
        int mid = (start + end) / 2;
        if(start <= idx and idx <= mid)
        {
            // If idx is in the left child, recurse on the left child
            update(2*node, start, mid, idx, val);
        }
        else
        {
            // if idx is in the right child, recurse on the right child
            update(2*node+1, mid+1, end, idx, val);
        }
        // Internal node will have the sum of both of its children
        stree[node] = stree[2*node] + stree[2*node+1];
    }
}

int query(int node, int start, int end, int l, int r)
{
    if(r < start || end < l)
    {
        // range represented by a node is completely outside the given range
        return 0;
    }
    if(l <= start && end <= r)
    {
        // range represented by a node is completely inside the given range
        return stree[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    int mid = (start + end) / 2;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, end, l, r);
    return (p1 + p2);
}

//------------------Trie----------------------------------------------------------------

// struct Trie *root = createNode(); in main()
//code for lowercase chage a to A for uppercase
const int ALPHA_SIZE = 26;

struct Trie {
   struct Trie *child[ALPHA_SIZE];
   bool endofstring; //It is true if node represents end of word.
};
struct Trie *createNode(void) //creation of new node {
{struct Trie *tNode = new Trie;
   tNode->endofstring = false;
   for (int i = 0; i < ALPHA_SIZE; i++)
      tNode->child[i] = NULL;
   return tNode;
}
void insert(struct Trie *root, string key) {
   struct Trie *curr = root;
   for (int i = 0; i < key.length(); i++) {
      int index = key[i] - 'a';
      if (!curr->child[index])
         curr->child[index] = createNode();
         curr = curr->child[index];
   }
   curr->endofstring= true; //last node as leaf
}
bool search(struct Trie *root, string key) { //check if key is present in trie. If present returns true
   struct Trie *curr = root;
   for (int i = 0; i < key.length(); i++) {
      int index = key[i] - 'a';
      if (!curr->child[index])
         return false;
      curr = curr->child[index];
   }
   return (curr != NULL && curr->endofstring);
}
bool isEmpty(Trie* root) //check if root has children or not {
{
   for (int i = 0; i < ALPHA_SIZE; i++)
   if (root->child[i])
   return false;
   return true;
}
Trie* deletion(Trie* root, string key, int depth = 0) {
   //If tree is empty return null.
   if (!root)
   return NULL;
   if (depth == key.size()) { //If last character of key is being processed,
      if (root->endofstring)
         root->endofstring = false; //then that node will be no more end of string after deleting it.
      if (isEmpty(root)) { //If given key is not prefix of any other string,
         delete (root);
         root = NULL;
      }
   return root;
   }
   //If key not last character,
   int index = key[depth] - 'a';
   root->child[index] =
   deletion(root->child[index], key, depth + 1); //Then recur for the child which will be obtained by using ASCII value.
   if (isEmpty(root) && root->endofstring == false) { //If root does not have any child leftand it is not end of another word
      delete (root);
      root = NULL;
   }
   return root;
}

//-----------------------------------------------------------------------------------------------------------------
int32_t main()
{
    int n;
    cin>>n;
    struct Trie *root = createNode();
    string y;
    fo(i,0,n)
    {cin>>y;
    insert(root,y);
    }
    int m;
    cin>>m;
    string x;
    fo(i,0,m)
    {
     cin>>x;
     cout<<search(root,x)<<endl;
    }

    return 0;

}
