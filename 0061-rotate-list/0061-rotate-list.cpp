/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 */
class Solution {
private:
    int getLength(ListNode* head) {
        int len = 0;
        while (head) {
            ++len; head = head->next;
        }
        return len;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) return head;
        int len = getLength(head);
        k %= len;
        if (k == 0) return head;
        k = len - k;
        int count = 0;
        ListNode* curr = head;
        while (count < k - 1) {
            curr = curr->next;
            ++count;
        }
        ListNode* secondPart = curr->next;
        curr->next = NULL;
        secondPart = reverse(secondPart);
        ListNode* firstPart = reverse(head);
        head->next = secondPart;
        return reverse(firstPart);
    }
};