#include<bits/stdc++.h> 
using namespace std;



class Solution {
public:
    
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        map<int,vector<pair<int,int>>>adj;
        for(int i =0; i<times.size(); i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]}) ;
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>q;
        vector<int>distance(n+1,INT_MAX);
        distance[k]=0;
        q.push({0,k});
        
        vector<bool> visit(n,false);
        
        while(q.empty()==false){
            int dt = q.top().first;
            int node =q.top().second;
            q.pop();
            for(auto x : adj[node]){
                int adjnode = x.first;
                int cost= x.second;
                if(distance[adjnode]>distance[node]+cost){
                    distance[adjnode]= distance[node]+cost;
                    q.push({distance[adjnode],adjnode});
                }
            }
            
        }
        
        
        int ans =INT_MIN;
        for(int i =1; i<distance.size(); i++){
            cout<<visit[i]<<" ";
            ans = max(ans,distance[i]);
        }
        
        if(ans==INT_MAX){return -1;}
        return ans;  
        
    }
};

int main(){
    
    return 0;
}