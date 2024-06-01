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
int val = 0;
    ListNode* removeNodes(ListNode* head) {
         if(!head) return NULL;
        
        auto l = removeNodes(head->next);
        val = max(val, head->val);
        if(val <=  head->val){
            head->next = l; 
            return head;
            }
            delete head;
            return l;
     
    }
};