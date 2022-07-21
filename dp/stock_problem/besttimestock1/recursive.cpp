#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    
    //RECURSIVE SOLUTION 
    int f(int i,  int buy , vector<int>&price){
        if(i>=price.size()){
            return 0;
        }
      
        if(buy==1){
            return max(-price[i]+f(i+1,0,price),f(i+1,1,price));    
        }
        
        else{
            return max(price[i]+f(i+2,1,price),f(i+1,0,price));
        }
    }
    int maxProfit(vector<int>& prices) {
        return f(0,1,prices);
    }
};
int main(){
    
    return 0;
}