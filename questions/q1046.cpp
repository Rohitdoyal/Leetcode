#include<bits/stdc++.h> 
using namespace std;


//method 1
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        //heap
        //max heap
        //already implemented , but we will do using both the method 
        
        //usig stl 
        
        //base case 
        if(stones.size()==1){
            return stones[0];
        }
        
        priority_queue<int> q;
        for(int i =0; i<stones.size(); i++){
            q.push(stones[i]);
        }
        
        
        //assumption a>b
        
        while(q.size()>1){
            int a = q.top(); q.pop();
            int b = q.top(); q.pop();
            a= a-b;
            if(a>0){
                q.push(a);
            }
            
        }
        if(q.size()==0){
            return 0;
        }
        else{
            return q.top();
        }
    }
};





int main(){
    
    return 0;
}