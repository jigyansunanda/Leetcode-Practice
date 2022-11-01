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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(-1);
        ListNode* dummyTail = dummyHead;
        ListNode* curr = head;
        while (curr != NULL and curr->next != NULL) {
            ListNode* next = curr->next;
            ListNode* nextOfNext = curr->next->next;
            next->next = curr;
            curr->next = nextOfNext;
            curr = nextOfNext;
            dummyTail->next = next;
            dummyTail = dummyTail->next->next;
        }
        dummyTail->next = curr;
        return dummyHead->next;
    }
};