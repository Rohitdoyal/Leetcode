#include<bits/stdc++.h> 
using namespace std;

//first method 
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k)    {
        if(points.size()==1){
            return points;
        }
        vector<vector<int>> ans;
        priority_queue<pair<double,vector<int>>>q;
        for(int i =0; i<points.size(); i++){
            double d= sqrt(points[i][0]*points[i][0]+points[i][1]*points[i][1]);
            q.push({d,points[i]});
            if(q.size()>k){
                q.pop();
            }
        }
        while(q.size()){
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    }
};


//second method can be what we can actually we can sort the points accoundring to distance and then can tell what is answer
//but it will take nlogn time complexity 
//our solution in klogn time complexity which is better 


int main(){
    
    return 0;
}