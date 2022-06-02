#include<bits/stdc++.h> 
using namespace std;

// so question is we need to find those place where we can reach through boundary point

// simple explation is just run dfs on boundary point and update those points to zero or some other value
// again itterate matrix n*m and when we fine grid [i][j] ==1 just increament ans and at the end return ans .
class Solution {
public:
    
    void dfs(vector<vector<int>>& grid,int i ,int j, int& k ){
        grid[i][j]=0;
        k++;
        
        if((i+1<grid.size()) &&(grid[i+1][j]==1)){
            dfs(grid,i+1,j,k);
        }
        
        if((j+1<grid[0].size()) &&(grid[i][j+1]==1)){
            dfs(grid,i,j+1,k);
        }
        
        if(i-1>=0 &&(grid[i-1][j]==1)){
            dfs(grid,i-1,j,k);
        }
        
        if(j-1>=0 &&(grid[i][j-1]==1)){
            dfs(grid,i,j-1,k);
        }
        return; 
    }
    
    void printgrid(vector<vector<int>>& grid){
        for(int i =0; i<grid.size(); i++){
            for(int j =0; j<grid[i].size() ;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"--------------------------\n";
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        //basecase
        if(grid.size()<=2|| grid[0].size()<=2){
            return 0;
        }
        // printgrid(grid);
        int h=0;
        for(int i =0; i<grid.size(); i++){
            if(grid[i][0]==1){
                h=0;
                dfs(grid,i,0,h);
            }
        }
        
        // cout<<"after 1 col \n";
        //  printgrid(grid);
        for(int i =0; i<grid.size(); i++){
            if(grid[i][grid[i].size()-1]==1){
                h=0;
                dfs(grid,i,grid[i].size()-1,h);
            }
        }
        
        // cout<<"after last col \n";
        //  printgrid(grid);
        for(int i =0; i<grid[0].size(); i++){
            if(grid[0][i]==1){
                h=0;
                dfs(grid,0,i,h);
            }
        }
        
        // cout<<"after top row \n";
        //  printgrid(grid);
        for(int i =0; i<grid[0].size(); i++){
            if(grid[grid.size()-1][i] ==1){
                h=0;
                dfs(grid,grid.size()-1,i,h);
            }
        }
        int ans =0;
        
        //print the matrix;
       // printgrid(grid);
        
        for(int i =1; i<grid.size()-1; i++){
            for(int j =1; j<grid[0].size(); j++){
                if(grid[i][j]==1){
                    ans++;
                }
            
            }
        }
        return ans;    
    }
};

int main(){
    
    return 0;
}