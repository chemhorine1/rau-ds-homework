#include "for_list_homework.h"
#include <cassert>
#include <iostream>

void test_push_front() {
    ForwardList<int> list;
    list.push_front(1);
    assert(list.size() == 1);
    assert(list.front() == 1);
    list.push_front(2);
    list.push_front(3);
    assert(list.size() == 3);
    assert(list.front() == 3);
    std::cout << "test_push_front passed" << std::endl;
}

void test_pop_front() {
    ForwardList<int> list;
    list.push_front(10);
    list.push_front(20);
    assert(list.size() == 2);
    assert(list.front() == 20);
    list.pop_front();
    assert(list.size() == 1);
    assert(list.front() == 10);
    list.pop_front();
    assert(list.size() == 0);
    assert(list.empty());
    std::cout << "test_pop_front passed" << std::endl;
}

void test_insert_erase_after() {
    ForwardList<int> list;
    list.push_front(1);
    auto node = list.begin();
    list.insert_after(node, 2);
    assert(list.size() == 2);
    assert(node->next->data == 2);
    list.insert_after(node, 3);
    assert(list.size() == 3);
    list.erase_after(node);
    assert(list.size() == 2);
    assert(node->next->data == 2);
    std::cout << "test_insert_erase_after passed" << std::endl;
}

void test_reverse() {
    ForwardList<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.reverse();
    assert(list.front() == 1);
    auto node = list.begin();
    assert(node->data == 1);
    assert(node->next->data == 2);
    assert(node->next->next->data == 3);
    std::cout << "test_reverse passed" << std::endl;
}

void test_copy_and_assignment() {
    ForwardList<int> list1;
    list1.push_front(10);
    list1.push_front(20);
    ForwardList<int> list2(list1);
    assert(list2.size() == 2);
    assert(list2.front() == 20);
    ForwardList<int> list3;
    list3 = list1;
    assert(list3.size() == 2);
    assert(list3.front() == 20);
    std::cout << "test_copy_and_assignment passed" << std::endl;
}

int main() {
    std::cout << "Running ForwardList tests" << std::endl;
    test_push_front();
    test_pop_front();
    test_insert_erase_after();
    test_reverse();
    test_copy_and_assignment();
    std::cout << "All tests passed" << std::endl;
    return 0;
}
