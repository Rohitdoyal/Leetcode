#include<bits/stdc++.h>
using namespace std;

class StockSpanner {
public:
    stack<pair<int,int>>s;
    StockSpanner() {
         stack<pair<int,int>>t;
         s=t;
    }
   

    int next(int price) {
        int k =1;
        int val =  price;
        if(s.empty()==true){
            s.push({k,val});
            return k;
        }

        else{
            if(s.top().second>val){
                s.push({k,val});
                return k;
            }
            else{
                while(s.empty()==false && s.top().second<=val){
                    k= k+s.top().first;
                    s.pop() ;
                }
                s.push({k,val});
                return k;
            }
        }
        return 0;


    }
};


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    

    return 0 ;
}