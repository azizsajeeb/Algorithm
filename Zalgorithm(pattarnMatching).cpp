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

z[i]=min(z[i-l],r-i+1);

while(i+z[i]<s.size() && s[z[i]]==s[i+z[i]]){
  z[i]++;
}

 if(i+z[I] -1 >r){
  l=i;
  r=i+z[i]-1;
 }
   
    if(z[i]==pat.size()){
      c++;
    }
}

cout<<c<<endl;

}
