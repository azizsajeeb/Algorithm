/*Milar Rabin Primality Test*/
#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll Bigmod(ll base,ll exp,const ll mod){

  ll ans=1%mod;
  base= base%mod;

   if(base<0)base+=mod;

    while(exp){

       if(exp & 1 ){
         ans= (ll)ans*base%mod;
       }

       base=(ll)base*base%mod;
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
  x= (x*x)%n;
  if(x==n-1)return false;
}

return true;
 }

bool millerRabin(ll n){

  if(n<4){
    return n==2 || n==3 ;
  }
    
  int s=0; ll d=n-1;

while( d%2==0){
  d/=2;
  s++;
}

for(int a:{2,3,5,7,11,13,17,19,23,29,31,37}){

  if(n==a)return true;

  if(check_composite(n,a,d,s)) return false;


}

return true;

}
void solve(){

ll n;cin>>n;

if(millerRabin(n)){
  cout<<"prime"<<endl;
}
else cout<<"not prime"<<endl;


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
