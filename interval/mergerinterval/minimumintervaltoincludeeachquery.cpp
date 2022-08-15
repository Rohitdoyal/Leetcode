#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    
    static bool compare(vector<int>&a , vector<int>&b){
        if((a[1]-a[0])==(b[1]-b[0])){
            return a[0]<b[0];
        }
        return (a[1]-a[0])<(b[1]-b[0]);
    }
    
    int checkpos(vector<vector<int>>& intervals , int element){
        int i =0;
        for( i =0; i<intervals.size(); i++){
            if(intervals[i][1]>=element &&((intervals[i][0]<=element))){
                return intervals[i][1]-intervals[i][0]+1;
            }
        }
        return -1;
        
        
    }
    
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        
        sort(intervals.begin(),intervals.end(),compare);
        vector<int> ans;
        
        for(int i =0; i<queries.size() ;i++){
            int lem= checkpos(intervals ,queries[i]);
            ans.push_back(lem);
        }
            
        return ans;        
    }
};
int main(){
    
    return 0;
}