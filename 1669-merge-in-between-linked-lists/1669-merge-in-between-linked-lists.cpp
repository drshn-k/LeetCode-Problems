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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
          ListNode* d=new ListNode();
        ListNode* tem=d;
        for(int i=0;i<a;i++){
            tem->next=list1;
            tem=tem->next;
            list1=list1->next;
        }
        tem->next=list2;
        while(list2->next!=NULL){
            list2=list2->next;
        }
        tem=list2;
        int dd=b-a+1;
        while(dd--){
            list1=list1->next;
        }
        tem->next=list1;
        return d->next;
    }
};