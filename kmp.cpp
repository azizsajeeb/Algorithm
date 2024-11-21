         /*in the name of almighty ALLAH*/
//kmp is a pattern matching algo
#include <bits/stdc++.h>

using namespace std;

/*ai ftn e amra akta lps array create kortaci , jeikhane 
kono akta ind er value dara bujay oi ind porjonto
koto len er suffix and prefix arrey equal
ex:ababa
pos 4 porjont 2 len er suf and pre arra equal, cz pre(ab)==suf(ab)
but pos 5 porjonto 1 len er suf and pre arry equal, pre(a)==suf(a)*/

//using createLPS ftn we can track the max len of suf and pre array/string up to any index

vector<int>createLPS(string pattern,int m){

  vector<int>lps(m);
  lps[0]=0;

  int ind=0;
  for(int i=1;i<m;){

 if(pattern[i]==pattern[ind]){
    lps[i]=ind+1;
    ind++;
    i++;
 }

 else{
   if(ind>0){
    ind=lps[i-1];
   }
   else{
    lps[i]=ind;
     i++;
   }
 }

  }
 

 return lps;
}

int main(){
  string text,pattern;
  cin>>text>>pattern;
int n=text.size();
int m=pattern.size();

  vector<int>lps= createLPS(pattern,m);

int i=0,j=0;//i->text,j->pattern

while(i<text.size()){

  if(text[i]==pattern[j]){
    i++;j++;
  }

 else{
   if(j>0){
    j=lps[j-1];
   }

   else i++;
 }

 if(j==pattern.size()){
  cout<<"pattern found"<<endl;
  return 0;
 }

}

  

cout<<"pattern not found"<<endl;


}
