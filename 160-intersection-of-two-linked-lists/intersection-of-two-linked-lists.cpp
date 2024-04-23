/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, bool> m;
        while(headB){
            m[headB] = true;
            headB = headB->next; 
        }
        while(headA){
            if(m.find(headA)!=m.end()){
                return headA;
            }
            headA = headA->next;
        }
        return NULL;
    }
};