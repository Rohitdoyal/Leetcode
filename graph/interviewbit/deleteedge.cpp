#include<bits/stdc++.h> 
using namespace std;
long long mod = 1000000007;
long long ans;
long long tot;
void dfs(int child, int parent, vector<int> &A, vector<int> *adj){
    long long sum = A[child-1];
    for(int i=0;i<adj[child].size();i++){
        int t = adj[child][i];
        if(t != parent){
            dfs(t,child,A,adj);
            sum += A[t-1];
        }
    }
    A[child-1]=sum;
    ans = max(ans,((sum%mod)*((tot-sum)%mod))%mod);
}
int deleteEdge(vector<int> &A, vector<vector<int> > &B) {
    ans=0;
    tot=0;
    vector<int> adj[A.size()+1];
    for(int i=0;i<A.size();i++) tot += A[i];
    for(int i=0;i<B.size();i++){
        adj[B[i][0]].push_back(B[i][1]);
        adj[B[i][1]].push_back(B[i][0]);
    }
    dfs(1,-1,A,adj);
    return ans%mod;
}
//more optimal solution 

void dfss(unordered_map<int,vector<int>>adj ,long long int node ,vector<int> &A, vector<long long int> &PC,long long int parent){
   
    PC[node]+=A[node-1];
    //cout<<"node: "<<node
    for(auto x: adj[node]){
        if(x!=parent){
            dfss(adj,x,A,PC,node);
            PC[node]=PC[node]+PC[x];
            
             
        }
    }
    return;
}

int deleteEdge2(vector<int> &A, vector<vector<int> > &B) {
    
    unordered_map<int,vector<int>>adj;    
    for(int i =0; i<B.size(); i++){
        adj[B[i][0]].push_back(B[i][1]);
        adj[B[i][1]].push_back(B[i][0]);
    }
    
    
    // for(auto x:adj){
    //     cout<<x.first<<" : ";
    //     for(auto y:adj[x.first]){
    //         cout<<y<<"->";
    //     }
    //     cout<<endl;
    // }
    long long int n =A.size();
   
    vector<long long int>PC(n+1,0);
    
    dfss(adj,1,A,PC,0);
    
    long long int total_sum = 0;
    for(long long int i =0; i<A.size(); i++){
        total_sum+= A[i];
    }
    
    long long int ans =INT_MIN;
    // cout<<"PC : ";
    // for(int i =1; i<n+1; i++){
    //     cout<<PC[i]<<" ";
    // }
    // cout<<endl;
    // cout<<"total sum == "<<total_sum<<endl;
    for(int i =2; i<=n; i++){
        long long int d1= PC[i];
        long long int d2= PC[1]-d1;
        long long int product = ((d1%1000000007)*(d2%1000000007)%1000000007);
        ans = max(ans, product);
        
    }
return ans%1000000007;
    
    
}
int main(){
    
    return 0;
}