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
public:

    struct Node{
        T value;
        Node* next;
    };

    Node *head{nullptr};
    Node *last{nullptr};

    void push_back(T& val){
        if(head == NULL){
            head = allocator.allocate(1);     /// в сущности только лишь выделяем sizeof(Node) байт
            head->value = val;                                                         /// не вызовется ли конструктор еще раз ?
            last = head;
        }
        last->next = allocator.allocate(1);     /// в сущности только лишь выделяем sizeof(Node) байт
        last = last->next;
        ++size_;
    }

    void push_back(T&& val){
        if(head == NULL){
            head = allocator.allocate(1);     /// в сущности только лишь выделяем sizeof(Node) байт
            head->value = val;                                                         /// не вызовется ли конструктор еще раз ?
            last = head;
        }
        last->next = allocator.allocate(1);     /// в сущности только лишь выделяем sizeof(Node) байт
        last = last->next;
        ++size_;
    }

    size_t size(){
        return size_;
    }

    bool empty(){
        return size_ == 0;
    }

    using node_alloc_t = typename std::allocator_traits<Alloc>::
    template rebind_alloc<Node>;

    // create an object of type node allocator
    node_alloc_t allocator;
    size_t size_ = 0;
};

#endif //IP_FILTER_LIST_SIMPLE_H
