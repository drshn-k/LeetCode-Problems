/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
ListNode* add(ListNode* l1,ListNode* l2){
    ListNode* ans=new ListNode(0);
        ListNode* temp=ans;
        int carry=0;
        int curr;
        int n1=0;
        while(l1 and l2){
            curr=l1->val+l2->val+carry;
            carry=curr/10;
            curr%=10;
            temp->next=new ListNode(curr);
            temp=temp->next;
            l1=l1->next;
            l2=l2->next;
        } 
        while(l1){
            curr=l1->val+carry;
            carry=curr/10;
            curr%=10;
            temp->next=new ListNode(curr);
            temp=temp->next;
            l1=l1->next;
        }
         while(l2){
            curr=l2->val+carry;
            carry=curr/10;
            curr%=10;
            temp->next=new ListNode(curr);
            temp=temp->next;
            l2=l2->next;
        }
        return ans->next;
}

ListNode* reverse(ListNode* l){
    if(l==NULL or l->next==NULL)
    return l;
    ListNode* next=l->next;
    ListNode* temp=reverse(next);
    next->next=l;
    l->next=NULL;
    return temp;
}

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans=new ListNode(0);
        ListNode* temp=ans;
        int carry=0;
        int curr;
        int n1=0;
        l1=reverse(l1);
        l2=reverse(l2);
        while(l1 and l2){
            curr=l1->val+l2->val+carry;
            carry=curr/10;
            curr%=10;
            temp->next=new ListNode(curr);
            temp=temp->next;
            l1=l1->next;
            l2=l2->next;
        } 
        while(l1){
            curr=l1->val+carry;
            carry=curr/10;
            curr%=10;
            temp->next=new ListNode(curr);
            temp=temp->next;
            l1=l1->next;
        }
         while(l2){
            curr=l2->val+carry;
            carry=curr/10;
            curr%=10;
            temp->next=new ListNode(curr);
            temp=temp->next;
            l2=l2->next;
        }
        if(carry>0){
            temp->next=new ListNode(carry);
        }
        return reverse(ans->next);
    }
};
