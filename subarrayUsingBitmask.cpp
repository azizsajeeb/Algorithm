#include <bits/stdc++.h>
using namespace std;
 

 
void solve() {
  int n;cin>>n;
   vector<int>v(n);
   for(int i=0;i<n;i++)cin>>v[i];

for(int i=0;i<(1<<n);i++){

    for(int j=0;j<n;j++){
        if(i & (1<<j)){
            cout<<v[j]<<" ";
        }
    }
    cout<<endl;
}




}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}