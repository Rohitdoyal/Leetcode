#include<bits/stdc++.h> 
using namespace std;


class Solution {
public:
    
    int maxeleindex(vector<int>&arr){
        int idx =0;
        for(int i =0; i<arr.size() ; i++){
            if(arr[i]>arr[idx]){
                idx = i;
            }
        }
        
        return idx;
    }
    
    bool isPossible(vector<int>& target) {
        //think about solution
        //we will go opposite direction 
        //heap  is created by defalut accourding to first element 
        
        
       
        
        int n= target.size();
        long long int sum  = 0;
       
        priority_queue<int> heap;
        
        for(int i =0; i<target.size() ; i++){
            heap.push(target[i]);
            
            sum+=target[i];
        
        }
        
       
        
      
       //  cout<<"sum is "<<sum<<" countone  ="<<countone<<endl;
        while(heap.top()!=1){
            //for optimization we can ue maxheap but let's solve using liner time 
            //we will use max heapfor it 
            
            
            int tp = heap.top();
            heap.pop();
         
            //cout<<"sum is "<<sum<<endl;
            sum = sum-tp;
             if((sum<=0) ||(sum>=tp)){
                return false;
            }
            
            tp = tp%sum;
            sum = sum+tp;
            if(tp>0){
                heap.push(tp);
            }
            else{
                heap.push(sum);
            }          
        }
        
      
        return true;
        
    }
};
int main(){
    
    return 0;
}