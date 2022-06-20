
#include<bits/stdc++.h> 
using namespace std;


 struct trienode{
        char val;
        int f=0;
        struct trienode* child[26]={NULL};
    };
    
    bool isrootleaf(struct trienode* root){
        for(int i =0; i<26; i++){
            if(root->child[i]!=NULL){
                return false;
            }
        }
        return true;
    }
    
    void inorder(struct trienode* root , string s, vector<string>&ans){
        if(root==NULL){
            return;
        }
        s=s+root->val;
        if(isrootleaf(root)==true){
            ans.push_back(s);
            return;
        }
        else{
            for(int i =0; i<26; i++){
                if(root->child[i]!=NULL){
                    inorder(root->child[i],s,ans);
                }
            }
            return;
        }
    }
    
    
    int minimumLengthEncoding(vector<string>& words) {
       
        //let's do it using tri
        struct trienode* root= new trienode();
        root->val='#';
        
        //insert all element in trie
        
        for(auto word:words){
         struct trienode* ptr = root;
        for(int i=word.length()-1; i>=0; i--){
           
            int index= word[i]-'a';
            if(ptr->child[index]==NULL){
                struct trienode*temp =new trienode();
                temp->val = word[i];
                ptr->child[index]= temp;
                ptr= ptr->child[index];
            }
            else{
                ptr= ptr->child[index];
            }
            (i==0)?(ptr->f=1):(ptr->f=0);
            
        }
        }
        
        vector<string>ans;
        string s="";
        inorder(root,s,ans);
        int as=0;
        for(int i =0; i<ans.size(); i++){
            cout<<ans[i]<<endl;
            as= as+ans[i].length();
        }
        return as;
}
    

int main(){
    vector<string> words= {"time","me","bell"};
    cout<<" word's encode length : "<<minimumLengthEncoding(words)<<endl;
    return 0;
}
