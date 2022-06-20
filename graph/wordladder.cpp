#include<bits/stdc++.h> 
using namespace std;


// point i learn from this question 
// see if you observe then question is simple most of time in graph question we think about integers , this question give us some different intutation .
// so here we need to play with string , don't worry map will handel this type of problem

// next things which come into my mind is so i need to select the path 
// so traversal will work here . 
// so we have two type of traversal .
// dfs and bfs 
// see IMPORTANT NOTE we are not going to use dfs reason because what dfs actually do it's goes it's child node then it traversal next child to it;s child note if it will get endword it will say yeah he got it but if it doesn't then it will backtrack and see some other path ,
// so worst case time complexity will go exponitial time

// so we will use bfs 
// simple logic 
// * push head  node queue
// * check the size of queue pop till size and with it push unvisited node again in queue
// * if we got destination return the level number 

// * we are done here :)  

// code is not much good but i hope it will give idea 

class Solution {
public:
    
    bool iscon(string a, string b){
        int k =0;
        for(int i =0;i<a.length(); i++){
            if(a[i]!=b[i]){
                k++;
            }
        }
        if(k==1){
            return true;
        }
        return false;

    }
    

    int bfs( unordered_map<string,vector<string>> m, string source,string dest){
        queue<string> q;
        q.push(source);
        
        int  k =0;
        
        unordered_map<string,bool> visit;
        for(auto x: m){
            visit[x.first]=false;
        }
        
        while(q.empty()==false){
            k++;
            int n = q.size();
            for(int i =0; i<n; i++){
                string t= q.front();
                visit[t]= true;
                if(t==dest){
                    return k;
                }
                q.pop();
                for(auto x: m[t]){
                    if(visit[x]==false){
                        q.push(x);
                    }
                }
            }
            
            
        }
        return 0;
        
        
        
    }
    
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        if(beginWord==endWord){
            return 0;
        }
        
        int g=0;
        int isin=0;
         int n = wordList.size();
        
         unordered_map<string, int> vis;
        for(int i =0; i<wordList.size(); i++){
            vis[wordList[i]]=0;
            if(wordList[i]==endWord){
                g=1;
                
            }
            if(wordList[i]==beginWord){
                isin=1;
            }
        }
        if(g==0){
            return 0;
        }
        unordered_map<string,vector<string>> m;
        
        if(isin==0){
            for(int j =0; j<n; j++){
                if(iscon(beginWord,wordList[j])==true){
                    m[beginWord].push_back(wordList[j]);
                    m[wordList[j]].push_back(beginWord);
                }
            }
        }
        
        
       
        
        for(int i =1; i<n; i++){
            for(int j =0; j<i; j++){
                if(iscon(wordList[i],wordList[j])==true){
                    m[wordList[i]].push_back(wordList[j]);
                    m[wordList[j]].push_back(wordList[i]);
                }
            }   
        }
        
        
        // ----------------till here everything is okay 
        //now let' apply bfs on it 
        
        
        int ans = bfs(m,beginWord,endWord);
        return ans;   
    }
};

int main(){
    
    return 0;
}