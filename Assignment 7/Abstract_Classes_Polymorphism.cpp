#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node {
    Node* next;
    Node* prev;
    int value;
    int key;

    Node(Node* p, Node* n, int k, int val)
        : prev(p), next(n), key(k), value(val) {}

    Node(int k, int val)
        : prev(NULL), next(NULL), key(k), value(val) {}
};

class Cache {
protected:
    map<int, Node*> mp;
    int cp;
    Node* tail;
    Node* head;

    virtual void set(int, int) = 0;
    virtual int get(int) = 0;
};

/* Write your code here */

class LRUCache : public Cache {
public:

    LRUCache(int capacity) {
        cp = capacity;
        head = NULL;
        tail = NULL;
    }

    void set(int key, int value) override {

        // If key already exists
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];

            node->value = value;

            // Remove from current position
            if (node->prev)
                node->prev->next = node->next;
            if (node->next)
                node->next->prev = node->prev;

            if (node == head)
                head = node->next;

            if (node == tail)
                tail = node->prev;

            // Put at front
            node->prev = NULL;
            node->next = head;

            if (head)
                head->prev = node;
            else
                tail = node;

            head = node;

            return;
        }

        // If cache is full, remove least recently used
        if (mp.size() == cp) {
            Node* node = tail;

            mp.erase(node->key);

            if (tail->prev) {
                tail = tail->prev;
                tail->next = NULL;
            } else {
                head = tail = NULL;
            }

            delete node;
        }

        // Create new node
        Node* node = new Node(key, value);

        node->next = head;

        if (head)
            head->prev = node;
        else
            tail = node;

        head = node;

        mp[key] = node;
    }

    int get(int key) override {

        if (mp.find(key) == mp.end()) {
            return -1;
        }

        Node* node = mp[key];

        // Move accessed node to front
        if (node != head) {

            if (node->prev)
                node->prev->next = node->next;

            if (node->next)
                node->next->prev = node->prev;

            if (node == tail)
                tail = node->prev;

            node->prev = NULL;
            node->next = head;

            head->prev = node;
            head = node;
        }

        return node->value;
    }
};

int main() {
    int n, capacity, i;
    cin >> n >> capacity;

    LRUCache l(capacity);

    for(i = 0; i < n; i++) {

        string command;
        cin >> command;

        if(command == "get") {
            int key;
            cin >> key;
            cout << l.get(key) << endl;
        }

        else if(command == "set") {
            int key, value;
            cin >> key >> value;
            l.set(key, value);
        }
    }

    return 0;
}