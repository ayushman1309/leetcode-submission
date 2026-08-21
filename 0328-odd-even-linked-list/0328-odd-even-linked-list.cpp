class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* temp = even;
        while(even!=nullptr && even->next != nullptr){
            odd->next = even->next;
            odd = odd->next;

            even->next = even->next->next;
            even = even->next;
        }

        odd->next = temp;
        return head;
    }
};