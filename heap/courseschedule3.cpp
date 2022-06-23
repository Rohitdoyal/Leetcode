#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    bool sortbysec(vector<int>&a,vector<int>&b){
        if(a[1]==b[1]){
            return a[0]<b[0];
        }
        return a[1]<b[1];
    }
    
    void printc(vector<vector<int>>& courses){
        for(int i =0; i<courses.size() ; i++){
            cout<<"["<<courses[i][0]<<", "<<courses[i][1]<<"]"<<", ";
        }
        cout<<endl;
    }
    
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(), [this] (vector<int>a, vector<int>b) {
    return sortbysec(a, b); });
        
       // printc(courses);
        
        priority_queue<int>heap;
        int time = 0;
      
        int n = courses.size();
        for(int i =0; i<n ; i++){
            if(courses[i][0]+time <=courses[i][1]){
                time+=courses[i][0];
                heap.push(courses[i][0]);
                
            }
            else{
                if((heap.empty()==false) &&(heap.top()>courses[i][0])){
                    time= time-heap.top()+courses[i][0];
                    heap.pop();
                    heap.push(courses[i][0]);
                }
            }
        }
        return heap.size();
        
        
    }
};

int main(){
    
    return 0;
}