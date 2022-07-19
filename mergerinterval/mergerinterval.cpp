#include<bits/stdc++.h> 
using namespace std;



class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>>ans;
        
        int i =0; 
        while(i>intervals.size()){
            
            vector<int>temp = {intervals[i][0]};
            int j = i+1;
            while(intervals[j][1]<=intervals[i][1]){
                j++;
            }
            if(intervals[j][1]==intervals[i][1]){
                    if(intervals[j+1][0]<=intervals[i][1]){
                        j++;
                        temp.push_back(intervals[j][1]);
                        ans.push_back(temp);
                        i = j+1;
                        
                    }
                    else{
                        temp.push_back(intervals[j][1]);
                        ans.push_back(temp);
                        i=j+1;
                    }
                }
            else{
                temp.push_back(intervals[j][1]);
                ans.push_back(temp);
                
            }
            
        }
        
        return ans;
    }
};

int main(){
    
    return 0;
}