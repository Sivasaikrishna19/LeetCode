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
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head; 
        }
        ListNode* slow = head;
        while(slow && slow->next){
           int temp = gcd(slow->val,slow->next->val);
           ListNode* tempNode = new ListNode;
           tempNode->val = temp;
           tempNode->next = slow->next;
           slow->next = tempNode;
           slow = slow->next->next;
        }
        return head;
    }
};