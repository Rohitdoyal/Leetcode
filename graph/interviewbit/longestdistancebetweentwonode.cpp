#include<bits/stdc++.h> 
using namespace std;

class Solution{
    int solve(vector<int>& a);
};

int Solution::solve(vector<int> &A) {
    if(A.size()==1){
        return 0;
    }
    vector<int> g={-1,0};
    if(A==g){
        return 1;
    }
    //what we are going to do we pick any node and apply bfs on it so at the end we reach that point which is 
    //100% one of the end of longest path 
    //you can prove it using take some exaple let's try to prove using some method 
    // now in next setp again apply bfs and find largest distance that is it voiliaa !!
    //---prove---
    //let's assume that longest path as simple line and all other node branches of that line 
    //now if we start from any node suppose it's near to left end so branch is small because we arrang in such a way 
    //so we end up with right end similary if we start from right then left . if we start from middle then one of the left or right so 
    // we are 100 % SURE we end up with one of the end then simple .
    //after that we again apply bfs and got the length 
    
    
    //adj matrix 
    //A{i} connected with i th node 
    unordered_map<int,vector<int>>adj;
    for(int i =0; i<A.size(); i++){
        if(A[i]!=-1){
            adj[A[i]].push_back(i);
            adj[i].push_back(A[i]);
        }
        
    }
    
    // for(auto x: adj){
    //     cout<<x.first<<":";
    //     for(int i =0; i<x.second.size(); i++){
    //         cout<<x.second[i]<<"->";
    //     }
    //     cout<<endl;
    // }
    //first bfs 
    
    
    int s= A[1];
    
    queue<int>q;
    q.push(s);
    int n = A.size();
    vector<bool>visit(n,false);
    
    int leaf= s;
    while(q.empty()==false){
        int n = q.size();
        for(int i =0; i<n; i++){
            int t= q.front();
            leaf= t;
            q.pop();
            for(auto x:adj[t]){
                if(visit[x]==false){
                    q.push(x);
                    visit[x]= true;
                }
                
            }
        }
    }
    
    //cout<<"leaf node is "<<leaf<<endl;
    
    for(int i =0; i<n; i++){
        visit[i]= false;
    }
    
    int depth =0;
    q.push(leaf);
    while(q.empty()==false){
        int n = q.size();
        depth++;
        for(int i =0; i<n; i++){
            int t= q.front();
          
            q.pop();
            for(auto x:adj[t]){
                 if(visit[x]==false){
                    q.push(x);
                    visit[x]= true;
                }
            }
        }
    }
    
    return depth-1; 
}

int main(){
    
    return 0;
}