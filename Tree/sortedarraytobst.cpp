#include<bits/stdc++.h> 
using namespace std;

/**
 * Definition for singly-linked list.
 * /
 *  **/
/**


 */// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

struct ListNode {
      int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    
    TreeNode* solve(int l, int r, vector<int>& nums){
        if(l>r){
            return NULL;
        }
        
        int mid = r-(r-l)/2;
        TreeNode* node= new TreeNode(nums[mid]);
        node->left= solve(l,mid-1,nums);
        node->right = solve(mid+1,r,nums);
        return node;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int l =0;
        int r= nums.size()-1;
        TreeNode *root= solve(l,r,nums);
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>A;
        while(head){
            A.push_back(head->val);
            head= head->next;
        }
        
        return sortedArrayToBST(A);
        
    }
};
int main(){
    
    return 0;
}