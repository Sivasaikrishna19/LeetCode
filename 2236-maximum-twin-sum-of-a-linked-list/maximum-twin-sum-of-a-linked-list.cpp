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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        stack<int> st;

        while(fast && fast->next){
            st.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        int sum = 0;
        while(slow){
        sum = max(sum, slow->val+st.top());
        st.pop();
        slow = slow->next;
        }

        return sum;
    }
};