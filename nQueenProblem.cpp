#include<bits/stdc++.h>
using namespace std;
#define vvi vector<vector<int>>

bool isSafe(vvi & a, int x, int y, int n){
    for(int row=0;row<x;row++){
if(a[row][y]==1){
    return false;
}
    }

    int row= x;
    int col=y;

while(row>=0 && col>=0){
  if(a[row][col]==1)return false;
  row--;
  col--;
}

     row= x;
  col=y;

while(row>=0 && col<0){
  if(a[row][col]==1)return false;
  row--;
  col++;
}

return true;

}
bool nQueen(vvi &a,int x,int n){
    if(x>=n){
return true; //queen place ses
    }

for(int col=0;col<n;col++){

if(isSafe(a,x,col,n)){
    a[x][col]=1;

    if(nQueen(a,x+1,n)){
        return true;
    }
    else a[x][col]=0;
}


}

return false;

}
int main(){
 int n;cin>>n;

 vector<vector<int>>a(n,vector<int>(n));

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        a[i][j]=0;
    }
  }

if(nQueen(a,0,n)){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)cout<<a[i][j]<<" ";
cout<<endl;
    }
}


}