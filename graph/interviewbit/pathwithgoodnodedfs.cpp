#include<bits/stdc++.h> 
using namespace std;



void dfs(unordered_map<int,vector<int>>&adj,vector<int> &A , int node,int c, int sum , int &ans){
    if(adj[node].size()==0){
        //leaf node
        if(sum <=c){ans++;}
        return;
    }
    
    for(auto x: adj[node]){
        if(A[x-1]==1){
            dfs(adj,A,x,c,sum+1,ans);
        }
        else{
            dfs(adj,A,x,c,sum,ans);
        }
    }
    return;
}


int solve(vector<int> &A, vector<vector<int> > &B, int C) {
    //let's solve using 
    
    //adj matrix ;
    unordered_map<int,vector<int>>adj;
    for(int i =0; i<B.size(); i++){
        sort(B[i].begin(),B[i].end());
    }

    for(int i =0; i<B.size(); i++){
        adj[B[i][0]].push_back(B[i][1]);
        //adj[B[i][1]].push_back(B[i][0]);
    }
    int ans =0;
    int sum = A[0];
    dfs(adj,A,1,C,sum,ans);
    return ans;
}



int main(){
    
    return 0;
}