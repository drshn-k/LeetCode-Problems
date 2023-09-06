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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
         vector<ListNode*> res(k, nullptr);
        int inOnePart = 0;
        // find lenght of list
        for(ListNode* h = head; h; h = h->next, ++inOnePart);
        int reminder = inOnePart % k;
        inOnePart /= k;

        for(int pos = 0; pos < k && head; ++pos) {
            res[pos] = head;
            ListNode* prev = nullptr;

            // fill up with mandatory elements
            for(int i = 0; i < inOnePart; ++i) {
                prev = prev ? prev->next : head;
                head = head->next;
            }

            // just add reminder by one in all parts from 0 ( if needed )
            if(reminder) {
                --reminder;
                prev = prev ? prev->next : head;
                head = head->next;
            }
            prev->next = nullptr;
        }
        return res;  
    }
};