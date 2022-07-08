#include<bits/stdc++.h> 
using namespace std;


#define pii pair<int, pair<int,int>>

class Solution {
public:
    //Directions (top, right, bottom, left)
    const int d4x[4] = {-1,0,1,0}, d4y[4] = {0,1,0,-1};
    
    int minimumEffortPath(vector<vector<int>>& h) {
        int n = h.size(), m = h[0].size();
        //min-heap
        priority_queue <pii, vector<pii>, greater<pii>> pq;
        //to store distances from (0,0)
        vector<vector<int>> dis(n,vector<int>(m,INT_MAX));
        dis[0][0] = 0;
        pq.push({0, {0, 0}});
        
        //Dijstra algorithm
        while(!pq.empty()) {
            pii curr = pq.top(); pq.pop();
            int d = curr.first, r = curr.second.first, c = curr.second.second;
            // bottom right position
            if(r==n-1 && c==m-1) return d;
            for(int i=0; i<4; ++i) {
                int nx = r+d4x[i], ny = c+d4y[i];
                //check if new position is invalid
                if(nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
                int nd = max(d, abs(h[nx][ny] - h[r][c]));
                if (nd < dis[nx][ny]) {
                    dis[nx][ny] = nd;
                    pq.push({nd, {nx, ny}});
                }
            }
        }
        return 0;
        //please upvote
    }
};
// typedef pair<int,pair<int,int>> pi;

// class Solution {
// public:
//     int minimumEffortPath(vector<vector<int>>& heights) {
//         //dijkstra on graph 
        
        
//         int n = heights.size();
//         int m = heights[0].size();
//         if((n==1) && (m==1)){
//             return 0;
//         }
        
          
//         if(m==1){
//             int ans  = INT_MIN;
//             for(int i =1; i<n; i++){
//                 ans = max(ans,abs(heights[i][0]-heights[i-1][0]));
//             } 
//             return ans;
//         }
        
//         if(n==1){
//             int ans = INT_MIN;
//             for(int j =1; j<m ; j++){
//                 ans = max(ans, abs(heights[0][j]-heights[0][j-1]));
//             }
//             return ans;
//         }
        
        
        
//         int ans =0;
        
      
        
        
        
//         priority_queue<pi, vector<pi>, greater<pi> > q;
//         //min heap will hold diff, next row,col that's it 
        
//         q.push({0,{0,0}});
//         vector<vector<bool>>visit;
//         for(int i =0; i<n; i++){
//             vector<bool>temp(m,false);
//             visit.push_back(temp);
//         }
//         visit[0][0] = true;
        
        
//         while(q.empty()==false){
//             int diff = q.top().first;
//             int i  = q.top().second.first;
//             int j = q.top().second.second;
//             ans = max(diff,ans);
//            // cout<<"poped element "<<i<<","<<j<<" diff="<<diff<<endl;
//             if((i==n-1) && (j==m-1)){
//                 return ans; 
//             }
//             q.pop();
//             visit[i][j]=true;
            
//             if((i+1<n) && (visit[i+1][j]==false)){
//                 int d = abs(heights[i+1][j]-heights[i][j]);
//               //  cout<<heights[i+1][j]<<"-"<<heights[i][j]<<" =="<<d<<endl;
//                 q.push({max(d,diff),{i+1,j}});
//                 //visit[i+1][j]= true;
//             }
            
//             if((i-1>=0) && (visit[i-1][j]==false)){
//                 int d = abs(heights[i-1][j]-heights[i][j]);
//               //  cout<<heights[i-1][j]<<"--"<<heights[i][j]<<" =="<<d<<endl;
//                 q.push({max(d,diff),{i-1,j}});
//                // visit[i-1][j]= true;
//             }
            
//             if((j+1<m) && (visit[i][j+1]==false)){
//                 int d = abs(heights[i][j+1]-heights[i][j]);
//                // cout<<heights[i][j+1]<<"--"<<heights[i][j]<<" =="<<d<<endl;
//                 q.push({max(d,diff),{i,j+1}});
//                 visit[i][j+1]= true;
//             }
            
//             if((j-1>=0) && (visit[i][j-1]==false)){
//                 int d = abs(heights[i][j-1]-heights[i][j]);
//                // cout<<heights[i][j-1]<<"--"<<heights[i][j]<<" =="<<d<<endl;
//                 q.push({max(d,diff),{i,j-1}});
//                // visit[i][j-1]= true;
                
//             }
//         }
        
//         return ans;
        
//     }
// };
int main(){
    
    return 0;
}