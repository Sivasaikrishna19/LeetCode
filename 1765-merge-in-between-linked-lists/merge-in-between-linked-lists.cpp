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
        
        ListNode* head = list1;
        ListNode* temp = nullptr;

        int i = 0;

        while (head) {
            if (i == a - 1) {
                temp = head;
            }
            if (i == b) {
                ListNode* next = head->next;
                temp->next = list2; 
                while (list2->next) {
                    list2 = list2->next;
                }
                list2->next = next; 
                break;
            }
            head = head->next;
            i++;
        }

        return list1;
    }
};