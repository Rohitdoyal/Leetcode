#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    
    // run bfs to track reachable grid position from pacific or atlantic boundary
    void bfs(int m, int n, queue<pair<int,int>>&Q, vector<vector<int>>& grid, vector<vector<bool>>&visited)
    {
        int rowOffset[] = {0,0,1,-1};
        int colOffset[] = {1,-1,0,0};
        int currentHeight;
        int cx,cy;
        int px,py;
        
        while(!Q.empty())
        {
            cx = Q.front().first;
            cy = Q.front().second;
            currentHeight = grid[cx][cy];
            
            Q.pop();
            
            for(int k=0;k<4;k++)
            {
                px = cx + rowOffset[k];
                py = cy + colOffset[k];
                
                // child node can be reached from current nodes if 
                // greater or equal in height compared to current node height
                if(px>=0 && px<m && py>=0 && py<n && grid[px][py]>=currentHeight && !visited[px][py])
                {
                    visited[px][py] = true;
                    Q.push({px,py});
                }
            }
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        
        vector<vector<int>>result;
        
        int m = grid.size();
        if(m==0) return result;
        
        int n = grid[0].size();
        if(n==0) return result;
        
        // track nodes reachable from pacific boundary
        vector<vector<bool>>pacificVisited(m,vector<bool>(n,false));
        
        // track nodes reachable from atlantic boundary
        vector<vector<bool>>atlanticVisited(m,vector<bool>(n,false));
        
        queue<pair<int,int>>Q;
        
        // add pacific boundary nodes  in to queue
        for(int i=0;i<n;i++)
        {
            if(!pacificVisited[0][i])
            {
                pacificVisited[0][i] = true;
                Q.push({0,i});                    
            }
        }

        // add pacific boundary nodes  in to queue       
        for(int i=1;i<m;i++)
        {
            if(!pacificVisited[i][0])
            {
                pacificVisited[i][0] = true;
                Q.push({i,0});                    
            }
        }
        
        // run bfs from pacific boundary nodes
        bfs(m,n,Q,grid,pacificVisited);
        
        // add atlantic boundary nodes
        for(int i=0;i<n;i++)
        {
            if(!atlanticVisited[m-1][i])
            {
                atlanticVisited[m-1][i] = true;
                Q.push({m-1,i});                    
            }
        }

        // add atlantic boundary nodes        
        for(int i=0;i<m-1;i++)
        {
            if(!atlanticVisited[i][n-1])
            {
                atlanticVisited[i][n-1] = true;
                Q.push({i,n-1});                    
            }
        }
        
        // run bfs from atlantic boundary nodes
        bfs(m,n,Q,grid,atlanticVisited);
        
        // push nodes in to result vector which are reachable both from pacific and atlantic boundary
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(pacificVisited[i][j] && atlanticVisited[i][j])
                    result.push_back({i,j});
        
        return result;
    }
};



// class Solution {
// public:
    
    
//     void dfs(int i , int j , int prevheight, vector<vector<bool>>&ao, vector<vector<bool>>&visit, vector<vector<int>>& h ){
//         if((prevheight>h[i][j]) || (visit[i][j]==true)||(i<0)||(j<0)||(i>=h.size())||(j>=h[0].size()) ||(ao[i][j]==true)){
//             return;
//         }
//         ao[i][j]=  true;
//         visit[i][j]=  true;
        
//         dfs(i-1,j,h[i][j],ao,visit,h);
//         dfs(i,j-1,h[i][j],ao,visit,h);
//         dfs(i+1,j,h[i][j],ao,visit,h);
//         dfs(i,j+1,h[i][j],ao,visit,h);
        
        
//     }

//     vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
//         int n = h.size();
//         int m = h[0].size();
        
//         vector<vector<bool>>ao,visitao;
//         vector<vector<bool>>po,visitbo;
        
//         for(int i =0; i<n; i++){
//             vector<bool>temp(m,false);
//             ao.push_back(temp);
//             po.push_back(temp);
//             visitao.push_back(temp);
//             visitbo.push_back(temp);
//         }
        
//         for(int i =0; i<n; i++){
//             dfs(i,0,h[i][0], po,visitbo , h );
//             dfs(i,m-1,h[i][m-1], ao,visitao , h);
//         }
        
//         for(int j =0; j<m ; j++){
//             dfs(0,j,h[0][j], po,visitbo ,h );
//             dfs(n-1,j,h[n-1][j], ao,visitao,h );
//         }
        
        
//         //so after that it will handle 
//         vector<vector<int>>ans;
//         for(int i =0; i<n; i++){
//             for(int j =0; j<m; j++){
//                 vector<int>temp;
//                 if(ao[i][j]&po[i][j]==1){
//                     temp.push_back(i);
//                     temp.push_back(j);
//                     ans.push_back(temp);
//                 }
//             }
//         }
//         return ans;
        
        
//     }
// };























