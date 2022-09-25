class MyCircularQueue {
public:
    int size;
    int capacity;
    int ptr;
    int *arr;

    MyCircularQueue(int k): size(0), capacity(k), ptr(0) {
        arr = new int[capacity];
    }

    bool enQueue(int value) {
        if (isFull()) return false;
        arr[ptr] = value;
        ++ptr;
        ptr %= capacity;
        ++size;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        int index = ptr - size;
        if (index < 0) index += capacity;
        --size;
        return true;
    }

    int Front() {
        if (isEmpty()) return -1;
        int index = ptr - size;
        if (index < 0) index += capacity;
        return arr[index];
    }

    int Rear() {
        return (isEmpty()) ? -1 : arr[(ptr - 1 + capacity) % capacity];
    }

    bool isEmpty() {
        return (size == 0);
    }

    bool isFull() {
        return (size == capacity);
    }
};