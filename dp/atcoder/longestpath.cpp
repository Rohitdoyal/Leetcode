#include<bits/stdc++.h> 
using namespace std;

int solve(int node,unordered_map<long long int, vector<long long int>>&adj,vector<long long int>&dp){

    if(adj[node].size()==0){
        return 0;
    }

    if(dp[node]!=-1){
        return dp[node];
    }

    int longpath =0;
    for(auto x: adj[node]){
        longpath = max(longpath,1+solve(x,adj,dp));
    }

    return dp[node]= longpath;

}

int main(){

    long long int n,m;
    cin>>n>>m;
    unordered_map<long long int, vector<long long int>>adj;
    for(int i =0; i<m; i++){
        long long int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }

    vector<long long int>dp(n+2,-1);

    long long int ans  = INT_MIN;
    for(int i =1; i<=n; i++){
        ans = fmax(ans,solve(i,adj,dp));
    }

    cout<<ans<<endl;


    return 0;
}

















//--------------------------------------------------------------------
// void dfs(long long int node, unordered_map<long long int,vector<long long int>>&adj, vector<long long int>&dist, long long int k ){
//     if(adj[node].size()==0){
//         return;
//     }
//     dist[node]= max(dist[node],k);
//     for(auto x: adj[node]){
//         dfs(x,adj,dist,k+1);
//     }
//     return;
// }

// int bfs(long long int node , unordered_map<long long int, vector<long long int>>&adj)
// {
//     queue<long long int>q;
//     q.push(node);
//     long long int ans = INT_MIN;
//     long long int k =-1;
//     while (q.empty()==false)
//     {   
//         k++;
//         long long int g= q.size();
//         for (int i = 0; i <g; i++)
//         {
//             int t= q.front();
//             q.pop();
//            // dist[t]= fmax(dist[t],k);
//             ans = fmax(ans,k);
//             for (auto x: adj[t]){q.push(x);}
        
//     }}
//     return ans;
    

// }

// int main(){ 
//     long long int n,m;
//     cin>>n>>m;
//     unordered_map<long long int,vector<long long int>>adj;

//     for(long long int i =0; i<m; i++){
//         long long int x,y;
//         cin>>x>>y;
//         adj[x].push_back(y);
//     }

//     long long int rp =-1;
//     for(long long int i =1; i<=n; i++){
//         rp = fmax(rp,bfs(i,adj));   
//     }
//     cout<<rp<<endl;
//     return 0;
// }



    // for(int i =0; i<n+1; i++){
    //     for(int j =0; j<n+1; j++){
    //         cout<<matrix[i][j]<<" ";
    //     }cout<<endl;
    // }


    // int as = INT_MIN;
    // for(int i =0; i<n+1; i++){
    //     for(int j =0; j<n+1; j++){
    //         as= fmax(as,matrix[i][j]);
    //     }
    // }
    // cout<<as<<endl;
