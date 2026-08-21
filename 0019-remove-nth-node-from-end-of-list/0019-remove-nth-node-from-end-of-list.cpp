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
    int getLenofLL(ListNode* head){
        int len = 0;
        while(head!=NULL){
            len++;
            head = head->next;
        }
        return len;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l = getLenofLL(head);
        if(l==n){
            ListNode* temp = head->next;
            delete(head);
            return temp; 
        }
        int a = l-n;
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(a--){
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        delete(temp);
        return head;
    }
};