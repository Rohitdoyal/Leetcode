#include<bits/stdc++.h> 
using namespace std;


class Solution {
public:
    
    static bool compare(vector<int>&a, vector<int>&b){
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),compare);
        
        
//         for(int i =0; i<intervals.size(); i++){
//             cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
     
//         }
        
        //we will use stack data structure
        
        stack<vector<int>>s;
        s.push(intervals[0]);
        
        for(int i =1; i<intervals.size(); i++){
            vector<int> t = s.top();
            
            if(intervals[i][0]<=t[1]){
                s.pop();
                if(t[1]<intervals[i][1]){
                     t[1]= intervals[i][1];
                }
               
                s.push(t);
            }
            else{
                s.push(intervals[i]);
            }
            
        }
        vector<vector<int>>ans;
        
        while(s.empty()==false){
            vector<int>temp = s.top();
            s.pop();
            ans.push_back(temp);
        }
        return ans;
    }
};
int main(){
    
    return 0;
}