#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
   
    int get(vector<int>&parent,int x){
        if(parent[x]==x){ return x;}
        else{return get(parent,parent[x]);}
    }

    bool uniond(int a, int b,vector<int>&parent,vector<int>&rank){
        a= get(parent,a);
        b= get(parent,b);
        if(a==b){return true;}

        if(rank[a]==rank[b]){
            rank[a]++;
            parent[b]=a;
        }
        else if(rank[a]>rank[b]){
            parent[b]=a;
        }
        else{
            parent[a]=b;
        }
        return false;
    }

    static bool compare(pair<int,pair<int,int>> a,pair<int,pair<int,int>> b){
        return a.first<b.first;
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<pair<int,pair<int,int>>> cost;
        for(int i =0; i<points.size()-1; i++){
            for(int j= i+1; j<points.size(); j++){
                int x1= points[i][0];
                int y1= points[i][1];
                
                int x2= points[j][0];
                int y2= points[j][1];
                
                int d= abs(x2-x1)+abs(y2-y1);
                cost.push_back({d,{i,j}});
            }
        }
        
        //now let's sort it and then see what is connected componet 
        
        sort(cost.begin(),cost.end(),compare);
        // for(int i =0; i<cost.size(); i++){
        //     cout<<cost[i].first<<" ";
        // }cout<<endl;
        
        //now we have a sorted cost vector and there correseponding points now le't add those points 
        //concept we  will use prime algorithm 
        //we connect point one by one abefore connecting the point we will check if we connect then it should not create a cycle 
        
        int ans = 0;
        vector<int> rank(points.size(),1);
        vector<int> parent;
        for(int i =0; i<points.size(); i++){
            parent.push_back(i);
        }
        
        
        for(int i =0; i<cost.size();i++){
            int karchaa  = cost[i].first;
            int point1= cost[i].second.first;
            int point2= cost[i].second.second;
            
            if(uniond(point1,point2,parent,rank)==false){
                ans+= karchaa;
            }
        }
        return ans;       
    }
};

int main(){
    
    return 0;
}