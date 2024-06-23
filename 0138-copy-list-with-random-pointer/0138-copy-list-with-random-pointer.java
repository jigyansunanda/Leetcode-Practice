class Solution {
    public Node copyRandomList(Node head) {
        Node curr = head;

        // duplicate nodes
        while (curr != null) {
            Node next = curr.next;
            curr.next = new Node(curr.val);
            curr.next.next = next;
            curr = next;
        }

        // duplicate random pointers
        curr = head;
        while (curr != null) {
            if (curr.random != null) {
                curr.next.random = curr.random.next;
            }
            curr = curr.next.next;
        }

        // remove the copy list and return
        Node copy = null, copyTail = null;
        curr = head;
        while (curr != null) {
            if (copy == null) {
                copy = curr.next;
                copyTail = curr.next;
            } else {
                copyTail.next = curr.next;
                copyTail = copyTail.next;
            }
            curr.next = curr.next.next;
            curr = curr.next;
        }
        if (copyTail != null) copyTail.next = null;
        return copy;
    }
}