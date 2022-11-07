class Node {
public:
    int key, val;
    Node *left, *right;
    Node(int _key, int _val): key(_key), val(_val), left(NULL), right(NULL) {}
};

class LRUCache {
private:
    int capacity, size;
    Node *head, *tail;
    unordered_map<int, Node*> memo;

    void insertNode(Node* node) {
        if (head == NULL) head = tail = node;
        else {
            tail->right = node;
            node->left = tail;
            tail = node;
        }
    }

    void deleteNode(Node* node) {
        if (node->left != NULL) node->left->right = node->right;
        else head = node->right;
        if (node->right != NULL) node->right->left = node->left;
        else tail = node->left;
        node->right = NULL;
        node->left = NULL;
    }
public:
    LRUCache(int _capacity): capacity(_capacity), size(0), head(NULL), tail(NULL) {}

    int get(int key) {
        if (memo.find(key) == memo.end()) return -1;
        Node* node = memo[key];
        deleteNode(node);
        insertNode(node);
        return node->val;
    }

    void put(int key, int value) {
        Node *node = new Node(key, value);
        if (memo.find(key) != memo.end()) {
            Node* existing = memo[key];
            deleteNode(existing);
            insertNode(node);
            memo[key] = node;
        } else {
            if (size == capacity) {
                auto it = memo.find(head->key);
                if (it != memo.end()) memo.erase(it);
                deleteNode(head);
                memo[key] = node;
                insertNode(node);
            } else {
                ++size;
                memo[key] = node;
                insertNode(node);
            }
        }
    }
};