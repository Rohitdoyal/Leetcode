#include<bits/stdc++.h> 
using namespace std;

int main(){
    
    return 0;
}
class Solution2 {
public:
    
    void solve(vector<int>& nums,int s, int e,vector<int>& t,vector<vector<int>>&ans){
        
        if(s>e){
            ans.push_back(t);
           return;
        }
       
        t.push_back(nums[s]);
        solve(nums,s+1,e,t,ans);
        t.pop_back();
        solve(nums,s+1,e,t,ans);    
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        //subset question 
        //backtraking 
        vector<vector<int>>ans;
        vector<int>t;
        solve(nums,0,nums.size()-1,t,ans);
        return ans; 
    }
};
class Solution {
public:
   
    
    vector<vector<int>> subsets(vector<int>& nums) {
        //subset question 
        //bimasking
        vector<vector<int>>ans;
        int n = nums.size();
        
        for(int i =0; i<pow(2,n); i++){
           
            vector<int> t;
            int j = n-1;
            int r= i;
            while(r){
                if(r&1==1){
                    t.push_back(nums[j]);
                }
                
                r = r/2;
                j--;
            }
            ans.push_back(t);
        }
       
        return ans; 
    }
};