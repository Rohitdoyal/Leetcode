#include<bits/stdc++.h> 
using namespace std;


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //bfs traversal 
        //logic is preety simply 
        
        queue<pair<int,int>>q;
        int ans =0;
        int n = grid.size();
        int m = grid[0].size();
        //initilaize 
        
        for(int i =0; i<n; i++){
            for(int j =0; j<m ; j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        
        
        //mst logic it will do 
        
    
        while(q.empty()==false){
            ans++;
            int sn = q.size();
            for(int i =0 ; i<sn; i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                if((x+1<n) && (grid[x+1][y]==1)){
                    grid[x+1][y]=2;
                    q.push({x+1,y});
                    
                }
                
                if((x-1>=0) &&(grid[x-1][y]==1)){
                    grid[x-1][y]=2;
                    q.push({x-1,y});
                }
                
                if((y+1<m)&&(grid[x][y+1]==1)){
                    grid[x][y+1]=2;
                    q.push({x,y+1});
                }
                
                if((y-1>=0)&&(grid[x][y-1]==1)){
                    grid[x][y-1]=2;
                    q.push({x,y-1});
                }
                
                
                
            }
        }
        
        for(int i =0; i<n; i++){
            for(int j =0; j<m ; j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        
        if(ans==0){
            return ans;
        }
        
        return ans-1;
    }
};


int main(){
    
    return 0;
}