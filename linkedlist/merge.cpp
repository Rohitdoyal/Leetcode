#include<bits/stdc++.h> 
using namespace std;


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
    int len(ListNode *head){
        int t=0;
        while(head){
            t++;
            head= head->next;
        }
        return t;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //do it without vector
        //do it o(1) space o(n)
        int d1= len(headA);
        int d2= len(headB);
        //assume A> B
    
        if(d1<d2){
            //if not then swap and make A>B
            ListNode *hold= headA;
            headA= headB;
            headB= hold;
            int tmp= d1;
            d1= d2;
            d2= tmp;
            //we are done
        }
        
        ListNode *tempa= headA;
        ListNode *tempb= headB;
        //now a will move till diff is not zero 
        int d= d1-d2;
        cout<<"d is "<<d<<endl;
        while((d--) &&(tempa!=NULL)){
            tempa= tempa->next;
        }
        
        cout<<tempa->val<<";"<<tempb->val<<endl;
        
        //both are at same distance 
        while(tempa && tempb){
            if(tempa== tempb){
                return tempa;
                break;
            }
            tempa= tempa->next;
            tempb= tempb->next;
        }
        return tempa;
        
        
    }
};

class Solution2 {
public:
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      // easy pessy 
        vector<int> va;
        ListNode * tempa= headA;
        while(tempa){
            va.push_back(tempa->val);
            tempa->val=-1;
            tempa= tempa->next;
        }
        
        ListNode * tempb= headB;
        while(tempb &&(tempb->val!=-1)){
            tempb= tempb->next;
        }
        
        tempa= headA;
        int k=0;
        while(tempa){
            tempa->val = va[k];
            k++;
            tempa= tempa->next;
        }     
        return tempb;
        
    }
};


        
int main(){
    
    return 0;
}