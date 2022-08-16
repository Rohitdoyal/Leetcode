#include<bits/stdc++.h> 
using namespace std;


class Solution {
public:
    
    void solve(int i ,vector<int>&cand, int target,vector<int>& temp, vector<vector<int>>&ans){
        
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(i>=cand.size() ||(target<0)){
            return;
        }
        
        for(int j =i; j<cand.size() ;j++){
            if(cand[j]>target){
                break;
            }
            
            if(j>i && (cand[j-1]==cand[j])){
                continue;
            }
            
            temp.push_back(cand[j]);
            solve(j+1,cand,target-cand[j],temp,ans);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        
        vector<int>temp;
        vector<vector<int>>ans;
        
        solve(0,candidates,target, temp,ans);
        return ans;
    }
};
int main(){
    
    return 0;
}