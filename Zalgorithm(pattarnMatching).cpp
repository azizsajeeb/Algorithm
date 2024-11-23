#include<bits/stdc++.h>
using namespace std;


int main(){
  string text,pat;
  cin>>text>>pat;
int c=0;

string s=pat+"$"+text;

vector<int>z(s.size(),0);

int l=0,r=0;//initial range 0

for(int i=1;i<s.size();i++){

if(i<r){
  z[i]=z[i-l];

   if(i+z[i]>r) {
    z[i]=r-i;
   }
}

while(i+z[i]<s.size() && s[z[i]]==s[i+z[i]]){
  z[i]++;
}

 if(i+z[i]>r){
  l=i;
  r=i+z[i];
 }
   
    if(z[i]==pat.size()){
      c++;
    }
}

cout<<c<<endl;

}