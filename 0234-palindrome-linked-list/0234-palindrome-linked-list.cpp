typedef ListNode node;

class Solution {
public:
    node* reverse(node* head) {
        node* prev = NULL;
        node* next = NULL;
        while (head) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

    node* getMiddleNode(node* head) {
        node* slow = head;
        node* fast = head;
        while (head->next and head->next->next) {
            slow = slow->next;
            head = head->next->next;
        }
        return slow;
    }

    bool isPalindrome(ListNode* head) {
        if (head == NULL or head->next == NULL) return true;
        node* middle_node = getMiddleNode(head);
        node* reverse_head = reverse(middle_node->next);
        middle_node->next = reverse_head;
        while (reverse_head) {
            if (reverse_head->val != head->val) return false;
            reverse_head = reverse_head->next;
            head = head->next;
        }
        return true;
    }
};