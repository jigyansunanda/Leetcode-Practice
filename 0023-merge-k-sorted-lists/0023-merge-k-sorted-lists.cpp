class Solution {
public:
    struct compare {
        bool operator() (const ListNode* A, const ListNode* B) {
            return (A->val > B->val);
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummyHead = new ListNode(-1);
        ListNode* dummyTail = dummyHead;
        priority_queue < ListNode*, vector<ListNode*>, compare> pq;
        for (auto l : lists) if (l) pq.push(l);
        while (!pq.empty()) {
            auto head = pq.top();
            pq.pop();
            dummyTail->next = head;
            dummyTail = dummyTail->next;
            if (head->next) pq.push(head->next);
        }
        dummyTail->next = NULL;
        return dummyHead->next;
    }
};