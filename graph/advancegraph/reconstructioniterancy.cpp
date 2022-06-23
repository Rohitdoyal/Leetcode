#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    bool dfs(unordered_map<string,vector<string>>&adj ,vector<string>&ans,string s,int z){
        if(ans.size()==z+1){
            return true;
        }
        if(adj[s].size()==0){
            return false;
        }
        for(int i =0; i<adj[s].size(); i++){
            if(adj[s][i] !="-1"){
                string h= adj[s][i];
                ans.push_back(h);
                adj[s][i]= "-1";
                if(dfs(adj,ans,h,z)==true){
                    return true;
                }
                adj[s][i]=h;
                ans.pop_back();
            }   
        }
        return false; 
    }
        
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<string>> adj;
        for(int i =0; i<tickets.size(); i++){
            adj[tickets[i][0]].push_back(tickets[i][1]);
        }
        //source is JFK it's given and boom it;s solve man 
        for(auto x: adj){
            sort(adj[x.first].begin(),adj[x.first].end());
        }
        vector<string>ans;
        string s="JFK";
        ans.push_back(s);
        int z= tickets.size();
        dfs(adj,ans,s,z);
        return ans;
    }
};
int main(){
    
    return 0;
}