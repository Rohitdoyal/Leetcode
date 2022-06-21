#include<bits/stdc++.h> 
using namespace std;


class solution{
    public:
 int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n =  heights.size();
        priority_queue<int>q;
        
        for(int i =1; i<heights.size() ; i++){
            int diff=  heights[i]-heights[i-1];
            (diff<0)?(diff=0):(diff= diff);
            q.push(diff);
            if(bricks<diff){
                if(ladders==0){return i-1;}
                bricks = bricks+q.top();
                q.pop();
                ladders--;
            }
            
           
                bricks= bricks-diff;
            
            
        }
        return n-1;
        
        
    }
};

int main(){
    
    return 0;
}