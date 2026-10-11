#ifndef LIST_HOMEWORK_H
#define LIST_HOMEWORK_H

#include <cassert>

template <typename T>
class ForwardList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& d) : data(d), next(nullptr) {}
    };
    
    Node* _head;
    int _size;

public:
    ForwardList() : _head(nullptr), _size(0) {}
    
    ~ForwardList() {
        clear();
    }
    
    ForwardList(const ForwardList& other) : _head(nullptr), _size(0) {
        if (other._head == nullptr) return;
        _head = new Node(other._head->data);
        Node* curr_new = _head;
        Node* curr_other = other._head->next;
        while (curr_other != nullptr) {
            curr_new->next = new Node(curr_other->data);
            curr_new = curr_new->next;
            curr_other = curr_other->next;
        }
        _size = other._size;
    }
    
    ForwardList& operator=(const ForwardList& other) {
        if (this == &other) return *this;
        clear();
        if (other._head != nullptr) {
            _head = new Node(other._head->data);
            Node* curr_new = _head;
            Node* curr_other = other._head->next;
            while (curr_other != nullptr) {
                curr_new->next = new Node(curr_other->data);
                curr_new = curr_new->next;
                curr_other = curr_other->next;
            }
            _size = other._size;
        }
        return *this;
    }
    
    void push_front(const T& x) {
        Node* newNode = new Node(x);
        newNode->next = _head;
        _head = newNode;
        ++_size;
    }
    
    void pop_front() {
        if (_head == nullptr) return;
        Node* temp = _head;
        _head = _head->next;
        delete temp;
        --_size;
    }
    
    T& front() {
        assert(_head != nullptr);
        return _head->data;
    }
    
    const T& front() const {
        assert(_head != nullptr);
        return _head->data;
    }
    
    void insert_after(Node* node, const T& value) {
        if (node == nullptr) return;
        Node* newNode = new Node(value);
        newNode->next = node->next;
        node->next = newNode;
        ++_size;
    }
    
    void erase_after(Node* node) {
        if (node == nullptr || node->next == nullptr) return;
        Node* temp = node->next;
        node->next = temp->next;
        delete temp;
        --_size;
    }
    
    void clear() {
        while (_head != nullptr) {
            Node* temp = _head;
            _head = _head->next;
            delete temp;
        }
        _size = 0;
    }
    
    void reverse() {
        Node* prev = nullptr;
        Node* current = _head;
        Node* next = nullptr;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        _head = prev;
    }
    
    int size() const {
        return _size;
    }
    
    bool empty() const {
        return _head == nullptr;
    }
    
    Node* begin() {
        return _head;
    }
    
    Node* begin() const {
        return _head;
    }
};

#endif
