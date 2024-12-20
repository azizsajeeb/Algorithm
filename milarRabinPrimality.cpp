/*Milar Rabin Primality Test*/
#include <bits/stdc++.h>

using namespace std;

#define ll long long
//CHECKING OVERFLOW
ll mulmod(ll ans,ll base,ll mod){
  return __int128(ans)*base%mod;
}

ll Bigmod(ll base,ll exp,const ll mod){

  ll ans=1%mod;
  base= base%mod;

   //if(base<0)base+=mod;

    while(exp){

       if(exp & 1 ){
        ans=mulmod(ans,base,mod);
        // ans= ((ans%mod)* (base%mod))%mod;
       }

       base=mulmod(base,base,mod);
       exp= exp/2;
    }

    return ans;
}
 bool check_composite(ll n,ll a, ll d,int s){

  ll x=Bigmod(a,d,n);

if(x==1 || x==n-1){
  return false;
}

for(int i=1;i<s;i++){
  x= mulmod(x,x,n);
  if(x==n-1)return false;
}

return true;
 }

bool millerRabin(ll n){

  if(n<2){
    return false;
  }
    
  int s=0; ll d=n-1;

while( d%2==0){
  d/=2;
  s++;
}

for(ll a:{2,3,5,7,11,13,17,19,23,29,31,37}){

  if(n==a)return true;
if(a>n)break;
  if(check_composite(n,a,d,s)) return false;


}

return true;

}
void solve(){

ll n;cin>>n;

if(millerRabin(n)){
  cout<<"YES"<<endl;
}
else cout<<"NO"<<endl;


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}
