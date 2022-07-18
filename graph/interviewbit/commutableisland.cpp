#include<bits/stdc++.h> 
using namespace std;


//we can do it using dsu 
//we already solve this question before so that is it 

int get(int x, vector<int>&parent){
    if(parent[x]==x){
        return x;
    }
    
    return get(parent[x],parent);
}


bool unionid(int a, int b ,vector<int>&parent ,vector<int>&rank){
    a= get(a,parent);
    b= get(b,parent);
    if(a==b){
        return true;
    }
    
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

bool compare(vector<int>&a , vector<int>&b){
    return a[2]<b[2];
}

int solve(int A, vector<vector<int> > &B) {
    
    sort(B.begin(),B.end(),compare);
    // for(int i =0; i<B.size(); i++){
    //     cout<<B[i][0]<<" "<<B[i][1]<<" "<<B[i][2]<<endl;
    // }
    vector<int>rank(A+1,1);
    vector<int>parent(A+1,0);
    for(int i =0; i<A+1; i++){parent[i]=i;}
    
    int cost =0;
    for(int i =0; i<B.size(); i++){
        if(unionid(B[i][0],B[i][1],parent,rank)==false){
            cost = cost +B[i][2];
        }
    }
    return cost;

    
    return 0;
    
}

int main(){
    
    return 0;
}