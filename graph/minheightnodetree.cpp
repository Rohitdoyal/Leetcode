#include<bits/stdc++.h> 
using namespace std;


// theory :
// see we have tree in graph theory tree is graph which does not contain cycle and all component connected , now we need to find out root .
// so suppose if we remove the leaf node then what we will get we get inner node for making height minimise we sure center most node should be root , for reach that node we use this concept we remove leaf node and got inner ,

// algortihm :

// datastructure: queue, indegree vector
// find all the nodes indegree
// now if we remove the leaf tree has property at the end we can got at most 2 node
// initialisation: put 1 degree node into queue
// decrease n to q size we are remove q size (leaf node from tree)
// pop all element in queue one by one go on adjecency node and decrease there indegree value to 1 if adj node indegree value is 1 then push into queue .
// after loop whater left in queue is our answer .
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        //let's build adj matrix 
        unordered_map<int,vector<int>>adj;
        for(int i =0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int>indegree(n,0);
        queue<int>q;
        for(int i =0; i<n; i++){
            indegree[i]= adj[i].size();
            if(indegree[i]==1){
                q.push(i);
            }
        }
        
        vector<int> ans;
        if(n==1){
            return {0};
        }
        
        
        while(n>2){
            int s= q.size();
            n = n-s;
            for(int i =0; i<s;i++){
                int t= q.front();
                q.pop();
                indegree[t]=0;
                for(auto x: adj[t]){
                   indegree[x]--;
                    if(indegree[x]==1){
                        q.push(x);
                    }
                }       
            }
        }
        while(q.empty()==false){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};
int main(){
    
    return 0;
}