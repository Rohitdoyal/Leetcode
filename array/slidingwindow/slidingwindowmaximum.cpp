#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //it's will done using max heap
        
        priority_queue<pair<int,int>>q;
        
        for(int i =0; i<k; i++){
            q.push({nums[i],i});
        }
        vector<int>ans;
        ans.push_back(q.top().first);
        
        for(int j =k; j<nums.size(); j++){
            
            q.push({nums[j],j});
           
            int pos= q.top().second;
            while(j-pos>=k){
                q.pop();
                pos= q.top().second;
            }
            ans.push_back(q.top().first);
            
        }
        return ans;
        
    }
};
int main(){
    
    return 0;
}