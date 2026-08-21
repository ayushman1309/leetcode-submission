class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* temp = dummy;
        while (temp->next != nullptr) {
            if (temp->next->val == val) {
                ListNode* nodeToDelete = temp->next;
                temp->next = temp->next->next;
               delete nodeToDelete;
            }
            else {
                temp = temp->next;
            }
        }
        return dummy->next;
    }
};