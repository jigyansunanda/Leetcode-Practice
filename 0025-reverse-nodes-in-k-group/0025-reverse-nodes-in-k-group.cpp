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

    ListNode* reverseKGroup(ListNode* head, int k) {
    	ListNode* P = new ListNode(-1);
    	ListNode* tail = P;
    	ListNode* prev = NULL;
    	ListNode* curr = head;
    	while (true) {
    		int cnt = 0;
    		ListNode* currHead = curr;
    		while (cnt < k and curr != NULL) {
    			cnt++;
    			prev = curr;
    			curr = curr->next;
    		}
    		if (cnt == k) {
    			prev->next = NULL;
    			tail->next = reverse(currHead);
    			tail = currHead;
    		}else {
    			tail->next = currHead;
    			break;
    		}
    	}
    	return P->next;
    }
};