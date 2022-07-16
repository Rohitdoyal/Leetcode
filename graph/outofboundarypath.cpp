#include<bits/stdc++.h> 
using namespace std;



class Solution {
    long long int fmod = 1e9 + 7;
public:
    long long int t[55][55][55];
    
    long long int dfs(int x, int y, int &m , int &n,int step){
        if(x>=m ||(x<0)||(y>=n)||(y<0)){
            return 1;
        }

        if(step<=0){
            return 0;
        }
        
        if(t[x][y][step]!=-1){
            return t[x][y][step];
        }
        
        int l = dfs(x+1,y,m,n,step-1)%fmod;
        int r = dfs(x-1,y,m,n,step-1)%fmod;
        int u = dfs(x,y+1,m,n,step-1)%fmod;
        int d = dfs(x,y-1,m,n,step-1)%fmod;
        
        
        return t[x][y][step] = ((l)%fmod+(r)%fmod+(u)%fmod+(d)%fmod)%fmod;
        
        
    }
    
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        memset(t, -1, sizeof(t));
        if(n==0){
            return 0;
        }
        return dfs(startRow, startColumn,m,n,maxMove);
         
    }
};

int main(){
    
    return 0;
}