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

Node* inorderSuccecor(Node *root){
  Node* current;

   while(current && current->left!=NULL){
    
current=current->left;

   }

   //it is inorder succecor
   return current;
}

Node* deleteBST(Node *root, int key){
  if(key<root->data){
    root->left = deleteBST(root->left,key);
  }
  else if(key>root->data){
    root->right=deleteBST(root->right,key);
  }
//equal hole
else{
   if(root->left==NULL){
    Node* temp=root->right;
     free(root);
     return temp;
   }

   else if(root->right==NULL){
    Node* temp=root->left;
    free(root);
     return temp;
   }
   // duita child 
   Node * temp= inorderSuccecor(root->right);
   root->data=temp->data;
   //inorder succecor delete
   root->right= deleteBST(root->right,temp->data);
}

return root;

}

int main()
{
  
Node *root=NULL;

root=new Node(4);
root->left=new Node(2);
root->right=new Node(5);
root->left->left=new Node(1);
root->left->right=new Node(3);
root->right->right=new Node(6);

 //printing after BST

 inorder(root);
 cout<<endl;
 //delete node
 root= deleteBST(root,5);
  inorder(root);

 
}

