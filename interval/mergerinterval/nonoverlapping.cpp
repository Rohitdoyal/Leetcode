#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count =0;
        int l =0;
        int r= 1 ;
        
        sort(intervals.begin(),intervals.end());
        
        while(r<intervals.size()){
            if(intervals[l][1]<=intervals[r][0]){
                l=r;
                r++;
            }
            
            else if(intervals[l][1]<=intervals[r][1]){
                r++;
                count++;
            }
            else { 
                l=r;
                r++;
                count++;
            }

        
            
        }
        return count;
    }
};
int main(){
    
    return 0;
}