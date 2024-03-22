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
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr != NULL){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while(fast != NULL && fast->next != NULL){
            //prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        //prev->next = NULL;
        slow = reverse(slow);
        fast = head;
        while(slow && fast){
            if(slow->val != fast->val)return false;
            slow = slow->next;
            fast = fast->next;
        }
        return true;
    }
};