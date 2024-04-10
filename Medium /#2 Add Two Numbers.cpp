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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        int digit = 0;
        ListNode* curr = head;
        while (l1 != NULL || l2 != NULL)
        {
            if (l1 != NULL)
            {
                digit += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL)
            {
                digit += l2->val;
                l2 = l2->next;
            }
            ListNode* temp = new ListNode(digit % 10);
            curr->next = temp;
            curr = temp;
            digit /= 10;
        }
        if (digit != 0)
        {
            ListNode* temp = new ListNode(digit);
            curr->next = temp;
        }
        ListNode* to_return = head->next;
        delete head;
        return to_return;
    }
};
