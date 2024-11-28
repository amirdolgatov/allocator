//
// Created by amir on 24.11.24.
//

#ifndef ALLOCATOR_ALLOCATOR_H
#define ALLOCATOR_ALLOCATOR_H

#include <iostream>

/*!
 * Аллокатор с предвыделенным объемом памяти
 * @tparam T тип данных для которых аллоцируется память
 */
template <class T>
class custom_allocator{
public:

    using value_type = T;

    custom_allocator(){
        this->volume = 100;
        pool = static_cast<T*>(::operator new(100 * sizeof(T)));     /// предварительно выделить память (пул) на n объектов
    }

    custom_allocator (size_t n) {
        this->volume = n;
        pool = static_cast<T*>(::operator new(n * sizeof(T)));     /// предварительно выделить память (пул) на n объектов
    }

    ~custom_allocator(){
        ::operator delete(pool);
    }

    /*!
     * Выделяем память
     * @param n количество байт
     * @return указатель на запрошенное пространство
     */
    T* allocate (std::size_t n)
    {
        auto tmp = offset + n;
        if(tmp > volume)         /// запрашивается больше чем доступно
            return nullptr;
        return pool + tmp;
    }

    /*!
     * Утилизировать указанный участок памяти
     * @param p указатель на память
     * @param n количество байт
     */
    void deallocate (T* p, std::size_t n)
    {
        if(n < offset){
            if(p == pool + offset - n)
                offset = offset - n;
        }
    }

private:

    T* pool{nullptr};
    T* current{nullptr};
    size_t offset = 0;
    size_t volume = 0;


};


#endif //ALLOCATOR_ALLOCATOR_H