// class Solution {
// public:
    
//     void dfs(vector<vector<int>>& h , int i , int j,vector<vector<bool>>& t){
//         int n = h.size();
//         int m = h[0].size();
        
//         if(i+1<n &&(h[i+1][j]<h[i][j])){
//             if(t[i+1][j]==true){
//                 t[i][j] = true;
//                 return;
//             }
//             else{
//                dfs(h,i+1,j,t); 
//             }
//         }
        
//         if(j+1<m &&(h[i][j+1]<h[i][j])){
//             if(t[i][j+1]==true){
//                 t[i][j] = true;
//                 return;
//             }
//             else{
//                dfs(h,i,j+1,t); 
//             }
//         }
        
//         if(i-1>=0 &&(h[i-1][j]<h[i][j])){
//             if(t[i-1][j]==true){
//                 t[i][j]= true;
//                 return;
//             }
//             else{
//                 dfs(h,i-1,j,t);
//             }
//         }
        
//         if(j-1>=0 &&(h[i][j-1]<h[i][j])){
//             if(t[i][j-1]==true){
//                 t[i][j]= true;
//                 return;
//             }
//             else{
//                 dfs(h,i,j-1,t);
//             }
//         }
//         return;
        
        
        
//     }
    
    
//     void crosscheck(int i , int j,vector<vector<bool>>& t , vector<vector<int>>& h){
//         int n = h.size();
//         int m = h[0].size();
//         if(i-1>=0 && h[i-1][j]==h[i][j]){
//             if(t[i-1][j]==true){
//                 t[i][j]= true;
//                 return;
//             }
//         }
        
//         if(j-1>=0 && h[i][j-1]==h[i][j]){
//             if(t[i][j-1]==true){
//                 t[i][j]= true; return;
//             }
//         }
        
//         if(i+1<n &&(h[i+1][j]==h[i][j])){
//             if(t[i+1][j]==true){
//                 t[i][j] = true; return;
//             }
//         }
        
//         if(j+1<m &&(h[i][j+1]==h[i][j+1])){
//             if(t[i][j+1]==true){
//                 t[i][j]= true; return;
//             }
//         }
        
//          return;
        
        
        
        
//     }
    
    
//     vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) { 
//         //let's try to solve by brute forces approach 
//         int n = h.size();
//         int m = h[0].size();
        
//         vector<vector<bool>>ao,po;
//         for(int i =0; i<n ; i++){
//             vector<bool> temp;
//             for(int j =0; j<m; j++){
//                 temp.push_back(false);
//             }
//             ao.push_back(temp);
//             po.push_back(temp);
//         }
        
//         //for ao only 
//         for(int i =0; i<n; i++){
//             ao[i][m-1]= true;
//             po[i][0]= true;
//         }
        
//         for(int j=0; j<m; j++){
//             ao[n-1][j]= true;
//             po[0][j]= true;
//         }
        
//         for(int i =n-2; i>=0; i--){
//             for(int j = m-2; j>=0;j--){
//                 if(ao[i][j]!=true){
//                     dfs(h,i,j ,ao);
//                 }
                
//             }
//         }
        
//         for(int i =1; i<n; i++){
//             for(int j =1; j<m; j++){
//                 if(po[i][j]!=true){
//                     dfs(h,i,j ,po);
//                 }
                
//             }
            
//         }
        
//        for(int i =0; i<n; i++){
//            for(int j =0; j<m; j++){
//                crosscheck(i,j,ao,h);
//                crosscheck(i,j,po,h);
//            }
//        }
        
        
        
        
//         cout<<"ao =="<<endl;
//         for(int i =0; i<n; i++){
//             for(int j =0; j<m; j++){
//                 cout<<ao[i][j]<<" ";
//             }
//             cout<<endl;
//         }
        
//         cout<<"vo =="<<endl;
//         for(int i =0; i<n; i++){
//             for(int j =0; j<m; j++){
//                 cout<<po[i][j]<<" ";
//             }
//             cout<<endl;
//         }
        
        
//         vector<vector<int>>ans;
        
//         for(int i =0; i<n; i++){
//             for(int j =0; j<m ; j++){
//                 vector<int> temp;
//                 if(ao[i][j]&po[i][j]==1){
//                     temp.push_back(i);
//                     temp.push_back(j);
//                     ans.push_back(temp);
//                 }
//             }
//         }
        
//         return ans;
        
   
        
//     }
// };

//dfs
//         int n = heights.size();
//         int m= heights[0].size();
        
//         vector<vector<int>> ans;
        
//         for(int i =0; i<n ; i++){
//            for(int j= 0; j<m ;j++){
//              if(dfs(heights,i,j)==true){
//                  ans.push_back({i,j});
//              }
//           } 
//         }
//         return ans;
        
int main(){
    
    return 0;
}