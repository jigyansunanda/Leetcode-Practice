public class Solution {
    public ListNode detectCycle(ListNode head) {
        /*
         * Detect loop using Floyd's Algorithm.
         * Move slow pointer to the beginning of linked list.
         * Move both slow and fast at same speed.
         * their new meeting point will be beginnnig of the loop.
        */
        if (head == null) return head;
        boolean cycleFound = false;
        ListNode slow = head, fast = head;
        while (fast!=null && fast.next!=null) {
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast) {
                cycleFound = true;
                break;
            }
        }
        // cycle not found
        if (!cycleFound) {
            return null;
        }
        slow = head;
        // cycle found
        while (slow != fast) {
            slow = slow.next;
            fast = fast.next;
        }
        return slow;
    }
}