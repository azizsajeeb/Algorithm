/*determine the valu of X :
aX^2 + bX + c for which minimum value of 
x , aX^2 + bX + c>=k(k is a given value) */
//prbLink:https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/monks-encounter-with-polynomial/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nl "\n"

int a,b,c,k;

ll calc(int mid){
  return (a*mid*mid)+(b*mid)+c;
}
int main(){
  int t;cin>>t;
  while(t--){
    cin>>a>>b>>c>>k;
int high=sqrt(k);/*because we have to do x^2*/
int low=0;

int ans=-1;
 while(low<=high){
   int mid=(low+high)/2;

   if(calc(mid)>=k){
    ans=mid;  high=mid-1;
   }

   else low=mid+1;
 }

cout<<"The value of x is: "<<ans<<endl;
    
  }
}