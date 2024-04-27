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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp = head;
        int count = 0;
        while(temp){
            temp = temp->next;
            count++;
        }
        int x = count-k;
        ListNode* front = head;
        ListNode* back = head;

        while(x!=0){
          back = back->next;
          x--;
        }
        while(k!=1){
          front = front->next;
          k--;
        }

        int tempVal = back->val;
        back->val = front->val;
        front->val = tempVal;

        return head;
    }
};