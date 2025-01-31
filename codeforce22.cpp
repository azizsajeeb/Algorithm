
 /*moore's voting algoritm:time-O(n); Space-O(1)
 given an array. find the majerity element(frequency>(n/2))*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vl vector<ll>
#define vi vector<int>

void solve(){
 int n;cin>>n;
 vi v(n); 
  for(int i=0;i<n;i++)cin>>v[i];

  int val=v[0];
  int c=0;

   for(auto x:v){
     if(x==val){
        c++;
     }

 else{
    c--;
    if(c==0){
        val=x; c++;
    }
 }


   }

    cout<<"THE MAJORITY ELEMENT IS : "<<val<<endl;

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
