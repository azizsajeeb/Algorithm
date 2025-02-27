#include<iostream>
using namespace std;

struct Node{
  int data;
  Node *left,*right;
  Node(int val){
    data=val;
    left=NULL;
    right=NULL;
  }
};

//creating binarySearchTree
//after inserting this function may update the node
//according to the val, the function will return the
//updated value to it's address using pointer
Node * insertBST(Node *root,int val){
    if(root==NULL){
        return new Node(val);
    }

    if(val<root->data){
        root->left=insertBST(root->left,val);
    }
    else{
        root->right=insertBST(root->right,val);
    }

    return root;
}

//printing BST in inorder way
void inorder(Node *root){
    if(root==NULL)return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

Node *searchInBST(Node *root, int key){
  if(root==NULL){
    return NULL;
  }
  if(root->data==key){
    return root;
  }

  if(root->data>key){
    return searchInBST(root->left,key);
  }
  else searchInBST(root->right,key);
}
int main()
{
  
Node *root=NULL;

root=insertBST(root,5);
   insertBST(root,1);
 insertBST(root,3);
  insertBST(root,4);
  insertBST(root,2);
   insertBST(root,7);

 //printing after BST

 inorder(root);
 cout<<endl;
 //search a node;
  Node * p=searchInBST(root,5);
  if(p!=NULL){
    cout<<"key exist"<<endl;
  }
  else cout<<"key not exist"<<endl;
}

