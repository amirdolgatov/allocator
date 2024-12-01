//
// Created by amir on 24.11.24.
//

#ifndef IP_FILTER_LIST_SIMPLE_H
#define IP_FILTER_LIST_SIMPLE_H

#include <memory>
#include <list>
#include "iterator_simple.h"



/// Пока для примтивных типов
template <typename T, typename Alloc = std::allocator<T>>
class list_simple{
public:


    Node<T> *head{nullptr};
    Node<T> *last{nullptr};

    void push_back(T& val){
        if(head == NULL){
            head = allocator.allocate(1);
            head->value = val;
            last = head;
        }
        last->next = allocator.allocate(1);
        last = last->next;
        ++size_;
    }

    void push_back(T&& val){
        if(head == NULL){
            head = allocator.allocate(1);
            head->value = val;
            head->next = nullptr;
            last = head;
        }
        else{
            last->next = allocator.allocate(1);
            last = last->next;
            last->value = val;
            last->next = nullptr;
        }
        ++size_;
    }

    size_t size(){
        return size_;
    }

    bool empty(){
        return size_ == 0;
    }

    iterator_simple<T> begin(){
        return iterator_simple<T>(head);
    }

    iterator_simple<T> end(){
        return iterator_simple<T>(nullptr);
    }

    using node_alloc_t = typename std::allocator_traits<Alloc>::
    template rebind_alloc<Node<T>>;

    // create an object of type node allocator
    node_alloc_t allocator;
    size_t size_ = 0;
};

#endif //IP_FILTER_LIST_SIMPLE_H
