#include<bits/stdc++.h> 
using namespace std;


class Solution {
public:
    int ans ;
    int t;
    
    void dfs(vector<vector<int>>& grid , int i , int j ){
        grid[i][j]=2;
        t++;
        
        if(i-1>=0 && (grid[i-1][j]==1)){
            dfs(grid,i-1,j );
        }
        
        if(i+1<grid.size() && (grid[i+1][j]==1)){
            dfs(grid,i+1,j);
        }
        
        if(j-1>=0 && (grid[i][j-1]==1)){
            dfs(grid,i,j-1);
        }
        
        if(j+1<grid[i].size() && (grid[i][j+1]==1)){
            dfs(grid,i,j+1);
        }
        return;  
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        ans = 0;
        
        for(int i =0; i<grid.size(); i++){
            for(int j =0; j<grid[i].size() ; j++){
                if(grid[i][j] == 1){
                    t=0;
                    dfs(grid,i,j);
                    ans = max(ans, t);
                }
            }
        }
        
        return ans;
        
    }
};

int main(){
    
    return 0;
}