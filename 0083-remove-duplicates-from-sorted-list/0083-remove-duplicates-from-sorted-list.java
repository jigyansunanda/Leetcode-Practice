class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null || head.next == null) return head;
        ListNode tail = head.next;
        ListNode prev = head;
        while (tail != null) {
            if (prev.val == tail.val) {
                tail = tail.next;
            } else {
                prev.next = tail;
                prev = tail;
                tail = tail.next;
            }
        }
        prev.next = null;
        return head;
    }
}