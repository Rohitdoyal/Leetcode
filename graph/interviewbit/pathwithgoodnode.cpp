#include<bits/stdc++.h> 
using namespace std;

int solve(vector<int> &A, vector<vector<int> > &B, int C) {
    //let's solve using 
    //bfs solve
    
    //adj matrix ;
    unordered_map<int,vector<int>>adj;
    for(int i =0; i<B.size(); i++){
        sort(B[i].begin(),B[i].end());
    }
    
    
    for(int i =0; i<B.size(); i++){
        adj[B[i][0]].push_back(B[i][1]);
        //adj[B[i][1]].push_back(B[i][0]);
    }
    
    // cout<<"adj matrixx :"<<endl;
    // for(auto x:adj){
    //     cout<<x.first<<" :";
    //     for(auto y: adj[x.first]){
    //         cout<<y<<"->";
    //     }
    //     cout<<endl;
    // }
    
    queue<pair<int,int>>q;
    int val =A[0];
    q.push({1,val});
    
    int n = A.size();
    int ans =0;
    //vector<bool>visit(n+1,false);
    
    while(q.empty()==false){
        int n = q.size();
        for(int i =0; i<n; i++){
            int t= q.front().first;
            int value= q.front().second;
            //cout<<"node :"<<t<<" ::"<<value<<endl;
            q.pop();
            //check is it root node or not 
            
            if(adj[t].size()==0){
                if(value<=C){
                   // cout<<"root node is "<<t<<" : ";
                   // cout<<"value is "<<value<<endl;
                    ans++;
                }
            }
            
            else{
                for(auto x: adj[t]){
               
                    //cout<<"adjecncy node "<<x<<" : "<<A[x-1]<<endl;
                        if(A[x-1]==1){
                            q.push({x,value+1});
                        }
                        else{
                        q.push({x,value});
                        }
                    //}
                }
            }
            
            
            
        }
        
    }
    
    return ans;
    
     
}


int main(){
    
    return 0;
}