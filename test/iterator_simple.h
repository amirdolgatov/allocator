//
// Created by amir on 01.12.24.
//

#ifndef ALLOCATOR_ITERATOR_SIMPLE_H
#define ALLOCATOR_ITERATOR_SIMPLE_H

template <class T>
struct Node{
    T value;
    Node* next{nullptr};
};

template <class T>
class iterator_simple{
public:

    using iterator_category = std::forward_iterator_tag;
    using value_type = int;


    Node<T> *node{nullptr};

    iterator_simple(){};

    iterator_simple(Node<T>* node): node{node}{};

    void operator++(){
        auto tmp = node;
        node = node->next;
    }

    T operator*(){
        return node->value;
    }

    bool operator==(iterator_simple& other){
        return node == other.node;
    }

    bool operator!=(iterator_simple& other){
        return node != other.node;
    }


};

#endif //ALLOCATOR_ITERATOR_SIMPLE_H
