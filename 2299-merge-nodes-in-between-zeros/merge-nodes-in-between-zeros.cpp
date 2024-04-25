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
    int sum(ListNode* node1, ListNode* node2){
        if(!node1 || !node2) return 0;
        int sum = 0;
        ListNode* node = node1;
        while(node->val !=0){
            sum += node->val;
            node = node->next;
        }
        return sum;
    }
public:
    ListNode* mergeNodes(ListNode* head) {
        if(head->next==NULL){
            return NULL;
        }
            ListNode* temp = head;
            ListNode* curr = temp->next;
            while(curr->val !=0){
                temp->val += curr->val;
                curr = curr->next;
            }
    
            ListNode* remaining = mergeNodes(curr);

            temp->next = remaining;
            return temp; 
    }
};