#include<bits/stdc++.h> 
using namespace std;



typedef pair<int,int> pi;
int dijkstra(unordered_map<int, vector<pair<int,int>>>&adj,int target, int C,int A ){
    
    
    priority_queue<pi,vector<pi>,greater<pi>>q;
    //cost, node 
    q.push({0,C});
    vector<int>distance(A+1,INT_MAX);
    distance[C]=0;
    
    while(q.empty()==false){
        int node = q.top().second;
        int cost  = q.top().first;
        q.pop();
        
        if(node== target){
            return cost;
        }
        
        for(auto x: adj[node]){
            int adjnode= x.first;
            int edgecost = x.second;
            
            if(distance[adjnode]>distance[node]+edgecost){
                distance[adjnode]  = distance[node]+edgecost;
                q.push({distance[adjnode],adjnode});
            }
        }
    }
    return -1;
}



int solve(int A, vector<vector<int> > &B, int C, int D, vector<vector<int> > &E) {
    
    //we will apply dijkstra here 
    //adj matrix 
    
    unordered_map<int, vector<pair<int,int>>>adj;
    
    for(int i =0; i<B.size(); i++){
        adj[B[i][0]].push_back({B[i][1],B[i][2]});
        adj[B[i][1]].push_back({B[i][0],B[i][2]});
    }
    
    int ans = INT_MAX;
    int temp = dijkstra(adj,D,C,A);
    
    if(temp!=-1){
        ans = min(ans ,temp);
    }
    
    int prevx=E[0][0];
    int prevy=E[0][1];
    //edge between x->y 
    adj[E[0][0]].push_back({E[0][1],E[0][2]});
    adj[E[0][1]].push_back({E[0][0],E[0][2]});
    int bold = dijkstra(adj,D,C,A);
    if(bold!=-1){
        ans = min(ans ,bold);
    }    
    
    for(int i =1; i<E.size(); i++){
       
        adj[prevx].pop_back();
        adj[prevy].pop_back();
        
        //add new edge 
        adj[E[i][0]].push_back({E[i][1],E[i][2]});
        adj[E[i][1]].push_back({E[i][0],E[i][2]});
        prevx= E[i][0];
        prevy= E[i][1];
        int told = dijkstra(adj,D,C,A);
        if(told!=-1){
            ans = min(ans ,told);
        }    
            
        
    }
    if(ans==INT_MAX){
        return -1;
    }
    return ans;   
}


int main(){
    
    return 0;
}