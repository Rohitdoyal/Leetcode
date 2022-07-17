#include<bits/stdc++.h> 
using namespace std;



typedef pair<int,pair<int,int>> pi;

int solve(int A, int B, vector<string> &C) {
    //let's try to solve using dfs first
    
    vector<vector<int>>t(A,vector<int>(B,INT_MAX));
    
    
    //min heap 
    //priority_queue<int,vector<int>,greater<int>>q;
    priority_queue<pi, vector<pi>,greater<pi>>q;
   // queue<pair<int,int>>q;
    q.push({0,{0,0}});
    t[0][0]= 0;
    
    while(q.empty()==false){
        int tillcost = q.top().first;
        int x= q.top().second.first;
        int y= q.top().second.second;
        q.pop();
        
        if((x==A-1) && (y==B-1)){
            return tillcost;
        }
        if(C[x][y]=='U'){
            if(x-1>=0){
                if(t[x-1][y]>t[x][y]){
                    t[x-1][y]= t[x][y];
                    q.push({tillcost,{x-1,y}});
                }
                
            }
            if(x+1<A){
                if(t[x+1][y]>t[x][y]){
                    t[x+1][y]= t[x][y]+1;
                    q.push({tillcost+1,{x+1,y}});
                }
            }
            
            if(y+1<B){
                if(t[x][y+1]>t[x][y]){
                    t[x][y+1]= t[x][y]+1;
                    q.push({tillcost+1,{x,y+1}});
                }
            }
            
            if(y-1>=0){
                if(t[x][y-1]>t[x][y]){
                    t[x][y-1]= t[x][y]+1;
                    q.push({tillcost+1,{x,y-1}});
                }
            }  
        }
        
        //down direction 
        if(C[x][y]=='D'){
            if(x-1>=0){
                if(t[x-1][y]>t[x][y]){
                    t[x-1][y]= t[x][y]+1;
                    q.push({tillcost+1,{x-1,y}});
                }
                
            }
            if(x+1<A){
                if(t[x+1][y]>t[x][y]){
                    t[x+1][y]= t[x][y];
                    q.push({tillcost,{x+1,y}});
                }
            }
            
            if(y+1<B){
                if(t[x][y+1]>t[x][y]){
                    t[x][y+1]= t[x][y]+1;
                    q.push({tillcost+1,{x,y+1}});
                }
            }
            
            if(y-1>=0){
                if(t[x][y-1]>t[x][y]){
                    t[x][y-1]= t[x][y]+1;
                    q.push({tillcost+1,{x,y-1}});
                }
            }  
        }
        
        //left direction 
        if(C[x][y]=='L'){
            if(x-1>=0){
                if(t[x-1][y]>t[x][y]){
                    t[x-1][y]= t[x][y]+1;
                    q.push({tillcost+1,{x-1,y}});
                }
                
            }
            if(x+1<A){
                if(t[x+1][y]>t[x][y]){
                    t[x+1][y]= t[x][y]+1;
                    q.push({tillcost+1,{x+1,y}});
                }
            }
            
            if(y+1<B){
                if(t[x][y+1]>t[x][y]){
                    t[x][y+1]= t[x][y]+1;
                    q.push({tillcost+1,{x,y+1}});
                }
            }
            
            if(y-1>=0){
                if(t[x][y-1]>t[x][y]){
                    t[x][y-1]= t[x][y];
                    q.push({tillcost,{x,y-1}});
                }
            }  
        }
        
        //right direction
        if(C[x][y]=='R'){
            if(x-1>=0){
                if(t[x-1][y]>t[x][y]){
                    t[x-1][y]= t[x][y]+1;
                    q.push({tillcost+1,{x-1,y}});
                }
                
            }
            if(x+1<A){
                if(t[x+1][y]>t[x][y]){
                    t[x+1][y]= t[x][y]+1;
                    q.push({tillcost+1,{x+1,y}});
                }
            }
            
            if(y+1<B){
                if(t[x][y+1]>t[x][y]){
                    t[x][y+1]= t[x][y];
                    q.push({tillcost,{x,y+1}});
                }
            }
            
            if(y-1>=0){
                if(t[x][y-1]>t[x][y]){
                    t[x][y-1]= t[x][y]+1;
                    q.push({tillcost+1,{x,y-1}});
                }
            }  
        }
        
        
    }
    return t[A-1][B-1];
    
    
}












//-------------dfs solution ----------------------------------------------------------------------------------------


// void dfs(int x, int y , int Ax,int By,vector<string> &C,long long int cost,long long int &ans){
//     if(x==Ax &&(y==By)){
//         ans = min(ans, cost);
//         return;
//     }
    
//     if(cost>ans){
//         return;
//     }
    
//     if(C[x][y]=='U'){
//         if(x-1>=0){
//             dfs(x-1,y,Ax,By,C,cost,ans);
//         }
//         if(y-1>=0){
//             dfs(x,y-1,Ax,By,C,cost+1,ans);
//         }
//         if(x+1<=Ax){
//             dfs(x+1,y,Ax,By,C,cost+1,ans);
//         }
//         if(y+1<=By){
//             dfs(x,y+1,Ax,By,C,cost+1,ans);
//         } 
//     }
//     if(C[x][y]=='L'){
//         if(x-1>=0){
//             dfs(x-1,y,Ax,By,C,cost+1,ans);
//         }
//         if(y-1>=0){
//             dfs(x,y-1,Ax,By,C,cost,ans);
//         }
//         if(x+1<=Ax){
//             dfs(x+1,y,Ax,By,C,cost+1,ans);
//         }
//         if(y+1<=By){
//             dfs(x,y+1,Ax,By,C,cost+1,ans);
//         } 
//     }
    
//     if(C[x][y]=='D'){
//         if(x-1>=0){
//             dfs(x-1,y,Ax,By,C,cost+1,ans);
//         }
//         if(y-1>=0){
//             dfs(x,y-1,Ax,By,C,cost+1,ans);
//         }
//         if(x+1<=Ax){
//             dfs(x+1,y,Ax,By,C,cost,ans);
//         }
//         if(y+1<=By){
//             dfs(x,y+1,Ax,By,C,cost+1,ans);
//         } 
//     }
//     if(C[x][y]=='R'){
//         if(x-1>=0){
//             dfs(x-1,y,Ax,By,C,cost+1,ans);
//         }
//         if(y-1>=0){
//             dfs(x,y-1,Ax,By,C,cost+1,ans);
//         }
//         if(x+1<=Ax){
//             dfs(x+1,y,Ax,By,C,cost+1,ans);
//         }
//         if(y+1<=By){
//             dfs(x,y+1,Ax,By,C,cost,ans);
//         } 
//     }
//     return;
    
// }

int main(){
    
    return 0;
}