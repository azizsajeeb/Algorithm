         /*in the name of almighty ALLAH*/

#include <bits/stdc++.h>

using namespace std;
//nicer dui ta ordered set niya kaj korer somoy lage
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>

typedef vector<int>                vi;
typedef vector<char>               vc;
typedef vector<long long>          vl;
typedef vector<string>              vs;
typedef pair<int,int>              pi;
typedef pair<long long ,long long> pl;
typedef vector<pair<int,int> >    vpi;
typedef vector<pair<long ,long > >  vpl;
typedef vector<bool>               vb;
typedef map<int,int>               mii;
typedef map<long long, int>        mli;
typedef set<int>                    si;
typedef set<long long>              sll;


#define ll long long
#define fl float
#define db double
#define ld long double
#define spc " "
#define nl "\n"
#define S  second
#define F   first

const int N  =1e5+123;
const int inf =2000000000;
const ll infLL =9000000000000000000;
const int mod =1000000000 + 7;

#define pb push_back
#define pob pop_back()
#define tc int t;cin>>t;while(t--)
#define dsort(v)   sort(v.begin(),v.end())
#define rsort(v)   sort(v.rbegin(),v.rend())
#define rev(v)   reverse(v.begin(),v.end());

#define mem(a,b)  memset(a,b,sizeof(a))
#define cin(v,n)  for(int i=0;i<n;i++)cin>>v[i];
#define uni unique(v.begin(),v.end())-v.begin()
#define maxel *max_element(v.begin(),v.end())
#define minel *min_element(v.begin(),v.end())
#define tsum accumulate(v.begin(),v.end(),0);
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define khojo find(s.begin(),s.end(),'1')-s.end();
inline void normal(ll &a) { a %= mod; (a < 0) && (a += mod); }
inline ll modMul(ll a, ll b) { a %= mod, b %= mod; normal(a), normal(b); return (a*b)%mod; }
inline ll modAdd(ll a, ll b) { a %= mod, b %= mod; normal(a), normal(b); return (a+b)%mod; }
inline ll modSub(ll a, ll b) { a %= mod, b %= mod; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, mod-2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

//if there are two consecutive duplicate element and 5 5 become 5
#define rem_consequitive_duplicatevec(vec) vec.erase(unique(vec.begin(),vec.end()),vec.end())
#define rem_consequitive_duplicates(s) s.erase(unique(s.begin(),s.end()),s.end())
//bool prime[100000000+1];//globally declare korer karone aitay sob 0 insert hoye thakbe
  /*kicui pari na-_-*/
int dx[]={0,+1,0,-1,+1,+1,-1,-1};
int dy[]={+1,0,-1,0,+1,-1,+1,-1};
  const int mx=1e6+123;
struct info{

};
/*minimum cost to build a tree*/
vi par,sz;

int findpar(int u){
  if(u==par[u])return u;
  return par[u]=findpar(par[u]);
}
void UNION(int u,int v){
  if(sz[u]>sz[v])swap(u,v);
  par[v]=u;
  sz[u]+=sz[v];
}
int main(){
  par.clear(),sz.clear();
  int node,edge;
  cin>>node>>edge;
  int an=0;
  int c=0;

par.resize(node);
sz.resize(node,1);//initially size of all node is 1(himself)

for(int i=0;i<node;i++){
  par[i]=i;//the parrent of the node is initially that node

}

vector<pair<int,pair<int,int>>>ed;
ll w=0;//total weight to build a tree

for(int i=0;i<edge;i++){
  int u,v,w;
  cin>>u>>v>>w;
  ed.pb({w,{u,v}});
}
dsort(ed);

for(auto e:ed){
  int u=e.S.F;
  int v=e.S.S;
  int w=e.F;
  int ur=findpar(u);
  int vr=findpar(v);
if(ur!=vr){
  UNION(ur,vr);
  c++;
  an+=w;
}

if(c==node-1)break;
}

cout<<an<<nl;
}