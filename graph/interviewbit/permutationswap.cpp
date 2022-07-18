#include<bits/stdc++.h> 
using namespace std;



void dfs(unordered_map<int,vector<int>>&adj,vector<bool>&visit, int node , int step ,vector<int> &A, vector<int> &B
, unordered_map<int, vector<int>>&Ahold, unordered_map<int, vector<int>>&Bhold){
    visit[node]= true;
    Ahold[step].push_back(A[node-1]);
    Bhold[step].push_back(B[node-1]);
  
    for(auto x: adj[node]){
        if(visit[x]==false){
            dfs(adj,visit,x,step,A,B,Ahold,Bhold);
            
        }
    }
    return;
}


int solve(vector<int> &A, vector<int> &B, vector<vector<int> > &C) {
    //first apprach
    
    ///let's build adj matrix first 
    unordered_map<int,vector<int>>adj;
    
    for(int i =0; i<C.size(); i++){
        adj[C[i][0]].push_back(C[i][1]);
        adj[C[i][1]].push_back(C[i][0]); 
    }
    
    //dfs and set it 
    
    int n = A.size();
    unordered_map<int, vector<int>>Ahold;
    unordered_map<int, vector<int>>Bhold;
    
    int step =0;
    vector<bool> visit(n+1,false);
    for(auto g: adj){
        int i = g.first;
        if(visit[i]==false){
            step++;
            dfs(adj,visit, i, step, A,B,Ahold,Bhold);
        }
        
    }
    
    // cout<<"A is =";
    // for(int i =0; i<A.size(); i++){
    //     cout<<A[i]<<" ";
    // }cout<<endl;
    
    // cout<<"B is =";
    // for(int i =0; i<B.size(); i++){
    //     cout<<B[i]<<" ";
    // }cout<<endl;
    
    
    for(int i =1; i<=step; i++){
        
        if(Ahold[i].size()!=Bhold[i].size()){
            return 0;
        }
        
        else{
            sort(Ahold[i].begin(),Ahold[i].end());
            sort(Bhold[i].begin(),Bhold[i].end());
            
            for(int j =0; j<Ahold[i].size(); j++){
                if(Ahold[i][j]!=Bhold[i][j]){
                    return 0;
                }
            }
        }
        
    }
    return 1;
    
    
    
}

int main(){
    
    return 0;
}