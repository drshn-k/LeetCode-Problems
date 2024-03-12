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
    ListNode* removeZeroSumSublists(ListNode* head) {
          ListNode* temp=head;
        ListNode* prev=NULL;
        ListNode* newhead=NULL;

        while(temp!=NULL){
            int sum=0;
            ListNode* curr=temp;

            do{
                sum=sum+curr->val;
                curr=curr->next;
            }while(sum!=0 && curr !=NULL);
            
            if(sum!=0){
                // cout<<temp->val<<" ";
                if(newhead==NULL){
                    newhead=temp;
                    prev=temp;
                }
                else{
                    // cout<<prev->val<<" "<<temp->val<<endl;
                    prev->next=temp;
                    prev=temp;
                }
                temp=temp->next;
            }
            else{
                temp=curr;
            }
        }
        if(prev)
            prev->next=temp;
        return newhead;
        
        
    }
};