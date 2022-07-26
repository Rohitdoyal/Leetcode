#include<bits/stdc++.h> 
using namespace std;


struct treenode {
    int val;
    struct treenode* left;
    struct treenode* right;
};


struct treenode* lcs(struct treenode* root, struct treenode* p,struct treenode*q){
    if(root==NULL){
        return NULL;
    }

    if((root==p) || (root==q)){
        return root;
    }

    struct treenode* l = lcs(root->left,p,q);
    struct treenode* r = lcs(root->right,p,q);

    if(l&&r){
        return root;
    }

    if(l){return l;}
    return r;

}


int main(){
    
    return 0;
}