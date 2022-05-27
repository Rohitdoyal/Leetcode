#include<bits/stdc++.h> 
using namespace std;


int knapsack(int val[], int weight[], int capacity, int n)
{
    if(n<=0 || weight==0){
        return 0;
    }
    else{
        if(weight[n-1]>capacity){
            return knapsack(val,weight,capacity,n-1);
        }
        else {
            return max(knapsack(val,weight,capacity,n-1), val[n-1]+knapsack(val,weight,capacity-weight[n-1],n-1));
        }
    }
}
int main(){
    //o-1 knapsack 
    //val array
    //weight array
    //bag's capacity

    int val[]= {1,4,5,7};
    int weight[]= {1,3,4,5};
    int capacity = 7;
    int n = sizeof(val)/sizeof(val[0]);
    cout<<"output=="<<knapsack(val,weight,capacity,n);
    return 0;
}