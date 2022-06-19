#include<bits/stdc++.h> 
using namespace std;


struct trienode{
    char val;
    int f=0;
    trienode *child[26]={NULL};
};


void insert(struct trienode* head, string r){
    struct trienode * ptr= head;
    for (int i = 0; i < r.length(); i++)
    {
        /* code */
        int index= r[i]-'a';
        if(ptr->child[index]==NULL){
            struct trienode *temp = new trienode();
            temp->val= r[i];
            ptr->child[index]= temp;
        }
        else{
            ptr= ptr->child[index];
        }

        (i==r.length()-1)?(ptr->f=1):(ptr->f=0);

    }
    
}


void print_tri(struct trienode * head){{
    if(head==NULL){
        return;
    }

    cout<<head->val<<" f="<<head->f<<endl;
    for (int i = 0; i <26; i++)
    {
        /* code */
        if(head->child[i]!=NULL){
            print_tri(head->child[i]);

        }
    }
    
    
    return;
    
}

}
vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>>ans;

        struct trienode * head =new trienode();
        for(int i =0; i<products.size(); i++){
            string r= products[i];
            insert(head,r);
        }

        print_tri(head);



        return ans;

    }



int main(){
    vector<vector<string>> ans;
    vector<string> products = {"mobile","mouse","moneypot","monitor","mousepad"};
    string searchword= "mouse";

    ans = suggestedProducts(products,searchword);
    for(int i =0; i<ans.size(); i++){
        for (int j = 0; j< ans[i].size() ;  j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }



    return 0;
}