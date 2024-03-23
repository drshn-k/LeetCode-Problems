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
    void reorderList(ListNode* head) {
       ListNode* ans=head;
        vector<ListNode*>helper;
        while(head!=nullptr){
            helper.push_back(head);
            head=head->next;
        }
        ListNode* curr=ans;
        int s=1;
        int e=helper.size()-1;
        bool front=true;
        while(s<=e){
            if(front){
                curr->next=helper[e];
                e--;            }
        if(!front){
            curr->next=helper[s];
            s++;
        }
         curr=curr->next;
         front=!front;
        }
        curr->next=nullptr;
       head=ans;
       return;  
    }
};