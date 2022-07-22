#include<bits/stdc++.h> 
using namespace std;


class Solution {
public:
    
    
    int f(int i , int amount , vector<int>& coins){
        if(i==0){
            return (amount%coins[0]==0);
        }
        
        int not_include = f(i-1,amount , coins);
        int include = 0;
        
        if(amount>=coins[i]){
            include  = f(i,amount-coins[i],coins);
        }
        
        return include+not_include;
        
    }
    
    int change(int amount, vector<int>& coins) {
        if(coins.size()==0){
            return 0;
        }
        return f(coins.size()-1, amount,coins);
    }
};

int main(){
    
    return 0;
}