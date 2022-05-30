#include<bits/stdc++.h> 
using namespace std;


class Solution {
public:
bool canJump(vector<int>& nums) {
     
        //simple question 
        // so what we have 
        //we have array of step //
        //so let's assume that we are at initially position 0 and 
        //whenever we get some position we iincrement ourselve and reach that location 
        
        if(nums.size()==1){
            return true;
        }
        int dist=0;
        for(int i =0; i<nums.size(); i++){
            dist = max(dist, i+nums[i]);
            if(dist>=nums.size()-1){return true;}
            if(dist<= i){return false;}
            
        }
        return false;
      
        
    }
};

int main(){
    
    return 0;
}