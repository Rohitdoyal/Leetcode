#include<bits/stdc++.h> 
using namespace std;

//dijkstra on matrix 

typedef pair<int,pair<int,int>> pi;
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<pi, vector<pi>, greater<pi> > q;
        //let's build min heap 
        //priority_queue<int, vector<int>, greater<int>>q;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visit;
        for(int i =0; i<n; i++){
            vector<bool>temp(m,false);
            visit.push_back(temp);
        }
        int ans = max(grid[0][0], grid[n-1][m-1]);
        visit[0][0]= true;
        q.push({grid[0][0],{0,0}});
        
        while(q.empty()==false){
            int node = q.top().first;
            int row= q.top().second.first;
            int col = q.top().second.second;
            
            q.pop();
            ans = max(ans,node);
            if(row==n-1 &&(col==m-1)){
                return ans;
            }
            //now let's check 4 directional 
            if((row+1<n) && (visit[row+1][col]==false)){
                // if((row+1==n-1) &&(col==m-1)){
                //     return ans;
                // }
                q.push({max(node,grid[row+1][col]),{row+1,col}});
                visit[row+1][col]= true;
            }
            
            if((row-1>=0) && (visit[row-1][col]==false)){
                // if((row-1==n-1) &&(col==m-1)){
                //     return ans;
                // }
                q.push({max(node,grid[row-1][col]),{row-1,col}});
                visit[row-1][col]= true;
            }
            
            if((col+1<m) &&(visit[row][col+1]==false)){
                // if((row==n-1) &&(col+1==m-1)){
                //     return ans;
                // }
                q.push({max(node,grid[row][col+1]),{row,col+1}});
                visit[row][col+1]= true;
            }
            
            if((col-1>=0)&&(visit[row][col-1]==false)){
                // if((row==n-1) &&(col-1==m-1)){
                //     return ans;
                // }
                q.push({max(node,grid[row][col-1]),{row,col-1}});
                visit[row][col-1]= true;
            }
              
        }
        return ans;
    }
};

int main(){
    
    return 0;
}