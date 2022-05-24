#include<bits/stdc++.h> 
using namespace std;


//logic
// so first idea which come into our mind is just sort the array and tell this element is kth largest in array 
// but time complexity of this algorithm will be nlog n so can we do it better then this one 
// and answer is yes we can so what we will do 
// we create a min heap min heap which contain smallest element at head
// so heap size is k 
//now insert element in heap if heap size more then k then simpy pop 
// so at the end we have k element at the top smallest element or other word i can say 
// it's kth largest element 

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>, greater<int> > q;
        
        for(int i =0; i<nums.size(); i++){
            q.push(nums[i]);
            if(q.size()>k){
                q.pop();
            }
        }
        return q.top();
        
    }
};
int main(){
    
    return 0;
}