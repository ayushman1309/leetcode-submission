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
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL){
            ListNode* nextnode = curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextnode;

        } 
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        head = reverse(head);
        int maxVal = head->val;
        ListNode* curr = head;
        while(curr!=NULL && curr->next != NULL){
            if(curr->next->val < maxVal){
                curr->next = curr->next->next;
            }
            else{
                curr=curr->next;
                maxVal = curr->val;
            }
        }
        return reverse(head);
    }
};