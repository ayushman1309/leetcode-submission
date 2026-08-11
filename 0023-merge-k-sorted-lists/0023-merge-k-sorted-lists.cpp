class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Min-heap:
        // pair<node value, node pointer>
        priority_queue<pair<int, ListNode*>,
        vector<pair<int, ListNode*>>,
        greater<pair<int, ListNode*>>>pq;

        for(auto node : lists){
            if(node!=nullptr) pq.push({node->val,node});
        }

        // dummy node
        ListNode* dummy = new ListNode(0);

        ListNode* curr = dummy;

        while(!pq.empty()){
            auto[val,node] = pq.top();

            pq.pop();

            curr->next = node;
            curr = curr->next;

            if(node->next != nullptr){
                pq.push({node->next->val,node->next});
            }
        }
        return dummy->next;

    }
};