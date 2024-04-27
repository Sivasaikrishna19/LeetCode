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
    ListNode* swapPairs(ListNode* head) {
       if(!head || !head->next) return head;

        ListNode* dummy = new ListNode();
        ListNode* prev = dummy;
        ListNode* currNode = head;

        while(currNode && currNode->next){
            prev->next = currNode->next;
            currNode->next = prev->next->next;
            prev->next->next = currNode;
            prev = currNode;
            currNode = currNode->next;
        }

        return dummy->next;
    }
};