//
// Created by amir on 24.11.24.
//

#ifndef IP_FILTER_LIST_SIMPLE_H
#define IP_FILTER_LIST_SIMPLE_H

#include <memory>
#include <list>

/// Пока для примтивных типов
template <typename T, typename Alloc = std::allocator<T>>
class list_simple{

    struct Node{
        T value;
        Node* next;
    };

    Node *head;
    Node *last;

    void push_back(T& val){
        if(head == NULL){
            head = std::allocator_traits<Node>::allocate(allocator, sizeof(Node));
            head->value = val;
        }
    }



    Alloc allocator;
    size_t size = 0;
};

#endif //IP_FILTER_LIST_SIMPLE_H
