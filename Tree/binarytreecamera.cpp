#include<bits/stdc++.h> 
using namespace std;


class Solution {
public:
    int cam;
    
    int dfs(TreeNode* root){
        if(root==NULL){
            return 1;
        }
        int l = dfs(root->left);
        int r= dfs(root->right);
        
        if(l==0 ||r==0){
            cam++;
            return 2;
        }
        
        else if(l==2 || (r==2)){
            return 1;
        }
        
        else{
            return 0;
        }
    }
    
    
    int minCameraCover(TreeNode* root) {
        //so this is one of good  question 
        cam= 0;
        int a= dfs(root);
        if(a==0){
        return cam+1;
        }
        return cam; 
    }
};

int main(){
    
    return 0;
}