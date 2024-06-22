class Node {
    Node prev, next;
    int key, val;

    Node(int key, int val) {
        this.key = key;
        this.val = val;
        this.prev = this.next = null;
    }
}

class LRUCache {
    Node head, tail;
    int capacity, size;
    HashMap<Integer, Node> map;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        this.size = 0;
        this.head = new Node(-1, -1);
        this.tail = new Node(-1, -1);
        head.next = tail;
        tail.prev = head;
        this.map = new HashMap<>();
    }

    public int get(int key) {
        if (!map.containsKey(key)) return -1;
        Node node = map.get(key);
        int value = node.val;
        Node prev = node.prev, next = node.next;
        prev.next = next;
        next.prev = prev;
        node.prev = head;
        node.next = head.next;
        head.next.prev = node;
        head.next = node;
        map.put(key, node);
        return value;
    }

    public void put(int key, int value) {
        if (map.containsKey(key)) {
            Node node = map.get(key);
            node.val = value;
            map.put(key, node);
            Node prev = node.prev, next = node.next;
            prev.next = next;
            next.prev = prev;
            node.prev = head;
            node.next = head.next;
            head.next.prev = node;
            head.next = node;
        } else {
            Node node = new Node(key, value);
            map.put(key, node);
            node.prev = head;
            node.next = head.next;
            head.next.prev = node;
            head.next = node;
            ++size;
        }
        if (size > capacity) {
            int evictKey = tail.prev.key;
            Node evictNode = tail.prev;
            evictNode.prev.next = tail;
            tail.prev = evictNode.prev;
            map.remove(evictKey);
            --size;
        }
    }
}