#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    /**
     * @param rooms: m x n 2D grid
     * @return: nothing
     */
    void wallsAndGates(vector<vector<int>> &rooms) {
        // write your code here

        //simple bfs code 
        queue<pair<int,int>>q;

        int n = rooms.size();
        int m = rooms[0].size();

        for(int i =0; i<n; i++){
            for(int j=0; j<m; j++){
                if(rooms[i][j]==0){
                    q.push({i,j});
                }
            }
        }

        int ans =-1;
        while(q.empty()==false){
            int sn = q.size();
            ans++;
            for(int i =0; i<sn; i++){
                int x = q.front().first;
                int y = q.front().second;

                rooms[x][y]= min(ans,rooms[x][y]);
                q.pop();
                if((x+1<n) &&(rooms[x+1][y]==2147483647)){
                    q.push({x+1,y});
                }

                if((y+1<m) &&(rooms[x][y+1]==2147483647)){
                    q.push({x,y+1});
                }

                if((x-1>=0) &&(rooms[x-1][y]==2147483647)){
                    q.push({x-1,y});
                }
                if((y-1>=0) &&(rooms[x][y-1]==2147483647)){
                    q.push({x,y-1});
                }
            }
        }
    }
};

int main(){
    
    return 0;
}