#include<bits/stdc++.h> 
using namespace std;



void dfs(int node , vector<bool>&visit,unordered_map<int, vector<int>>&adj){
    visit[node]= true;
    for(auto x: adj[node]){
        if(visit[x]==false){
            dfs(x,visit,adj);
        }
    }
    return;
}


int motherVertex(int A, vector<vector<int> > &B) {
    
    //dfs 
    unordered_map<int, vector<int>> adj;
    for(int i =0; i<B.size(); i++){
        if(B[i][0]!=B[i][1]){
            adj[B[i][0]].push_back(B[i][1]);
    }}
    
    int mother =-1;
    vector<bool>visit(A+1,false);
    
    for(int i =1; i<A+1; i++){
        if(visit[i]==false){
            dfs(i,visit,adj);
            mother =i;
        }
    }
    
    for(int i =0; i<A+1; i++){
        visit[i]= false;
    }
    
    dfs(mother, visit, adj);
    int ans =1;
    for(int i =1; i<A+1; i++){
        if(visit[i]==false){
            ans =  0;
            break;
        }
    }
    visit.clear();
    adj.clear();
    return ans;
    
    
    
}


int main(){
    
    return 0;
}