#include <iostream>
using namespace std;
 
struct node
{
    int data;
    node* left;
    node* right;
};
typedef struct node tree;
tree* CreateNode(int datum)
{
    tree* node;
    node = new tree;
    node->data = datum;
    node->left = NULL;
    node->right = NULL;
    return node;
}
void AddNode(tree* &root , int datum)
{
    if(root == NULL)
       root = CreateNode(datum);
    else{
       if(root->data > datum)
          AddNode(root->left,datum);
       else
          AddNode(root->right,datum);
    }
}
void NLR(tree* root)
{
    if(root != NULL){
       cout<<root->data<<" ";
      NLR(root->left);
       NLR(root->right);
    }
}
 
void LRN(tree* root) {
     if (root != NULL) {
         LRN(root->left);
         LRN(root->right);
         cout<<root->data<<" ";
     }
}
 
void LNR(tree* root) {
     if (root != NULL) {
         LNR(root->left);
         cout<<root->data<<" ";
         LNR(root->right);
     }
}
 
int main()
{
    int i;
    int a[] = {23,11,41,15,27,29,24,5,42,52};
    tree* root = NULL;
    for(i=0;i<10;i++)
       AddNode(root,a[i]);
    cout<<"Duyet truoc: NLR ";
    NLR(root);
    cout<<endl;
    cout<<"Duyet giua: LNR ";
    LNR(root);
     cout<<endl; 
    cout<<"Duyet sau: LRN ";
    LRN(root);
    return 0;
}