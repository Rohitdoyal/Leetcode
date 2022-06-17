#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    
    //bool iscycle()
//     bool iscycle(unordered_map<int,vector<int>>&adj, int node , int parent ,vector<int>&visit , vector<int>&ans ){
//     if(visit[node]==1){
//         ans.push_back(node);
//         ans.push_back(parent);
//         return true;
//     }

//     else if(visit[node]==0){
//         visit[node]=1;
//         for (auto x:adj[node])
//         {
//             /* code */
//             if(x!=parent && iscycle(adj,x,node,visit,ans)){
//                 // ans.push_back(node);
//                 // ans.push_back(parent);
//                 return true;
//             }
//         }
        
//     }
//     visit[node]= 2;
//     return false;
// }
    
    //let's do it using union and rank
    
    int get(vector<int>&parent, int x){
        if(parent[x]==x){
            return x;
        }
        return get(parent,parent[x]);
    }
  
    
    

    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        //cycle detection in undirected graph 

        
        int n = edges.size();
        vector<int>parent;
        vector<int>rank(n+1,1);
        for(int i =0; i<n+1; i++){
            parent.push_back(i);
        }
        
    
        vector<int> ams;
        for(auto edge: edges){
           
            int a= edge[0];
            int b= edge[1];
            int la= get(parent,a);
            int lb= get(parent,b);
//             cout<<"parent of "<< a<<":"<<la<<endl;
//             cout<<"parent of "<< b<<":"<<lb<<endl;
            
            if(la!=lb){
                if(rank[la]>rank[lb]){
                    parent[lb] =la; 
                }
                else if(rank[lb]>rank[la]){
                    parent[la] = lb; 
                }
                else{
                    parent[lb]=la;
                    rank[la]++;
                }
            }
            else{
                return edge;
            }
           
        }
        return ams;        
    }
};

        
//         unordered_map<int, vector<int>>adj;
//         int n = 0;
//         for(int i =0; i<edges.size() ; i++){
//             adj[edges[i][1]].push_back(edges[i][0]);
//             adj[edges[i][0]].push_back(edges[i][1]);
//             n = max(n,max(edges[i][1],edges[i][0]));
//         }
        
//         vector<int> visit(1000,0);
//         vector<int>ans;
        
//         iscycle(adj,1,0,visit,ans);
//         return ans;


int main(){
    
    return 0;
}