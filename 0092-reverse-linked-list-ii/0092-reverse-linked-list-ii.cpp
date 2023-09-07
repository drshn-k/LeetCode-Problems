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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        //handle the edge case of head;
        ListNode*dummy=new ListNode(0);
        dummy->next=head;
        ListNode*curr=head;
        ListNode*leftprev=dummy;
        //find postion of left
        for(int i=0;i<left-1;i++){
            leftprev=curr;
            curr=curr->next;
        }
        ListNode*prev=NULL;
        ListNode*store=NULL;
        //reverse the linked list for right-left+1 node;
       for(int i=0;(curr&&i<right-left+1);i++){
           store=curr->next;
           curr->next=prev;
           prev=curr;
           curr=store;
        }
        //point the pointers to first and last of reversed ll;
        leftprev->next->next=curr;
        leftprev->next=prev;
        return dummy->next;
        
    }
    //TC:O(N);
    //SC:O(1);
};