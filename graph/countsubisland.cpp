#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    
    //we passes vector through reference so it will not make copy of this and we can update this also 
    
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i , int j ){
        grid1[i][j]=0;
        grid2[i][j]=0;
        
        int n = grid1.size();
        int m = grid1[0].size();
        
        if(i+1<n &&(grid1[i+1][j]==1)&&(grid2[i+1][j]==1)){
            dfs(grid1,grid2,i+1,j);
        }
        
        if(j+1<m &&(grid1[i][j+1]==1) &&(grid2[i][j+1]==1)){
            dfs(grid1,grid2,i,j+1);
        }
        
        if(i-1>=0 &&(grid1[i-1][j]==1)&&(grid2[i-1][j]==1)){
            dfs(grid1,grid2,i-1,j);
        }
        
        if(j-1>=0 &&(grid1[i][j-1]==1) &&(grid2[i][j-1]==1)){
            dfs(grid1,grid2,i,j-1);
        }
        return;
        
        
    }
     void dfss( vector<vector<int>>& grid2, int i , int j ){
      
        grid2[i][j]=0;
        
        int n = grid2.size();
        int m = grid2[0].size();
        
        if(i+1<n &&(grid2[i+1][j]==1)){
            dfss(grid2,i+1,j);
        }
        
        if(j+1<m &&(grid2[i][j+1]==1)){
            dfss(grid2,i,j+1);
        }
        
        if(i-1>=0 &&(grid2[i-1][j]==1)){
            dfss(grid2,i-1,j);
        }
        
        if(j-1>=0  &&(grid2[i][j-1]==1)){
            dfss(grid2,i,j-1);
        }
        return;
        
        
    }
    
    void printgrid(vector<vector<int>>& grid){
        for(int i =0; i<grid.size(); i++){
            for(int j =0; j<grid[i].size(); j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"-----------------------------------------\n";
    }
    
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
    
        //if one of zero then set zero 
        for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                if(grid1[i][j]==0 && (grid2[i][j]==1)){
                    dfss(grid2,i,j);
                   
                }
               
            }
        }
 
        //now let's check connected componet and 
        
        
        int ans =0;
        for(int i =0; i<n; i++){
            for(int j =0; j<m ; j++){
                if((grid1[i][j]==1) && (grid2[i][j]==1)){
                    ans= ans+1;
                    //here dfs will convert connected 1 to zeros 
                    dfs(grid1,grid2,i,j);
                }
            }
        }
        
        return ans; 
        
    }
};
int main(){
    
    return 0;
}