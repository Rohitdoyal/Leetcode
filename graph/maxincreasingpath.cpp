#include<bits/stdc++.h> 
using namespace std;



class Solution {
public:
    
    int dfs(vector<vector<int>>& matrix , int i , int j,vector<vector<int>>&mem){
        int l =0; 
        int u =0;
        int r= 0;
        int d= 0;
        if(mem[i][j]!=-1){
            return mem[i][j];
        }
        
        if(i-1>=0 &&(matrix[i-1][j]>matrix[i][j])){
            l =  1+dfs(matrix,i-1,j,mem);
        }
        if(i+1<matrix.size() && (matrix[i+1][j]>matrix[i][j]) ){
            r= 1+dfs(matrix,i+1,j,mem);
        }
        
         if(j-1>=0 &&(matrix[i][j-1]>matrix[i][j])){
            u =  1+dfs(matrix,i,j-1,mem);
        }
        if(j+1<matrix[0].size() && (matrix[i][j+1]>matrix[i][j]) ){
            d= 1+dfs(matrix,i,j+1,mem);
        }
        return mem[i][j]= max(max(l,r),max(u,d));
    }
    
    
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        //what we will do 
        //we apply dfs on each node and find the length 
        
        
        int n  =   matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>>mem;
        for(int i =0; i<n; i++){
            vector<int>temp(m,-1);
            mem.push_back(temp);
        }
        
        int ans = INT_MIN;
        for(int i =0; i<n; i++){
            for(int j =0; j<m ; j++){
                int d= 1+dfs(matrix, i, j,mem);        
                ans = max(ans,d);
            
            
            }
            
        }
        
        return ans;
        
    }
};
int main(){
    
    return 0;
}